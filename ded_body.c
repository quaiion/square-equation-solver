#include "ded.h"

bool cmp_0 (double value){
    return cmp (value, 0);
}

bool cmp (double value1,  double value2){
    return (fabs(value1 - value2) < EPS);
}

int get_rootcode_roots (double a, double b, double c, double* root1, double* root2){
    assert (root2 != nullptr);
    assert (root1 != nullptr);
    assert (root1 != root2);
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    if (cmp_0(a) && cmp_0(b)){
        if (!cmp_0(c)) return NO_ROOTS;
        else return ROOTCODE::INF_ROOTS;
    }

    if (cmp_0(a) && !cmp_0(b) && !cmp_0(c)){
        *root1 = -c / b;
        *root2 = -c / b;
        return ROOTCODE::ONE_ROOT;
    }

    double discr = 0;
    discr = b * b - 4 * a * c;
    if (discr < 0 && !cmp_0(discr)) return ROOTCODE::NO_REAL_ROOTS;

    double sqrt_discr = 0;
    sqrt_discr = sqrt (discr);
    *root1 = (-b + sqrt_discr) / (2 * a);
    *root2 = (-b - sqrt_discr) / (2 * a);

    if (cmp_0(discr)) return ROOTCODE::ONE_ROOT;

    return ROOTCODE::TWO_ROOTS;
}

void print_rootcode (int rootcode, double root1, double root2){
    switch (rootcode)
    {
        case ROOTCODE::NO_REAL_ROOTS: printf ("\nThere is no real roots.\n\n");
            break;

        case ROOTCODE::ONE_ROOT: printf ("\nThe only root is %lg.\n\n", root1);
            break;

        case ROOTCODE::TWO_ROOTS: printf ("\nThe equation roots are %lg and %lg.\n\n", root1, root2);
            break;

        case ROOTCODE::NO_ROOTS: printf ("\nThere is no roots.\n\n");
            break;

        case ROOTCODE::INF_ROOTS: printf ("\nAny number is a root.\n\n");
            break;

        default: printf ("\nmain(): ERROR: rootcode = %d\n\n", rootcode);
            break;
    }
}