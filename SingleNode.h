#include "Interfaces01.h"
#include <cstdlib>

class SingleNode : public ISingleNode
{
private:
	int element;
	ISingleNode * next;

public:
	SingleNode() {}
	~SingleNode() {}
	void setValue(int value);
	int getValue();
	ISingleNode *getNext();
	void setNext(ISingleNode *next);
};