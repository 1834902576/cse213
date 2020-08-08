#include <stdio.h>
int main()
{
    int ar[20] = {23,5,67,4,21};
    int i, a;
    int size = 5;
    int tag = 0;

    scanf("%d", &a);

    for (i=0; i<size; i++)
    {
        if(ar[i]==a)
            tag++;
    }
    if(tag==1)
        printf("Found\n");
    else
        printf("Not Found");

    return 0;
}


