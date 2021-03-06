//-----------------------------------------------------------------------------
// File: unifier.h
// Copyright (c) 2000-2006, Ensemble Studios
//-----------------------------------------------------------------------------
#pragma once

#include "containers\hashMap.h"

// A Unifier is a container of unique objects with a fixed index associated with each.

template<
   class ObjectType, 
   class Hasher=BHasher<ObjectType>,
   class Comparer=BEqualTo<ObjectType>
   >
class Unifier
{
public:
   typedef int Index;
   enum { cInvalidIndex = -1 };

   typedef BHashMap<ObjectType, Index, Hasher, Comparer> BObjectHashMap;
   typedef BDynamicArray<ObjectType> ObjectVector;
   
   Unifier()
   {
   }

   virtual ~Unifier()
   {
   }

   int size(void) const
   {
      return static_cast<int>(mObjs.size());
   }

   bool empty(void) const
   {
      return mObjs.empty();
   }

   const BObjectHashMap& getHashMap(void) const
   {
      return mHashMap;
   }

   const ObjectVector& getObjects(void) const
   {
      return mObjs;
   }

   const ObjectType& at(int i) const
   {
      const ObjectType& o = mObjs[debugRangeCheck(i, size())];

#ifdef DEBUG      
      BObjectHashMap::const_iterator it = mHashMap.find(o);
      BASSERT(it != mHashMap.end());
      BASSERT(it->second == i);
#endif

      return o;
   }

   const ObjectType& operator[] (int i) const
   {
      return at(i);
   }

   void clear(void)
   {
      mHashMap.clear();
      mObjs.clear();
   }

   // first is the object index
   // second is false if insert failed (object already exists)
   typedef std::pair<Index, bool> InsertResult;

   InsertResult insert(const ObjectType& o)
   {
      Index nextIndex = size();
      
      const std::pair<BObjectHashMap::const_iterator, bool> res = 
         mHashMap.insert(std::make_pair(o, nextIndex));

      if (res.second)
         mObjs.push_back(o);
      else
         nextIndex = (*res.first).second;
      
      return std::make_pair(nextIndex, res.second);
   }

   // cInvalidIndex if object does not exist in the container
   Index find(const ObjectType& o) const
   {
      BObjectHashMap::const_iterator res = mHashMap.find(o);
      if (res == mHashMap.end())
         return cInvalidIndex;
      return res->second;
   }

protected:
   BObjectHashMap mHashMap;
   ObjectVector mObjs;
};

#if 0
template<
   class ObjectType, 
   class HashCompareType = stdext::hash_compare<ObjectType, std::less<ObjectType> > 
   >
class IndexedUnifier : public Unifier<ObjectType, HashCompareType>
{
   typedef Unifier<ObjectType, HashCompareType> Base;
   
public:
   IndexedUnifier() : 
      Base(), 
      mNextInputIndex(0)
   {
   }

   virtual ~IndexedUnifier()
   {
   }
   
   void clear(void)
   {
      Base::clear();
      mInputToMergedIndices.clear();
      mMergedToInputIndices.clear();
      mNextInputIndex = 0;
   }

   struct InsertResult
   {
      Index objectIndex;
      bool inserted;
      Index origIndex;
      
      InsertResult() 
      {
      }

      InsertResult(Index objI, bool i, Index origI) : objectIndex(objI), inserted(i), origIndex(origI)
      {
      }
   };

   InsertResult insert(const ObjectType& o)
   {
      // first is the object index
      // second is false if insert failed (object already exists)
      std::pair<Index, bool> res = Base::insert(o);

      if (res.second)
      {
         // insertion - object has not been seen before
         mMergedToInputIndices.push_back(mNextInputIndex);
      }
      
      mInputToMergedIndices.push_back(res.first);
      
      const Index origIndex = mNextInputIndex;
      
      mNextInputIndex++;

      return InsertResult(res.first, res.second, origIndex);
   }

   int numInputObjects(void) const 
   {
      return mNextInputIndex;
   }

   // returns the input index of the indicated merged object
   Index mergedIndexToInputIndex(Index mergedIndex) const
   {
      return mMergedToInputIndices[
         debugRangeCheck(mergedIndex, static_cast<int>(mMergedToInputIndices.size()))
      ];
   }
   
