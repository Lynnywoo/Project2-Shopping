/**
 * @file project2.cpp
 * @brief Client program that simulates an online shopping cart application
 *
 * @description
 *   This program simulates a online shopping experience The user enters
 *   an item (name, unit price, quantity) into the shopping cart as many times as they like, until they choose
 *   to stop The cart is then displayed with a running total The user may
 *   then modify the cart by adding items or removing items or changing the
 *   quantity of existing items on this list. the Final cart contents and total are displayed
 *   before the program exits (aka. they "check out")
 * 
 *     ShoppingCart : public Bag<Item>
 *
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 2 Thursday 23:59
 * @instructor Jie Meichsner Ph.D
 */

#include <iostream>
#include <string>
#include <limits>
#include "shoppingCart.h"
using namespace std;

// Forward declarations

/**
 * @brief Prompts the user to enter a single item and returns it
 * @return A populated Item object
 */
Item getItemFromUser();

/**
 * @brief Handles the modify-order menu loop (add / remove / change qty)
 * @param cart Reference to the shopping cart to modify
 */
void modifyOrder(ShoppingCart& cart);

// main

int main() {
    ShoppingCart cart;
    char continueChoice;

    cout << "\nWelcome to XXX SHOPPING CENTER." << endl;
    cout << "Enter the item you selected as the following order:" << endl;
    cout << "name unitPrice quantity" << endl;
    cout << "(Name can not contain any space. Otherwise errors happen!)" << endl;

    // initial item entry loop

    do {
        cout << "\n--> ";
        Item item = getItemFromUser();
        cart.add(item);

        cout << "Want to continue y/n-->";
        cin >> continueChoice;
    } while (continueChoice == 'y' || continueChoice == 'Y');

    // display initial cart

    cout << "\nHere is your order:" << endl;
    cart.display();

    // optional modification loop
 
    cout << "\nWant to modify your order? y/n-->";
    cin >> continueChoice;

    while (continueChoice == 'y' || continueChoice == 'Y') {
        modifyOrder(cart);
        cout << "\nWant to modify your order? y/n-->";
        cin >> continueChoice;
    }

    // display final cart and farewell
    
    cout << "\nHere is your updated order:" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "You have ordered the following items:" << endl;
    cart.display();

    cout << "Thanks for shopping in XXX SHOPPING CENTER." << endl;

    return 0;
}

// Helper function implementations

/**
 * Reads a single item from stdin in the order of name, unitPrice, quantity
 */

Item getItemFromUser() {
    Item item;
    cin >> item;
    return item;
}

/**
 * Presents a menu: 1 = add, 2 = remove, 3 = change quantity
 * Executes the chosen choice once and returns to this
 */

void modifyOrder(ShoppingCart& cart) {
    int choice;
    cout << "What do you want? Enter 1: add  2: remove  3: change quantity" << endl;
    cout << "--> ";
    cin >> choice;

    if (choice == 1) {
        // Add 
        cout << "Enter the item to add as the following order:" << endl;
        cout << "name unitPrice quantity" << endl;
        cout << "--> ";
        Item item = getItemFromUser();
        cart.add(item);
        cout << "The item has been added." << endl;

    } else if (choice == 2) {
        // Remove 
        cout << "Enter the item to remove as the following order:" << endl;
        cout << "name unitPrice quantity" << endl;
        cout << "--> ";
        Item item = getItemFromUser();

        if (cart.remove(item)) {
            cout << "The item has been removed." << endl;
        } else {
            cout << "No such item in your shopping cart!" << endl;
        }

    } else if (choice == 3) {
        // Change quantity 
        cout << "Enter the item to change as the following order:" << endl;
        cout << "name unitPrice quantity" << endl;
        cout << "--> ";
        Item item = getItemFromUser();

        if (!cart.contains(item)) {
            cout << "No such item in your shopping cart!" << endl;
            return;
        }

        // Validate quantity – must be a positive integer
        int newQty;
        cout << "Enter a new quantity --> ";
        while (true) {
            cin >> newQty;
            if (cin.fail() || newQty <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << newQty << " is not a valid input." << endl;
                cout << "Enter a new quantity --> ";
            } else {
                break;
            }
        }

        cart.changeQuantity(item, newQty);
        cout << "The quantity has been modified." << endl;
    }
}
