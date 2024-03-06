#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "roots.h"

char rootstr[50];

char* roots(int a, int b,int c){
    double root1, root2, discriminant;

    if (a == 0 ){
        if (b == 0){
            if (c == 0){
                return "Любой x";
            } else{
                return "Нет корней";
            }
        } else if (c == 0){
            return "0";
        } else{
            root1 = -c / b;
            sprintf(rootstr, "%.2lf", root1);
            return rootstr;
        }
    } else if (b == 0){
        if (c == 0){
            return "0";
        } else{
            root1 = sqrt(abs(-c / a));
            sprintf(rootstr, "%.2lf;%.2lf", root1, -root1);
            return rootstr;
        }
    }

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
