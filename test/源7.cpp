#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<assert.h>
////由于不知道传的是什么类型，所以形参为void*的形式
//void *my_memcpy(void* e1, const void* e2, size_t num)
//{
//	void* ret = e1;
//	assert(e1 && e2);
//	while (num--)
//	{
//		*(char*)e1 = *(char*)e2;
//		e1 = (char*)e1 + 1;
//		e2 = (char*)e2 + 1;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[10] = "yuxuan";
//	int arr2[] = { 0 };
//	my_memcpy(arr1+1, arr1, 2);//从后往前，y给第二个位置，arr1：yyxuan，在把y给第三个位置，arr1：yyyuan
//	printf("%s", arr1);
//
//	return 0;
//}
void* my_memmove(void* e1,const void* e2, size_t num)
{
	void* ret = e1;
	assert(e1 && e2);
	if (e1 < e2)
	{
		//从前往后拷贝
		*(char*)e1 = *(char*)e2;
		e1 = (char*)e1 + 1;
		e2 = (char*)e2 + 1;
	}
	else
	{
		//从后往前拷贝
		*((char*)+num) = *((char*)+num);
	}
	return ret;
}
int main()
{
	char arr1[10] = "yuxuan";
	int arr2[] = { 0 };
	my_memmove(arr1+1, arr1+2, 2);
	printf("%s", arr1);

	return 0;
}