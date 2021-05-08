// 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Stack
{
	char* data;	//указатель на данные
	Stack* prev;	//указатель на предыдущий элемент
}*top = NULL;

void Push(Stack** top, char* data)
{
	Stack* temp = new Stack;
	temp->data = data;
	temp->prev = *top;
	*top = temp;
}
void PrintStack(Stack* top) {
    Stack* temp = top;
    if (temp == NULL) {
        cout << "Stack empty" << endl;
        return; 
    }
    while (temp != NULL) {
        cout << (temp->data) << endl;
        temp = temp->prev;
    }
}
//template<typename T>
char* Pop(Stack **top)
{
    char *out;
    Stack* t = *top;
    out = (*top)->data;
    *top = (*top)->prev;
    delete t;
    return out;
}

void* DeleteAll(Stack*& top) {
    Stack* temp;
    while (top != NULL) {
        temp = top;
        top = top->prev;
        delete temp;
    }
    

    cout << "Stack deleted" << endl;
    return top;
}

int main()
{
    char a[] = "element 1(bottom)";
    Push(&top, a);
    char b[] = "element 2";
    Push(&top, b);
    char c[] = "element 3(new head after pop())";
    Push(&top, c);
    char d[] = "this element will be removed by Pop and written to test variable";
    Push(&top, d);
    PrintStack(top);
    char *test;
    test = Pop(&top);
    cout << "removed top:  " << test << endl;
   
    cout << endl << "new Stack:" << endl;
    PrintStack(top);

    DeleteAll(top);

    PrintStack(top);
    
    //std::cout << "Hello World!\n";
}

