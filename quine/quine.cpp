#include <iostream>
 
int main()
{
   const char *str = "int main()%c{%c%cconst char *str = %c%s%c%c%cprintf(str,10,10,9,34, str,34,10,9,10,10);%c}%c";
   printf(str,10,10,9,34, str,34,10,9,10,10);
}

