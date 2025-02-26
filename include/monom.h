
#ifndef monom_h
#define monom_h

const int MAX_DEG = 9;

class Monom
{
	int degree;
	double k;
public:
	Monom(int _degree = 0, double _k = 0) : k(_k) { if (_degree <= 999) degree = _degree; else throw 1; };
	int get_deg();
	double get_k();
	int x_deg();
	int y_deg();
	int z_deg();
	bool is_deg_correct();
	Monom operator+(const Monom& m);
	Monom operator-(const Monom& m);
	Monom operator*(const Monom& m);
	Monom operator=(const Monom& m);
};

#endif
