#include<stdio.h>
void function();
int main()
{
    int ar[100];
    int i;
    int size;
    function();
    return 0;
}
void function(){
    int ar[100];
    int i, j;
    for(i = 0; i < 100; i++)
    {
        scanf("%d",&ar[i]);
        if(ar[i] == 0){
            printf("Overflow\n");
            break;
        }
    }
    for(j = 0; j < i; j++){
        printf("%d, ",ar[j]);
    }
}
