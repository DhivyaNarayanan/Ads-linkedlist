#pragma once

#include "Interfaces01.h"
#include <cstdlib>

class DoubleNode : public IDoubleNode
{
private:
	int element;
	IDoubleNode * next;
	IDoubleNode *prev;
public:
	DoubleNode() {}
	~DoubleNode() {}
	void setValue(int value);
	int getValue();
	IDoubleNode *getPrev();
	IDoubleNode *getNext();
	void setPrev(IDoubleNode *prev);
	void setNext(IDoubleNode *next);
};


