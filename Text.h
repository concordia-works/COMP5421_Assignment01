//
// Created by Quoc Minh Vu on 2017-05-08.
//

#ifndef ASSIGNMENT01_TEXT_H
#define ASSIGNMENT01_TEXT_H

#include <iostream>
using std::ostream;

class Text {
private:
    char* text;
public:
    Text(); // Default constructor
    Text(const Text&); // Copy constructor
    Text(const char*); // Conversion constructor
    Text& operator= (const Text&); // Assignment operator overloading
    friend ostream& operator<< (ostream&, const Text*);
    friend ostream& operator<< (ostream&, const Text&);
    friend bool operator== (const Text&, const Text&);
    friend bool operator== (const Text&, const char*);
    friend bool operator!= (const Text&, const Text&);
    friend bool operator!= (const Text&, const char*);
    void set(char*);
    void set(const Text&);
    void append(const char);
    void append(const char*);
    void append(const Text&);
    bool isEmpty();
    virtual ~Text();
};

#endif //ASSIGNMENT01_TEXT_H