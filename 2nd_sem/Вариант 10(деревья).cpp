

#include <iostream>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <stack>


using namespace std;

struct Tree {
    
    int data;
    Tree* left;
    Tree* right;
}*root, *temp_root;

Tree* makeList(int);
Tree* addList(Tree*, int);
Tree* findNode(Tree*, int, Tree*&);
void viewTree(Tree*, int);
void preOrderShow(Tree*);
void inOrderShow(Tree*);
void postOrderShow(Tree*);
Tree* deleteNode(Tree*, int);
void delTree(Tree* temp);
void addToArr(Tree*, int*, int&);
int sizeTree(Tree*);
void quickSort(int*, int);
void balance(Tree**, int, int, int*);

int getFullAmount(Tree *root) //индивидуальное задание(вариант 10)
{
    if (!root) return 0;

    int counter = 0;
    if (root->left && root->right) counter++;

    counter += (getFullAmount(root->left) + getFullAmount(root->right));

    return counter;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    bool flag_exit = true, flag_menu;
    temp_root = root = NULL;
    while (flag_exit) 
    {
        flag_menu = true;
        cout << " 1 - Создать дерево" << endl
            << " 2 - Посмотреть заданное дерево" << endl // в этом вызове также распечатывается информация в дереве прямым, обратным ходом и по возрастанию
            << " 3 - Удалить ключ " << endl
            << " 4 - Поиск " << endl
            << " 5 - Сбалансировать дерево" << endl
            << " 6 - Подсчитать количество узлов в дереве, у которых 2 потомка(индивидуальное задание)" << endl
            << " 7 - Очистить память " << endl
            << " Esc - Выход" << endl;
        while (flag_menu) 
        {
            switch (_getch())
            {
                case '1': 
                {
                    cout << "Заполнить автоматически?\n1.Да\n2.Нет"<< endl;
                    int info;
                    
                    switch (_getch())
                    {
                        case '1':
                        {
                            cout << "Введите количество узлов в дереве" << endl;
                            int node_amount;
                            cin >> node_amount;
                            node_amount--; //корень дерева создается отдельно
                            info = rand() % 100 - 50;
                            root = makeList(info);
                            // создаем масссив уникальных чисел
                            ///////////////////////////////////////////////
                            /*int* unique_arr = new int[node_amount];
                            int temp_size = 1;
                            while (true) 
                            {
                                unique_arr[0] = rand() % 100 - 50;
                                if (unique_arr[0] != root->num) break;
                            }
                            while (temp_size < node_amount)
                            {
                                bool unique = true;
                                info = rand() % 100 - 50;
                                for (int i = 0; i < temp_size; i++)
                                {
                                    if (unique_arr[i] == info || info == root->num) unique = false;
                                }

                                if (unique && temp_size < node_amount)
                                {
                                    unique_arr[temp_size] = info;
                                    temp_size++;
                                }
                                

                            }
                            ///////////////////////////////////////////////
                            for (int i = 0; i < node_amount; i++)
                            {
                                
                                addList(root, unique_arr[i]);
                                
                            }
                            cout << endl;
                            delete[]unique_arr;*/
                            for (int i = 0; i < node_amount; i++) {
                                info = rand() % 100 - 50;
                                if (addList(root, info)) continue;
                                else i--;
                            }
                            break;
                        }
                        case '2':
                        {
                            bool flag_continue = true;
                            int info;
                            while (flag_continue) {
                                if (root == NULL) {
                                    cout << "Введите корень: ";
                                    cin >> info;
                                    root = makeList(info);
                                }
                                else {
                                    cout << "Введите узел: ";
                                    cin >> info;
                                    if(addList(root, info) == NULL) cout << "Такой узел уже есть" << endl;
                                }
                                cout << "Нажмите любую клавишу для продолжения или Esc для заверешения построения дерева..." << endl;
                                if (_getch() == 27) break;
                            }
                            break;
                        }
                        default: cout << "Такой опции не существует.Выберите верно!" << endl; 
                        break;
                    }
                    flag_menu = false;
                    break;
                }
                case '2': 
                {   
                    if (root == NULL)
                    {
                        cout << "Дерево пусто!" << endl;
                        flag_menu = false;
                        break;
                    }
                    viewTree(root, 0);
                    cout << "Прямой обход" << endl;
                    preOrderShow(root);
                    cout << endl << "Обратный Обход" << endl;
                    postOrderShow(root);
                    cout << endl << "В порядке возрастания" << endl;
                    inOrderShow(root);
                    cout << endl;
                    flag_menu = false;
                    break;
                }
                case '3': 
                {

                    int key;
                    if (root == NULL)
                    {
                        cout << "Дерево пусто!" << endl;
                    }
                    else
                    {
                        cout << "Введите ключ узла, который хотите удалить: ";
                        cin >> key;
                        root = deleteNode(root, key);
                    }
                    flag_menu = false;
                    break;
                }
                case '4':
                {
                    Tree* pkey = NULL, *parent_pkey = NULL;
                    int key;
                    cout << "Введите ключ, который надо найти: ";
                    cin >> key;
                    if (pkey = findNode(root, key, parent_pkey)) {
                        cout << "Ключ найден! " << pkey->data << endl;
                        
                    }
                    else {
                        cout << "Rлюч не найден!" << endl;
                        cout << root->data;
                    } 
                    flag_menu = false;
                    break;
                }
                case '5': 
                {
                    int sizeArr = 0, idx = 0;
                    sizeArr = sizeTree(root);
                    if (!sizeArr)
                    {
                        cout << "Дерево пусто! " << endl;
                        flag_menu = false;
                        break;
                    }
                    else 
                    {
                        int* data_arr = new int[sizeArr];
                        addToArr(root, data_arr, idx);
                        quickSort(data_arr, sizeArr);
                        balance(&root, 0, sizeArr, data_arr);
                        delete[]data_arr;
                        cout << "Дерево успешно сбалансировано!" << endl;
                        viewTree(root,0);
                    }
                    flag_menu = false;
                    break;
                }
                case '6': 
                {
                    cout << "Количество узлов в дереве, у которых 2 потомка равняется " << getFullAmount(root) << endl;
                    flag_menu = false;
                    break;
                }
                case '7':
                {
                    if (!root) 
                    { 
                        flag_menu = false;
                        cout << "Дерево не создано!" << endl;
                        break; 
                    }
                    else
                    {
                        delTree(root);
                        root = NULL;
                        flag_menu = false;
                        break;
                    }
                }
                case 27:
                {
                    if (root != NULL) 
                    {
                        delTree(root);
                    }
                    flag_exit = false;
                    flag_menu = false;
                }
            }
        }
            
    }
    return 0;
}

