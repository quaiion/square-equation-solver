#include <stdio.h>
#include "ded.h"


int main() {
    printf ("\nSQUARE EQUATION SOLVER V1.3 \n\n");

    double coef1 = NAN, coef2 = NAN, coef3 = NAN;

    get_coefs (&coef1, &coef2, &coef3);

    double root1 = NAN, root2 = NAN;

    int rootcode = INVALID_CODE;
    rootcode = solve_square (coef1, coef2, coef3, &root1, &root2);

    print_result (rootcode, root1, root2);

    return 0;
}
