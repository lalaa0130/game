#pragma once
#include <stdio.h>

class C_LINE
{
private:
    double m_da;
    double m_db;
    double m_dSlope;

public:
    C_LINE() = default;
    ~C_LINE() = default;

    void Init(double dA, double dB);
    double GetSlope();
    double GetA() const { return m_da; }
    double GetB() { return m_db; }
    double GetY(double dX);
    double GetX(double dY);
    bool Intersect(const C_LINE& c, double* dIntersectX, double* dIntersectY);
    void print();
};