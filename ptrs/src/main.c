#include <stdlib.h>
#include <stdio.h>

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

int main(int argc, char **argv) {
    int i = 0;
    printf("initial value = %d\n", i);
    update(&i);
    printf("final value = %d\n", i);

    PAIR pair = { 0, 0 };
    printf("initial pair value = { %d, %d }\n", pair.x, pair.y);
    updatePair(&pair);
    printf("final pair value = { %d, %d }\n", pair.x, pair.y);

    exit(EXIT_SUCCESS);
}
