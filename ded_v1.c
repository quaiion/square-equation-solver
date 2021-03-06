#include <stdio.h>
#include <assert.h>
#include <math.h>
#define NO_REAL_ROOTS 0
#define ONE_ROOT 1
#define TWO_ROOTS 2
#define NO_ROOTS 3
#define INF_ROOTS 4
const double eps = 1e-6;        //откуда-то полученная константа

bool cmp_0 (double num);
int solve (double a, double b, double c, double* r1, double* r2);

int main(){
    printf ("\nSQUARE EQUASION SOLVER V1.2 \n\n");

    double coef1 = 0, coef2 = 0, coef3 = 0;
    printf ("Insert the coefficients (before x^2, before x^1,  before x^0):\n") ;
    int check = scanf ("%lg %lg %lg", &coef1, &coef2, &coef3);
    if (check != 3){
        printf ("\nWrong input, try again.");
        return 0;
    }

    double root1 = NAN, root2 = NAN;

    int rootcode = -1;
    rootcode = solve (coef1, coef2, coef3, &root1, &root2);

    switch (rootcode)
    {
        case NO_REAL_ROOTS: printf ("\nThere is no real roots.\n\n");
            break;

        case ONE_ROOT: printf ("\nThe only root is %.3lg.\n\n", root1);
            break;

        case TWO_ROOTS: printf ("\nThe equation roots are %.3lg and %.3lg.\n\n", root1, root2);
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

bool cmp_0 (double value){
    if (fabs(value) < eps) return true;
    else return false;
}

int solve (double a, double b, double c, double* r1, double* r2){
    assert (r2 != nullptr);
    assert (r1 != nullptr);
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    if (cmp_0(a) && cmp_0(b)){
        if (!cmp_0(c)) return NO_ROOTS;
        else return INF_ROOTS;
    }

    if (cmp_0(a) && !cmp_0(b) && !cmp_0(c)){
        *r1 = -c / b;
        *r2 = -c / b;
        return ONE_ROOT;
    }

    double discr = 0;
    discr = b * b - 4 * a * c;
    if (discr < 0 && !cmp_0(discr)) return NO_REAL_ROOTS;

    double sqrt_discr = 0;
    sqrt_discr = sqrt (discr);
    *r1 = (-b + sqrt_discr) / (2 * a);
    *r2 = (-b - sqrt_discr) / (2 * a);

    if (cmp_0(discr)) return ONE_ROOT;

    return TWO_ROOTS;
}
