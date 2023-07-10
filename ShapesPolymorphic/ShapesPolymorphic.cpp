#include <iostream>
#include <vector>
#include <memory>

class Shape {
public:
    virtual ~Shape() = default;

    void setColor(const std::string& color) {
        this->color = color;
    }

    std::string getColor() const {
        return color;
    }

    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;

protected:
    std::string color;
};

class Rectangle : public Shape {
public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double calculateArea() const override {
        return length * width;
    }

    double calculatePerimeter() const override {
        return 2 * (length + width);
    }

private:
    double length;
    double width;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}

    double calculateArea() const override {
        const double PI = 3.14159265359;
        return PI * radius * radius;
    }

    double calculatePerimeter() const override {
        const double PI = 3.14159265359;
        return 2 * PI * radius;
    }

private:
    double radius;
};

class Triangle : public Shape {
public:
    Triangle(double side1, double side2, double side3)
        : side1(side1), side2(side2), side3(side3) {}

    double calculateArea() const override {
        // Heron's formula to calculate the area of a triangle
        double semiPerimeter = (side1 + side2 + side3) / 2;
        return sqrt(semiPerimeter *
            (semiPerimeter - side1) *
            (semiPerimeter - side2) *
            (semiPerimeter - side3));
    }

    double calculatePerimeter() const override {
        return side1 + side2 + side3;
    }

private:
    double side1;
    double side2;
    double side3;
};

class Drawing {
public:
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void draw() const {
        for (const auto& shape : shapes) {
            std::cout << "Shape: " << typeid(*shape).name() << std::endl;
            std::cout << "Area: " << shape->calculateArea() << std::endl;
            std::cout << "Perimeter: " << shape->calculatePerimeter() << std::endl;
            std::cout << "Color: " << shape->getColor() << std::endl;
            std::cout << "---------------------------" << std::endl;
        }
    }

private:
    std::vector<Shape*> shapes;
};

int main() {
    Drawing drawing;

    Shape* rectangle = new Rectangle(5.0, 3.0);
    rectangle->setColor("Red");

    Shape* circle = new Circle(2.5);
    circle->setColor("Blue");

    Shape* triangle = new Triangle(3.0, 4.0, 5.0);
    triangle->setColor("Green");

    drawing.addShape(rectangle);
    drawing.addShape(circle);
    drawing.addShape(triangle);

    drawing.draw();

    // Clean up the dynamically allocated objects
    delete rectangle;
    delete circle;
    delete triangle;

    return 0;
}
