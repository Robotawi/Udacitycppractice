//
// Created by zozo on 1/17/20.
//

#include <stdio.h>
#include <stdlib.h>
struct MyStruct{
    int i;
    //double d;
    //char a[5];
};

int main()
{   int *p = (int *)malloc(3*sizeof(int));
//    int *p = (int *)malloc(3 * sizeof(int));
    p[0] = 5; p[1] = 0; p[2] = 30;
    printf("address=%p, value=%d\n", p, *(p));

    MyStruct *pstruct = (MyStruct *) calloc(1, sizeof(MyStruct));
    printf("Size of MyStruct is %lu bytes, or %f megabytes. \n", sizeof(MyStruct), sizeof(MyStruct)/1000.0/1024.0);
    return 0;
}