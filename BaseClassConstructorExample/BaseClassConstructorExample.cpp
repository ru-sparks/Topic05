// BaseClassConstructorExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base Default Constructor\n";
    }

    Base(int value) {
        std::cout << "Base Non-Default Constructor with value: " << value << "\n";
    }

    ~Base() {
        std::cout << "Base Destructor\n";
    }
};

class Derived : public Base {
public:
    Derived() : Base(), derivedValue(42) {
        std::cout << "Derived Default Constructor\n";
    }

    Derived(int value) : Base(value), derivedValue(value) {
        std::cout << "Derived Non-Default Constructor with value: " << value << "\n";
    }

    ~Derived() {
        std::cout << "Derived Destructor\n";
    }

private:
    int derivedValue;
};

int main() {
    std::cout << "Creating Base object:\n";
    Base baseObj;
    std::cout << "----------------------\n";

    std::cout << "\nCreating Derived object:\n";
    Derived derivedObj;
    std::cout << "----------------------\n";

    std::cout << "\nCreating Derived object with value:\n";
    Derived derivedObjWithValue(10);
    std::cout << "----------------------\n";

    return 0;
}
