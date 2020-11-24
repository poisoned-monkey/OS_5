#include <dlfcn.h>

#include "vector.h" 

int main(void)
{
   void (*vectorInit)(vector* v);
    int (*vectorCount)(vector* v);
    void (*vectorAdd)(vector* v, double d);
    void (*vectorSet)(vector* v, int index, double d);
    double (*vectorGet)(vector* v, int index);
    void (*vectorDelete)(vector* v, int index);
    void (*vectorFree)(vector* v);
    void (*vectorPrint)(vector* v);

    void* libHandle;
    libHandle = dlopen("./libvector.so", RTLD_LAZY);
    if (!libHandle) {
        perror("dlopen error");
        exit(-1);
    }

    vectorInit = (void (*)(void))dlsym(libHandle, "vectorInit");
    vectorCount = (int (*)(void))dlsym(libHandle, "vectorCount");
    vectorAdd = (void (*)(void))dlsym(libHandle, "vectorAdd");
    vectorSet = (void (*)(void))dlsym(libHandle, "vectorSet");
    vectorGet = (double (*)(void))dlsym(libHandle, "vectorGet");
    vectorDelete = (void (*)(void))dlsym(libHandle, "vectorDelete");
    vectorFree = (void (*)(void))dlsym(libHandle, "vectorFree");
    vectorPrint = (void (*)(void))dlsym(libHandle, "vectorPrint");

    int act = 0;
    double key = 0;
    int ind;
    vector *v = (vector*)malloc(sizeof(vector));
    printf("Choose an operation:\n");
    printf("1) Initialize the vector\n");
    printf("2) Push back\n");
    printf("3) Insert in random place\n");
    printf("4) Print vector\n");
    printf("0) Exit\n");

    while (scanf("%d", &act) && act) {
        switch(act) {
        case 1:
            printf("Enter key to initialize the queue: ");
            ( *vectorInit)(v);
            break;

        case 2:
            printf("Enter key: ");
            scanf("%lf", &key);
            (*vectorAdd)(v, key);
            break;

        case 3:
            printf("Enter index: ");
            scanf("%d", &ind);   
            printf("Enter key: ");
            scanf("%lf", &key);
            (*vectorSet)(v,ind,key);
            break;

        case 4:
            (*vectorPrint)(v);
            break;
        case 5:
            printf("Enter index: ");
            scanf("%d", &ind);
            (*vectorDelete)(v,ind);
        default:
            printf("Incorrect command\n");
            break;
        }
    printf("Choose an operation:\n");
    printf("1) Initialize the vector\n");
    printf("2) Push back\n");
    printf("3) Insert in random place\n");
    printf("4) Print vector\n");
    printf("0) Exit\n");
    }
    (*vectorFree)(&v);
    free(v);
    if (dlclose(libHandle) != 0) {
        perror("dlclose error");
        exit(-1);
    }

    return 0;
}