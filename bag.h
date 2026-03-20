/**
 * @file bag.h
 * @brief Header for array-based Bag class
 *
 * @Description Declares the array-based implementation of the Bag ADT,
 * stores items in a unordered collection which allows duplicates
 *
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 2 Thursday 23:59
 * @instructor Jie Meichsner Ph.D
 */

#ifndef BAG_H
#define BAG_H

#include "bagInterface.h"

/**
 * @class Bag
 * @brief Array-based implementation of  Bag ADT
 * @tparam ItemType The type of items stored in the bag
 */
template<class ItemType>
class Bag : public BagInterface<ItemType> {
private:
    static const int DEFAULT_CAPACITY = 100;  ///< Default max capacity of the bag
    ItemType items[DEFAULT_CAPACITY];         ///< Array of bag items
    int itemCount;                            ///< Current number of items in the bag
    int maxItems;                             ///< Maximum capacity of the bag

    /**
     * @brief Returns the index of target in items[], or -1 if not found
     * @param target The item to search for
     * @return Index of the target, or -1 if not found
     */
    int getIndexOf(const ItemType& target) const;

public:
    /** @brief Default constructor. Initializes an empty bag */
    Bag();

    /** @brief Gets the current number of entries @return Integer count */
    int getCurrentSize() const;

    /** @brief Checks if the bag is empty @return True if empty */
    bool isEmpty() const;

    /**
     * @brief Adds a new entry to the bag
     * @param newEntry The item to add
     * @return True if successful
     */
    bool add(const ItemType& newEntry);

    /**
     * @brief Removes one occurrence of a given entry
     * @param anEntry The item to remove
     * @return True if successful
     */
    bool remove(const ItemType& anEntry);

    /** @brief Removes all entries from the bag */
    void clear();

    /**
     * @brief Counts how many of the given entry
     * @param anEntry The item to count
     * @return The number of occurrences
     */
    int getFrequencyOf(const ItemType& anEntry) const;

    /**
     * @brief Tests whether the bag contains the given entry
     * @param anEntry The item to find
     * @return True if found
     */
    bool contains(const ItemType& anEntry) const;

    /**
     * @brief Returns all entries as a vector
     * @return Vector of all bag items
     */
    vector<ItemType> toVector() const;
};

#include "bag.cpp"
#endif
