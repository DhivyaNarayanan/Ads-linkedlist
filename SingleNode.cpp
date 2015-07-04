#include "SingleNode.h"

void SingleNode::setValue(int value)
{
	this->element = value;
}

int SingleNode::getValue()
{
	return this->element;
}

ISingleNode *SingleNode::getNext()
{
	return this->next;
}

void SingleNode::setNext(ISingleNode *next)
{
	this->next = next;
}
