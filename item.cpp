/**
 * @file item.cpp
 * @brief Implements the Item class
 * @Description Implements constructors, getters, setters, and operator
 * overloads for the Item class.  
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 2 Thursday 23:59
 * @instructor Jie Meichsner Ph.D
 */

#include "item.h"
#include <iomanip>

// Constructors

Item::Item() : name(""), unitPrice(0.0), quantity(0) {}

Item::Item(const string& n, double p, int q)
    : name(n), unitPrice(p), quantity(q) {}

// Setters

void Item::setName(const string& n) {
    name = n;
}

void Item::setUnitPrice(double p) {
    unitPrice = p;
}

void Item::setQuantity(int q) {
    quantity = q;
}

// Getters

string Item::getName() const {
    return name;
}

double Item::getUnitPrice() const {
    return unitPrice;
}

int Item::getQuantity() const {
    return quantity;
}

// Operators

/**
 * When two items have the same name and price they are equal
 * Quantity is excluded so duplicate items are recognised
 */
bool Item::operator==(const Item& other) const {
    return (name == other.name) && (unitPrice == other.unitPrice);
}

/** Reads the name, unitPrice, and quantity from input */
istream& operator>>(istream& in, Item& item) {
    in >> item.name >> item.unitPrice >> item.quantity;
    return in;
}

/**
 *   Prints the item into three rows
 *   Name (20 chars)  |  $UnitPrice (20 chars)  |  Quantity
 */
ostream& operator<<(ostream& out, const Item& item) {
    out << left  << setw(20) << item.name
        << left  << setw(20) << ("$" + to_string(item.unitPrice))
        << left  << setw(10) << item.quantity;
    return out;
}
