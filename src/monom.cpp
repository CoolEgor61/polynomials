#include "monom.h"

int Monom::get_deg() { return degree; };
double Monom::get_k() { return k; };
int Monom::x_deg() { return degree / 100; };
int Monom::y_deg() { return (degree / 10) % 10; };
int Monom::z_deg() { return degree % 10; };
bool Monom::is_deg_correct() { return (x_deg() <= MAX_DEG && y_deg() <= MAX_DEG && z_deg() <= MAX_DEG); };
Monom Monom::operator+(const Monom& m)
{
	Monom res;
	if (degree == m.degree) {
		res.k = k + m.k;
		res.degree = degree;
		return res;
	}
	else throw 1;
}
Monom Monom::operator-(const Monom& m)
{
	Monom res;
	if (degree == m.degree) {
		res.k = k - m.k;
		res.degree = degree;
		return res;
	}
	else throw 1;
}
Monom Monom::operator*(const Monom& m)
{
	Monom res;
	if (this->x_deg() + ((m.degree) / 100) <= MAX_DEG && this->y_deg() + ((m.degree / 10) % 10) <= MAX_DEG && this->z_deg() + ((m.degree) % 10) <= MAX_DEG)
	{
		res.k = k * m.k;
		res.degree = (this->x_deg() + ((m.degree) / 100)) * 100 + (this->y_deg() + ((m.degree / 10) % 10)) * 10 + (this->z_deg() + ((m.degree) % 10));
		return res;
	}
	else throw 1;
}
Monom Monom::operator=(const Monom& m)
{
	Monom res;
	res.degree = m.degree;
	res.k = k;
	return res;
}