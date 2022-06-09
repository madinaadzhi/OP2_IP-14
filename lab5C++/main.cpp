#include "TSystemLinearEquation.h"

int main() {
    srand(time(nullptr));

    int countOfSystems1;
    cout << "Enter the count of systems with two equations: ";
    cin >> countOfSystems1;
    auto *arrayOfDualSystem = new SLEWithTwoEquations[countOfSystems1];
    for (int i = 0; i < countOfSystems1; ++i) {
        arrayOfDualSystem[i].printSLE();
        arrayOfDualSystem[i].sleSolutionTest();
        arrayOfDualSystem[i].sleSolution();
    }


    int countOfSystems2;
    cout << "Enter the count of systems with three equations: ";
    cin >> countOfSystems2;
    auto *arrayOfTripleSystem = new SLEWithThreeEquations[countOfSystems2];
    for (int i = 0; i < countOfSystems2; ++i) {
        arrayOfTripleSystem[i].printSLE();
        arrayOfTripleSystem[i].sleSolutionTest();
        arrayOfTripleSystem[i].sleSolution();
    }

    delete[] arrayOfDualSystem;
    delete[] arrayOfTripleSystem;
}

