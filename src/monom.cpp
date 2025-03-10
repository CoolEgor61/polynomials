#include "monom.h"
#include <iostream>

int Monom::get_deg() noexcept { return degree; };
double Monom::get_k() noexcept { return k; };
int Monom::x_deg() const noexcept { return degree / 100; };
int Monom::y_deg() const noexcept { return (degree / 10) % 10; };
int Monom::z_deg() const noexcept { return degree % 10; };
bool Monom::is_deg_correct() { return (x_deg() <= MAX_DEG && y_deg() <= MAX_DEG && z_deg() <= MAX_DEG); };
Monom Monom::operator+(const Monom& m)
{
	Monom res;
	if (degree == m.degree) {
		if (k + m.k == 0) return Monom(0,0);
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
		if (k - m.k == 0) return Monom(0, 0);
		res.k = k - m.k;
		res.degree = degree;
		return res;
	}
	else throw std::logic_error("different degrees");
}
Monom Monom::operator*(const Monom& m)
{
	Monom res;
	if (this->x_deg() + m.x_deg() <= MAX_DEG && this->y_deg() + m.y_deg() <= MAX_DEG && this->z_deg() + m.z_deg() <= MAX_DEG)
	{
		if (k * m.k == 0) return Monom(0, 0);
		res.k = k * m.k;
		res.degree = ((this->degree) + (m.degree));
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