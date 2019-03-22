//模拟实现strstr

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdlib.h>
//#include <assert.h>
//
//char* my_strstr(char* str, char* substr)
//{
//	assert(str&&substr);
//	const char* cur = str;
//	const char* s1 = str;
//	const char* s2 = substr;
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = substr;
//		while (*s1 && *s2 && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s1=='\0')
//		{
//			return NULL;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)cur;
//		}
//		cur++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char* str1 = "hello world";
//	char* str2 = "llo";
//	char* ret=my_strstr(str1, str2);
//	if (ret == NULL)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//
//	system("pause");
//	return 0;
//}

