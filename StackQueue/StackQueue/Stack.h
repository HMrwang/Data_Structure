#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* st);
void StackDestroy(Stack* st);
void StackPush(Stack* st, STDataType x);
void StackPop(Stack* st);
STDataType StackTop(Stack* st);
int StackSize(Stack* st);
bool StackEmpety(Stack* st);
