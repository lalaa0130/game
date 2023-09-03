#include <iostream>
#include "line.h"


int main()
{
    C_LINE c1{};
    C_LINE c2{};
    C_LINE c3{};

    c1.Init(2, 10);
    c2.Init(2, 5); 
    c3.Init(6, 7);
  
    double nX{};
    double nY{};
    if (c1.Intersect(c3,&nX,&nY))
    {
        c1.print();
        c3.print();
        printf("X: %.2lf, Y: %.2lf\n",nX,nY);
    }
    if (c2.Intersect(c3, &nX, &nY))
    {
        c2.print();
        c3.print();
        printf("X: %.2lf, Y: %.2lf\n", nX, nY);
    }
    if (c2.Intersect(c1, &nX, &nY))
    {
        c2.print();
        c1.print();
        printf("X: %.2lf, Y: %.2lf\n", nX, nY);
    }

}

