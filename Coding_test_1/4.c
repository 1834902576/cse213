#include<stdio.h>
int main()
{
    int i;
    int *p;
    int sum=0;
    int avg=0;
    int ar[20] = {12,3,42,11,45};
    int size=5;
    p = &ar[0];
    for(i=0; i<size; i++)
        printf("%d ",*(p+i));
    printf("\n");
    for(i=0; i<size; i++){
        sum += *(p+i);
    }
        avg = sum/size;
        printf("Average= %d",avg);
    return 0;
}
