#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	int num;
	cout << "Enter size: ";
	cin >> num;
	int* arr = new int[num];
	bool f;
	srand(time(NULL)); 


	for (int i = 0; i < num; i++)
	{
		cout << "enter arr [" << i << "]: ";
		cin >> arr[i];
		//cout << (arr[i] = rand() % 20) << "\n";
	}


	for (int i = 0; i < num; i++)
	{
		if (arr[i] == arr[num - i - 1]) f = true;
		else f = false;
	}


	cout << ((f == true) ? "Symmetrical" : "Dissymetrical") << endl;
	/*if (f == true) cout << "Symmetrical";
	else cout << "Dissymetrical"; */

	return 0;
}
