
#ifndef monom_h
#define monom_h

#include <iostream>

const int MAX_DEG = 9;

class Monom
{
	int degree;
	double k;
public:
	Monom(int _degree = 0, double _k = 0) : k(_k) { if (_degree <= 999) degree = _degree; else throw std::logic_error("wrong degree"); };
	int get_deg() noexcept;
	double get_k() noexcept;
	int x_deg() const noexcept;
	int y_deg() const noexcept;
	int z_deg() const noexcept;
	bool is_deg_correct();
	Monom operator+(const Monom& m);
	Monom operator-(const Monom& m);
	Monom operator*(const Monom& m);
	Monom operator*(const double q);
	Monom& operator=(const Monom& m);
};

#endif
