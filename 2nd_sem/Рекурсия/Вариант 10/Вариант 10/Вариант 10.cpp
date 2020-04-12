#include <iostream>
using namespace std;

double prod(double);
double recprod(double);

int main() {
	double n;
	cout << "Input n(n>=2): ";
	cin >> n;
	//cout << "NOT reccurent product: " << prod(n) << endl;
	cout << "reccurent product: " << recprod(n) << endl;
	return 0;
}
double prod(double n) {
	for (n; n >= 1; n--) {

	}
 }

double recprod(double n) {
	if (n == 1) {
		return 2;
	}
	if (static_cast<int>(n) % 2 == 0) {
		return (n / (n + 1)) * recprod(n - 1);
	}
	if (static_cast<int>(n) % 2 != 0) {
		return ((n + 1) / n) * recprod(n - 1);
	}
}