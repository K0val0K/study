//TODO 
//@ шаблонный класс Stack, все функции сделать шаблонными


#include <iostream>
#include<stack>


template<class T>
class Stack
{
private:
    struct StackItem
    {
        T* data;	//указатель на данные
        StackItem* prev;	//указатель на предыдущий элемент
       //StackItem() :data(NULL), prev(NULL) { std::cout << "STACKITEM default constructor launched" << std::endl; }
        StackItem(T _data, StackItem* _prev) : prev(_prev), data(new T(_data)) {
            //strcpy_s(data, strlen(str) + 1, str);
            std::cout << "STACKITEM constructor WITH PARAMETRS launched" << std::endl;
        }


        ~StackItem() {
            std::cout << "StackItem destructor launched" << std::endl;
            delete data;
        }

    };
    StackItem* top; //указатель на вершину стека
    int size;

public:

    Stack() : top(NULL), size(0) { //конструктор по умолчанию
        std::cout << "default constructor launched" << std::endl;
    }

    Stack(T data) : top(new StackItem(data, top)), size(1) { //конструктор с параметрами
        std::cout << "constructor WITH PARAMETRS launched" << std::endl;
    }

    Stack(Stack& from) { // конструктор копирования
        size = from.size;
        StackItem* temp_copy = from.top;
        top = new StackItem(*temp_copy->data, NULL);
        temp_copy = temp_copy->prev;
        StackItem* temp_this = top;
        while (temp_copy != NULL) {
            temp_this->prev = new StackItem(*temp_copy->data, NULL);
            temp_this = temp_this->prev;
            temp_copy = temp_copy->prev;
        }
    }

    void push(T data) { // помещение данных в стек
        size++;
        top = new StackItem(data, top);
        std::cout << "element pushed" << std::endl;
    }

    T pop() { // извлечкние данных из стека
        if (size != 0) {
            T data = *top->data;
            StackItem* temp = top;
            top = top->prev;
            size--;
            delete temp;
            std::cout << "element popped" << std::endl;
            return data;

        }
        else {
            std::cout << "stack empty";
        }
    }

    int getSize() { return size; } // размре стека 

    T getTop() { return top == NULL ? NULL : *(top->data); } //получение верхнего элемента стека

    template <class T>
    friend void printStack(Stack<T>&);

    Stack& operator=(const Stack& from) { // оператор присваивания
        StackItem* temp = top;
        while (top != NULL) {
            temp = top;
            top = top->prev;
            delete temp;
        }
        size = from.size;
        StackItem* temp_copy = from.top;
        top = new StackItem(*temp_copy->data, NULL);
        temp_copy = temp_copy->prev;
        StackItem* temp_this = top;
        while (temp_copy != NULL) {
            temp_this->prev = new StackItem(*temp_copy->data, NULL);
            temp_this = temp_this->prev;
            temp_copy = temp_copy->prev;
        }
        return*this;
    };

    Stack& operator<<(T& data) { //помещение данных в стек ~ push
        this->push(data);
        return *this;
    }

    Stack& operator>>(T& data) { //извлечение вархнего элемента стека в пременную data (без удаления)
        data = this->getTop();
        return *this;
        // strcpy_s(data, strlen(this->getTop()) + 1 , this->getTop());
        // можно было и так, но я не придумал как обработать случай,
        // когда переменная data меньше чем требуется для копирования ¯\_(ツ)_/¯

    }

    template<class T>
    friend std::ostream& operator<<(std::ostream& os, const Stack<T>& from); // вывод стека на экран ~ print(для работы  cout <<)

    template<class T>
    friend std::istream& operator>>(std::istream& is, Stack<T>&); // помещение данных в стек ~ push (для работы с cin>>)


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

template <class T>
std::istream& operator>>(std::istream& in, Stack<T>& to) {
    T buffer;
    in >> buffer;
    to.push(buffer);
    return in;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Stack<T>& from) {

    if (from.size == 0) {
        out << "stack is empty" << std::endl;
    }
    typename Stack<T>::StackItem* temp = from.top;
    while (temp != NULL) {
        out << *(temp->data) << std::endl;
        temp = temp->prev;
    }
    return out;
}

template <class T>
void printStack(Stack<T>& p) {
    if (p.size == 0) {
        std::cout << "stack is empty" << std::endl;
    }

    typename Stack<T>::StackItem* temp = p.top;

    while (temp != NULL) {
        std::cout << *(temp->data) << std::endl;
        temp = temp->prev;
    }

}

int main()
{
    //integer test
    Stack<int> i;
    Stack<int> i1(0);
    i.push(1);
    i.push(2);
    int a = 3;
    i.push(a);
    i.push(4.4);
    std::cout << i.getSize() << std::endl;
    std::cout << i.getTop() << std::endl;
    printStack(i);
    std::cin >> i;
    std::cout << i;
    Stack<int> i2 = i;
    a = i.pop();
    std::cout << a << std::endl;
    i = i1;
    std::cout << i2;
    //string

    Stack<std::string> s;
    s.push("test1");
    std::cout << s.getTop();
    s.getSize();
    s.push("test2");
    s.push("test3");
    std::string m;
    m = s.pop();
    
    std::cout << s;
    std::cout << m << std::endl;
    

}

