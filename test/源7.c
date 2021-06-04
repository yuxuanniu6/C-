#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
//由于还没学习结构体，这里告知结构体的大小是20个字节
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
//int main()
//{
//	printf("%p\n", p + 0x1);
//	printf("%p\n", (unsigned long)p + 0x1);
//	printf("%p\n", (unsigned int*)p + 0x1);
//	return 0;
//}
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1); 
//	//指向数组最后的地址，就是4后面的地址，最后*(ptr-1)指向4，所以结果为4
//	int* ptr2 = (int*)((int)a + 1); 
//	//a为1的地址 0x01000000 加1指向下一个地址0x02000000，因为这里强制转换a的地址，所以结果为02000000
//	//01 00 00 00 | 02 00 00 00 | 03 00 00 00 | 04 00 00 00 
//	//printf("%x,%x", ptr1[-1], *ptr2);
//	/*int x = -1;
//	printf("%d", x << 1);*/
//	char arr[] = "hello world!";
//	char* s = arr;
//	printf("%p\n", &arr[0]);
//	printf("%p", s);
//	return 0;
//}
//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//	char* str3 = "hello bit."; //常量字符串，c中可以这样写，c++中需要加const修饰，以表示是const char*，确保类型相同
//	char* str4 = "hello bit.";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//
//	return 0;
//}
//void test(char** s)
//{
//	
//}
//int main()
//{
//	//char a[] = { 'a','b','c','d','e' };
//	//char b[] = { 'b','c','d','e' ,'f'};
//	//char c[] = { 'c','d','e' ,'f' ,'g' };
//	////a，b，c首元素的地址为字符数据的地址，所以可以用char*指针来接受
//	//char* arr1[3] = { a,b,c };
//	//for (int i = 0; i < 3; i++)
//	//{
//	//	for (int j = 0; j < 5; j++)
//	//	{
//	//		printf("%c ", *(arr1[i] + j));
//	//	}
//	//	printf("\n");
//	//}
//
//	/*int arr[10] = { 0 };
//	printf("arr的地址：%p\n", arr); 
//	printf("&arr的地址：%p\n\n", &arr);
//
//	printf("arr+1的地址：%p\n", arr+1);
//	printf("&arr+1的地址：%p", &arr+1);*/
//
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int(*p)[10] = &arr;//把数组arr的地址赋值给数组指针变量p
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", (*p)[i]);
//	}
//	return 0;
//}
//void print_arr(int(*arr)[5], int row, int col) {
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void test(int arr[3][5])//ok？
//{}
//void test(int arr[][])//错误
//{}
//void test(int arr[][5])//ok？
//{}
//总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
//因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
//这样才方便运算。
//void test(int* arr)//ok？
//{}
//void test(int* arr[5])//ok？
//{}
//void test(int(*arr)[5])//ok？
//{}
//void test(int** arr)//ok？
//{}
//int main()
//{
//	//int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	//print_arr(arr, 3, 5); //将第一行的地址传给数组指针(*arr)[5]
//	
//	
//	int arr[3][5] = { 0 };
//	test(arr);
//	
//	return 0;
//}
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int div(int a, int b) {
	return a / b;
}
int main()
{
	int (*p1)(int, int) = add;
	int (*p2)(int, int) = sub;
	int (*p3)(int, int) = mul;
	int (*p4)(int, int) = div;
	int x = 10, y = 5;
	int ret = 0;
	ret = (*p1)(x, y);
	printf("%d\n", ret);
	ret = (*p2)(x, y);
	printf("%d\n", ret);
	ret = (*p3)(x, y);
	printf("%d\n", ret);
	ret = (*p4)(x, y);
	printf("%d\n", ret);
	return 0;
}