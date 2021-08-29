#include "ded.h"

void run_unit_tests (FILE* file)

static bool unit_test (FILE* fptr, int counter);

int main() {
    FILE* fptr = fopen ("test.txt", "r");

    run_unit_tests (fptr);

    fclose (fptr);

    return 0;
}

void run_unit_tests (FILE* file) {
    for (int i = 1; !feof(file); i++) {
        unit_test (file, i);
    }
}

static bool unit_test (FILE* fptr, int counter) { 
    bool test_success = true;

    double coef1 = NAN, coef2 = NAN, coef3 = NAN, root1 = NAN, root2 = NAN;
    int test_code = INVALID_CODE;

    fscanf (fptr, "%d", &test_code);
    fscanf (fptr, "%lg %lg %lg", &coef1, &coef2, &coef3);
    if (test_code == ONE_ROOT || test_code == TWO_ROOTS) fscanf (fptr, "%lg %lg", &root1, &root2);

    int rootcode = INVALID_CODE;
    double test_root1 = NAN, test_root2 = NAN;

    rootcode = solve_square (coef1, coef2, coef3, &test_root1, &test_root2);

    if (test_code == ONE_ROOT || test_code == TWO_ROOTS) {
        if ((is_equal (test_root1, root1) && is_equal (test_root2, root2) || is_equal (test_root1, root2) && is_equal (test_root2, root1)) && rootcode == test_code) {
            printf ("\nTest %d succeeded.\n", counter);
        } else {
            printf ("\nTest %d failed.", counter);
            printf ("function returned %d as the rootcode, %lg as root1, %lg as root2;", rootcode, test_root1, test_root2);
            printf ("coefs: %lg; %lg; %lg; rootcode expected: %d; roots expected: %lg; %lg\n", coef1, coef2, coef3, test_code, root1, root2);
            test_success = false;
        }
    } else {
        if (rootcode == test_code) {
            printf ("\nTest %d succeeded.\n", counter);
        } else {
            printf ("\nTest %d failed.", counter);
            printf ("function returned %d as the rootcode, %lg as root1, %lg as root2;", rootcode, test_root1, test_root2);
            printf ("coefs: %lg; %lg; %lg; rootcode expected: %d; no roots expected.\n", coef1, coef2, coef3, test_code);
            test_success = false;
        }
    }

    return test_success;
}
