//
// Created by Quoc Minh Vu on 2017-05-11.
//

#ifndef ASSIGNMENT01_MENU_H
#define ASSIGNMENT01_MENU_H

#include <iostream>
#include "Text.h"

using std::ostream;
using std::cin;
using std::cout;
using std::endl;

class Menu {
private:
    int count; // The number of option in the list
    int max_list_size; // The maximum number of option supported by current options list
    char* strLtr = (char*) "?->";
    Text* option_list; // The dynamically allocated array storing the options list
    Text top_prompt; // The top prompt
    Text bottom_prompt; // The bottom prompt
    Text top_text; // The opening message
    Text bottom_text; // The closing message
    void double_capacity(); // Double the current capacity of the options list
public:
    Menu(); // Default constructor
    Menu(const Menu&); // Copy constructor
    virtual ~Menu(); // Destructor
    Menu& operator= (const Menu&); // Operator= overloading
    friend ostream& operator<< (ostream&, const Menu*);
    friend ostream& operator<< (ostream&, const Menu&);
    void insert(int, const Text&); // Insert new option into selected index, shift all option at or past index to the right by one position
    void push_back(const char*); // Add new option to the end of the list
    void push_back(const Text&); // Add new option the the end of the list
    Text remove(int); // Remove the option at the given index, shift all option past the index to the left by one position
    int size() const; // Return the number of options in the list
    int capacity() const; // Return the maximum number of options that menu can support
    void pop_back(); // Remove the last option in the list
    Text get(int); // Return the k'th option in the list
    Text toString() const; // Return a Text object storing a string representation of this menu
    int read_option_number(); // Display the menu and read and return a valid option number
    void set_top_prompt(const Text&); // Set top prompt to the supplied prompt
    void set_bottom_prompt(const Text&); // Set bottom prompt to the supplied prompt
    void set_top_message(const Text&); // Set opening message to the supplied message
    void set_bottom_message(const Text&); // Set closing message to the supplied message
    void clear_top_prompt(); // Remove top prompt
    void clear_bottom_prompt(); // Remove bottom prompt
    void clear_top_message(); // Remove opening message
    void clear_bottom_message(); // Remove closing message
    bool isEmpty() const; // Return true if this menu's option list is empty
};

#endif //ASSIGNMENT01_MENU_H
