#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include "SBullet.h"
#include "List.h"

class Stack
{
private:
	SBullet* top = nullptr;

public:
	Stack();
	Stack(const Stack& other) = delete;
	~Stack();
	bool isEmpty() const { return (top == nullptr); }
	void MakeEmpty(); 
	void Push(SBullet toInsert);
	SBullet Pop();
};
#endif