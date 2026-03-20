/**
 * @file shoppingCart.cpp
 * @brief Implementation of the ShoppingCart class.
 *
 * @Description Implements the defined methods from the class shoppingCart.h
 * The ShoppingCart wraps the Bag<Item> and keeps a totalPrice
 * members is updated with every mutation of the cart
  *
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 2 Thursday 23:59
 * @instructor Jie Meichsner Ph.D
 */

#include "shoppingCart.h"
#include <sstream>

// Constructor

ShoppingCart::ShoppingCart() : totalPrice(0.0) {}

// Accessor

double ShoppingCart::getTotalPrice() const {
    return totalPrice;
}

// Overridden Bag methods

/**
 * Delegates Bag<Item>::add() if a success it increases the totalPrice by
 * the item's unitPrice * quantity
 */
bool ShoppingCart::add(const Item& newEntry) {
    bool success = Bag<Item>::add(newEntry);
    if (success) {
        totalPrice += newEntry.getUnitPrice() * newEntry.getQuantity();
    }
    return success;
}

/**
 * Searches for a matching item by its name and related price via the operator==
 * On success it subtracts the item's contribution from the  totalPrice before
 * delegating the removal of the Bag<Item>::remove()
 */
bool ShoppingCart::remove(const Item& anEntry) {
    // Finds the  item in the bag so we can retrieve its quantity 
    vector<Item> contents = toVector();
    Item foundItem;
    bool found = false;

    for (int i = 0; i < (int)contents.size(); i++) {
        if (contents[i] == anEntry) {
            foundItem = contents[i];
            found = true;
            break;
        }
    }

    if (!found) return false;

    // Subtracts the cost before removing
    totalPrice -= foundItem.getUnitPrice() * foundItem.getQuantity();

    return Bag<Item>::remove(anEntry);
}

/**
 * Resets the totalPrice to 0 then delegates to Bag<Item>::clear()
 */
void ShoppingCart::clear() {
    totalPrice = 0.0;
    Bag<Item>::clear();
}

// Additional operations

/**
 * Iterates over the internal vectors of the items by searching for a match through 
 * its name and its price When the item is found the old item is removed and the new item with
 * the updated quantity is added to the totalPrice and will be recalculated 
 */
bool ShoppingCart::changeQuantity(const Item& anEntry, int newQuantity) {
    vector<Item> contents = toVector();

    for (int i = 0; i < (int)contents.size(); i++) {
        if (contents[i] == anEntry) {
            // Builds the replacement item and keeps the name & price, swapping quantity
            Item updated(contents[i].getName(),
                         contents[i].getUnitPrice(),
                         newQuantity);

            // remove() adjusts totalPrice using the OLD quantity
            remove(contents[i]);
            // add() adjusts totalPrice using the NEW quantity
            add(updated);
            return true;
        }
    }
    return false;
}

/**
 * Prints a table of all the cart items followed by the formatted total charge
 * Rows ex. Name (20), Unit_Price (20), Quantity (10)
 */
void ShoppingCart::display() const {
    cout << "-------------------------------------------------" << endl;
    cout << left << setw(20) << "Name"
         << left << setw(20) << "Unit_Price"
         << left << setw(10) << "Quantity"  << endl;

    vector<Item> contents = toVector();
    for (int i = 0; i < (int)contents.size(); i++) {
        // Print name
        cout << left << setw(20) << contents[i].getName();

        // Print price with $ prefix and 2 decimal places
        ostringstream priceStream;
        priceStream << "$" << fixed << setprecision(2) << contents[i].getUnitPrice();
        cout << left << setw(20) << priceStream.str();

        // Print quantity
        cout << left << setw(10) << contents[i].getQuantity() << endl;
    }

    cout << "The total charge is $" << fixed << setprecision(2)
         << totalPrice << endl;
    cout << "--------------------------------------------------" << endl;
}
