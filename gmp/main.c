#include <gmp.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkLength(mpz_t num, size_t length) {
    // assumes num is positive
    size_t guess = mpz_sizeinbase(num, 10);
    if (guess == length) {
        char* real = NULL;
        gmp_asprintf(&real, "%Zd", num);
        if (strlen(real) == length) {
            free(real);
            return true;
        } else {
            free(real);
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    mpz_t a;
    mpz_init(a);

    mpz_t b;
    mpz_init(b);
    mpz_set_ui(b, 1);

    for (int i = 2; true; i++) {
        // check for completion
        if (checkLength(a, 1000)) {
            gmp_printf("#%i: %Zd\n", i, a);
            break;
        } else if (checkLength(b, 1000)) {
            gmp_printf("#%i: %Zd\n", i, b);
            break;
        }

        // increment sequence
        if (mpz_cmp(a, b) < 0) {
            mpz_add(a, a, b);
        } else {
            mpz_add(b, a, b);
        }
    }

    mpz_clear(a);
    mpz_clear(b);

    return 0;
}