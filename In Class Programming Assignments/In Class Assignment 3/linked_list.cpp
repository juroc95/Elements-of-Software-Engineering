// Juhwan Lee
// CS300: Elements of Software Engineering
// Professor Fei Xie
// In Class Programming Assignment 3

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct node
{
    int data;
    node *next;
};

class array_list
{
public:
    array_list()
    {
        size = 0;
        maxsize = 10;
        head = new int[maxsize];
    }
    ~array_list()
    {
        delete[] head;
    }
    int insert(int toinsert)
    {
        if (size == maxsize)
        {
            return 0;
        }
        head[size] = toinsert;
        ++size;
        cout << "data inserted" << endl;
        return 1;
    }
    int remove(int toremove)
    {
        int flag = 0;
        for (int i = 0; i < maxsize; ++i)
        {
            if (toremove == head[i])
            {
                flag = 1;
            }
            if (flag == 1)
            {
                head[i] = head[i + 1];
            }
        }
        if (flag == 1)
        {
            cout << "data removed" << endl;
            --size;
        }
        else
        {
            cout << "there is no match" << endl;
        }
        return 1;
    }
    int search(int tosearch)
    {
        int flag = 0;
        for (int i = 0; i < maxsize; ++i)
        {
            if (head[i] == tosearch)
            {
                cout << "there is a match" << endl;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "there is no match" << endl;
        }
        return 1;
    }
    int display()
    {
        for (int i = 0; i < maxsize; ++i)
        {
            cout << head[i];
            if (i < maxsize - 1)
            {
                cout << " -> ";
            }
        }
        cout << endl;
        return 1;
    }
    int reverse()
    {
        int temp;
        int iter = size - 1;
        for (int i = 0; i < iter; ++i)
        {
            temp = head[i];
            head[i] = head[iter];
            head[iter] = temp;
            --iter;
        }
        cout << "list reversed" << endl;
        return 1;
    }

private:
    int *head;
    int size;
    int maxsize;
};

class linked_list
{
public:
    linked_list()
    {
        head = NULL;
    }
    ~linked_list()
    {
        if (!head)
        {
            return;
        }
        destroy(head);
    }
    void destroy(node *&head)
    {
        if (!head)
            return;
        destroy(head->next);
        delete head;
        head = NULL;
    }
    int insert(int toinsert)
    {
        return insert(head, toinsert);
    }
    int insert(node *&head, int toinsert)
    {
        if (!head)
        {
            head = new node;
            head->data = toinsert;
            head->next = NULL;
            cout << "data inserted" << endl;
            return 1;
        }
        return insert(head->next, toinsert);
    }
    int remove(int toremove)
    {
        return remove(head, toremove);
    }
    int remove(node *&head, int toremove)
    {
        if (!head)
        {
            cout << "there is no match" << endl;
            return 0;
        }
        if (head->data == toremove)
        {
            node *temp = head->next;
            delete head;
            head = temp;
            cout << "data removed" << endl;
            return 1;
        }
        return remove(head->next, toremove);
    }
    int search(int tosearch)
    {
        return search(head, tosearch);
    }
    int search(node *head, int tosearch)
    {
        if (!head)
        {
            cout << "there is no match" << endl;
            return 0;
        }
        if (head->data == tosearch)
        {
            cout << "there is a match" << endl;
            return 1;
        }
        return search(head->next, tosearch);
    }
    int display()
    {
        return display(head);
    }
    int display(node *head)
    {
        if (!head)
        {
            return 1;
        }
        cout << head->data;
        if (head->next != NULL)
            cout << " -> ";
        else
            cout << endl;
        return display(head->next);
    }
    int reverse()
    {
        cout << "list reversed" << endl;
        return reverse(head);
    }
    int reverse(node *&head)
    {
        node *first;
        node *rest;
        if (!head)
        {
            return 1;
        }
        first = head;
        rest = first->next;
        if (!rest)
        {
            return 1;
        }
        reverse(rest);
        first->next->next = first;
        first->next = NULL;
        head = rest;
        return 1;
    }

private:
    node *head;
};

int main()
{
    int list_option = 0;
    linked_list Llist;
    array_list Alist;

    cout << "1. linked list" << endl
         << "2. array list" << endl
         << endl;

    cout << "please enter (1-2): ";
    cin >> list_option;
    cin.ignore(100, '\n');

    int menu = 0;
    int toinsert = 0;
    int toremove = 0;
    int tosearch = 0;

    while (menu != 6)
    {

        cout << endl
             << "1. insert" << endl
             << "2. remove" << endl
             << "3. search" << endl
             << "4. display" << endl
             << "5. reverse" << endl
             << "6. quit" << endl
             << endl;

        cout << "please enter (1-5): ";
        cin >> menu;
        cin.ignore(100, '\n');

        if (menu == 1)
        {
            cout << "please enter data you want to insert: ";
            cin >> toinsert;
            cin.ignore(100, '\n');
            if (list_option == 1)
                Llist.insert(toinsert);
            if (list_option == 2)
                Alist.insert(toinsert);
        }

        if (menu == 2)
        {
            cout << "please enter data you want to remove: ";
            cin >> toremove;
            cin.ignore(100, '\n');
            if (list_option == 1)
                Llist.remove(toremove);
            if (list_option == 2)
                Alist.remove(toremove);
        }

        if (menu == 3)
        {
            cout << "please enter data you want to search: ";
            cin >> tosearch;
            cin.ignore(100, '\n');
            if (list_option == 1)
                Llist.search(tosearch);
            if (list_option == 2)
                Alist.search(tosearch);
        }

        if (menu == 4)
        {
            if (list_option == 1)
                Llist.display();
            if (list_option == 2)
                Alist.display();
        }

        if (menu == 5)
        {
            if (list_option == 1)
                Llist.reverse();
            if (list_option == 2)
                Alist.reverse();
        }
    }
    return 0;
}