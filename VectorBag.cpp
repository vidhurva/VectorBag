//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class VectorBag.
    @file VectorBag.cpp */

#include "VectorBag.h"
#include <cstddef>

template<class ItemType>
VectorBag<ItemType>::VectorBag()
{
   items.clear(); //Removes all elements from the items-vector (which are destroyed), leaving the VectorBag with a size of 0.
}  // end default constructor

template<class ItemType>
int VectorBag<ItemType>::getCurrentSize() const
{
   return items.size();
}  // end getCurrentSize

template<class ItemType>
bool VectorBag<ItemType>::isEmpty() const
{
   return items.size() == 0;
}  // end isEmpty

template<class ItemType>
bool VectorBag<ItemType>::add(const ItemType& newEntry)
{
   items.push_back(newEntry); //Adds a new element at the end of the items-vector, after its current last element
   return true;
}  // end add
 
template<class ItemType>
bool VectorBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
   bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
   if (canRemoveItem)
      {
         items.erase(items.begin()+locatedIndex);  // remove anEntry element from items-vector and reduce the VectorBag size by one.
      }  // end if
    
   return canRemoveItem;
}  // end remove

template<class ItemType>
void VectorBag<ItemType>::clear()
{  
   items.clear(); //Removes all elements from the items-vector (which are destroyed), leaving the VectorBag with a size of 0.
}  // end clear

template<class ItemType>
int VectorBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current vector index
   while (curIndex < items.size())
      {
         if (items[curIndex] == anEntry)
            {
               frequency++;
            }  // end if
      
         curIndex++;          // Increment to next entry
      }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool VectorBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
   template<class ItemType>
   bool VectorBag<ItemType>::contains(const ItemType& target) const 
   {
   return getFrequencyOf(target) > 0;
   }  // end contains

// ALTERNATE 2: Second version 
template<class ItemType>
bool VectorBag<ItemType>::contains(const ItemType& anEntry) const
{
bool found = false;
int curIndex = 0;        // Current vector index
while (!found && (curIndex < items.size()))
{
if (anEntry == items[curIndex])
{
found = true;
} // end if
      
curIndex++;           // Increment to next entry
}  // end while   
   
return found;
}  // end contains
*/

template<class ItemType>
vector<ItemType> VectorBag<ItemType>::toVector() const
{
   
   return items;
}  // end toVector

template<class ItemType>
VectorBag<ItemType> VectorBag<ItemType>::operator+(VectorBag<ItemType> anotherBag){
   VectorBag<ItemType> unionBag;   // create new VectorBag 
   for(int i=0;i<items.size();i++)
      unionBag.add(items[i]);     // add items of current VectorBag in new VectorBag 

   for(int i=0;i<anotherBag.items.size();i++)
      unionBag.add(anotherBag.items[i]);    // add items of anotherBag VectorBag in new VectorBag

   return unionBag;

} // end operator+

template<class ItemType>
VectorBag<ItemType> VectorBag<ItemType>::operator*(VectorBag<ItemType> anotherBag){
   VectorBag<ItemType> intersectBag;   // create new VectorBag


   for(int i=0;i<items.size();i++)
      intersectBag.add(items[i]);   // add items of current VectorBag in new VectorBag 
   
   return intersectBag - (intersectBag - anotherBag);

} // end operator*

template<class ItemType>
VectorBag<ItemType> VectorBag<ItemType>::operator-(VectorBag<ItemType> anotherBag){
   VectorBag<ItemType> diffBag;   // create new VectorBag

   for(int i=0;i<items.size();i++)
      diffBag.add(items[i]);    // add items of current VectorBag in new VectorBag 

   for(int i=0;i<anotherBag.items.size();i++)
      diffBag.remove(anotherBag.items[i]);    // remove items of anotherBag VectorBag from new VectorBag 


   return diffBag;

} // end operator-


// private
template<class ItemType>
int VectorBag<ItemType>::getIndexOf(const ItemType& target) const
{
   bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, items.size() is zero, so loop is skipped
   while (!found && (searchIndex < items.size()))
      {
         if (items[searchIndex] == target)
            {
               found = true;
               result = searchIndex;
            } 
         else
            {
               searchIndex++;
            }  // end if
      }  // end while
   
   return result;
}  // end getIndexOf