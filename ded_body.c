#include "ded.h"

void get_coefs (double* coef1, double* coef2, double* coef3) {
    assert (coef1 != NULL);
    assert (coef2 != NULL);
    assert (coef3 != NULL);

    while (true) {
        printf ("\nInsert the coefficients (before x^2, before x^1, before x^0):\n");

        if (scanf ("%lg %lg %lg", coef1, coef2, coef3) == 3) {
            break;
        }

        printf ("\nWrong input, try again.\n");
        while (getchar() != '\n') ;
    }
}

bool is_zero (double value) {
    return fabs(value) < EPS;
}

bool is_equal (double value1,  double value2) {
    return fabs(value1 - value2) < EPS;
}

int solve_square (double a, double b, double c, double* root1, double* root2) {
    assert (root2 != nullptr);
    assert (root1 != nullptr);
    assert (root1 != root2);
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    if (is_zero(a)) {
        if (is_zero(b)) {
            return (!is_zero(c)) ? NO_ROOTS : INF_ROOTS;
        } else if (!is_zero(c)) {
            *root1 = -c / b;
            *root2 = -c / b;
            return ONE_ROOT;
        }
    }

    double discr = b * b - 4 * a * c;
    if (discr < -EPS) return NO_REAL_ROOTS;

    double sqrt_discr = sqrt (discr);
    *root1 = (-b + sqrt_discr) / (2 * a);
    *root2 = (-b - sqrt_discr) / (2 * a);

    return (is_zero(discr)) ? ONE_ROOT : TWO_ROOTS;
}

void print_result (int rootcode, double root1, double root2) {
    switch (rootcode) {
        case NO_REAL_ROOTS:
            printf ("\nThere is no real roots.\n\n");
            break;

        case ONE_ROOT:
            printf ("\nThe only root is %lg.\n\n", root1);
            break;

        case TWO_ROOTS:
            printf ("\nThe equation roots are %lg and %lg.\n\n", root1, root2);
            break;

        case NO_ROOTS:
            printf ("\nThere is no roots.\n\n");
            break;

        case INF_ROOTS:
            printf ("\nAny number is a root.\n\n");
            break;

        default:
            printf ("\nmain(): ERROR: rootcode = %d\n\n", rootcode);
            break;
    }
}
