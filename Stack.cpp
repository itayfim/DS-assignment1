#include "Stack.h"
#include "SBullet.h"

using namespace std;

Stack::Stack() // default c'tor
{
}

Stack::~Stack()
{
	MakeEmpty();
}

void Stack::MakeEmpty()
{
	SBullet* curr = top, * temp;
	while (curr != nullptr)
	{
		temp = curr;
		curr = curr->getNext();
		delete temp;
	}
	top = nullptr;
}

void Stack::Push(SBullet toInsert)
{
	SBullet* newBullet = new SBullet(toInsert);
	newBullet->setNext(top);
	top = newBullet;
}

SBullet Stack::Pop()
{
	if (this->isEmpty())
	{
		cout << "Cannot Pop, Stack is empty" << endl;
	}
	else {
		SBullet* temp;
		SBullet res(*top);
		temp = top;
		top = top->getNext();
		delete temp;
		return res;
	}
}
