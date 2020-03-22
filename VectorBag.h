//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Header file for an vector-based implementation of the ADT bag.
 @file VectorBag.h */

#ifndef _VECTOR_BAG
#define _VECTOR_BAG

#include "BagInterface.h"

template<class ItemType>
class VectorBag : public BagInterface<ItemType>
{
private:
	vector<ItemType> items;      // Vector of bag items
   
   // Returns either the index of the element in the vector items that
   // contains the given target or -1, if the vector does not contain 
   // the target.
   int getIndexOf(const ItemType& target) const;   

public:
	VectorBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
   vector<ItemType> toVector() const;

   // fuction signature of VectorBag operations (union, intersection, difference).
   VectorBag<ItemType> operator+(VectorBag<ItemType> anotherBag);
   VectorBag<ItemType> operator*(VectorBag<ItemType> anotherBag);
   VectorBag<ItemType> operator-(VectorBag<ItemType> anotherBag);
}; // end VectorBag

#include "VectorBag.cpp"
#endif