#include "DoubleNode.h"

void DoubleNode::setValue(int value)
{
	this->element = value;
}

int DoubleNode::getValue()
{
	return this->element;
}
IDoubleNode *DoubleNode::getPrev()
{
	return this->prev;
}
IDoubleNode *DoubleNode::getNext()
{
	return this->next;
}
void DoubleNode::setPrev(IDoubleNode *prev)
{
	this->prev = prev;
}

void DoubleNode::setNext(IDoubleNode *next)
{
	this->next = next;
}