   // returns the merged index of the indicated input object
   Index inputIndexToMergedIndex(Index inputIndex) const
   {
      return mInputToMergedIndices[debugRangeCheck(inputIndex, static_cast<int>(mInputToMergedIndices.size()))];
   }
   
   // returns input index of the first instance of the indicated input object
   // (i.e. the first time the object was encountered)
   Index inputIndexToFirstInstance(Index inputIndex) const
   {
      const Index mergedIndex = inputIndexToMergedIndex(inputIndex);
      return mergedIndexToInputIndex(mergedIndex);
   }

   // cInvalidIndex if object does not exist in the container
   Index find(const ObjectType& o) const
   {
      BObjectHashMap::const_iterator res = mHashMap.find(o);
      if (res == mHashMap.end())
         return cInvalidIndex;
      return res->second;
   }

protected:
   // maps input index to new index
   BDynamicArray<Index> mInputToMergedIndices;
   
   // maps new indices to input index
   BDynamicArray<Index> mMergedToInputIndices;

   int mNextInputIndex;
};
#endif

#if 0
template<class ObjectType>
class MapUnifier
{
public:
   typedef int Index;
   enum { cInvalidIndex = -1 };

   typedef std::map<ObjectType, Index> ObjectMap;
   typedef BDynamicArray<ObjectType> ObjectVector;

   MapUnifier()
   {
   }

   virtual ~MapUnifier()
   {
   }

   int size(void) const
   {
      return static_cast<int>(mObjs.size());
   }

   bool empty(void) const
   {
      return mObjs.empty();
   }

   const ObjectMap& getMap(void) const
   {
      return mMap;
   }

   const ObjectVector& getObjects(void) const
   {
      return mObjs;
   }

   const ObjectType& at(int i) const
   {
      const ObjectType& o = mObjs[debugRangeCheck(i, size())];

#if 0
#ifdef DEBUG      
      ObjectMap::const_iterator it = mMap.find(o);
      BASSERT(it != mMap.end());
      BASSERT(it->second == i);
#endif
#endif

      return o;
   }

   const ObjectType& operator[] (int i) const
   {
      return at(i);
   }

   void clear(void)
   {
      mMap.clear();
      mObjs.clear();
   }

   // first is the object index
   // second is false if insert failed (object already exists)
   std::pair<Index, bool> insert(const ObjectType& o)
   {
      Index nextIndex = size();
      
      const std::pair<ObjectMap::const_iterator, bool> res = 
         mMap.insert(std::make_pair(o, nextIndex));

      if (res.second)
         mObjs.push_back(o);
      else
         nextIndex = (*res.first).second;
      
      return std::make_pair(nextIndex, res.second);
   }

   // cInvalidIndex if object does not exist in the container
   Index find(const ObjectType& o) const
   {
      ObjectMap::const_iterator res = mMap.find(o);
      if (res == mMap.end())
         return cInvalidIndex;
      return res->second;
   }

protected:
   ObjectMap mMap;
   ObjectVector mObjs;
};
#endif

template<class ObjectType>
class BArrayUnifier
{
public:
   typedef int Index;
   enum { cInvalidIndex = -1 };

   typedef BDynamicArray<ObjectType> ObjectVector;

   BArrayUnifier()
   {
   }

   virtual ~BArrayUnifier()
   {
   }

   uint size(void) const
   {
      return mObjs.size();
   }

   bool empty(void) const
   {
      return mObjs.empty();
   }
   
   const ObjectVector& getObjects(void) const
   {
      return mObjs;
   }

   const ObjectType& at(int i) const
   {
      const ObjectType& o = mObjs[i];
      return o;
   }

   const ObjectType& operator[] (int i) const
   {
      return at(i);
   }

   void clear(void)
   {
      mObjs.clear();
   }

   // first is the object index
   // second is false if insert failed (object already exists)
   std::pair<Index, bool> insert(const ObjectType& o)
   {
      for (uint i = 0; i < mObjs.size(); i++)
         if (o == mObjs[i])
            return std::make_pair(i, false);
      
      mObjs.pushBack(o);
      
      return std::make_pair(mObjs.size() - 1, true);
   }

   // cInvalidIndex if object does not exist in the container
   Index find(const ObjectType& o) const
   {
      for (uint i = 0; i < mObjs.size(); i++)
         if (o == mObjs[i])
            return i;
            
      return cInvalidIndex;
   }

protected:
   ObjectVector mObjs;
};