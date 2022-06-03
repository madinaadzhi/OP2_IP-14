#include "vector.h"

Vector::Vector() {
    m_length = 1;
    m_corner = 0;
}

Vector::Vector(int length, int corner) {
    m_length = length;
    if (corner >= 360) {
        m_corner = corner % 360;
    } else {
        m_corner = corner;
    }
}

Vector::Vector(Vector &obj) {
    m_length = obj.m_length;
    m_corner = obj.m_corner;
}

int Vector::getLength() {
    return m_length;
}

int Vector::getCorner() {
    return m_corner;
}

void Vector::setVector() {
    cout << "Length:";
    cin >> m_length;
    cout << "Corner:";
    cin >> m_corner;
}

Vector operator/(const Vector &vector, int num) {
    return Vector(vector.m_length / num, vector.m_corner);
}

void Vector::vectorAngleRotation(int rotationAngle) {
    m_corner = m_corner + rotationAngle;
    if (m_corner >= 360) {
        m_corner %= 360;
    }
}

double Vector::cartesianCoordinatesX() {
    return m_length * cos((m_corner * PI) / 180);
}

double Vector::cartesianCoordinatesY() {
    return m_length * sin((m_corner * PI) / 180);
}

Vector Vector::operator+(Vector vector) {
    double VectorCoordinateX = cartesianCoordinatesX() + vector.cartesianCoordinatesX();
    double VectorCoordinateY = cartesianCoordinatesY() + vector.cartesianCoordinatesY();

    double VectorLength = sqrt(pow(VectorCoordinateX, 2) + pow(VectorCoordinateY, 2));

    double VectorAngle = acos(VectorCoordinateX / VectorLength) * 180 / PI;
    return Vector(VectorLength, VectorAngle);
}

void Vector::printVector() {
    cout << "Vector length: "<< m_length << endl;
    cout << "Vector angle: " << m_corner << endl;
}

