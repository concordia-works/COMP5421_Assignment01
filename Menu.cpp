//
// Created by Quoc Minh Vu on 2017-05-11.
//

#include "Menu.h"

// Default constructor
Menu::Menu() : top_prompt(""),
               bottom_prompt(""),
               top_text(""),
               bottom_text(""),
               count(0),
               max_list_size(1),
               option_list(new Text[1]) {}

// Copy constructor
Menu::Menu(const Menu& menu) : option_list(menu.option_list),
                               count(menu.count),
                               max_list_size(menu.max_list_size),
                               top_prompt(menu.top_prompt),
                               bottom_prompt(menu.bottom_prompt),
                               top_text(menu.top_text),
                               bottom_text(menu.bottom_text) {}

// Destructor
Menu::~Menu() {
    delete[] option_list;
    option_list = nullptr;
}

// Insert new option into selected index, shift all option at or past index to the right by one position
void Menu::insert(int index, const Text& text) {
    Text* newOptionsList = new Text[this->max_list_size];
    for (int i = 0; i < this->max_list_size; i++) {
        if (i < index)
            newOptionsList[i] = this->option_list[i];
        else if (i > index)
            newOptionsList[i] = this->option_list[i - 1];
        else // i == index
            newOptionsList[i] = text;
    }
    delete[] this->option_list;
    this->option_list = newOptionsList;
    this->count++;
}

// Double the current capacity of the options list
void Menu::double_capacity() {
    int newSize = this->max_list_size * 2;
    Text* newOptionsList = new Text[newSize];
    for (int i = 0; i < this->count; i++)
        newOptionsList[i] = this->option_list[i];
    delete[] this->option_list;
    this->option_list = newOptionsList;
    this->max_list_size = newSize;
}

// Add new option to the end of the list
void Menu::push_back(const char* c) {
    if (this->count == this->max_list_size)
        this->double_capacity();
    this->option_list[count] = c;
    count++;
}

// Add new option the the end of the list
void Menu::push_back(const Text& text) {
    if (this->count == this->max_list_size)
        this->double_capacity();
    this->insert(count, text);
}

// Remove the last option in the list
void Menu::pop_back() {
    this->option_list[count] = "";
    this->count--;
}

// Return the k'th option in the list
Text Menu::get(int index) {
    return this->option_list[index];
}

// Return the maximum number of options that menu can support
int Menu::capacity() const {
    return this->max_list_size;
}

// Remove the option at the given index, shift all option past the index to the left by one position
Text Menu::remove(int index) {
    Text* newOptionsList = new Text[this->max_list_size];
    for (int i = 0; i < this->count; i++) {
        if (i < index)
            newOptionsList[i] = this->option_list[i];
        else if (i > index)
            newOptionsList[i - 1] = this->option_list[i];
    }
    delete[] this->option_list;
    this->option_list = newOptionsList;
    this->count--;
}

// Return the number of options in the list
int Menu::size() const {
    return this->count;
}

int Menu::read_option_number() {
    int input;
    bool isInputValid = false;
    while (!isInputValid) {
        cout << this;
        cin >> input;
        if ((this->count == 0) || ((input >= 1) && (input <= count))) // Input is valid if count=0 or 1 <= input <= count
            isInputValid = true;
        else
            cout << "Invalid choice " << input << ". It must be in the range [1, " << this->count << "]" << endl << endl << endl;
    }
    return input;
}

// Set top prompt to the supplied prompt
void Menu::set_top_prompt(const Text& text) {
    this->top_prompt = text;
}

// Set bottom prompt to the supplied prompt
void Menu::set_bottom_prompt(const Text& text) {
    this->bottom_prompt = text;
}

// Set opening message to the supplied message
void Menu::set_top_message(const Text& text) {
    this->top_text = text;
}

// Set closing message to the supplied message
void Menu::set_bottom_message(const Text& text) {
    this->bottom_text = text;
}

// Remove top prompt
void Menu::clear_top_prompt() {
    this->top_prompt = "";
}

// Remove bottom prompt
void Menu::clear_bottom_prompt() {
    this->bottom_prompt = "";
}

// Remove opening message
void Menu::clear_top_message() {
    this->top_text = "";
}

// Remove closing message
void Menu::clear_bottom_message() {
    this->bottom_text = "";
}

// Return true if this menu's option list is empty
bool Menu::isEmpty() const {
    return (this->count == 0);
}

// Return a Text object storing a string representation of this menu
Text Menu::toString() const {
    Text* content = new Text();
    if (this->top_text != "") {
        content->append(this->top_text);
        content->append("\n");
    }
    if (this->top_prompt != "") {
        content->append(this->top_prompt);
        content->append("\n");
    }
    if (count > 0)
        content->append("\n");
    for (int i = 0; i < count; i++) {
        content->append("   (");
        content->append('0' + i + 1);
        content->append(") ");
        content->append(this->option_list[i]);
        content->append("\n");
    }
    if (count > 0)
        content->append("\n");
    if (this->bottom_text != "") {
        content->append(this->bottom_text);
        content->append("\n");
    }
    content->append(this->strLtr);
    content->append(" ");
    if (this->bottom_prompt != "") {
        content->append(this->bottom_prompt);
    }

    return *content;
}

// Operators overloading
Menu& Menu::operator=(const Menu& rhs) {
    if (this != &rhs) {
        this->max_list_size = rhs.max_list_size;
        this->option_list = new Text[this->max_list_size];
        for (int i = 0; i < rhs.count; i++)
            this->push_back(rhs.option_list[i]);
        this->set_top_message(rhs.top_text);
        this->set_top_prompt(rhs.top_prompt);
        this->set_bottom_message(rhs.bottom_text);
        this->set_bottom_prompt(rhs.bottom_prompt);
    }
    return *this;
}

ostream& operator<< (ostream& os, const Menu* menu) {
    return os << menu->toString();
}

ostream& operator<< (ostream& os, const Menu& menu) {
    return os << menu.toString();
}