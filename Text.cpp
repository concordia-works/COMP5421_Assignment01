//
// Created by Quoc Minh Vu on 2017-05-11.
//

#include "Text.h"

using std::ostream;
using std::cout;
using std::endl;

// Default constructor
Text::Text() : Text("") {}

// Copy constructor
Text::Text(const Text& t) {
    this->text = new char[strlen(t.text) + 1];
    strcpy(this->text, t.text);
}

// Conversion constructor
Text::Text(const char* t) {
    this->text = new char[strlen(t) + 1];
    strcpy(this->text, t);
}

// Operator overloading
Text& Text::operator= (const Text& rhs) {
    if (this != &rhs) { // Avoid self-assignment
        delete[] this->text;
        this->text = new char[strlen(rhs.text) + 1];
        strcpy(this->text, rhs.text);
    }
    return *this;
}

ostream& operator<< (ostream& os, const Text* t) {
    return os << t->text;
}

ostream& operator<< (ostream& os, const Text& t) {
    return os << t.text;
}

bool operator== (const Text& text1, const Text& text2) {
    return strcmp(text1.text, text2.text) == 0;
}

bool operator== (const Text& text1, const char* text2) {
    return strcmp(text1.text, text2) == 0;
}

bool operator!= (const Text& text1, const Text& text2) {
    return strcmp(text1.text, text2.text) != 0;
}

bool operator!= (const Text& text1, const char* text2) {
    return strcmp(text1.text, text2) != 0;
}

void Text::set(char* t) {
    delete[] this->text;
    this->text = new char[strlen(t) + 1];
    strcpy(this->text, t);
}

void Text::set(const Text& t) {
    delete[] this->text;
    this->text = new char[strlen(t.text) + 1];
    strcpy(this->text, t.text);
}

void Text::append(const char c) {
    char* tmpPt = new char[strlen(this->text) + 2];
    strcpy(tmpPt, this->text);
    tmpPt[strlen(this->text)] = c;
    tmpPt[strlen(this->text) + 1] = '\0';
    delete[] this->text;
    this->text = tmpPt;
}

void Text::append(const char* t) {
    char* tmpPt = new char[strlen(this->text) + strlen(t) + 1];
    strcpy(tmpPt, this->text);
    strcat(tmpPt, t);
    delete[] this->text;
    this->text = tmpPt;
}
void Text::append(const Text& t) {
    char* tmpPt = new char[strlen(this->text) + strlen(t.text) + 1];
    strcpy(tmpPt, this->text);
    strcat(tmpPt, t.text);
    delete[] this->text;
    this->text = tmpPt;
}

bool Text::isEmpty() {
    if (strlen(this->text) == 0)
        return true;
    else
        return false;
}

// Destructor
Text::~Text() {
    delete[] this->text;
    this->text = nullptr;
}
