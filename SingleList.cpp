#include "SingleNode.h"
#include "SingleList.h"
#include <cstdlib>


ISingleNode * SingleList::getHead()
{
	return head_node;
}

void SingleList::setHead(ISingleNode *head)
{
	head_node = head;
}
void SingleList::addHead(int value)
{
	ISingleNode *ptr = NULL;
	ptr = new SingleNode();
	ptr->setValue(value);
	ptr->setNext(head_node);
	setHead(ptr);
}

void SingleList::orderSort2()
{
	ISingleNode *prev, *cur, *tmp;
	prev = head_node;
	cur = prev->getNext();
	prev->setNext(cur->getNext());
	cur->setNext(head_node);
	head_node = cur;
	cur = prev->getNext();
	while (prev->getNext() != NULL && cur->getNext() != NULL)
	{
		tmp = cur->getNext();
		prev->setNext(tmp);
		cur->setNext(tmp->getNext());
		tmp->setNext(cur);
		prev = cur;
		cur = prev->getNext();

	}


}

void SingleList::orderSort3()
{
	ISingleNode * prev, *cur, *tmp;

	prev = head_node;
	tmp = prev->getNext();
	cur = tmp->getNext();

	prev->setNext(cur->getNext());
	tmp->setNext(prev);
	cur->setNext(tmp);
	head_node = cur;
	prev = tmp;
	tmp = prev->getNext();
	while (tmp->getNext() != NULL)
	{
		ISingleNode *ct;
		ct = tmp;
		int chk = 0;
		while (chk < 3 && ct->getNext() != NULL)
		{

			ct = ct->getNext();
			//if (ct->getNext() != NULL)

			chk++;


		}
		if (chk == 3)
		{
			prev = tmp->getNext();
			cur = prev->getNext();
			tmp->setNext(cur->getNext());
			tmp = tmp->getNext();
			prev->setNext(tmp->getNext());
			tmp->setNext(cur);
			cur->setNext(prev);
			tmp = prev;
		}
		else if (chk == 2)
		{
			prev = tmp->getNext();
			cur = prev->getNext();
			tmp->setNext(cur);
			prev->setNext(NULL);
			cur->setNext(prev);
			tmp = prev;
		}

	}

}

void SingleList::sequenceOrderSort()
{
	ISingleNode *prev, *cur, *tmp, *nxt, *cptr, *cnt_ptr;
	int order = 2;
	int ct;
	cur = head_node;
	tmp = head_node;
	cnt_ptr = head_node;
	cptr = tmp;
	while (cur != NULL && cur->getNext() != NULL)
	{
		ct = 0;
		while (ct < order)
		{
			if (cnt_ptr != NULL)
			{
				cnt_ptr = cnt_ptr->getNext();
				ct++;
			}
			else
			{
				order = ct;
				break;
			}
		}
		prev = NULL;
		tmp = cur;

		for (int i = 0; i < order; i++)
		{

			nxt = cur->getNext();
			cur->setNext(prev);
			prev = cur;
			cur = nxt;
			if (order == 2)
			{
				head_node = prev;
			}

		}
		cptr->setNext(prev);
		cptr = tmp;
		order++;

	}
}

void SingleList::reverse()
{
	ISingleNode *ptr = NULL;
	ISingleNode *nxt;
	while (head_node != NULL)
	{
		nxt = head_node->getNext();
		head_node->setNext(ptr);
		ptr = head_node;
		head_node = nxt;
	}
	head_node = ptr;

}



