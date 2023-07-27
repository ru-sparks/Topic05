// StaticandDynamicCasting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class Shape {
public:
    virtual void printType() const {
        std::cout << "Shape\n";
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void printType() const override {
        std::cout << "Circle\n";
    }
};

class Rectangle : public Shape {
public:
    void printType() const override {
        std::cout << "Rectangle\n";
    }
};

int main() {
    // Create instances of Circle and Rectangle, and store them as Shape pointers
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    // Static casting
    Circle* circlePtr = static_cast<Circle*>(shape1);
    Rectangle* rectanglePtr = static_cast<Rectangle*>(shape2);

    // Expectation: Static casting is performed at compile-time without runtime checks.
    // If the cast is valid based on the static type information, it is successful.
    // If the cast is invalid, it still compiles but can lead to undefined behavior if accessed.

    if (circlePtr) {
        std::cout << "Static cast: shape1 is a Circle\n";
        circlePtr->printType();
    }
    else {
        std::cout << "Static cast: shape1 is not a Circle\n";
    }

    // Undefined behaviour
    if (rectanglePtr) {
        std::cout << "Static cast: shape2 is a Rectangle\n";
        rectanglePtr->printType();
    }
    else {
        std::cout << "Static cast: shape2 is not a Rectangle\n";
    }

    circlePtr = static_cast<Circle*>(shape2);
    if (circlePtr) {
        std::cout << "2 Static cast: shape1 is a Circle\n";
        circlePtr->printType();
    }
    else {
        std::cout << "2 Static cast: shape1 is not a Circle\n";
    }

    // Dynamic casting
    Circle* circleDynamicPtr = dynamic_cast<Circle*>(shape1);
    Rectangle* rectangleDynamicPtr = dynamic_cast<Rectangle*>(shape2);

    // Expectation: Dynamic casting is performed at runtime and checks if the cast is valid
    // based on the actual type of the object. If the cast is not valid, the result is a nullptr.

    if (circleDynamicPtr) {
        std::cout << "Dynamic cast: shape1 is a Circle\n";
        circleDynamicPtr->printType();
    }
    else {
        std::cout << "Dynamic cast: shape1 is not a Circle\n";
    }

    if (rectangleDynamicPtr) {
        std::cout << "Dynamic cast: shape2 is a Rectangle\n";
        rectangleDynamicPtr->printType();
    }
    else {
        std::cout << "Dynamic cast: shape2 is not a Rectangle\n";
    }

    circleDynamicPtr = dynamic_cast<Circle*>(shape2);
    if (circleDynamicPtr) {
        std::cout << "2 Dynamic cast: shape2 is a Rectangle\n";
        rectangleDynamicPtr->printType();
    }
    else {
        std::cout << "2 Dynamic cast: shape2 is not a Rectangle\n";
    }
    /*
      This example shows downcasting, casting down the inheritence hierarchy.
      When you need downcasting:  You have polymorphic objects in a container (vector). These objects will
      behave properly when using virtual methods defined in the base class.
      The compiler will not allow you to call methods defined uniquely in the child class, however.  It will
      not see the child class methods.  You need to downcast to a specific type for the compiler to see the
      child class methods.  In C++, you should use dynamic_cast for this operation.  Only at runtime
      is the correct behavior fully defined. 
    */


    delete shape1;
    delete shape2;

    return 0;
}
