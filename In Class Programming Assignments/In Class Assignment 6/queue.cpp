// Juhwan Lee
// CS300: Elements of Software Engineering
// Professor Fei Xie
// In Class Programming Assignment 6

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

class queue
{
public:
    queue()
    {
        head = NULL;
    }
    ~queue()
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
    int enqueue(int newdata)
    {
        return enqueue(head, newdata);
    }
    int enqueue(node *&head, int newdata)
    {
        if (!head)
        {
            head = new node;
            head->data = newdata;
            head->next = NULL;
            return 1;
        }
        return enqueue(head->next, newdata);
    }
    int dequeue()
    {
        return dequeue(head);
    }
    int dequeue(node *&head)
    {
        if (!head)
        {
            cout << "queue is empty" << endl;
            return 1;
        }
        else
        {
            node *temp = head->next;
            delete head;
            head = temp;
            return 1;
        }
    }
    int peek()
    {
        return peek(head);
    }
    int peek(node *head)
    {
        if (!head)
        {
            cout << "queue is empty" << endl;
            return 1;
        }
        else
        {
            cout << "peek: " << head->data << endl;
            return 1;
        }
    }
    int display()
    {
        cout << "queue: ";
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
    queue myqueue;
    int option = 0;
    int menu = 0;
    int newdata = 0;

    do
    {
        cout << endl
             << "1. stack" << endl
             << "2. queue" << endl
             << endl
             << "please enter (1-2): ";
        cin >> option;
        cin.ignore(100, '\n');
    } while (option != 1 && option != 2);

    while (menu != 5)
    {
        if (option == 1)
        {
            cout << endl
                 << "1. push" << endl
                 << "2. pop" << endl
                 << "3. peek" << endl
                 << "4. display" << endl
                 << "5. exit" << endl
                 << endl;
            cout << "please enter (1-5): ";
        }
        if (option == 2)
        {
            cout << endl
                 << "1. enqueue" << endl
                 << "2. dequeue" << endl
                 << "3. peek" << endl
                 << "4. display" << endl
                 << "5. exit" << endl
                 << endl;
            cout << "please enter (1-5): ";
        }
        cin >> menu;
        cin.ignore(100, '\n');

        if (menu == 1)
        {
            cout << "please enter new data: ";
            cin >> newdata;
            cin.ignore(100, '\n');
            if (option == 1)
            {
                mystack.push(newdata);
                mystack.display();
            }
            if (option == 2)
            {
                myqueue.enqueue(newdata);
                myqueue.display();
            }
        }

        if (menu == 2)
        {
            if (option == 1)
            {
                mystack.pop();
                mystack.display();
            }
            if (option == 2)
            {
                myqueue.dequeue();
                myqueue.display();
            }
        }

        if (menu == 3)
        {
            if (option == 1)
            {
                mystack.peek();
                mystack.display();
            }
            if (option == 2)
            {
                myqueue.peek();
                myqueue.display();
            }
        }

        if (menu == 4)
        {
            if (option == 1)
            {
                mystack.display();
            }
            if (option == 2)
            {
                myqueue.display();
            }
        }
    }

    return 0;
}