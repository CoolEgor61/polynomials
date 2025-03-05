#include "monom.h"
#include <iostream>

int Monom::get_deg() noexcept { return degree; };
double Monom::get_k() noexcept { return k; };
int Monom::x_deg() noexcept { return degree / 100; };
int Monom::y_deg() noexcept { return (degree / 10) % 10; };
int Monom::z_deg() noexcept { return degree % 10; };
bool Monom::is_deg_correct() { return (x_deg() <= MAX_DEG && y_deg() <= MAX_DEG && z_deg() <= MAX_DEG); };
Monom Monom::operator+(const Monom& m)
{
	Monom res;
	if (degree == m.degree) {
		if (degree == 0 || k + m.k == 0) return Monom(0,0);
		res.k = k + m.k;
		res.degree = degree;
		return res;
	}
	else throw std::logic_error("different degrees");
}
Monom Monom::operator-(const Monom& m)
{
	Monom res;
	if (degree == m.degree) {
		if (degree == 0 || k - m.k == 0) return Monom(0, 0);
		res.k = k - m.k;
		res.degree = degree;
		return res;
	}
	else throw std::logic_error("different degrees");
}
Monom Monom::operator*(const Monom& m)
{
	Monom res;
	if (this->x_deg() + ((m.degree) / 100) <= MAX_DEG && this->y_deg() + ((m.degree / 10) % 10) <= MAX_DEG && this->z_deg() + ((m.degree) % 10) <= MAX_DEG)
	{
		if (degree == 0 || k * m.k == 0) return Monom(0, 0);
		res.k = k * m.k;
		res.degree = (this->x_deg() + ((m.degree) / 100)) * 100 + (this->y_deg() + ((m.degree / 10) % 10)) * 10 + (this->z_deg() + ((m.degree) % 10));
		return res;
	}
	else throw std::logic_error("different degrees");
}
Monom Monom::operator*(const double q)
{
	Monom res(*this);
	res.k *= q;
	return res;
}
Monom& Monom::operator=(const Monom& m)
{
	if (this != &m)
	{
		k = m.k;
		degree = m.degree;
	}
	return *this;
}