#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<assert.h>
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	int len = 0;
//	while (*str++ != '\0')
//		len++;
//	return len;
//}
//int main()
//{
//	//char str1[]="hello world!";
//	//printf("%d", my_strlen(str1));
//	return 0;
//}
//char * my_strcpy(char* dest, const char* str)
//{
//	assert(dest != NULL && str != NULL);
//	char* s = dest;
//	while ((*dest++ = *str++) != '\0')
//	{
//		NULL;
//	}
//	return s;
//}
//int main()
//{
//	char str1[] = "hello world!";//���ƹ�����Ҫע����ܵ���������������㹻�󣬻��߽��ܲ��ˣ�����ȫ
//	char str2[] = "xiaobite!";
//	printf("%s", my_strcpy(str1, str2));
//	printf("\n%s", str1);
//	return 0;
//}
//int my_strcmp(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	while (*s1 == *s2)
//	{
//		if (*s1 == '\0')
//			return 0;
//		s1++;
//		s2++;
//	}
//	return *s1 - *s2;
//}
//int main()
//{
//	char *str1 = "abcde";
//	char *str2 = "abcdef";
//	int ret = my_strcmp(str1, str2);
//	if (ret > 0)
//		printf("str1��");
//	else if (ret < 0)
//		printf("str2��");
//	else
//		printf("str1��str2���");
//	return 0;
//}
//char* my_strcat(char* dest, const char* s)
//{
//	char* str = dest;
//	assert(dest && s);
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *s++)
//	{
//		;
//	}
//	return str;
//}
//int main()
//{
//	char s1[20] = "hello ";//������Ҫע��������һ�����ַ�����Ū���ַ��������У�����һ��Ҫ����
//	char* s2 = "bit.";
//	my_strcat(s1, s2);
//	printf("%s", s1);
//	return 0;
//}
char* my_strstr(const char* dest, const char* s)
{
	assert(dest && s);
	const char* str1 = NULL;
	const char* str2 = NULL;
	const char* p = dest;
	//���sΪ���ַ�����ֱ�ӷ���str1
	if (*s == '\0')
		return (char*)dest;
	while (*p)
	{
		str1 = p;
		str2 = s;
		while ((*str1 == *str2)&&str1&&str2)
		{
			str1++;
			str2++;
		}
		//���Ϊ�Ӵ����򷵻�����ƥ�������ַ���
		if (*str2 == '\0')
			return (char*)p;
		p++;
	}
	return NULL;
}
int main()
{
	char* s1 = "abbbbcde";
	char* s2 = "bb";
	printf("%s", my_strstr(s1, s2));
	return 0;
}