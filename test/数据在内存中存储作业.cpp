#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<string.h>
#include<assert.h>
/*ʵ��һ�����������������ַ����е�k���ַ���
	���磺
	ABCD����һ���ַ��õ�BCDA
	ABCD���������ַ��õ�CDAB */
void reverse_string(char* s,int k,int len)
{
	assert(k <= len);
	while (k > 0)
	{
		int a = s[0];
		for (int i = 1; i < len; i++)
		{
			s[i - 1] = s[i];
		}
		s[len - 1] = a;
		k--;
	}
}
/*дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
	���磺����s1 =AABCD��s2 = BCDAA������1
	����s1=abcd��s2=ACBD������0.
	AABCD����һ���ַ��õ�ABCDA
	AABCD���������ַ��õ�BCDAA
	AABCD����һ���ַ��õ�DAABC
*/
int string_isequal(char* s1, const char *s2,int len)
{
	int k = 1;
	while (k<=len)
	{
		int start = s1[0];
		for (int i = 1; i < len; i++)
		{
			s1[i - 1] = s1[i];
		}
		s1[len - 1] = start;
		if (strcmp(s1, s2) == 0)
		{
			return 1;
		}
		k++;
	}
	return 0;
}
int main()
{
	// ������
	/*char str[100] = { 0 };
	printf("�������ַ���������\n");
	gets_s(str);
	int len = strlen(str);
	int k;
	printf("����������Ҫ��ת���ٸ��ַ�������\n");
	scanf("%d", &k);
	reverse_string(str, k, len);
	printf("%s", str);*/

	// ������
	char str1[100]="abcde", str2[100] = "BCDAA";
	int len = strlen(str1);
	printf("%d", string_isequal(str1, str2, len));
	return 0;
}