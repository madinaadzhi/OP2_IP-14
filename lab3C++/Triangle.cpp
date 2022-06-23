#include "Triangle.h"

double Apex::getSide(Apex endpoint) {
    double side = sqrt(pow((endpoint.x - x), 2) + (pow((endpoint.y - y), 2)));

    return side;
}

Apex::Apex() {
    cout << "Enter coordinates of the triangle apex:" << endl << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    cout << endl;
}

[[maybe_unused]] Apex Triangle::getA() {
    return A;
}

[[maybe_unused]] Apex Triangle::getB() {
    return B;
}

[[maybe_unused]] Apex Triangle::getC() {
    return C;
}

double Triangle::getArea() {
    double sideAB = A.getSide(B);
    double sideAC = A.getSide(C);
    double sideBC = B.getSide(C);

    double semiPerimeter = (sideAB + sideAC + sideBC) / 2;
    double areaOfATriangle = sqrt(semiPerimeter * (semiPerimeter - sideAB) * (semiPerimeter - sideAC) * (semiPerimeter - sideBC));

    return areaOfATriangle;
}

