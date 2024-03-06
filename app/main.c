#include <stdio.h>

#include "myfunc.h"
#include "roots.h"

int main()
{
    printf("Hello World!\n");
    char* stroka = roots(2, 2, 2);
    return printf("%s\n", stroka);
}
