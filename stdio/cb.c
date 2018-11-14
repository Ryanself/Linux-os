#include<stdio.h>

int callback_1(int x) //callback func1
{
	printf("hello, that's my first callback_1 func: %d.\n", x);
	return 0;
}

int handle(int y, int (*callback)(int))
{
	printf("ENTER CALL BACK HANDLER!\n");
	callback(y);
	printf("leave call back\n");
	return 0;
}

int main(){
	int a = 3;
	handle(a, callback_1);
	return 0;
}
