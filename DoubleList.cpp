
#include "DoubleNode.h"
#include "DoubleList.h"
#include <cstdlib>
#include <iostream>

using namespace std;


IDoubleNode * DoubleList::getHead()
{
	return head_node;
}

IDoubleNode * DoubleList::getTail()
{
	return tail_node;
}

void DoubleList::setHead(IDoubleNode *head)
{
	head_node = head;
}

void DoubleList::setTail(IDoubleNode * tail)
{
	tail_node = tail;
}

void DoubleList::addSorted(int value)
{
	
	IDoubleNode  *ptr = NULL;
	IDoubleNode *nn = new DoubleNode();
	
	if (head_node == NULL)
	{
		nn->setValue(value);
		nn->setNext(NULL);
		nn->setPrev(NULL);
		head_node = nn;
		tail_node = nn;
	}
	else
	{
		if (value <= head_node->getValue())
		{
			ptr = head_node;
			nn->setValue(value);
			nn->setNext(ptr);
			nn->setPrev(NULL);
			ptr->setPrev(nn);
			head_node = nn;
		}
		else if (value > head_node->getValue())
		{
			ptr = head_node;
			while (ptr!= NULL)
			{
				if (value >= ptr->getValue())
				{
					if (ptr->getNext() == NULL)
					{
						nn->setValue(value);
						ptr->setNext(nn);
						nn->setPrev(ptr);
						nn->setNext(NULL);
						tail_node = nn;
						break;
					}
					else
						ptr = ptr->getNext();
				}
				else
				{
					nn->setValue(value);
					nn->setNext(ptr);
					ptr->getPrev()->setNext(nn);
					nn->setPrev(ptr->getPrev());
					ptr->setPrev(nn);
					break;
				}
			}
		}
	}
}

void DoubleList::orderSort2()
{
	IDoubleNode *p, *cur, *tmp;
	p = head_node;
	cur = p->getNext();

	p->setNext(cur->getNext());
	cur->getNext()->setPrev(p);
	cur->setNext(p);
	p->setPrev(cur);
	cur->setPrev(NULL);
	head_node = cur;
	cur = p->getNext();
	while (p->getNext() != NULL && cur->getNext() != NULL)
	{
		if (cur->getNext() != tail_node)
		{

			tmp = cur->getNext();
			p->setNext(tmp);
			tmp->setPrev(p);
			cur->setNext(tmp->getNext());
			tmp->getNext()->setPrev(cur);
			tmp->setNext(cur);
			cur->setPrev(tmp);
			p = cur;
			cur = p->getNext();
		}
		else
		{
			tmp = cur->getNext();
			p->setNext(tmp);
			tmp->setPrev(p);
			cur->setNext(NULL);
			//tmp->Next->Prev = cur;
			tmp->setNext(cur);
			cur->setPrev(tmp);

			tail_node = cur;
			cur = cur->getNext();
			break;

		}
	}
	
}
void DoubleList::orderSort3()
{
	
	IDoubleNode * p = NULL, *cur = NULL, *tmp = NULL;

	p = head_node;
	tmp = p->getNext();
	cur = tmp->getNext();

	p->setNext(cur->getNext());
	cur->getNext()->setPrev(p);
	tmp->setNext(p);
	p->setPrev(tmp);
	cur->setNext(tmp);
	tmp->setPrev(cur);
	cur->setPrev(NULL);
	head_node = cur;
	//p = tmp;
	tmp = tmp->getNext();
	while (p->getNext() != NULL)
	{
		IDoubleNode *ct;
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
			if (ct != tail_node)
			{
				p = tmp->getNext();
				cur = p->getNext();
				tmp->setNext(cur->getNext());
				cur->getNext()->setPrev(tmp);
				tmp = tmp->getNext();
				p->setNext(tmp->getNext());
				tmp->getNext()->setPrev(p);
				tmp->setNext(cur);
				cur->setPrev(tmp);
				cur->setNext(p);
				p->setPrev(cur);
				tmp = p;
			}
			else if (ct == tail_node)
			{
				p = tmp->getNext();
				cur = p->getNext();
				tmp->setNext(ct);
				ct->setPrev(tmp);
				//tmp = tmp->Next;
				//tmp->getNext()->setPrev(p);
				ct->setNext(cur);
				cur->setPrev(ct);
				cur->setNext(p);
				p->setPrev(cur);
				p->setNext(NULL);
				tail_node = p;
				break;
			}

		}
		else if (chk == 2)
		{
			p = tmp->getNext();
			//cur = p->Next;
			tmp->setNext(ct);
			ct->setPrev(tmp);
			ct->setNext(p);
			p->setPrev(ct);
			p->setNext(NULL);
			tail_node = p;
			break;
		}

	}

}

void DoubleList::sequenceOrderSort()
{
	IDoubleNode *p = NULL, *cur = NULL, *tmp = NULL, *nxt = NULL, *cptr = NULL, *cnt_ptr1 = NULL, *cnt_ptr2 = NULL, *tn = NULL;
	int order = 2;
	int ct;
	cur = head_node;
	tmp = head_node;
	cnt_ptr1 = head_node;
	cnt_ptr2 = NULL;
	cptr = tmp;
	p = NULL;

	while (cur != NULL && cur->getNext() != NULL)
	{
		ct = 0;
		while (ct < order)
		{
			if (cnt_ptr1 != NULL)
			{
				cnt_ptr2 = cnt_ptr1;
				cnt_ptr1 = cnt_ptr1->getNext();
				ct++;
			}
			else
			{
				order = ct;
				break;
			}
		}//end of while2
		p = NULL;
		tmp = cur;
		if (order == 2)
		{
			for (int i = 0; i < order; i++)
			{

				if (i == 0)
				{
					nxt = cur->getNext();
					cur->setNext(p);
					p = cur;
					cur = nxt;
				}
				else if (i == 1)
				{
					nxt = cur->getNext();
					cur->setNext(p);
					p->setPrev(cur);
					p = cur;             //cur->prev=null
					cur = nxt;

					if (cnt_ptr2 != tail_node)
					{
						p->setPrev(NULL);
						head_node = p;
					}
				}
			}//eof for
		}//eof if
		else
		{

			for (int i = 0; i < order; i++)
			{
		
				if (i == 0)
				{
					nxt = cur->getNext();
					cur->setNext(p);
					p = cur;
					cur = nxt;
				}
				else
				{
					nxt = cur->getNext();
					cur->setNext(p);
					p->setPrev(cur);
					p = cur;
					cur = nxt;
				}
												
			}

		}//eof for
		if (cnt_ptr2 == tail_node)
		{
			tail_node = tmp;
			tmp->setNext(NULL);
		}
		cptr->setNext(p);
		if (p->getPrev() != NULL)
			p->setPrev(cptr);
		cptr = tmp;
		order++;

	}
	if (cur != NULL &&cur->getNext() == NULL)
	{
		cptr->setNext(cur);
		cur->setPrev(cptr);
		tail_node = cur;
	}

}
void DoubleList::reverse()
{
	IDoubleNode *cur = head_node;
	IDoubleNode *p = NULL;
	IDoubleNode *nxt = NULL;
	IDoubleNode * tmp = NULL;
	tail_node = head_node;
	while (cur != NULL)
	{
		nxt = cur->getNext();
		tmp = cur->getNext();
		if (tmp != NULL)
			tmp->setPrev(p);
		cur->setPrev(cur->getNext());
		cur->setNext(p);
		p = cur;
		cur = nxt;
	}
	head_node = p;
	p->setPrev(NULL);

}