Tree* makeList(int info)
{
    Tree* temp = new Tree;
    temp->data = info;
    temp->left = temp->right = NULL;
    return temp;
}

Tree* addList(Tree* root, int info)
{
    Tree* prev, * current;
    bool find = true;
    prev = current = root;
    
    while (current && find)
    {
        prev = current;
        if (info == current->data)
        {
            find = false;
        }
        else
        {
            if (info < current->data) current = current->left;
            else current = current->right;
        }
    }
    if (find) 
    {
        current = makeList(info);
        if (info < prev->data) prev->left = current;
        else prev->right = current;
        return prev;
    }
    else
    {
        return NULL;
    }
}

void viewTree(Tree* peek, int level)
{
    if (peek) 
    {
        viewTree(peek->right, level + 1);
        for (int i = 0; i < level; i++)
            cout << "    ";
        cout << setw(3) << peek->data << endl;
        viewTree(peek->left, level + 1);
    }
}

void delTree(Tree* temp)
{
    if (temp != NULL) 
    {
        delTree(temp->left);
        delTree(temp->right);
        delete temp;
    }
}

void preOrderShow(Tree* temp) { // прямой обход
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preOrderShow(temp->left);
        preOrderShow(temp->right);
    }
}
void postOrderShow(Tree* temp) { // обратный
    if (temp != NULL)
    {
        postOrderShow(temp->left);
        postOrderShow(temp->right);
        cout << temp->data << " ";
    }
}
void inOrderShow(Tree* temp) { //в порядке возрастания 
    if (temp != NULL) 
    {
        inOrderShow(temp->left);
        cout << temp->data << " ";
        inOrderShow(temp->right);
    }
}

