#include<stack>
#include <iostream>
#include <string.h>


class Stack
{
private:
    struct StackItem
    {
        char* data;	//указатель на данные
        StackItem* prev;	//указатель на предыдущий элемент
       //StackItem() :data(NULL), prev(NULL) { std::cout << "STACKITEM default constructor launched" << std::endl; }
        StackItem(const char* str, StackItem* _prev) :prev(_prev), data(new char[strlen(str) + 1]) {
            strcpy_s(data, strlen(str) + 1, str);
            std::cout << "STACKITEM constructor WITH PARAMETRS launched" << std::endl;
        }


        ~StackItem() {
            std::cout << "StackItem destructor launched" << std::endl;
            delete[]data;
        }

    };
    StackItem* top; //указатель на вершину стека
    int size;

public:
    
    Stack() :top(NULL), size(0) { //конструктор по умолчанию
        std::cout << "default constructor launched" << std::endl;
    } 

    Stack(const char* str) : top(new StackItem(str, top)), size(1) { //конструктор с параметрами
        std::cout << "constructor WITH PARAMETRS launched" << std::endl;
    } 

    Stack(Stack& from) { // конструктор копирования
        size = from.size;
        StackItem* temp_copy = from.top;
        top = new StackItem(temp_copy->data, NULL);
        temp_copy = temp_copy->prev;
        StackItem* temp_this = top;
        while (temp_copy != NULL) {
            temp_this->prev = new StackItem(temp_copy->data, NULL);
            temp_this = temp_this->prev;
            temp_copy = temp_copy->prev;
        }
    } 

    void init() { // инициализация стека
        if (top != NULL) {
            std::cout << "stack is already initialized(probably by constructor)" << std::endl;
            return;
        }
        this->top = NULL;
        this->size = 0;
    }

    void push(const char* data) { // помещение данных в стек
        size++;
        top = new StackItem(data, top);
        std::cout << "element pushed" << std::endl;
    }

    void pop() { // извлечкние данных из стека
        if (size != 0) {
            StackItem* temp = top;
            top = top->prev;
            size--;
            delete temp;
            std::cout << "element popped" << std::endl;

        }
        else {
            std::cout << "stack empty";
        }
    }

    int getSize() { return size; } // размре стека 

    char* getTop() { return top == NULL ? NULL : top->data;} //получение верхнего элемента стека

    friend void printStack(Stack&);



    Stack& operator=(const Stack& from) { // оператор присваивания
        StackItem* temp = top;
        while (top != NULL) {
            temp = top;
            top = top->prev;
            delete temp;
        }
        size = from.size;
        StackItem* temp_copy = from.top;
        top = new StackItem(temp_copy->data, NULL);
        temp_copy = temp_copy->prev;
        StackItem* temp_this = top;
        while (temp_copy != NULL) {
            temp_this->prev = new StackItem(temp_copy->data, NULL);
            temp_this = temp_this->prev;
            temp_copy = temp_copy->prev;
        }
        return*this;
    };

    Stack& operator<<(const char* data) { //помещение данных в стек ~ push
        this->push(data);
        return *this;
    }

    Stack& operator>>(char** data) { //извлечение вархнего элемента стека в пременную data (без удаления)
        *data = this->getTop();
        return *this;
        // strcpy_s(data, strlen(this->getTop()) + 1 , this->getTop());
        // можно было и так, но я не придумал как обработать случай,
        // когда переменная data меньше чем требуется для копирования ¯\_(ツ)_/¯

    }

    friend std::ostream& operator<<(std::ostream& os, const Stack& from); // вывод стека на экран ~ print(для работы  cout <<)
    
    friend std::istream& operator>>(std::istream& is, Stack&); // помещение данных в стек ~ push (для работы с cin>>)


    ~Stack() { //детсруктор
        std::cout << "destructor launched" << std::endl;
        size = 0;
        StackItem* temp = top;
        while (top != NULL) {
            temp = top;
            top = top->prev;
            delete temp;
        }
    } 
};

std::istream& operator>>(std::istream& in, Stack& to) {
    char buffer[256];
    in >> buffer;
    to.push(buffer);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Stack& from) {

    if (from.size == 0) {
        out << "stack is empty" << std::endl;
    }
    Stack::StackItem* temp = from.top;
    while (temp != NULL) {
        out << temp->data << std::endl;
        temp = temp->prev;
    }
    return out;
}

void printStack(Stack& p) {
    if (p.size == 0) {
        std::cout << "stack is empty" << std::endl;
    }
    Stack::StackItem* temp = p.top;
    while (temp != NULL) {
        std::cout << temp->data << std::endl;
        temp = temp->prev;
    }

}

void test() {

    Stack def;
    def.getTop();
    def.push("1");
    def.push("2");
    def << "3";
    def.push("4");
    std::cin >> def;
    /*char* a = NULL;
    def >> &a;
    a = def.getTop();
    std::cout << "A: " << a;*/
    def << "5";
    std::cout << def;
    //printStack(def);
    std::cout << std::endl;
    Stack sec = def;
    sec.push("TEST");
    //printStack(sec);
    std::cout << std::endl;
    def = sec;
    //printStack(def);
    std::cout << std::endl;

}

int main()
{
    
    test();

    return 0;
}




