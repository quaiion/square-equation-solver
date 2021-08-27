#include "ded.h"

static bool unit_test (FILE* fptr, int counter);

int main(){
    FILE* fptr = fopen ("test.txt", "r");

    for (int i = 1; !feof(fptr); i++)
        unit_test (fptr, i);

    fclose (fptr);

    return 0;
}

static bool unit_test (FILE* fptr, int counter){
    bool indic = 1;

    double coef1 = NAN, coef2 = NAN, coef3 = NAN, root1 = NAN, root2 = NAN;
    int test_code = -1;

    fscanf (fptr, "%d", &test_code);
    fscanf (fptr, "%lg %lg %lg", &coef1, &coef2, &coef3);
    if (test_code == ONE_ROOT || test_code == TWO_ROOTS) fscanf (fptr, "%lg %lg", &root1, &root2);

    int rootcode = -1;
    double test_root1 = NAN, test_root2 = NAN;

    rootcode = get_rootcode_roots (coef1, coef2, coef3, &test_root1, &test_root2);

    if (test_code == ONE_ROOT || test_code == TWO_ROOTS){
        if ((cmp (test_root1, root1) && cmp (test_root2, root2) || cmp (test_root1, root2) && cmp (test_root2, root1)) && rootcode == test_code) 
            printf ("\nTest %d succeeded.\n", counter);
        else{
            printf ("\nTest %d failed.\nfunction returned %d as the rootcode, %lg as root1, %lg as root2;\ncoefs: %lg; %lg; %lg; rootcode expected: %d; roots expected: %lg; %lg\n", counter, rootcode, test_root1, test_root2, coef1, coef2, coef3, test_code, root1, root2);
            indic = 0;
        }
    }
    else{
        if (rootcode == test_code) printf ("\nTest %d succeeded.\n", counter);
        else{
            printf ("\nTest %d failed.\nfunction returned %d as the rootcode, %lg as root1, %lg as root2;\ncoefs: %lg; %lg; %lg; rootcode expected: %d; no roots expected.\n", counter, rootcode, test_root1, test_root2, coef1, coef2, coef3, test_code);
            indic = 0;
        }
    }
    return indic;
}
