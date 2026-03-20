/**
 * @file bag.cpp
 * @brief Implementation of the array-based Bag class
 *
 * @Description Implements the methods that are declared in bag.h for generic
 * array-based Bag ADT
 *
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 2 Thursday 23:59
 * @instructor Jie Meichsner Ph.D
 */

#include "bag.h"

// Constructor

template<class ItemType>
Bag<ItemType>::Bag() : itemCount(0), maxItems(DEFAULT_CAPACITY) {}


// Public

template<class ItemType>
int Bag<ItemType>::getCurrentSize() const {
    return itemCount;
}

template<class ItemType>
bool Bag<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
bool Bag<ItemType>::add(const ItemType& newEntry) {
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd) {
        items[itemCount] = newEntry;
        itemCount++;
    }
    return hasRoomToAdd;
}

template<class ItemType>
bool Bag<ItemType>::remove(const ItemType& anEntry) {
    int foundIndex = getIndexOf(anEntry);
    bool canRemoveItem = (!isEmpty() && (foundIndex > -1));
    if (canRemoveItem) {
        itemCount--;
        items[foundIndex] = items[itemCount];
    }
    return canRemoveItem;
}

template<class ItemType>
void Bag<ItemType>::clear() {
    itemCount = 0;
}

template<class ItemType>
int Bag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
    int frequency = 0;
    for (int i = 0; i < itemCount; i++) {
        if (items[i] == anEntry) {
            frequency++;
        }
    }
    return frequency;
}

template<class ItemType>
bool Bag<ItemType>::contains(const ItemType& anEntry) const {
    return getIndexOf(anEntry) > -1;
}

template<class ItemType>
vector<ItemType> Bag<ItemType>::toVector() const {
    vector<ItemType> bagContents;
    for (int i = 0; i < itemCount; i++) {
        bagContents.push_back(items[i]);
    }
    return bagContents;
}

// Private

template<class ItemType>
int Bag<ItemType>::getIndexOf(const ItemType& target) const {
    bool found = false;
    int result = -1;
    int searchIndex = 0;
    while (!found && (searchIndex < itemCount)) {
        if (items[searchIndex] == target) {
            found = true;
            result = searchIndex;
        } else {
            searchIndex++;
        }
    }
    return result;
}
