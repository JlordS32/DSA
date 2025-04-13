#include <utility>
#include <list>
#include "hash.hpp"

const float INIT_MAXLOADFACTOR = 1;
const int INIT_IDXSIZE = 0;

HashSet::Iterator HashSet::begin()
{
   return this->_elements.begin();
}

HashSet::Iterator HashSet::end()
{
   return this->_elements.end();
}

HashSet::HashSet() : _numElements(0),
                     _maxLoadFactor(INIT_MAXLOADFACTOR),
                     _currentBucketCount(_sizes[INIT_IDXSIZE]),
                     _selectableSize(INIT_IDXSIZE)
{
   // Initialise buckets.
   this->_buckets = new Iterator[this->_currentBucketCount];
   for (std::size_t i = 0; i < _currentBucketCount; ++i)
      _buckets[i] = _elements.end();
}

HashSet::HashSet(const HashSet &other)
{
   this->_maxLoadFactor = other._maxLoadFactor;
   this->_currentBucketCount = other._currentBucketCount;
   this->_selectableSize = other._selectableSize;
   this->_numElements = 0;

   // Initialise buckets.
   this->_buckets = new Iterator[this->_currentBucketCount];
   for (std::size_t i = 0; i < _currentBucketCount; ++i)
   {
      _buckets[i] = _elements.end();
   }

   // Copy elements
   for (auto val : other._elements)
   {
      insert(val);
   }
}

// Note: Second parameter for rehash().
std::size_t HashSet::hash(int key, std::size_t bucketCount = 0) const
{
   if (bucketCount == 0)
      bucketCount = this->_currentBucketCount;
   return key % bucketCount;
}

HashSet &HashSet::operator=(HashSet other)
{
   if (this == &other)
      return *this;

   // Clean up existing data
   delete[] _buckets;

   // Copy scalar fields
   _maxLoadFactor = other._maxLoadFactor;
   _currentBucketCount = other._currentBucketCount;
   _selectableSize = other._selectableSize;
   _numElements = 0;

   // Copy elements one by one
   _elements.clear();

   _buckets = new Iterator[_currentBucketCount];
   for (std::size_t i = 0; i < _currentBucketCount; ++i)
      _buckets[i] = _elements.end();

   for (const auto &val : other._elements)
      insert(val); // reuses your existing insert()

   return *this;
}

HashSet::~HashSet()
{
   delete[] _buckets;
}

void HashSet::insert(int key)
{
   // We avoid inserting for values that already exists
   // on the set.
   if (contains(key))
      return;

   // Validate first if we should rehash before inserting element.
   if (loadFactor() > this->_maxLoadFactor)
   {
      rehash();
   }

   // Get the bucket
   std::size_t index = hash(key);
   auto bucket = this->_buckets[index];

   // Since we assume that each bucket has an initial value of _elements.end().
   // we can insert values into _elements from .
   auto it = this->_elements.insert(bucket, key);
   this->_numElements++;
   this->_buckets[index] = it;
}

bool HashSet::contains(int key) const
{
   // Get bucket
   std::size_t index = hash(key);
   auto bucket = this->_buckets[index];

   // Loop through elements starting at the iterator contained from the selected bucket.
   // unti the hash of the next value is different from the hash of the current value.
   while (bucket != this->_elements.end() && hash(*bucket) == index)
   {
      if (*bucket == key)
         return true;
      bucket++;
   }

   // Return false for fallback.
   return false;
}

HashSet::Iterator HashSet::find(int key)
{
   // Get bucket
   std::size_t index = hash(key);
   auto bucket = this->_buckets[index];

   // Same implementation as contains(), but we return the iterator instead.
   while (bucket != this->_elements.end() && hash(*bucket) == index)
   {
      if (*bucket == key)
         return bucket;
      bucket++;
   }

   // Return nothing for fallback.
   return _elements.end();
}

void HashSet::erase(int key)
{
   erase(find(key));
}

HashSet::Iterator HashSet::erase(HashSet::Iterator it)
{
   // Return if the key does not exist.
   if (it == this->_elements.end())
      return it;

   std::size_t index = hash(*it);

   // If bucket is equal to head.
   if (it == this->_buckets[index])
   {
      auto next = _elements.erase(it);
      --_numElements;

      // If the next value has a different hash
      if (next != this->_elements.end() && hash(*next) == index)
         this->_buckets[index] = next;
      // If the next value has the same hash, simply assign the value the next value.
      else
         this->_buckets[index] = this->_elements.end();

      return next;
   }

   // Not head of the bucket
   auto next = _elements.erase(it);
   _numElements--;
   return next;
}

void HashSet::rehash()
{
   int newSize = this->_sizes[this->_selectableSize++];

   // Instantiate a new bucket of new size.
   Iterator *newBuckets = new Iterator[newSize];
   for (std::size_t i = 0; i < newSize; i++)
      newBuckets[i] = this->_elements.end();

   auto it = this->_elements.begin();
   while (it != this->_elements.end())
   {
      std::size_t newIndex = hash(*it, newSize);
      auto next = std::next(it);

      // If head
      if (newBuckets[newIndex] == this->_elements.end())
         newBuckets[newIndex] = it;

      else
      {

         // Simply re-order, such that the new elements is on the front.
         // E.g the new element is now the head.
         _elements.splice(newBuckets[newIndex], _elements, it);

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
std::size_t HashSet::size() const
{
   return this->_numElements;
}

// Check if number of elements is 0.
bool HashSet::empty() const
{
   return this->_numElements == 0;
}

// Getter for _currentBucketCount.
std::size_t HashSet::bucketCount() const
{
   return this->_currentBucketCount;
}

// We simply return the .size() of the bucket,
// presuming it exists. Most case if the b maps
// to empty bucket, it should return 0.
std::size_t HashSet::bucketSize(std::size_t b) const
{
   auto &bucket = this->_buckets[b];
   std::size_t size = 0;
   for (auto it = bucket; it != this->_elements.end(); it++)
   {
      if (hash(*it) == b)
      {
         size++;
      }
      else
      {
         break;
      }
   }
   return size;
}

// Use hash function.
std::size_t HashSet::bucket(int key) const
{
   return hash(key);
}

// Get current load factor.
float HashSet::loadFactor() const
{
   return static_cast<float>(this->_numElements) / this->_currentBucketCount;
}

// Get max load factor.
float HashSet::maxLoadFactor() const
{
   return this->_maxLoadFactor;
}

void HashSet::maxLoadFactor(float maxLoad)
{
   // Guard clause to ensure maxLoad does not go less than 0.
   if (maxLoad < 0)
      maxLoad = 0.1;

   // Assign the value to maxLoadFactor
   this->_maxLoadFactor = maxLoad;

   // We keep rehashing until currentLoad is less than the new max load factor.
   while (loadFactor() > this->_maxLoadFactor)
   {
      // Another guard clause to ensure we don't go over sizes[sizes.size() + 1].
      // We get segmentation fault if we go over.
      if (this->_selectableSize + 1 > this->_sizes.size())
         break;
      rehash();
   }
}
