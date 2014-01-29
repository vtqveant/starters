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

void updateArray(int *aInt) {
    int *aIntLocal;
    aIntLocal = aInt;
    aIntLocal[0] = 5;
    aInt[4] = 50; // a local pointer is not really required
}

void updateString(char **szStr) {
    char *upd = "updated string";
    *szStr = upd;
}

void updateArrOfStructs(PAIR *aPair) {
    aPair[1].x = 7;
}

/**
 * populates a ptr, size is not known beforehand 
 */
void updateDynamicArray(int **aEntries, int *pNumEntries) {
    *pNumEntries = 0;
    int bufSize = 1;
    aEntries = malloc(bufSize * sizeof(int *));

    const int limit = 70;
    int x = 5;
    
    while (1) {
        if (*pNumEntries == limit) break;
        if (*pNumEntries == bufSize - 1) {
            bufSize *= 2;
            printf("reallocating dynamic array, size = %d\n", bufSize);
            aEntries = realloc(aEntries, bufSize * sizeof(int *));
        }
        aEntries[*pNumEntries] = &x;
        (*pNumEntries)++;
    }

    printf("aEntries[5] = %d\n", *(aEntries[5]));

    /* truncate */
    printf("truncating dynamic array, size = %d\n", *pNumEntries);
    aEntries = realloc(aEntries, *pNumEntries * sizeof(int *));

    printf("aEntries[5] = %d\n", *(aEntries[5]));
}

int main(int argc, char **argv) {
    printf("                              \n");
    printf("------------------------------\n");
    printf("                              \n");

    int i = 0;
    printf("initial value = %d\n", i);
    update(&i);
    printf("final value = %d\n", i);

    printf("                              \n");
    printf("------------------------------\n");
    printf("                              \n");

    PAIR pair = { 0, 0 };
    printf("initial pair value = { %d, %d }\n", pair.x, pair.y);
    updatePair(&pair);
    printf("final pair value = { %d, %d }\n", pair.x, pair.y);

    printf("                              \n");
    printf("------------------------------\n");
    printf("                              \n");

    int aInt[5]; 
    memset(&aInt, 0, sizeof(aInt));
    printf("initial 1st element of array = %d\n", aInt[0]);
    printf("initial 5th element of array = %d\n", aInt[4]);
    updateArray(aInt);  // aInt is of type int *, therefore I should pass aInt itself, not the reference
    printf("final 1st element of array = %d\n", aInt[0]);
    printf("final 5th element of array = %d\n", aInt[4]);

    printf("                              \n");
    printf("------------------------------\n");
    printf("                              \n");

    char *str = "initial string";
    printf("initial str = %s\n", str);
    updateString(&str);
    printf("final str = %s\n", str);

    printf("                              \n");
    printf("------------------------------\n");
    printf("                              \n");

    int nbrPairs = 5;
    PAIR aPairs[nbrPairs];
    memset(&aPairs, 0, sizeof(aPairs));
    printf("aPairs[1].x = %d\n", aPairs[1].x);
    updateArrOfStructs(aPairs);
    printf("aPairs[1].x = %d\n", aPairs[1].x);

    printf("                              \n");
    printf("------------------------------\n");
    printf("                              \n");

    int **aEntries, pNumEntries = 0;
    updateDynamicArray(aEntries, &pNumEntries);
    if (pNumEntries != 0) {
        printf("got %d entries\n", pNumEntries);
        printf("aEntries[5] = %d\n", *(aEntries[5]));
    }


    exit(EXIT_SUCCESS);
}
