#include <iostream>
using namespace std;

// 문자열의 길이 함수 만들기 strlen
int StringLength(char* str)
{
	if (str == nullptr)
		return NULL;
	int idx = 0;
	while (str[idx] != '\0')
		idx++;
	return idx;
}
//문자열복사하기 strcpy_s
char* StringCopy(char* dest, char* src)
{
	int idx = 0;
	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';

	return dest;

	/*	
	char* ret = dest;

	 while(*src!='\0')
	{
		*dest = *src;
		dest++;
		src++
	}
	  *dest='\0'
	  
	return ret;  
	*/	
}
//문자열 뒤에 이어쓰기 strcat
char* StringCat(char* dest,char* src)
{
	char* ret = dest;

	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return ret;
}
//문자열 비교 strcomp
bool StringCmp(char* dest, char* src)
{
	while (*dest != '\0' || *src != '\0')
	{
		if (*dest > *src)
			return 1;
		else if (*dest < *src)
			return -1;
		dest++;
		src++;
	}
	return 0;
}
//문자열 뒤집기
void ReverseString(char* str)
{
	int len = StringLength(str);
	char tmp;
	for (int i = 0; i < len / 2; i++)
	{
		tmp = *(str + i);
		*(str + i) = *(str + len - 1 - i);
		*(str + len - 1 - i) = tmp;
	}
}

int main()
{
	char a[100] = "hello";
	char b[100] = "hella";
	int len = StringLength(a);
	cout << len<<'\n';
	
	//StringCopy(b, a);
	cout << b << '\n';
	//StringCat(a, b);
	cout << a << '\n';
	//int value = StringCmp(a, b);
	//cout << value;
	ReverseString(b);
	cout << b;

	return 0;
}
