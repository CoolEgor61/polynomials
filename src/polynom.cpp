#include "polynom.h"

TList<Monom> Polynom::get_Plnm() noexcept { return Plnm; };

Polynom::Polynom()
{
	Monom s;
	Plnm.push_front(s);
}
Polynom::Polynom(TList<Monom>& _Plnm)
{
	Monom s, f;
	Plnm.push_front(s);
	TNode<Monom>* next_n = _Plnm.first;
	f = next_n->value;
	while (next_n != NULL)
	{
		Plnm.push_back(f);
		next_n = next_n->next;
		if (next_n != NULL) f = next_n->value;
	}
}
Polynom::Polynom(const Polynom& p) : Plnm(p.Plnm) {};
Polynom Polynom::operator+(Polynom& p)
{
	Polynom res;
	Monom val_t, val_p;
	TNode<Monom> *next_this = this->Plnm.first->next, *next_p = p.Plnm.first->next;
	val_t = next_this->value; val_p = next_p->value;
	while (next_this != NULL && next_p != NULL)
	{
		if (val_t.get_deg() == val_p.get_deg())
		{
			Monom tmp = val_t+val_p;
			if (tmp.get_k() != 0) res.Plnm.push_back(tmp);
			next_this = next_this->next; next_p = next_p->next;
			if (next_this != NULL) val_t = next_this->value;
			if (next_p != NULL) val_p = next_p->value;
		}
		else if (val_t.get_deg() > val_p.get_deg())
		{
			Monom tmp(val_t.get_deg(), val_t.get_k());
			res.Plnm.push_back(tmp);
			next_this = next_this->next;
			if (next_this != NULL) val_t = next_this->value;
		}
		else {
			Monom tmp(val_p.get_deg(), val_p.get_k());
			res.Plnm.push_back(tmp);
			next_p = next_p->next;
			if (next_p != NULL) val_p = next_p->value;
		}
	}
	while (next_this != NULL)
	{
		Monom tmp(val_t.get_deg(), val_t.get_k());
		res.Plnm.push_back(tmp);
		next_this = next_this->next;
		if (next_this != NULL) val_t = next_this->value;
	}
	while (next_p != NULL)
	{
		Monom tmp(val_p.get_deg(), val_p.get_k());
		res.Plnm.push_back(tmp);
		next_p = next_p->next;
		if (next_p != NULL) val_p = next_p->value;
	}
	return res;
}

Polynom Polynom::operator-(Polynom& p)
{
	Polynom res;
	Monom val_t, val_p;
	TNode<Monom>* next_this = this->Plnm.first->next, * next_p = p.Plnm.first->next;
	val_t = next_this->value; val_p = next_p->value;
	while (next_this != NULL && next_p != NULL)
	{
		if (val_t.get_deg() == val_p.get_deg())
		{
			Monom tmp = val_t - val_p;
			if (tmp.get_k() != 0) res.Plnm.push_back(tmp);
			next_this = next_this->next; next_p = next_p->next;
			if (next_this != NULL) val_t = next_this->value;
			if (next_p != NULL) val_p = next_p->value;
		}
		else if (val_t.get_deg() > val_p.get_deg())
		{
			Monom tmp(val_t.get_deg(),-val_t.get_k());
			res.Plnm.push_back(tmp);
			next_this = next_this->next;
			if (next_this != NULL) val_t = next_this->value;
		}
		else {
			Monom tmp(val_p.get_deg(), -val_p.get_k());
			res.Plnm.push_back(tmp);
			next_p = next_p->next;
			if (next_p != NULL) val_p = next_p->value;
		}
	}
	while (next_this != NULL)
	{
		Monom tmp(val_t.get_deg(), -val_t.get_k());
		res.Plnm.push_back(tmp);
		next_this = next_this->next;
		if (next_this != NULL) val_t = next_this->value;
	}
	while (next_p != NULL)
	{
		Monom tmp(val_p.get_deg(), -val_p.get_k());
		res.Plnm.push_back(tmp);
		next_p = next_p->next;
		if (next_p != NULL) val_p = next_p->value;
	}
	return res;
}

Polynom Polynom::operator*(const double q)
{
	Polynom res; Monom val_t;
	TNode<Monom> *next_this = this->Plnm.first->next;
	while (next_this != NULL)
	{
		val_t = next_this->value;
		res.Plnm.push_back(val_t*q);
		next_this = next_this->next;
	}
	return res;
}
Polynom Polynom::operator*(Polynom& p)
{
	Polynom res;
	Monom val_t, val_p;
	TNode<Monom> *next_this = this->Plnm.first->next;
	TNode<Monom>* next_p = p.Plnm.first->next, *next_p_reserve = p.Plnm.first->next;
	while (next_this != NULL)
	{
		val_t = next_this->value;
		while (next_p != NULL)
		{
			val_p = next_p->value;
			res.Plnm.push_back(val_t * val_p);
			next_p = next_p->next;
		}
		next_this=next_this->next;
		next_p = next_p_reserve;
	}
	return res;
}