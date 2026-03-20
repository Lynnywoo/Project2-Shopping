/**
 * @file item.h
 * @brief Header for the Item class
 *
 * @Description Declares the Item class, which represents the single product
 * in the online shopping cart Each of these items has a name, unit price, and a quantity
 * This class helps support testing (by name and price), stream input,
 * and stream output
 *
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 2 Thursday 23:59
 * @instructor Jie Meichsner Ph.D
 */

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

/**
 * @class Item
 * @brief Represents a product in a shopping cart
 *
 * Stores the name, unit price, and the quantity of the item
 * Two items are considered equal if they share the same name and price,
 * regardless of their quantity 
 */
class Item {
private:
    string name;       ///< Name of the item thats input (no spaces allowed)
    double unitPrice;  ///< Unit price of the item in dollars 
    int quantity;      ///< Number of units of the item input

public:

    // Constructors

    /**
     * @brief Default constructor Initializes the name to "", price and quantity to 0 aswell
     */
    Item();

    /**
     * @brief Parameterized constructor
     * @param n  Name of an item
     * @param p  Unit price of an item.
     * @param q  Quantity of an item.
     */
    Item(const string& n, double p, int q);

    // Setters

    /**
     * @brief Sets the name of the item
     * @param n The new name of the item
     */
    void setName(const string& n);

    /**
     * @brief Sets the unit price of the item
     * @param p The new unit amount price
     */
    void setUnitPrice(double p);

    /**
     * @brief Sets the quantity of the item
     * @param q The new quantity of the item
     */
    void setQuantity(int q);

    // Getters

    /**
     * @brief Returns the name of the item
     * @return The item's name as the string
     */
    string getName() const;

    /**
     * @brief Returns the unit price of the item
     * @return The item's unit price as a double
     */
    double getUnitPrice() const;

    /**
     * @brief Returns the quantity of the item
     * @return The item's quantity as an integer 
     */
    int getQuantity() const;

    // Operators

    /**
     * @brief Equality operator if items name AND price match they are equal
     *        quantity is not considered in this comparison 
     * @param other The item to compare against
     * @return True if name and price are the same
     */
    bool operator==(const Item& other) const;

    /**
     * @brief Stream input operator. Reads name, unitPrice, and quantity
     * @param in    Input stream
     * @param item  Item to populate
     * @return The modified input stream
     */
    friend istream& operator>>(istream& in, Item& item);

    /**
     * @brief Stream output operator. Prints the name, unit price, and quantity in columns
     * @param out Output stream
     * @param item Item to display
     * @return The modified output stream
     */
    friend ostream& operator<<(ostream& out, const Item& item);
};

#endif
