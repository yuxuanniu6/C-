#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<string.h>
#include<assert.h>
/*实现一个函数，可以左旋字符串中的k个字符。
	例如：
	ABCD左旋一个字符得到BCDA
	ABCD左旋两个字符得到CDAB */
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
/*写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
	例如：给定s1 =AABCD和s2 = BCDAA，返回1
	给定s1=abcd和s2=ACBD，返回0.
	AABCD左旋一个字符得到ABCDA
	AABCD左旋两个字符得到BCDAA
	AABCD右旋一个字符得到DAABC
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
	// 第五题
	/*char str[100] = { 0 };
	printf("请输入字符串！！！\n");
	gets_s(str);
	int len = strlen(str);
	int k;
	printf("请输入你需要旋转多少个字符！！！\n");
	scanf("%d", &k);
	reverse_string(str, k, len);
	printf("%s", str);*/

	// 第六题
	char str1[100]="abcde", str2[100] = "BCDAA";
	int len = strlen(str1);
	printf("%d", string_isequal(str1, str2, len));
	return 0;
}