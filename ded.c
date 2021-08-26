#include <stdio.h>
#include "ded.h"

int main(){
    printf ("\nSQUARE EQUATION SOLVER V1.3 \n\n");

    double coef1 = 0, coef2 = 0, coef3 = 0;

    printf ("Insert the coefficients (before x^2, before x^1,  before x^0):\n");
    int check = scanf ("%lg %lg %lg", &coef1, &coef2, &coef3);

    if (check != 3){
        printf ("\nWrong input, try again.");
        return 0;
    }

    double root1 = NAN, root2 = NAN;

    int rootcode = -1;
    rootcode = get_rootcode_roots (coef1, coef2, coef3, &root1, &root2);

    print_rootcode (rootcode, root1, root2);

    return 0;
}