#include <stdlib.h>
#include <stdio.h>

#include <dlfcn.h>

int main(int argc, char **argv) {
    void *handle;
    void (*fn)(const char *);
    char *error;

    handle = dlopen("./module.so", RTLD_NOW);  
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();

    *(void **) (&fn) = dlsym(handle, "run");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    (*fn)("it works!\n");

    dlclose(handle);
    exit(EXIT_SUCCESS);
}
