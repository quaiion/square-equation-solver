#include <stdio.h>
#include <assert.h>
#include <math.h>
#define NO_REAL_ROOTS 0
#define ONE_ROOT 1
#define TWO_ROOTS 2
#define NO_ROOTS 3
#define INF_ROOTS 4

int solve (float a, float b, float c, float* r1, float* r2){
    assert (r2 != nullptr);
    assert (r1 != nullptr);
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    if (a == 0 && b == 0){
        if (c) return NO_ROOTS;
        else return INF_ROOTS;
    }

    if (a == 0 && b != 0 && c != 0){
        *r1 = -c / b;
        *r2 = -c / b;
        return ONE_ROOT;
    }

    float discr = 0;
    discr = b * b - 4 * a * c;
    if (discr < 0) return NO_REAL_ROOTS;

    float sqrt_discr = 0;
    sqrt_discr = sqrt (discr);
    *r1 = (-b + sqrt_discr) / (2 * a);
    *r2 = (-b - sqrt_discr) / (2 * a);

    if (discr == 0) return ONE_ROOT;

    return TWO_ROOTS;
}

int main(){
    printf ("\nSQUARE EQUASION SOLVER V1.1 \n\n");

    float coef1 = 0, coef2 = 0, coef3 = 0;
    printf ("Insert the coefficients (before x^2, before x^1,  before x^0):\n") ;
    int check = scanf ("%f %f %f", &coef1, &coef2, &coef3);
    if (check != 3){
        printf ("\nWrong input, try again.");
        return 0;
    }

    float root1 = 0, root2 = 0;

    int rootcode = -1;
    rootcode = solve (coef1, coef2, coef3, &root1, &root2);

    switch (rootcode)
    {
        case NO_REAL_ROOTS: printf ("\nThere is no real roots.\n\n");
            break;

        case ONE_ROOT: printf ("\nThe only root is %.3f.\n\n", root1);
            break;

        case TWO_ROOTS: printf ("\nThe equation roots are %.3f and %.3f.\n\n", root1, root2);
            break;

        case NO_ROOTS: printf ("\nThere is no roots.\n\n");
            break;

        case INF_ROOTS: printf ("\nAny number is a root.\n\n");
            break;

        default: printf ("\nmain(): ERROR: rootcode = %d\n\n", rootcode);
            return 1;
    }

    return 0;
}
