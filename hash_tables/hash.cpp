#include <utility>
#include <list>
#include "hash.hpp"

HashSet::Iterator HashSet::begin() {
  return this->_elements.begin();
}

HashSet::Iterator HashSet::end() {
  return this->_elements.end();
}

HashSet::HashSet() : 
  _numElements(0), 
  _maxLoadFactor(INIT_MAXLOADFACTOR),
  _currentBucketCount(_sizes[INIT_IDXSIZE]),
  _selectableSize(INIT_IDXSIZE)
{
  this->_buckets = new Iterator[this->_currentBucketCount];
  for (std::size_t i = 0; i < this->_currentBucketCount; i++)
    this->_buckets[i] = _elements.end();
}

HashSet::HashSet(const HashSet& other) {
  this->_maxLoadFactor = other._maxLoadFactor;
  this->_currentBucketCount = other._currentBucketCount;
  this->_selectableSize = other._selectableSize;
  this->_numElements = 0;

  // Initialise bucket
  this->_buckets = new Iterator[this->_currentBucketCount];
  for (std::size_t i = 0; i < this->_currentBucketCount; i++) {
    this->_buckets[i] = _elements.end();
  }

  // Copy elements
  for (auto val : other._elements) {
    insert(val);
  }
}

// Note: Second parameter for rehash(). 
std::size_t HashSet::hash(int key, std::size_t bucketCount = 0) const {
  if (bucketCount == 0) 
    bucketCount = this->_currentBucketCount;
  return key % bucketCount;
}

HashSet& HashSet::operator=(HashSet other) {
  if (this == &other) return *this;
  
  // Empty _buckets first.
  delete[] this->_buckets;

  // Typical assignment like the copy constructor.
  this->_maxLoadFactor = other._maxLoadFactor;
  this->_currentBucketCount = other._currentBucketCount;
  this->_selectableSize = other._selectableSize;
  this->_numElements = 0;
  this->_elements.clear();

  // Initialise bucket
  this->_buckets = new Iterator[this->_currentBucketCount];
  for (std::size_t i = 0; i < this->_currentBucketCount; i++) {
    this->_buckets[i] = _elements.end();
  }

  // Copy elements
  for (auto val : other._elements) {
    insert(val);
  }

  return *this;
}

HashSet::~HashSet() {
  delete[] this->_buckets;
}

void HashSet::insert(int key) {
  if (contains(key)) return;

  // Validate load factor first if we should rehash before inserting element.
  if (loadFactor() > this->_maxLoadFactor && _selectableSize < this->_sizes.size()) {
    rehash();
  }

  // Get bucket
  std::size_t index = hash(key);
  auto bucket = this->_buckets[index];

  // Insert key starting from bucket iterator.
  auto it = this->_elements.insert(bucket, key);
  
  // Increment number of elements.
  this->_numElements++;

  // Update the head pointer of the bucket.
  this->_buckets[index] = it;
}

bool HashSet::contains(int key) const {
  // Get bucket
  std::size_t index = hash(key);
  auto bucket = this->_buckets[index];

  // Starting from the iterator at the bucket, we iterate through _elements, 
  // until the hash of the next value is not equal to the bucket index.
  while (bucket != this->_elements.end() && hash(*bucket) == index) {
    if (*bucket == key) return true;
    bucket++;
  }

  return false;
}

// Same implementation as contains(), but we return iterator.
HashSet::Iterator HashSet::find(int key) {
  // Get bucket
  std::size_t index = hash(key);
  auto bucket = this->_buckets[index];

  // Keep iterating until next item has a different hash value/index.
  while (bucket != this->_elements.end() && hash(*bucket) == index) {
    // Return iterator if found.
    if (*bucket == key) return bucket;
    bucket++;
  }

  // Fallback
  return _elements.end();
}

// We simply reuse all the functions that we have already implemented together.
void HashSet::erase(int key) {
  erase(find(key));
}

HashSet::Iterator HashSet::erase(HashSet::Iterator it) {
  if (it == this->_elements.end()) return it;

  std::size_t index = hash(*it);

  // If bucket equal to head.
  if (it == this->_buckets[index]) {
    auto next = _elements.erase(it);
    this->_numElements--;

    // If the value after the head has the same index value.
    // we point the current bucket pointer to it.
    if (next != this->_elements.end() && hash(*next) == index) 
      this->_buckets[index] = next;
    // Otherwise, we set it to the default value.
    else 
      this->_buckets[index] = this->_elements.end();

    // We then return with the next iterator.
    return next;
  }

  // Not head
  auto next = _elements.erase(it);
  this->_numElements--;
  return next;
}

void HashSet::rehash() {
  // Get new size
  std::size_t newSize = this->_sizes[this->_selectableSize++];
  
  // Initialise new buckets.
  Iterator* newBuckets = new Iterator[newSize];
  for (std::size_t i = 0; i < newSize; i++) {
    newBuckets[i] = this->_elements.end();
  }

  // Loop through all items in _elements.
  auto it = this->_elements.begin();
  while (it != this->_elements.end()) {
    std::size_t newIndex = hash(*it, newSize);
    auto next = std::next(it);

    // If head is empty
    if (newBuckets[newIndex] == this->_elements.end())
      newBuckets[newIndex] = it;
    
    // If head not empty
    else {
      // Simply re-order, such that the new elements is on the front.
      // e.g the new element is now the head.
      this->_elements.splice(newBuckets[newIndex], this->_elements, it);

      // Move pointer one back.
      newBuckets[newIndex]--;
    }
    
    it = next;
  } 

  // Clean up
  delete[] this->_buckets;
  this->_buckets = newBuckets;
  this->_currentBucketCount = newSize;
}

// Returns the number of elements.
std::size_t HashSet::size() const {
  return this->_numElements;
}

// Check if number of elements is 0.
bool HashSet::empty() const {
  return this->_numElements == 0;
}

// Getter for _currentBucketCount.
std::size_t HashSet::bucketCount() const {
  return this->_currentBucketCount;
}

// We simply return the .size() of the bucket,
// presuming it exists. Most case if the b maps 
// to empty bucket, it should return 0.
std::size_t HashSet::bucketSize(std::size_t b) const {
  auto bucket = this->_buckets[b];
  std::size_t size = 0;
  
  for (auto it = bucket; it != this->_elements.end(); it++) {
    if (hash(*it) == b) size++;
    else break;
  }

  return size;
}

// Use hash function.
std::size_t HashSet::bucket(int key) const {
  return hash(key);
}

// Get current load factor.
float HashSet::loadFactor() const {
  return (double)this->_numElements / this->_currentBucketCount;
}

// Get max load factor.
float HashSet::maxLoadFactor() const {
  return this->_maxLoadFactor;
}


void HashSet::maxLoadFactor(float maxLoad) {
  // Guard clause to ensure maxLoad does not go less than 0.
  if (maxLoad < 0) maxLoad = 0.1;

  // Assign the value to maxLoadFactor
  this->_maxLoadFactor = maxLoad;

  // We keep rehashing until currentLoad is less than the new max load factor.
  while (loadFactor() > this->_maxLoadFactor) {
    // Another guard clause to ensure we don't go over sizes[sizes.size() + 1].
    // We get segmentation fault if we go over.
    if (_selectableSize > this->_sizes.size()) break;
    rehash();
  }
}