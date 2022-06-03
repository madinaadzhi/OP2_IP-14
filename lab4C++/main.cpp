#include "vector.h"

int main() {
    Vector B3(4, 45);
    B3.vectorAngleRotation(45);
    cout << "Vector B3:" << endl;
    B3.printVector();
    cout << endl;

    Vector B2;
    cout << "Vector B2:" << endl;
    B2.setVector();
    Vector UpdatedB2(B2 / 2);
    cout << endl << "Updated vector B2:" << endl;
    UpdatedB2.printVector();
    cout << endl;

    Vector B1 = UpdatedB2 + B3;
    cout << "Vector B1:" << endl;
    B1.printVector();
    cout << endl;
}




