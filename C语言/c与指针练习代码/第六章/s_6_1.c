/**
 * 计算一个字符串的长度
 */

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char *str) 
{
	int length = 0;
	while(*str++ != '\0') 
	{
		length++;
	}
	return length;
}

int main()
{
	char* str = "abcde";
	printf("%d\n", my_strlen(str));
	return 0;
}