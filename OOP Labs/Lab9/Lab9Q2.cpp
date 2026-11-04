#include <iostream>
#include <cmath>
using namespace std;

class Circle {};

template <typename T, int D>
class ShapeInfo {
private:
    string name;

public:
    ShapeInfo(string n) : name(n) {}

    void print() {
        cout << "Generic Shape: " << name 
             << " | Dimensions: " << D << endl;
    }
};

template <>
class ShapeInfo<Circle, 2> {
private:
    double radius;

public:
    ShapeInfo(double r) : radius(r) {}

    void print() {
        double area = M_PI * radius * radius;
        double circumference = 2 * M_PI * radius;

        cout << "2D Circle | Radius: " << radius
             << " | Area: " << round(area * 100) / 100
             << " | Circumference: " << round(circumference * 100) / 100
             << endl;
    }
};

template <typename T>
class ShapeInfo<T, 3> {
private:
    string name;
    int l, w, h;

public:
    ShapeInfo(string n, int length, int width, int height)
        : name(n), l(length), w(width), h(height) {}

    void print() {
        cout << "3D Shape: " << name
             << " | Volume: " << (l * w * h)
             << " | (" << l << "x" << w << "x" << h << ")"
             << endl;
    }
};

// ---------------- Main ----------------
int main() {

    // 1. Base template
    ShapeInfo<int, 4> shape1("Polygon");
    shape1.print();

    // 2. Full specialization
    ShapeInfo<Circle, 2> circle(5);
    circle.print();

    // 3. Partial specialization
    ShapeInfo<int, 3> box("Box", 3, 4, 5);
    box.print();

    // 4. Edge case
    ShapeInfo<Circle, 3> weird("SphereLike", 2, 3, 4);
    weird.print();

    /*
    Explanation:
    ShapeInfo<Circle, 3> uses the PARTIAL specialization (ShapeInfo<T, 3>)
    because:
     It matches any type T with dimension 3
     There is NO full specialization for (Circle, 3)
     Partial specialization is more specific than base template
    */

    return 0;
}