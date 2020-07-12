#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

struct Stack
{
	double info;
	Stack* a;
};

Stack* AddStack(Stack* sp, double inf)
{
	Stack* spt = new Stack;
	spt->info = inf;
	spt->a = sp;
	return spt;
}

Stack* ReadStack(Stack* sp, double& inf)
{
	Stack* spt = sp;
	inf = sp->info;
	sp = sp->a;
	delete spt;
	return sp;
}

double masz[122];
char str[100], strp[100];

int priority(char ch)
{
	switch (ch)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': case '^': return 2;
	//case '*': case '/': return 2;
	//case '^': return 3;
	default: return -1;
	}
}

void AddPostFix(char* strin, char* strout)
{
	Stack* sp = NULL;
	int n = 0;
	char ch;
	double inf;
	for (unsigned int i = 0; i < strlen(strin); i++)
	{
		ch = strin[i];
		if ((ch >= 'A') && (ch != '^')) { strout[n++] = ch; continue; }
		if (sp == NULL || ch == '(') { sp = AddStack(sp, ch); continue; }
		if (ch == ')')
		{
			while (sp->info != '(')
			{
				sp = ReadStack(sp, inf);
				strout[n++] = (char)inf;
			}
			sp = ReadStack(sp, inf);
			continue;
		}
		int pr = priority(ch);
		while (sp != NULL && priority((char)sp->info) >= pr)
		{
			sp = ReadStack(sp, inf);
			strout[n++] = (char)inf;
		}
		sp = AddStack(sp, ch);
	}

	while (sp != NULL)
	{
		sp = ReadStack(sp, inf);
		strout[n++] = (char)inf;
	}
	strout[n++] = '\0';
}

double rasAV(char* str, double* mz)
{
	Stack* sp = NULL;
	char ch;
	double inf, inf1, inf2;
	for (unsigned int i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		if ((ch >= 'A') && (ch != '^')) { sp = AddStack(sp, mz[int(ch)]); continue; }
		sp = ReadStack(sp, inf2);
		sp = ReadStack(sp, inf1);
		switch (ch)
		{
		case '+': sp = AddStack(sp, inf1 + inf2); break;
		case '-': sp = AddStack(sp, inf1 - inf2); break;
		case '*': sp = AddStack(sp, inf1 * inf2); break;
		case '/': sp = AddStack(sp, inf1 / inf2); break;
		case '^': sp = AddStack(sp, pow(inf1, inf2)); break;
		}
	}
	sp = ReadStack(sp, inf);
	return inf;
}

int main()
{
	cout << "Vvedite x" << endl; cin >> masz[int('x')];
	cout << "Vvedite y" << endl; cin >> masz[int('y')];
	cout << "Vvedite b" << endl; cin >> masz[int('b')];
	cout << "Vvedite s" << endl; cin >> masz[int('s')];
	cout << "Vvedite w" << endl; cin >> masz[int('w')];
	cout << "Vvedite viragenie(x, y, b, s, w)" << endl;
	cin >> str;
	AddPostFix(str, strp);
	cout << endl << strp;
	double s = rasAV(strp, masz);
	cout << endl << "Res = " << s << endl;
	return 0;
} 

/*struct Stack 
{
	char info;
	Stack* next;
};

int priority(char);
Stack* pushStack(Stack*, char);
Stack* popStack(Stack*, char*);

int main()
{
	Stack* opHead = NULL, *temp;
	char a, input[81], output[81];
	int inIdx = 0, outIdx = 0;
	cout << "Введите формулу ";
	cin >> input;
	while (input[inIdx] != '/0') 
	{
		if (input[inIdx] >= 'a' && input[inIdx] <= 'z') 
		{
			output[outIdx++] = input[inIdx];
		}
		if (input[inIdx] == '(')
			opHead = pushStack(opHead, input[inIdx]);
		if (input[inIdx] == ')') 
		{
			while ((opHead->info) != '(')
			{
				opHead = popStack(opHead, &a);
				if (!opHead) a = '\0';
				output[outIdx++] = a;
			}
			temp = opHead;
			opHead = opHead->next;
			delete temp;
		}
		if(input[inIdx] == '+' || input[inIdx] == '-' || input[inIdx] == '*' || input[inIdx] == '/') 
		{
			while(opHead != NULL && )
		}
	}
	return 0;
}
Stack* pushStack(Stack* head, char s) {
	Stack* temp = new Stack;
	temp->info = s;
	temp->next = head;
	return temp;
}

Stack* popStack(Stack* head, char* s)
{
	Stack* temp = head;
	*s = temp->info;
	head = head->next;
	delete temp;
	return head;
}

int priority(char a) 
{
	switch(a) 
	{
	case '*':case '/': return 3;
	case '-':case '+': return 2;
	case '(': return 1;
	}
	return 0;
}*/
