#include "Interfaces01.h"
//#include "SingleNode.h" 

#include <cstdlib>

class SingleList : public ISingleList
{
	ISingleNode *head_node = NULL;
public:
	SingleList() {}
	~SingleList() {}
	ISingleNode *getHead();
	void setHead(ISingleNode *head);
	void addHead(int value);
	void orderSort2();
	void orderSort3();
	void sequenceOrderSort();
	void reverse();

};