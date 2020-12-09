#define _CRT_SECURE_NO_WARNINGS 1

////求两个数的较大值
//#include <stdio.h>
//
//int  max(int a, int b)
//{
//	return a > b ? a : b;
//}
//
//int main()
//{
//	int x;
//	int y;
//	scanf("%d", &x);
//	scanf("%d", &y);
//	printf("%d\n", max(x, y));
//	return 0;
//}


////函数判断素数
//#include <stdio.h>
//
//int is_prime(int x)
//{
//	int i = 0;
//	for (i = 2; i <= x / 2; i++)
//	{
//		if (x % i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int n = 0;
//	for (n = 100; n <= 200; n++)
//	{
//		if (is_prime(n) == 1)
//			printf("%d\n", n);
//	}
//	return 0;
//}


////函数判断闰年
//#include <stdio.h>
//
//int is_leap_year(int year)
//{
//	if ((year % 4 == 0) && (year % 100 != 0))
//		return 1;
//	else if (year % 400 == 0)
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if (is_leap_year(year) == 1)
//		printf("%d年是闰年\n", year);
//	else
//		printf("%d年不是闰年\n", year);
//	system("pause");
//	return 0;
//}


////交换两个整数
//#include <stdio.h>
//
//void swap(int* a, int* b)
//{
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d", &a);
//	scanf("%d", &b);
//	swap(&a, &b);
//	printf("%d %d\n", a, b);
//	system("pause");
//	return 0;
//}


//乘法口诀表
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
//#include <stdio.h>
//
//void mul_table(int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//			printf("%2d *%2d = %3d  ", i, j, i*j);
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//	mul_table(x);
//	system("pause");
//	return 0;
//}


////递归方式实现打印一个整数的每一位
//#include <stdio.h >
//
//void print(int n)
//{
//	if (n>9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}


////递归求n！
//#include <stdio.h >﻿
//
//int factorial(int n)
//{
//	if (n>1)
//	{
//		return n*factorial(n - 1);
//	}
//	else
//		return 1;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = factorial(n);
//	printf("%d\n", ret);
//	return 0;
//}

////非递归求n！
//#include <stdio.h >
//
//int factorial(int n)
//{
//	int result = 1;
//	while (n>1)
//	{
//		result *= n;
//		n--;
//	}
//	return result;
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = factorial(n);
//	printf("%d\n", ret);
//	return 0;
//}


//strlen的模拟（递归实现）
//#include <stdio.h >﻿
//
//int Strlen(const char* arr)
//{
//	if (*arr != '\0')
//		return 1 + Strlen(arr + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "abcdefgh";
//	printf("%s\n", arr);
//	int len = Strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

////strlen的模拟（非递归实现）
//#include <stdio.h >
//
//int Strlen(char* arr)
//{
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "abcdefgh";
//	int len = Strlen(arr);
//	printf("%d", len);
//	return 0;
//}


////编写一个函数 reverse_string(char * string)（递归实现）
////实现：将参数字符串中的字符反向排列。
////要求：不能使用C函数库中的字符串操作函数。
//#include <stdio.h >
//
//char reverse_string(char * string)
//{
//	if (*string != '\0')
//	{
//		reverse_string(string + 1);
//	}
//	printf("%c", *string);
//}
//
//int main()
//{
//	char arr[] = "abcdefgh";
//	printf("%s\n", arr);
//	reverse_string(arr);
//	return 0;
//}


////计算一个数的每位之和（递归实现）
//#include <stdio.h >
//
//int sum(int n)
//{
//	if (n>9)
//	{
//		return sum(n / 10) + n % 10;
//	}
//	else
//		return n;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = sum(n);
//	printf("%d ", ret);
//	return 0;
//}


////递归实现n的k次方
//#include <stdio.h >
//
//int power(int n, int k)
//{
//	if (k>1)
//	{
//		return power(n, k - 1)*n;
//	}
//	else
//		return n;
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d", &n);
//	scanf("%d", &k);
//	int ret = power(n, k);
//	printf("%d ", ret);
//	return 0;
//}


////递归计算斐波那契数
//#include <stdio.h >
//
//int fib(int n)
//{
//	if (n>2)
//	{
//		return fib(n - 1) + fib(n - 2);
//	}
//	else
//		return 1;
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fib(n);
//	printf("%d ", ret);
//	return 0;
//}

//非递归
#include <stdio.h >

int fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;
	while (n>2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = fib(n);
	printf("%d ", ret);
	return 0;
}