#include <iostream>
#include "Text.h"
#include "Menu.h"

using std::cout;

int demoText();

int main() {
//    demoText();

    Menu menu;
    menu.push_back("Pepsi");
    menu.push_back("Apple juice");
    menu.push_back("Root beer");
    menu.set_top_prompt("Choose your thirst crusher: ");
    menu.set_bottom_prompt("Enter a drink number: ");
    menu.pop_back(); // remove the last option
    menu.insert(1, "Iced tea with lemon"); // this will be option 2
    menu.pop_back(); // remove the last option
    menu.remove(0); // remove the first option (index k indexes option k+1)
    menu.set_top_message("Quench your thirst with our fine drinks");
    menu.set_bottom_message("Time to obey your thirst!");
    menu.pop_back(); // remove the last option
    menu.set_top_message("Who Says You Can’t Buy Happiness?");
    menu.clear_bottom_message();
    menu.set_top_prompt("Just Consider Our Seriously Delicious Ice Cream Flavors for Summer ");
    menu.set_bottom_prompt("Enter the number of your Happiness Flavor: ");
    menu.push_back("Bacon ice cream!");
    menu.push_back("Strawberry ice cream");
    menu.push_back("Vanilla ice cream");
    menu.push_back("Chocolate chip cookie dough ice cream");
    int choice = menu.read_option_number();
    cout << "you entered: " << choice << endl;
    return 0;
}

int demoText() {
    Text t1("Welcome to C++"); // conversion constructor
    Text t2; // defalt constructor
    Text t3{ t1 }; // copy constructor
    cout << "t1: " << t1 << endl; // operator<< overload
    cout << "t2: " << t2 << endl;
    cout << "t3: " << t3 << endl;
    t2.set(" Programming"); // set t2’s text to " Programming"
    cout << "t2: " << t2 << endl;
    t3.set(t1); // set t3’s text to t1’s text
    cout << "t3: " << t3 << endl;
    t1.append(" Programming"); // append the c-string " Programming" to t1’s text
    cout << "t1: " << t1 << endl;
    t3.append(t2); // append t2’s text to t3’s text
    cout << "t3: " << t3 << endl;
}