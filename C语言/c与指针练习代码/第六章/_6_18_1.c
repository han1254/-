/**************************************** 
*  File Name  : find_char.c 
*  Creat Data : 2015.1.20 
*  Author     : ZY 
*****************************************/ 
 
/*请编写一个函数，它在一个字符串中进行搜索，查找所有
在一个给定字符集合中出现的字符。
它的基本想法是查找source字符串中匹配chars字符的第一个
字符，函数然后返回一个指向source中第一个匹配所找到的
位置的指针。如果source中的所有字符均不匹配chars中的任
何字符，函数就返回一个NULL指针。如果任何一个参数为
NULL，或任何一个参数所指向的字符串为空，函数也返回一
个NULL指针。*/
#include <stdlib.h>
#include <stdio.h>
 
#define TRUE 1
#define FALSE 0
 
char *find_char(const char *source, const char *chars)

{
     const char *temp = NULL;
     if(source == NULL || chars == NULL || source == "" || chars == "")
         return NULL;
     while(*source != '\0')

     {
     
          temp = chars;
         while(*temp != '\0')

         {
             if(*temp == *source)
                return (char *)source;
             else
                temp++;

          }
          source++;

      }

      return NULL;

}
 
int main()
{
	char *arr = "234567";
	char *brr = "356";
	printf("%c\n",*(find_char(arr,brr)));
	printf("%p\n",find_char(arr,brr));
	return 0;
}
 