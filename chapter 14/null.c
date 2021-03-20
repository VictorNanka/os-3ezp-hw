#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int * null = NULL;
    printf("null = %/d", *null);
    free(null);
    return 0;
}
