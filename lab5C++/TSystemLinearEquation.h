#include <iostream>
#include <cstdlib>

using namespace std;

class TSystemLinearEquation {
public:
    virtual void printSLE() = 0;
    virtual void sleSolutionTest() = 0;
    virtual void sleSolution() = 0;
};
class SLEWithTwoEquations : public TSystemLinearEquation {
private:
    double m_firstEquation[3];
    double m_secondEquation[3];

public:
    SLEWithTwoEquations();

    [[maybe_unused]] SLEWithTwoEquations(const double *arr1, const double *arr2);
    void printSLE() override;
    void sleSolutionTest() override;
    void sleSolution() override;
};
class SLEWithThreeEquations : public TSystemLinearEquation {
    double m_firstEquation[4];
    double m_secondEquation[4];
    double m_thirdEquation[4];

public:
    SLEWithThreeEquations();

    [[maybe_unused]] SLEWithThreeEquations(const double *arr1, const double *arr2, const double *arr3);
    void printSLE() override;
    void sleSolutionTest() override;
    void sleSolution() override;
};
