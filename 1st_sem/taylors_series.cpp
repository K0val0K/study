#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	double a, b, h, x, y, sum, temp;
	int n, i;
	cout << "Enter a: "; cin >> a;
	cout << "Enter b: "; cin >> b;
	cout << "Enter n: "; cin >> n;
	h = (b - a) / 10;
	x = a;

	cout << "---------------------------------------------" << endl;
	cout << setw(15) << "x |" << setw(15) << "cos(2x) |" << setw(15)
		<< "Taylor series |" << endl;
	cout << "---------------------------------------------" << endl;

	do {
		int k = 1;
		temp =  sum = 0;
			do {
				
				temp = (((pow((-1), (k + 1.))) / k) + ((pow((-1), k) * 6.) / (k * k * k * pi * pi))) * sin(k * pi * x);
				sum += temp;
				k++;
			} while (fabs(temp) > eps);
		
		y = pow(x , 3) * pi / 2; // сравнение разложения в ряд Тейлора со значением функции
		cout << setw(13) << x << " |" << setw(13) << y << " |" << setw(13)  << sum << endl;
		x += h;
	} while (x <= b + h / 2);

	cout << "---------------------------------------------" << endl;

	return 0;

}
