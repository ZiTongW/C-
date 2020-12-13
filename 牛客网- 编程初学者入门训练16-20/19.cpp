#include <stdio.h>

int main()
{
    int a=0;
    scanf("%d",&a);
    while(a)
    {
        printf("%d",a%10);
        a=a/10;
    }
   return 0;
}
