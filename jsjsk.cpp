#include <iostream>
using namespace std;

class Parent {
public:
    void display() {
        cout << "Display function of Parent class" << endl;
    }
};

class Child : public Parent {
public:
    void display() {
        cout << "Display function of Child class" << endl;
    }
};

int main() {
    Child obj;
    Parent*ptr=&obj;
    ptr->display();  // Calls Child's display() method
    return 0;
}