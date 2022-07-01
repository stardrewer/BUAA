﻿#/*
	教材 第4章 堆栈和队列 栈
*/
#include "4_Stack.hpp"

// <数据结构教程>p87 栈的一系列操作
void Init(int& top) {
	top = -1;
}
bool IsEmpty(int top) {
	return top == -1;
}
bool IsFull(int top) {
	return top == M - 1;
}
bool GetTop(ElemType stack[], int& top, ElemType& item) {
	if (IsEmpty(top))
		return false;
	item = stack[top];
	return true;
}
bool Push(ElemType stack[], int& top, ElemType item) {
	if (IsFull(top))
		return false;
	stack[top++] = item;
	return true;
}
bool Pop(ElemType stack[], int& top, ElemType& item) {
	if (IsEmpty(top))
		return false;
	item = stack[top--];
	return true;
}

// <数据结构教程>p89 两个栈共享一个空间
bool Push2(ElemType stack[], int top[], int i, ElemType item) {
	if (top[0] == top[1] - 1)
		return false;
	if (i == 1)
		top[0]++;
	else
		top[1]--;
	stack[top[i - 1]] = item;
	return true;
}
bool Pop2(ElemType stack[], int top[], int i, ElemType& item) {
	if (i == 1) {
		if (top[0] == -1)
			return false;
		item = stack[top[0]--];
		return true;
	}
	else {
		if (top[1] == 5) // 令M=5, 方便调试
			return false;
		item = stack[top[1]++];
		return true;
	}
}
void PushPop2Test() {
	ElemType stack[5] = {};
	int top[2] = { -1, 5 };
	Push2(stack, top, 1, 1);
	Push2(stack, top, 2, 2);
	Push2(stack, top, 1, 3);
	Push2(stack, top, 2, 4);
	Push2(stack, top, 1, 5);
	Push2(stack, top, 2, 6);
	for (ElemType item : stack)
		cout << item << " ";
	cout << endl;

	ElemType item;
	cout << top[0] << " " << top[1] << endl;
	Pop2(stack, top, 1, item);
	cout << top[0] << " " << top[1] << endl;
}

// <数据结构教程>p93 栈的链式存储的一系列操作
void InitLink(LinkNode& top) {
	top = NULL;
}
bool EmptyLink(LinkNode top) {
	return top == NULL;
}
bool GetTopLink(LinkNode top, ElemType& item) {
	if (EmptyLink(top))
		return false;
	item = top->data;
	return true;
}
bool PushLink(LinkNode& top, ElemType item) {
	LinkNode newptr = (LinkNode)malloc(sizeof(Node));
	if (!newptr)
		return false;
	newptr->data = item;
	newptr->next = top;
	top = newptr;
	return true;
}
bool PopLink(LinkNode& top, ElemType& item) {
	if (EmptyLink(top))
		return false;
	LinkNode p = top;
	item = top->data;
	top = top->next;
	free(p);
	return true;
}

int main() {
	PushPop2Test();
}