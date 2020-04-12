// "Cчастливый билет" билет содержит 6 цифр 

#include <iostream>
using namespace std;

bool rec(char*, int);
int menu();
void nonRec(char*);

int main()
{
    char ticket[7];
    int choice;
    cout << "Enter ticket number(6 syllables): ";
    cin >> ticket;
    while (true) {
        switch (menu()) {
        case 1:  
            if (rec(ticket, 0)) {
                cout << "Lucky ticket" << endl;
            }
            else {
                cout << "Non-lucky ticket" << endl;
            }  break;
        case 2: nonRec(ticket); break;
        case 3: return 0;
        default: "Choose right!";
        }
    }
}
int menu() {
    int choice;
    cout << "Choose algorithm:\n1.Recursive\n2.Non-recursive\n3.Exit" << endl;
    cin >> choice;
    return choice;
}

void nonRec(char* ticket) {
    bool isLucky = true;
    for (int i = 0; i < 3; i++) {
        if (ticket[i] != ticket[5 - i]) {
            isLucky = false;
            break;
        }
    }
    (isLucky == true) ? cout << "Lucky ticket" : cout << "Non-lucky ticket";
    cout << endl;
}

bool rec(char *ticket, int i) {
    if (i == 3) {
        return true;
    }
    if (ticket[i] == ticket[5 - i]) {
        return rec(ticket, i + 1);
    }
    else {
        return false;
    }

}


