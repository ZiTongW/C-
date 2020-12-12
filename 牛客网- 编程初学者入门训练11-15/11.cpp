#include <stdio.h>

int main()
{
    int num = 0;
    float grade1 = 0;
    float grade2 = 0;
    float grade3 = 0;
    scanf("%d;%f,%f,%f",&num,&grade1,&grade2,&grade3);
    printf("The each subject score of  No. %d is %.2f, %.2f, %.2f.",num,grade1,grade2,grade3);
    return 0;
}
