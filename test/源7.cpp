#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<assert.h>
////���ڲ�֪��������ʲô���ͣ������β�Ϊvoid*����ʽ
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
//	my_memcpy(arr1+1, arr1, 2);//�Ӻ���ǰ��y���ڶ���λ�ã�arr1��yyxuan���ڰ�y��������λ�ã�arr1��yyyuan
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
		//��ǰ���󿽱�
		*(char*)e1 = *(char*)e2;
		e1 = (char*)e1 + 1;
		e2 = (char*)e2 + 1;
	}
	else
	{
		//�Ӻ���ǰ����
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