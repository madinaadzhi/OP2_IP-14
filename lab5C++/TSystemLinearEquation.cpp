#include "TSystemLinearEquation.h"

SLEWithTwoEquations::SLEWithTwoEquations():TSystemLinearEquation() {
    for (int i = 0; i < 3; ++i) {
        m_firstEquation[i] = rand() % 10 + 1;
    }
    for (int i = 0; i < 3; ++i) {
        m_secondEquation[i] = rand() % 10 + 1;
    }
}

[[maybe_unused]] SLEWithTwoEquations::SLEWithTwoEquations(const double *arr1, const double *arr2) {
    for (int i = 0; i < 3; ++i) {
        m_firstEquation[i] = arr1[i];
    }
    for (int i = 0; i < 3; ++i) {
        m_secondEquation[i] = arr2[i];
    }
}

void SLEWithTwoEquations::printSLE() {
    cout << m_firstEquation[0] << "x" << "+"<< m_firstEquation[1] << "y" << "=" << m_firstEquation[2] << endl;
    cout << m_secondEquation[0] << "x" << "+"<< m_secondEquation[1] << "y" << "=" << m_secondEquation[2] << endl;
    cout << endl;
}

void SLEWithTwoEquations::sleSolutionTest() {
    double firstRoot, secondRoot;
    cout << "Enter the roots of the equations:" << endl << "x = ";
    cin >> firstRoot;
    cout << "y = ";
    cin >> secondRoot;
    if (m_firstEquation[0] * firstRoot + m_firstEquation[1] * secondRoot == m_firstEquation[2]) {
        if (m_secondEquation[0] * firstRoot + m_secondEquation[1] * secondRoot == m_secondEquation[2]) {
            cout << "Entered data is the solution of equations." << endl << endl;
        } else {
            cout << "Entered data is not a solution of equations." << endl << endl;
        }
    } else {
        cout << "Entered data is not a solution of equations." << endl << endl;
    }
}

void SLEWithTwoEquations::sleSolution() {
    double determinant = m_firstEquation[0] * m_secondEquation[1] - m_firstEquation[1] * m_secondEquation[0];
    if (determinant != 0) {
        double x = (m_firstEquation[2] * m_secondEquation[1] - m_firstEquation[1] * m_secondEquation[2]) / determinant;
        double y = (m_firstEquation[0] * m_secondEquation[2] - m_firstEquation[2] * m_secondEquation[0]) / determinant;
        cout << "Roots of the system of linear equations:" << endl << "x = " << x << endl << "y = " << y << endl << endl;
    } else {
        cout << "Since the determinant of the system matrix is zero, the SLE has no solution" << endl;
    }
}

SLEWithThreeEquations::SLEWithThreeEquations():TSystemLinearEquation(){
    for (int i = 0; i < 4; ++i) {
        m_firstEquation[i] = rand() % 10 + 1;
    }
    for (int i = 0; i < 4; ++i) {
        m_secondEquation[i] = rand() % 10 + 1;
    }
    for (int i = 0; i < 4; ++i) {
        m_thirdEquation[i] = rand() % 10 + 1;
    }
}

[[maybe_unused]] SLEWithThreeEquations::SLEWithThreeEquations(const double *arr1, const double *arr2, const double *arr3) {
    for (int i = 0; i < 4; ++i) {
        m_firstEquation[i] = arr1[i];
    }
    for (int i = 0; i < 4; ++i) {
        m_secondEquation[i] = arr2[i];
    }
    for (int i = 0; i < 4; ++i) {
        m_thirdEquation[i] = arr3[i];
    }
}

void SLEWithThreeEquations::printSLE() {
    cout << m_firstEquation[0] << "x" << "+" << m_firstEquation[1] << "y" << "+" << m_firstEquation[2] << "z" << "="
         << m_firstEquation[3] << endl;
    cout << m_secondEquation[0] << "x" << "+" << m_secondEquation[1] << "y" << "+" << m_secondEquation[2] << "z"
         << "=" << m_secondEquation[3] << endl;
    cout << m_thirdEquation[0] << "x" << "+" << m_thirdEquation[1] << "y" << "+" << m_thirdEquation[2] << "z" << "="
         << m_thirdEquation[3] << endl;
    cout << endl;
}

