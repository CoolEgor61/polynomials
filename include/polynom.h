
#ifndef polynom_h
#define polynom_h

#include "list.h"
#include "monom.h"

class Polynom : TList<Monom>
{
public:
	Polynom()
	{
		TNode<Monom>* s = new TNode<Monom>;
		first = s;
		s->next = s;
		size = 1;
	}
	~Polynom()
	{
		while (size) this->pop_front();
	}
	Polynom(const Polynom& p)
	{
		while ((p.next) != NULL) {
			TNode<Monom>* new_node = new TNode<Monom>(p.value,p.next);
			//p.next = p.next.next;
			if (this->first == NULL) this->first = p.first;
			size++;
		}
	}
};

#endif
