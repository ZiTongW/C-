#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    scanf("a=%d,b=%d",&a,&b);
    int temp;
    temp = a;
    a=b;
    b=temp;
    printf("a=%d,b=%d",a,b);
    return 0;    
}
