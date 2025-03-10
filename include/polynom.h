
#ifndef polynom_h
#define polynom_h

#include "list.h"
#include "monom.h"

class Polynom
{
public:
	TList<Monom> Plnm;
	TList<Monom> get_Plnm() noexcept;
	Polynom();
	Polynom(const Polynom& p);
	Polynom(const TList<Monom>& Plnm);
	Polynom operator+(Polynom& p);
	Polynom operator-(Polynom& p);
	Polynom operator*(const double q);
	Polynom operator*(Polynom& p);
};

#endif