void SLEWithThreeEquations::sleSolutionTest() {
    double firstRoot, secondRoot, thirdRoot;
    cout << "Enter the roots of the equations:" << endl << "x = ";
    cin >> firstRoot;
    cout << "y = ";
    cin >> secondRoot;
    cout << "z = ";
    cin >> thirdRoot;
    if (m_firstEquation[0] * firstRoot + m_firstEquation[1] * secondRoot + m_firstEquation[2] * thirdRoot == m_thirdEquation[3]) {
        if (m_secondEquation[0] * firstRoot + m_secondEquation[1] * secondRoot + m_secondEquation[2] * thirdRoot == m_thirdEquation[3]) {
            if (m_thirdEquation[0] * firstRoot + m_thirdEquation[1] * secondRoot == m_thirdEquation[2] * thirdRoot == m_thirdEquation[3]) {
                cout << "Entered data is the solution of equations." << endl << endl;
            } else {
                cout << "Entered data is not a solution of equations." << endl << endl;
            }
        } else {
            cout << "Entered data is not a solution of equations." << endl << endl;
        }
    } else {
        cout << "Entered data is not a solution of equations." << endl << endl;
    }
}

void SLEWithThreeEquations::sleSolution() {
    double determinant = (m_firstEquation[0] * m_secondEquation[1] * m_thirdEquation[2]) +
                         (m_firstEquation[1] * m_secondEquation[2] * m_thirdEquation[0]) +
                         (m_firstEquation[2] * m_secondEquation[0] * m_thirdEquation[1]) -
                         (m_thirdEquation[0] * m_secondEquation[1] * m_firstEquation[2] +
                         m_thirdEquation[1] * m_secondEquation[2] * m_firstEquation[0] +
                         m_thirdEquation[2] * m_secondEquation[0] * m_firstEquation[1]);

    double determinantX = (m_firstEquation[3] * m_secondEquation[1] * m_thirdEquation[2]) +
                          (m_firstEquation[1] * m_secondEquation[2] * m_thirdEquation[3]) +
                          (m_firstEquation[2] * m_secondEquation[3] * m_thirdEquation[1]) -
                          (m_thirdEquation[3] * m_secondEquation[1] * m_firstEquation[2] +
                          m_thirdEquation[1] * m_secondEquation[2] * m_firstEquation[3] +
                          m_thirdEquation[2] * m_secondEquation[3] * m_firstEquation[1]);

    double determinantY = m_firstEquation[0] * m_secondEquation[3] * m_thirdEquation[2] +
                          m_firstEquation[3] * m_secondEquation[2] * m_thirdEquation[0] +
                          m_firstEquation[2] * m_secondEquation[0] * m_thirdEquation[3] -
                          (m_thirdEquation[0] * m_secondEquation[3] * m_firstEquation[2] +
                          m_thirdEquation[3] * m_secondEquation[2] * m_firstEquation[0] +
                          m_thirdEquation[2] * m_secondEquation[0] * m_firstEquation[3]);

    double determinantZ = (m_firstEquation[0] * m_secondEquation[1] * m_thirdEquation[3]) +
                          (m_firstEquation[1] * m_secondEquation[3] * m_thirdEquation[0]) +
                          (m_firstEquation[3] * m_secondEquation[0] * m_thirdEquation[1]) -
                          (m_thirdEquation[0] * m_secondEquation[1] * m_firstEquation[3] +
                           m_thirdEquation[1] * m_secondEquation[3] * m_firstEquation[0] +
                           m_thirdEquation[3] * m_secondEquation[0] * m_firstEquation[1]);

    if (determinant != 0) {
        double x = determinantX / determinant;
        double y = determinantY / determinant;
        double z = determinantZ / determinant;
        cout << "Roots of the system of linear equations:" << endl << "x = " << x << endl << "y = " << y << endl
             << "z = " << z << endl << endl;
    } else {
        cout << "Since the determinant of the system matrix is zero, the SLE has no solution" << endl;
    }
}