Tree* findNode(Tree* root, int key, Tree *& parent_key) { // функция возвращает указатель на искомый элемент и на его родителя
    Tree* temp = root, *prev_temp = NULL;
    while (temp != NULL)
    {
        if (temp->data == key) 
        {
            parent_key = prev_temp;
            return temp;
        }
        prev_temp = temp;
        if (key < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    return NULL;
}

Tree* deleteNode(Tree*root, int key) 
{
    Tree* unit_delete, * prev_unit_delete = NULL, * unit_replace, * prev_unit_replace = NULL;
    unit_delete = root;
    unit_delete = findNode(root, key, prev_unit_delete);
    if (unit_delete == NULL) 
    {
        return root;
        cout << "Ключ не найден!" << endl;
    }

    if(unit_delete->right == NULL)
    {
        unit_replace = unit_delete->left;
    }
    else 
    {
        if (unit_delete->left == NULL)
            unit_replace = unit_delete->right;
        else 
        {
            prev_unit_replace = unit_delete;
            unit_replace = unit_delete->left;
            while(unit_replace->right != NULL)
            {
                prev_unit_replace = unit_replace;
                unit_replace = unit_replace->right;
            }
            if (prev_unit_replace == unit_delete)
                unit_replace->right = unit_delete->right;
            else
            {
                unit_replace->right = unit_delete->right;
                prev_unit_replace->right = unit_replace->left;
                unit_replace->left = unit_delete->left;
            }
        }
    }

    if (unit_delete == root)
    {
        root = unit_replace;
    }
    else
    {
        if (unit_delete->data < prev_unit_delete->data)
            prev_unit_delete->left = unit_replace;
        else
        prev_unit_delete->right = unit_replace;
    }
    delete unit_delete;
    return root;
}

int sizeTree(Tree* root) 
{
    if (!root)
    {
        return 0;
    }
    return 1 + sizeTree(root->left) + sizeTree(root->right);
}

void addToArr(Tree*root,int *arr, int&idx)
{
    arr[idx++] = root->data;
    if (root->left) addToArr(root->left, arr, idx);
    if (root->right) addToArr(root->right, arr, idx);
}

void quickSort(int* arr, int n) {
    if (n == 1) {
        return;
    }
    int pivot, first, last, left, right;
    pivot = first = last = left = right = 0;
    stack<int>bourders;
    bourders.push(n - 1);
    bourders.push(0);
    do { // while (bourders.empty() != NULL)
        first = bourders.top(); bourders.pop();
        last = bourders.top(); bourders.pop();
        if (((last - first) == 1) && (arr[first] > arr[last])) {
            swap(arr[last], arr[first]);
            
        }
        else {
            pivot = arr[(first + last) / 2];
            left = first;
            right = last;
            do {    //while (left <= right)
                while (arr[left] < pivot) left++;
                while (arr[right] > pivot) right--;
                if (left <= right) {
                    swap(arr[left], arr[right]);
                    
                    left++; right--;

                }
            } while (left <= right);
        }

        if (right > first) {
            bourders.push(right);
            bourders.push(first);
        }
        if (left < last) {
            bourders.push(last);
            bourders.push(left);
        }




    } while (!bourders.empty());
}

void balance(Tree** p, int begin, int end, int* arr)
{
    if (begin == end)
    {
        *p = NULL;
        return;
    }
    else 
    {
        int mid = (begin + end) / 2;
        *p = new Tree;
        (*p)->data = arr[mid];
        balance(&(*p)->left, begin, mid, arr);
        balance(&(*p)->right, mid + 1, end, arr);
    }
}