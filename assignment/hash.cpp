#include <utility>
#include <list>
#include "hash.hpp"

const float INIT_MAXLOADFACTOR = 1;
const int INIT_IDXSIZE = 0;

HashSet::Iterator HashSet::begin()
{
   return Iterator(&_buckets, 0);
}

HashSet::Iterator HashSet::end()
{
   return Iterator(&_buckets, _buckets.size());
}

// HashSet::Iterator::Iterator(std::vector<std::list<int>> *buckets, std::size_t bucketIndex)
//     : _buckets(buckets),
//       _bucketIndex(bucketIndex)
// {
//    if (_bucketIndex < _buckets->size())
//       _listIt = (*_buckets)[_bucketIndex].begin();
//    goToNextBucket();
// }

// HashSet::Iterator::Iterator(std::vector<std::list<int>> *buckets, std::size_t bucketIndex, std::list<int>::iterator it)
//     : _buckets(buckets),
//       _bucketIndex(bucketIndex),
//       _listIt(it)
// {
// }

// void HashSet::Iterator::goToNextBucket()
// {
//    while (_bucketIndex < _buckets->size())
//    {
//       // Get bucket
//       auto& bucket = (*_buckets)[_bucketIndex];

//       // At this point, we have found the bucket, so we return.
//       if (_listIt != bucket.end()) // not empty
//          return;

//       // Move to next bucket
//       // and assign the iterator the beginning of the next bucket.
//       _bucketIndex++;
//       if (_bucketIndex < _buckets->size())
//       {
//          _listIt = (*_buckets)[_bucketIndex].begin();
//       }
//    }
// }

// int &HashSet::Iterator::operator*() const
// {
//    return *_listIt;
// }

// HashSet::Iterator &HashSet::Iterator::operator++()
// {
//    ++_listIt;
//    goToNextBucket();
//    return *this;
// }

// HashSet::Iterator HashSet::Iterator::operator++(int)
// {
//    Iterator temp = *this;
//    ++(*this);
//    return temp;
// }

// bool HashSet::Iterator::operator!=(const Iterator &other)
// {
//    return _bucketIndex != other._bucketIndex;
// }

// bool HashSet::Iterator::operator==(const Iterator &other)
// {
//    return _bucketIndex == other._bucketIndex;
// }

// // HashSet::Iterator HashSet::find(int key)
// // {
// //    std::size_t index = hash(key);
// //    auto &bucket = _buckets[index];

// //    for (auto it = bucket.begin(); it != bucket.end(); it++) {
// //       if (*it == key) {
// //          return Iterator(&_buckets, index, it);
// //       }
// //    }

// //    return end();
// // }

HashSet::HashSet() : _buckets(sizes[INIT_IDXSIZE]),
                     _numElements(0),
                     _maxLoadFactor(INIT_MAXLOADFACTOR),
                     _currentBucketCount(sizes[INIT_IDXSIZE]),
                     _selectableSize(INIT_IDXSIZE)
{
}

HashSet::HashSet(const HashSet &other)
{
   this->_buckets = other._buckets;
   this->_maxLoadFactor = other._maxLoadFactor;
   this->_currentBucketCount = other._currentBucketCount;
   this->_numElements = other._numElements;
   this->_selectableSize = other._selectableSize;
}

std::size_t HashSet::hash(int key, std::size_t bucketCount = 0) const
{
   if (bucketCount == 0)
      bucketCount = this->_currentBucketCount;
   return key % bucketCount;
}

HashSet &HashSet::operator=(HashSet other)
{
   this->_buckets = other._buckets;
   this->_maxLoadFactor = other._maxLoadFactor;
   this->_currentBucketCount = other._currentBucketCount;
   this->_numElements = other._numElements;
   this->_selectableSize = other._selectableSize;

   return *this;
}

HashSet::~HashSet()
{
}

void HashSet::insert(int key)
{
   // We avoid inserting for values that already exists
   // on the set.
   if (contains(key))
      return;

   // Rehash if load factor breaches _maxLoadFactor;
   float currentLoadFactor = static_cast<float>(_numElements) / _currentBucketCount;
   if (currentLoadFactor > _maxLoadFactor)
   {
      _selectableSize++;
      int newSize = sizes[_selectableSize];
      rehash(newSize);
   }

   // Get bucket based on hash value.
   std::size_t index = hash(key);
   auto &bucket = _buckets[index];

   // Push item into that bucket.
   bucket.push_back(key);

   // Increment current number of elements.
   _numElements++;
}

bool HashSet::contains(int key) const
{

   // Get bucket using hash value as the index.
   std::size_t index = hash(key);
   auto &bucket = _buckets[index];

   // Iterate through the selected bucket
   // and check if item exists.
   for (auto &item : bucket)
   {
      if (item == key)
      {
         return true;
      }
   }

   // Return false for fallback.
   return false;
}

void HashSet::erase(int key)
{
   // Return if value does not exist.
   if (!contains(key))
      return;

   // Get bucket again.
   std::size_t index = hash(key);
   auto &bucket = _buckets[index];

   // Iterate through the bucket
   for (auto it = bucket.begin(); it != bucket.end(); it++)
   {
      // If found, simply remove the item on the bucket
      // and decrement the number of elements, then return.
      if (*it == key)
      {
         bucket.erase(it);
         _numElements--;
         return;
      }
   }
}

// HashSet::Iterator HashSet::erase(HashSet::Iterator it)
// {
//    std::ignore = it;
// }

void HashSet::rehash(std::size_t newSize)
{
   // Instantiate a new bucket of new size.
   std::vector<std::list<int>> newBuckets(newSize);

   // We simply copy the stuff over from the old buckets
   // to the new buckets by getting a new index for each
   // items on the bucket.
   for (const auto &bucket : _buckets)
   {
      for (int key : bucket)
      {
         std::size_t newIndex = hash(key, newSize);
         auto &newBucket = newBuckets[newIndex];
         newBucket.push_back(key);
      }
   }

   // We then assign the value of newBackets
   // to our member variables `_buckets`.
   this->_buckets = newBuckets;

   // Make sure to also not forget this.
   this->_currentBucketCount = newSize;
}

std::size_t HashSet::size() const
{
   return _numElements;
}

bool HashSet::empty() const
{
   return this->_numElements == 0;
}

std::size_t HashSet::bucketCount() const
{
   return this->_currentBucketCount;
}

std::size_t HashSet::bucketSize(std::size_t b) const
{
   auto &bucket = _buckets[b];
   return bucket.size();
}

std::size_t HashSet::bucket(int key) const
{
   return hash(key);
}

float HashSet::loadFactor() const
{
   return static_cast<float>(_numElements) / _currentBucketCount;
}

float HashSet::maxLoadFactor() const
{
   return _maxLoadFactor;
}

void HashSet::maxLoadFactor(float maxLoad)
{
   if (maxLoad < 0)
      maxLoad = 0.1;
   this->_maxLoadFactor = maxLoad;

   // Fallback in case the new load factor is less than the current load.
   // Same implementation as in the member function insert().
   float currentLoad = static_cast<float>(_numElements) / _currentBucketCount;
   if (currentLoad > _maxLoadFactor)
   {
      _selectableSize++;
      int newSize = sizes[_selectableSize];
      rehash(newSize);
   }
}