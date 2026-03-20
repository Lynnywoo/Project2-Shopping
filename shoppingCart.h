/**
 * @file shoppingCart.h
 * @brief Header and implementation for the ShoppingCart class.
 *
 * @Description Declares and implements the ShoppingCart class which
 * inherits from Bag<Item> and models the online shopping cart this allows
 * items to be added, removed, and modified, and it tracks the running total
 * cost of all items that are in the cart 
 *
 * The implementation is included in this header (via
 * #include "shoppingCart.cpp") so this template-based Bag base class
 * resolves correctly during compilation
 *
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 2 Thursday 23:59
 * @instructor Jie Meichsner Ph.D
 */

#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "bag.h"
#include "item.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**
 * @class ShoppingCart
 * @brief Models the online shopping cart as a Bag of Items
 *
 * Inherits all storage and lookup behaviours from Bag<Item> and adds the following...
 *  Tracking of the running total price
 *  Overrides of add(), remove(), and clear() that keep the total updated
 *  A changeQuantity() helper for modifying the total quantity of existing items
 *  A display() method to print the cart contents in 3 organised rows
 */
class ShoppingCart : public Bag<Item> {
private:
    double totalPrice; ///< Running sum of (unitPrice * quantity) for all items in the cart

public:

    // Constructor

    /**
     * @brief Default constructor Initialises the empty cart with totalPrice = 0
     */
    ShoppingCart();

    // Accessor

    /**
     * @brief Returns the total cost of all items currently in the cart
     * @return Total price as a double
     */
    double getTotalPrice() const;

    // Overridden Bag methods

    /**
     * @brief Adds an item to the cart and updates the totalPrice
     *
     * Overrides Bag<Item>::add() so that the totalPrice is increased by the
     * item.unitPrice * item.quantity when a new item is added
     *
     * @param newEntry The Item to add to the cart
     * @return True if the item was added successfully 
     */
    bool add(const Item& newEntry) override;

    /**
     * @brief Removes one of the matching items from the cart and updates the total price
     *
     * Overrides Bag<Item>::remove()  item matches if the name and price are equal
     * If no matching item exists
     * the cart isntchanged and false is returned
     *
     * @param anEntry The Item to remove matched by its name and price
     * @return True if the item was found and removed
     */
    bool remove(const Item& anEntry) override;

    /**
     * @brief Removes all items from the cart and resets the totalPrice to 0
     *
     * Overrides Bag<Item>::clear()
     */
    void clear() override;

    // Additional operations

    /**
     * @brief Changes the quantity of an existing item in the cart
     *
     * Searches the cart for an item matching the anEntry by its name and price
     * If found, the quantity is replaced with newQuantity and totalPrice is
     * recalculated If not found, no changes are made to the cart
     *
     * @param anEntry     The Item(s) to locate matched by their names and prices
     * @param newQuantity The replacement quantity must be >0
     * @return True if the item was found and quantity was updated
     */
    bool changeQuantity(const Item& anEntry, int newQuantity);

    /**
     * @brief Prints the carts items in a formatted table
     *        and the total at the bottom
     */
    void display() const;
};

#include "shoppingCart.cpp"
#endif
