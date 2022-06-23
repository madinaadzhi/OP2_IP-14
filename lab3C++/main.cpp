#include "Triangle.h"

int main() {
    int countOfTriangles = 0;
    cout << "Enter count of triangles: ";
    cin >> countOfTriangles;
    while (countOfTriangles <= 0) {
        cout << "Enter more than zero triangles: ";
        cin >> countOfTriangles;
        }

    Triangle *arrayOfTriangles = new Triangle[countOfTriangles];
    double maxArea = 0;
    int numOfTriangle = 0;
    for (int i = 0; i < countOfTriangles; ++i) {
        cout << "Area " << i + 1 << " triangle: " << arrayOfTriangles[i].getArea() << endl;
        if (arrayOfTriangles[i].getArea() > maxArea) {
            numOfTriangle = i + 1;
            maxArea = arrayOfTriangles[i].getArea();
        }
    }
    cout << "Triangle " << numOfTriangle << " has maximum area: " << maxArea << endl;

    return 0;
}
