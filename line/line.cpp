#include"line.h"


void C_LINE::Init(double dA, double dB)
{
    m_da = dA;
    m_db = dB;
    m_dSlope = m_da;
}

double C_LINE::GetSlope()
{
    return m_dSlope;
}

double C_LINE::GetY(double dX)
{
    double dY{};
    dY = dX * m_da + m_db;

    return dY;
}

double C_LINE::GetX(double dY)
{
    double dX{};
    dX = (dY - m_db) / m_da;

    return dX;
}

bool C_LINE::Intersect(const C_LINE& c, double* dIntersectX, double* dIntersectY)
{
    if (c.m_dSlope == m_dSlope)
    {
        printf("Parallel\n");
        return false;
    }

    *dIntersectX = (m_db - c.m_db) / (c.m_da - m_da);
    *dIntersectY = GetY(*dIntersectX);
    return true;

}

void C_LINE::print()
{
    printf("Line Format: y = %.2lfx + %.2lf\n", m_da, m_db);
}
