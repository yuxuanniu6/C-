#define _CRT_SECURE_NO_WARNINGS 1 
//演示实例
#include<string.h>
#include <stdio.h>
#include<stdlib.h>
//比较大小，没有修改值，需要加const防止修改
int cmp(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);//记住需要解引用
}
void _swap(void* e1, void* e2,int size)
{
	for (int i = 0; i < size; i++)
	{
		char cmp = *((char *)e1+i);
		*((char*)e1 + i) = *((char*)e2 + i);
		*((char*)e2 + i) = cmp;
	}
}
void maopao(void *base,int size,int width,int (*cmp)(const void *,const void *))
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			//这里不知道base的类型，先用char*进行调整,所以下面的size也需要传进swap函数，一个一个字节的进行交换
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				_swap((char*)base + j * width, (char*)base+(j + 1) * width,width);
			}
		}
	}

}
struct MyStruct
{
	char arr[10];
	int age;
};
int sort_byage(const void* e1, const void* e2)
{
	return ((MyStruct*)e1)->age - ((MyStruct*)e2)->age;
}
int sort_byname(const void* e1, const void* e2)
{
	return strcmp(((MyStruct*)e1)->arr, ((MyStruct*)e2)->arr);
}
int main()
{
	int arr[] = { 1,3,5,7,9,1,2,3,4,5 };
	//maopao(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), cmp);
	/*for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}*/

	MyStruct s[3] = { {"zs",1},{"ls",9},{"ww",5} };
	//qsort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), sort_byage);
	qsort(s, sizeof(s) / sizeof(s[0]), sizeof(s[0]), sort_byname);
	for (int i = 0; i < 3; i++)
	{
		printf("%s %d\n", s[i].arr, s[i].age);
	}
	return 0;
}