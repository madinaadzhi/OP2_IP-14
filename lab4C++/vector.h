#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14;

class Vector {
private:
    int m_length;
    int m_corner;

public:
    Vector();

    Vector(int length, int corner);

    Vector(Vector &obj);

    void setVector();

    int getLength();

    int getCorner();

    friend Vector operator/(const Vector &vector, int num);

    void vectorAngleRotation (int rotationAngle);

    double cartesianCoordinatesX();

    double cartesianCoordinatesY();

    Vector operator+(Vector vector);

    void printVector();
};

