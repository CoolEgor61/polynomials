#include "list.h"
#include "polynom.h"

TList<Monom> Polynom::get_Plnm() noexcept { return Plnm; };

Polynom::Polynom()
{
	Monom s;
	Plnm.push_front(s);
}
Polynom::Polynom(const TList<Monom>& _Plnm)
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
	TList<Monom>::mIterator it1 = this->Plnm.begin(), it2 = p.Plnm.begin();
	++it1; ++it2;
	while (it1 != this->Plnm.end() && it2 != p.Plnm.end())
	{
		if (it1->value.get_deg() == it2->value.get_deg()) {
			res.Plnm.push_back(it1->value + it2->value);
			++it1; ++it2;
		}
		else if (it1->value.get_deg() > it2->value.get_deg()) {
			res.Plnm.push_back(it1->value);
			++it1;
		}
		else {
			res.Plnm.push_back(it2->value);
			++it2;
		}
	}
	while (it1 != this->Plnm.end())
	{
		res.Plnm.push_back(it1->value);
		++it1;
	}
	while (it2 != p.Plnm.end())
	{
		res.Plnm.push_back(it2->value);
		++it2;
	}
	return res;
}
Polynom Polynom::operator-(Polynom& p)
{
	Polynom res;
	TList<Monom>::mIterator it1 = this->Plnm.begin(), it2 = p.Plnm.begin();
	++it1; ++it2;
	while (it1 != this->Plnm.end() && it2 != p.Plnm.end())
	{
		if (it1->value.get_deg() == it2->value.get_deg()) {
			res.Plnm.push_back(it1->value - it2->value);
			++it1; ++it2;
		}
		else if (it1->value.get_deg() > it2->value.get_deg()) {
			res.Plnm.push_back(it1->value*(-1));
			++it1;
		}
		else {
			res.Plnm.push_back(it2->value*(-1));
			++it2;
		}
	}
	while (it1 != this->Plnm.end())
	{
		res.Plnm.push_back(it1->value*(-1));
		++it1;
	}
	while (it2 != p.Plnm.end())
	{
		res.Plnm.push_back(it2->value*(-1));
		++it2;
	}
	return res;
}

Polynom Polynom::operator*(const double q)
{
	Polynom res;
	TList<Monom>::mIterator it1 = this->Plnm.begin(); ++it1;
	while (it1 != this->Plnm.end())
	{
		res.Plnm.push_back(it1->value * (q));
		++it1;
	}
	return res;
}
Polynom Polynom::operator*(Polynom& p)
{
	Polynom res;
	TList<Monom>::mIterator it1 = this->Plnm.begin(), it2 = p.Plnm.begin();
	++it1; ++it2;
	while (it1 != this->Plnm.end())
	{
		while (it2 != p.Plnm.end())
		{
			res.Plnm.push_back(it1->value * it2->value);
			++it2;
		}
		++it1;
		it2 = p.Plnm.begin(); ++it2;
	}
	return res;
}