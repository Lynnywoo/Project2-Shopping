/**
 * @file bagInterface.h
 * @brief Abstract interface for the Bag ADT
 *
 * @Description Defines the virtual interface for the generic Bag container
 * Any class that inherits the from BagInterface must implement all of the listed methods
 *
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 2 Thursday 23:59
 * @instructor Jie Meichsner Ph.D
 */

#ifndef BAG_INTERFACE_H
#define BAG_INTERFACE_H

#include <vector>
using namespace std;

/**
 * @class BagInterface
 * @brief Abstract interface for a Bag (multiset) ADT
 * @tparam ItemType The type of items stored in the bag
 */
template<class ItemType>
class BagInterface {
public:
    /**
     * @brief Gets the current number of entries in the bag
     * @return The integer number of the entries currently in the bag
     */
    virtual int getCurrentSize() const = 0;

    /**
     * @brief Sees whether the bag is empty
     * @return True if the bag is empty, or false if not
     */
    virtual bool isEmpty() const = 0;

    /**
     * @brief Adds a new entry to the bag
     * @post If successful, newEntry is stored in the bag and the count of items
     *       in the bag increases by 1
     * @param newEntry The object to be added as a new entry
     * @return True if addition was successful, or false if not
     */
    virtual bool add(const ItemType& newEntry) = 0;

    /**
     * @brief Removes one occurrence of a given entry from this bag, if possible
     * @post If successful, anEntry has been removed from the bag and the count
     *       of items in the bag decreases by 1
     * @param anEntry The entry to be removed
     * @return True if removal was successful, or false if not
     */
    virtual bool remove(const ItemType& anEntry) = 0;

    /**
     * @brief Removes all entries from this bag
     * @post The bag contains no items, and the count of items is 0
     */
    virtual void clear() = 0;

    /**
     * @brief Counts the number of times a given entry appears in this bag
     * @param anEntry The entry to be counted
     * @return The number of times anEntry appears in the bag
     */
    virtual int getFrequencyOf(const ItemType& anEntry) const = 0;

    /**
     * @brief Tests whether this bag contains a given entry
     * @param anEntry The entry to locate
     * @return True if the bag contains anEntry, or false otherwise
     */
    virtual bool contains(const ItemType& anEntry) const = 0;

    /**
     * @brief Empties and then fills a vector with all entries in this bag
     * @return A vector containing all entries in the bag
     */
    virtual vector<ItemType> toVector() const = 0;

    /** @brief Virtual destructor */
    virtual ~BagInterface() {}
};

#endif
