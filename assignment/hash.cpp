 #include <utility>
#include <list>
#include "hash.hpp"

const float INIT_MAXLOADFACTOR = 1;
const int INIT_IDXSIZE = 0;

HashSet::Iterator HashSet::begin() {
  return this->_elements.begin();
}

HashSet::Iterator HashSet::end() {
  return this->_elements.end();
}

HashSet::HashSet() :
  _buckets(_sizes[INIT_IDXSIZE]), 
  _numElements(0), 
  _maxLoadFactor(INIT_MAXLOADFACTOR),
  _currentBucketCount(_sizes[INIT_IDXSIZE]),
  _selectableSize(INIT_IDXSIZE)
{
}

HashSet::HashSet(const HashSet& other) {
  this->_buckets = other._buckets;
  this->_maxLoadFactor = other._maxLoadFactor;
  this->_currentBucketCount = other._currentBucketCount;
  this->_numElements = other._numElements;
  this->_selectableSize = other._selectableSize;
}

// Note: Second parameter for rehash(). 
std::size_t HashSet::hash(int key, std::size_t bucketCount = 0) const {
  if (bucketCount == 0) 
    bucketCount = this->_currentBucketCount;
  return key % bucketCount;
}

HashSet& HashSet::operator=(HashSet other) {
  this->_buckets = other._buckets;
  this->_maxLoadFactor = other._maxLoadFactor;
  this->_currentBucketCount = other._currentBucketCount;
  this->_numElements = other._numElements;
  this->_selectableSize = other._selectableSize;

  return *this;
}

HashSet::~HashSet() {
}

void HashSet::insert(int key) {
  // We avoid inserting for values that already exists 
  // on the set.
  if (contains(key)) return;

  // Validate first if we should rehash before inserting element.
  if (loadFactor() > this->_maxLoadFactor) {
    rehash();
  }

  // Insert value into the element list first.
  // And get an iterator for it. Since the _elements
  // vector grows from the front, we get the value at the back.
  this->_elements.push_back(key);
  auto it = std::prev(this->_elements.end());

  // Get bucket based on hash value.
  std::size_t index = hash(key);
  auto& bucket = this->_buckets[index];

  // Push the iterator into that bucket.
  bucket.push_back(it);
  // Increment current number of elements.
  this->_numElements++;
}

bool HashSet::contains(int key) const {
  // Get bucket
  std::size_t index = hash(key);
  auto& bucket = this->_buckets[index];

  // Iterate through the selected bucket
  // and check if item exists.
  for (auto it = bucket.begin(); it != bucket.end(); it++) {
    if (*(*it) == key) {
      return true;
    }
  }

  // Return false for fallback.
  return false;
}

HashSet::Iterator HashSet::find(int key) {
  // Evaluate first if key exists, we return nothing otherwise.
  if (!contains(key)) return this->_elements.end();

  // Get bucket
  std::size_t index = hash(key);
  auto& bucket = this->_buckets[index];

  // Loop through the bucket and find the value co
  for (auto it = bucket.begin(); it != bucket.end(); it++){
    if (*(*it) == key) {
      return *it;
    }
  }

  // We return nothing for fall back
  return this->_elements.end();
}

void HashSet::erase(int key) {
  // Return if value does not exist.
  if (!contains(key)) return;

  // Get bucket again.
  std::size_t index = hash(key);
  auto& bucket = this->_buckets[index];

  // Iterate through the bucket
  for (auto it = bucket.begin(); it != bucket.end(); it++) {
    // If found, simply remove the item on the bucket
    // and decrement the number of elements, then return.
    if (*(*it) == key) {
      this->_elements.erase(*it);
      bucket.erase(it);
      this->_numElements--;
      return;
    }
  }
}

HashSet::Iterator HashSet::erase(HashSet::Iterator it) {
  // Return if the iterator not valid.
  if (it == _elements.end()) return it;

  // Get bucket using the iterator
  int key = *it;
  std::size_t index = hash(key);
  auto& bucket = this->_buckets[index];

  // Loop through the bucket and find the corresponding
  // value and erase.
  for (auto it = bucket.begin(); it != bucket.end(); it++) {
    if (*(*it) == key) {
      bucket.erase(it);
      break;
    }
  }

  // After the iterator is gone on the bucket,
  // we also remove from the _elements list
  auto nextIt = this->_elements.erase(it);
  
  // Decrement the number of elements.
  this->_numElements--;
  
  // Simply return the iterator.
  return nextIt;
}

void HashSet::rehash() {
  int newSize = this->_sizes[this->_selectableSize++];
  
  // Instantiate a new bucket of new size.
  std::vector<std::list<Iterator>> newBuckets(newSize);

  // We simply copy the stuff over from the old buckets 
  // to the new buckets by getting a new index for each
  // items on the bucket.
  for (auto it = _buckets.begin(); it != _buckets.end(); it++) {
    for (auto& item : *it) {
      std::size_t newIndex = hash(*item, newSize);
      newBuckets[newIndex].push_back(item);
    }
  }
  
  // We then assign the value of newBackets
  // to our member variables `_buckets`.
  this->_buckets = std::move(newBuckets);
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
  auto& bucket = this->_buckets[b];
  return bucket.size();
}

// Use hash function.
std::size_t HashSet::bucket(int key) const {
  return hash(key);
}

// Get current load factor.
float HashSet::loadFactor() const {
  return static_cast<float>(this->_numElements) / this->_currentBucketCount;
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
    if (this->_selectableSize + 1 > this->_sizes.size()) break;
    rehash();
  }
}
