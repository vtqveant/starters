#include <stdio.h>

/* interface */

typedef struct {
    void (*quack)();
    void (*whoami)();
} ANIMAL_INTERFACE;

typedef struct {
    char *szName;
    ANIMAL_INTERFACE *pInterface;
} OBJECT;

static void construct(char *szName, ANIMAL_INTERFACE *pVerbsImpl, OBJECT hObj) {
   hObj.szName = szName;
   hObj.pInterface = pVerbsImpl;
}

/* implementations */

/* Duckling */
void Quack() {
    printf("quack!\n");
}

void WhoAmI() {
    printf("I am a duckling.\n");
}


int main(int argc, char **argv) {

    OBJECT duckling;
    ANIMAL_INTERFACE ducklingVerbs;
    ducklingVerbs.quack = Quack;
    ducklingVerbs.whoami = WhoAmI;

    construct("Tim", &ducklingVerbs, duckling);

    // duckling.pInterface->quack();
    ANIMAL_INTERFACE *ptest;
    ptest = duckling.pInterface;
    ptest->quack();
}
