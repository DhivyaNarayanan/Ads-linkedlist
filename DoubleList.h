#include "Interfaces01.h"
#include "DoubleNode.h" 
#include <cstdlib>

class DoubleList : public IDoubleList
{

	IDoubleNode *head_node = NULL;
	IDoubleNode *tail_node = NULL;

public:
	DoubleList()
	{
		head_node = NULL;
		tail_node = NULL;
	}
	~DoubleList(){}
	IDoubleNode *getHead();
	IDoubleNode *getTail();
	void setHead(IDoubleNode *head);
	void setTail(IDoubleNode *tail);
	void addSorted(int value);
	void orderSort2();
	void orderSort3();
	void sequenceOrderSort();
	void reverse();
};


