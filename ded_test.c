#include "ded.h"

static void unit_test (FILE* fptr, int test_code, int counter);

int main(){
    FILE* fptr = fopen ("test.txt", "r");

    int counter = 1;

    unit_test (fptr, NO_REAL_ROOTS, counter); counter++;
    unit_test (fptr, ONE_ROOT, counter); counter++;
    unit_test (fptr, TWO_ROOTS, counter); counter++;
    unit_test (fptr, NO_ROOTS, counter); counter++;
    unit_test (fptr, INF_ROOTS, counter); counter++;
    unit_test (fptr, ONE_ROOT, counter);

    fclose (fptr);

    return 0;
}

static void unit_test (FILE* fptr, int test_code, int counter){
    double coef1 = NAN, coef2 = NAN, coef3 = NAN, root1 = NAN, root2 = NAN;

    fscanf (fptr, "%lg %lg %lg", &coef1, &coef2, &coef3);
    if (test_code == ONE_ROOT || test_code == TWO_ROOTS) fscanf (fptr, "%lg %lg", &root1, &root2);

    int rootcode = -1;
    double test_root1 = NAN, test_root2 = NAN;

    rootcode = get_rootcode_roots (coef1, coef2, coef3, &test_root1, &test_root2);

    if (test_code == ONE_ROOT || test_code == TWO_ROOTS){
        if ((cmp (test_root1, root1) && cmp (test_root2, root2) || cmp (test_root1, root2) && cmp (test_root2, root1)) && rootcode == test_code) 
            printf ("\nTest %d succeeded.\n", counter);
        else printf ("\nTest %d failed.\n", counter);
    }
    else{
        if (rootcode == test_code) printf ("\nTest %d succeeded.\n", counter);
        else printf ("\nTest %d failed.\n", counter);
    }
}
