// Juhwan Lee
// CS300: Elements of Software Engineering
// Professor Fei Xie
// In Class Programming Assignment 5

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct node
{
    int data;
    node *next;
};

class stack
{
public:
    stack()
    {
        head = NULL;
    }
    ~stack()
    {
        if (head)
        {
            destroy(head);
        }
    }
    void destroy(node *&head)
    {
        if (!head)
        {
            return;
        }
        destroy(head->next);
        delete head;
        head = NULL;
    }
    int push(int newdata)
    {
        return push(head, newdata);
    }
    int push(node *&head, int newdata)
    {
        if (!head)
        {
            head = new node;
            head->data = newdata;
            head->next = NULL;
            return 1;
        }
        return push(head->next, newdata);
    }
    int pop()
    {
        return pop(head);
    }
    int pop(node *&head)
    {
        if (!head)
        {
            cout << "stack is empty" << endl;
            return 1;
        }
        if (!head->next)
        {
            delete head;
            head = NULL;
            return 1;
        }
        return pop(head->next);
    }
    int peek()
    {
        return peek(head);
    }
    int peek(node *head)
    {
        if (!head)
        {
            cout << "stack is empty" << endl;
            return 1;
        }
        if (!head->next)
        {
            cout << "peek: " << head->data << endl;
            return 1;
        }
        return peek(head->next);
    }
    int display()
    {
        cout << "stack: ";
        return display(head);
    }
    int display(node *head)
    {
        if (!head)
        {
            cout << endl;
            return 1;
        }
        cout << head->data;
        if (head->next != NULL)
            cout << " -> ";
        return display(head->next);
    }

private:
    node *head;
};

int main()
{
    stack mystack;
    int menu = 0;
    int newdata = 0;

    while (menu != 5)
    {
        cout << endl
             << "1. push" << endl
             << "2. pop" << endl
             << "3. peek" << endl
             << "4. display" << endl
             << "5. exit" << endl
             << endl;
        cout << "please enter (1-5): ";
        cin >> menu;
        cin.ignore(100, '\n');

        if (menu == 1)
        {
            cout << "please enter new data: ";
            cin >> newdata;
            cin.ignore(100, '\n');
            mystack.push(newdata);
            mystack.display();
        }

        if (menu == 2)
        {
            mystack.pop();
            mystack.display();
        }

        if (menu == 3)
        {
            mystack.peek();
            mystack.display();
        }

        if (menu == 4)
        {
            mystack.display();
        }
    }

    return 0;
}