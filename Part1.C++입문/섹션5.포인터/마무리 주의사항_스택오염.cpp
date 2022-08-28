#include <iostream>
using namespace std;

int* TestPointer()
{
	int a = 1;
	return &a;
}
void TestWrong(int* ptr)
{
	int arr[100] = {};
	arr[99] = 0xAAAAAAAA;
	*ptr = 0x12341234;
}

int main()
{
	int* pointer = TestPointer(); //스택이라서 사라질 a의 주소에 연결해버림.
	TestWrong(pointer);

	return 0;
}