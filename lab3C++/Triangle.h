#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Apex {
    double x{};
    double y{};
public:
    Apex();
    double getSide(Apex);
};

class Triangle {
    Apex A;
    Apex B;
    Apex C;
public:
    [[maybe_unused]] Apex getA();
    [[maybe_unused]] Apex getB();
    [[maybe_unused]] Apex getC();
    double getArea();
};
