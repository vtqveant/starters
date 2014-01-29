#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct PAIR_S {
    int x;
    int y;
} PAIR;

void update(int *pInt) {
    *pInt = 5;
}

void updatePair(PAIR *pPair) {
    pPair->x = 5;
    pPair->y = 10;
}

void updateArray(int *paInt) {
    int *aIntLocal;
    aIntLocal = paInt;
    aIntLocal[0] = 5;
    paInt[4] = 50; // a local pointer is not really required
}

int main(int argc, char **argv) {
    int i = 0;
    printf("initial value = %d\n", i);
    update(&i);
    printf("final value = %d\n", i);

    PAIR pair = { 0, 0 };
    printf("initial pair value = { %d, %d }\n", pair.x, pair.y);
    updatePair(&pair);
    printf("final pair value = { %d, %d }\n", pair.x, pair.y);

    int aInt[5]; 
    memset(&aInt, 0, sizeof(aInt));
    printf("initial 1st element of array = %d\n", aInt[0]);
    printf("initial 5th element of array = %d\n", aInt[4]);
    updateArray(aInt);  // aInt is of type int *, therefore I should pass aInt itself, not the reference
    printf("final 1st element of array = %d\n", aInt[0]);
    printf("final 5th element of array = %d\n", aInt[4]);

    exit(EXIT_SUCCESS);
}
