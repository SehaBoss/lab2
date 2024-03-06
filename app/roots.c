#include <stdio.h>
#include <math.h>
#include "roots.h"

char rootstr[50];

char* roots(int a, int b,int c){
    double root1, root2, discriminant;

    discriminant = b*b - 4*a*c;
    if (discriminant > 0){
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        sprintf(rootstr, "%.2lf;%.2lf", root1, root2);
        return rootstr;
    } else if (discriminant == 0){
        root1 = -b / (2 * a);
        sprintf(rootstr, "%.2lf", root1);
        return rootstr;
    } else {
        return "Нет корней";
    }
}
