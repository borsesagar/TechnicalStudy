#include<stdio.h>
#include "StaticLib.h"

int main(void)
{
	printf("In main.c\n");
	printf("Calling CallLib() from main.c\n");
	CallLib();
	return 0;
}
