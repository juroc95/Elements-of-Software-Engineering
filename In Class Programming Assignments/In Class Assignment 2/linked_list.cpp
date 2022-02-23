#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct node
{
    int data;
    node *next;
};

class list
{
public:
    list()
    {
        head = NULL;
    }
    ~list()
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
            return 0;
        }
        if (head->data == toremove)
        {
            node *temp = head->next;
            delete head;
            head = temp;
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
            return 0;
        }
        if (head->data == tosearch)
        {
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
        cout << head->data << endl;
        return display(head->next);
    }

private:
    node *head;
};

int main()
{
    list mylist;
    int menu = 0;
    int toinsert = 0;
    int toremove = 0;
    int tosearch = 0;

    while (menu != 5)
    {

        cout << "1. insert" << endl
             << "2. remove" << endl
             << "3. search" << endl
             << "4. display" << endl
             << "5. quit" << endl
             << endl;

        cout << "please enter (1-5): ";
        cin >> menu;
        cin.ignore(100, '\n');

        if (menu == 1)
        {
            cout << "please enter data you want to insert: ";
            cin >> toinsert;
            cin.ignore(100, '\n');
            mylist.insert(toinsert);
        }

        if (menu == 2)
        {
            cout << "please enter data you want to remove: ";
            cin >> toremove;
            cin.ignore(100, '\n');
            mylist.remove(toremove);
        }

        if (menu == 3)
        {
            cout << "please enter data you want to search: ";
            cin >> tosearch;
            cin.ignore(100, '\n');
            mylist.search(tosearch);
        }

        if (menu == 4)
        {
            mylist.display();
        }
    }
    return 0;
}