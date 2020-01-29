#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double x, y, z, f, a, s;
	int k;
	cout << "Enter x: "; cin >> x;
	cout << "Enter y: "; cin >> y;
	cout << "Chose f(x): 1 -sh(x), 2- x^2, 3 - exp(x): "; cin >> k;
	switch (k)
	{
	case 1: f = sinh(x); break;
	case 2: f = pow(x, 2); break;
	case 3: f = exp(x); break;
	default: cout << "Function hasn't chosen"; return 1;
	}
	a = fabs(x * y);
	if (a > 10) s = log(fabs(x) + fabs(y));
	else
		if (a < 10) s = exp(x + y);
		else
			if (a == 10) s = pow(x, 1. / 3) + y;
	cout << "result: " << s << endl;
	return 0;

}
