#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    double key = 0;
    int ind;
    printf("This is compile-time linking\n\n");


    int act = 0;
    vector *v = (vector*)malloc(sizeof(vector));
    printf("Choose an operation:\n");
    printf("1) Initialize the vector\n");
    printf("2) Push back\n");
    printf("3) Insert in random place\n");
    printf("4) Print vector\n");
    printf("5) delete last element vector\n");

    printf("0) Exit\n");

    while (scanf("%d", &act) && act) {
        switch(act) {
        case 1:
            printf("Enter key to initialize the queue: ");
            vectorInit(v);
            break;

        case 2:
            printf("Enter key: ");
            scanf("%lf", &key);
            vectorAdd(v, key);
            break;

        case 3:
            printf("Enter index: ");
            scanf("%d", &ind);   
            printf("Enter key: ");
            scanf("%lf", &key);
            vectorSet(v,ind,key);
            break;

        case 4:
            vectorPrint(v);
            break;
        case 5:
            printf("Enter index: ");
            scanf("%d", &ind);
            vectorDelete(v,ind);
        default:
            printf("Incorrect command\n");
            break;
        }
    printf("Choose an operation:\n");
    printf("1) Initialize the vector\n");
    printf("2) Push back\n");
    printf("3) Insert in random place\n");
    printf("4) Print vector\n");
    printf("5) delete last element vector\n");

    printf("0) Exit\n");
    }
    (*vectorFree)(&v);
    free(v);
  

    return 0;
}