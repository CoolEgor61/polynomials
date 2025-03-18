#include <iostream>
#include "polynom.h"

int main()
{
	std::cout << "Choose operation with polynom/polynoms:\n1. Add 2 polynoms\n2. Sub 2 polynoms\n3. Mul polynom with const\n4. Mul 2 polynoms\n";
	int n;
	std::cin >> n;
	switch (n)
	{
	case 1: {
		Polynom fst, scnd;
		std::cout << "Input amount of monoms in first polynom\n";
		int q;
		std::cin >> q;
		std::cout << "Input coeff and degrees of monom xyz\n";
		int k, deg;
		for (int i = 0; i < q; i++)
		{
			std::cin >> k >> deg;
			Monom a(deg, k);
			fst.Plnm.push_back(a);
		}
		std::cout << "Input amount of monoms in second polynom\n";
		std::cin >> q;
		std::cout << "Input coeff and degrees of monom xyz\n";
		for (int i = 0; i < q; i++)
		{
			std::cin >> k >> deg;
			Monom a(deg, k);
			scnd.Plnm.push_back(a);
		}
		Polynom ans(fst + scnd);
		std::cout << "Answer: ";
		TNode<Monom>* tmp = ans.Plnm.first->next;
		while(tmp!=NULL) {
			if (tmp->value.get_k() == 0) tmp = tmp->next;
			else {
				std::cout << tmp->value.get_k() << "x^" << tmp->value.x_deg() << "*y^" << tmp->value.y_deg() << "*z^" << tmp->value.z_deg();
				tmp = tmp->next;
				if (tmp != NULL && tmp->value.get_k() >= 0) std::cout << "+";
			}
		}
		break;
	}
	case 2:
	{
		Polynom fst, scnd;
		std::cout << "Input amount of monoms in first polynom\n";
		int q;
		std::cin >> q;
		std::cout << "Input coeff and degrees of monom xyz\n";
		int k, deg;
		for (int i = 0; i < q; i++)
		{
			std::cin >> k >> deg;
			Monom a(deg, k);
			fst.Plnm.push_back(a);
		}
		std::cout << "Input amount of monoms in second polynom\n";
		std::cin >> q;
		std::cout << "Input coeff and degrees of monom xyz\n";
		for (int i = 0; i < q; i++)
		{
			std::cin >> k >> deg;
			Monom a(deg, k);
			scnd.Plnm.push_back(a);
		}
		Polynom ans(fst - scnd);
		std::cout << "Answer: ";
		TNode<Monom>* tmp = ans.Plnm.first->next;
		while (tmp != NULL) {
			if (tmp->value.get_k() == 0) tmp = tmp->next;
			else {
				std::cout << tmp->value.get_k() << "x^" << tmp->value.x_deg() << "*y^" << tmp->value.y_deg() << "*z^" << tmp->value.z_deg();
				tmp = tmp->next;
				if (tmp != NULL && tmp->value.get_k() >= 0) std::cout << "+";
			}
		}
	}
		break;
	case 3:
	{
		Polynom fst;
		std::cout << "Input amount of monoms in polynom\n";
		int q;
		std::cin >> q;
		std::cout << "Input coeff and degrees of monom xyz\n";
		int k, deg;
		for (int i = 0; i < q; i++)
		{
			std::cin >> k >> deg;
			Monom a(deg, k);
			fst.Plnm.push_back(a);
		}
		std::cout << "Input coeff\n";
		std::cin >> q;
		Polynom ans(fst * q);
		std::cout << "Answer: ";
		TNode<Monom>* tmp = ans.Plnm.first->next;
		while (tmp != NULL) {
			if (tmp->value.get_k() == 0) tmp = tmp->next;
			else {
				std::cout << tmp->value.get_k() << "x^" << tmp->value.x_deg() << "*y^" << tmp->value.y_deg() << "*z^" << tmp->value.z_deg();
				tmp = tmp->next;
				if (tmp != NULL && tmp->value.get_k() >= 0) std::cout << "+";
			}
		}
	}
	break;
	case 4:
	{
		Polynom fst, scnd;
		std::cout << "Input amount of monoms in first polynom\n";
		int q;
		std::cin >> q;
		std::cout << "Input coeff and degrees of monom xyz\n";
		int k, deg;
		for (int i = 0; i < q; i++)
		{
			std::cin >> k >> deg;
			Monom a(deg, k);
			fst.Plnm.push_back(a);
		}
		std::cout << "Input amount of monoms in second polynom\n";
		std::cin >> q;
		std::cout << "Input coeff and degrees of monom xyz\n";
		for (int i = 0; i < q; i++)
		{
			std::cin >> k >> deg;
			Monom a(deg, k);
			scnd.Plnm.push_back(a);
		}
		Polynom ans(fst * scnd);
		std::cout << "Answer: ";
		TNode<Monom>* tmp = ans.Plnm.first->next;
		while (tmp != NULL) {
			if (tmp->value.get_k() == 0) tmp = tmp->next;
			else {
				std::cout << tmp->value.get_k() << "x^" << tmp->value.x_deg() << "*y^" << tmp->value.y_deg() << "*z^" << tmp->value.z_deg();
				tmp = tmp->next;
				if (tmp != NULL && tmp->value.get_k() >= 0) std::cout << "+";
			}
		}
	}
	break;
	default:
		return 0;
	}
}