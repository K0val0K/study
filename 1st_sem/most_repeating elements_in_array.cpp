#include <iostream>

using namespace std;

int main() {
	int n, list[50];
	bool flag = true;
	cout << "Enter size: ";
	cin >> n;

		int* arr = new int[n];

		cout << "Enter arr: " << endl
			;
		for (int i = 0; i < n; i++) {
			cout << "arr [" << i << "]";
			cin >> arr[i];
		 }

		int counter = 0, m = arr[0], temp, comparison_counter = 1, k = 0, size_k = 1, len = 0;

		for (int i = 0; i < n; i++) {
			counter = 0;
			for (int j = i + 1; j < n; j++) {
				if (arr[i] == arr[j]) {
					counter++;
					temp = arr[i];
				}	
				
				if (counter >= comparison_counter) {
					comparison_counter = counter;
					m = temp;
					//len = 0;
					list[len] = temp;
					
				}
				
			}

			if (counter == comparison_counter) {
				list[len] = temp;
				len++;

			}
			
		}
		if (comparison_counter != 1) {
			cout << "All most repeatable values: \n";
			for (int i = 0; i < len; i++) {
				cout << list[i] << endl;
			}
		}
		else {
			cout << "There's no repiatable value";
		}
		delete[]arr;
		return 0;
}
