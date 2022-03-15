#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class signup
{
public:
    signup()
    {
        name = "";
        year = 0;
        month = 0;
        day = 0;
    }
    ~signup()
    {
        name = "";
        year = 0;
        month = 0;
        day = 0;
    }
    int create()
    {
        cin >> new_signup.name;
        cin.ignore(100, '\n');
        cin >> year;
        cin.ignore(100, '\n');
        cin >> month;
        cin.ignore(100, '\n');
        cin >> day;
        cin.ignore(100, '\n');
        return 1;
    }
    int retrieve(signup &to_retrieve)
    {
        to_retrieve.name = name;
        to_retrieve.year = year;
        to_retrieve.month = month;
        to_retrieve.day = day;
        return 1;
    }

private:
    string name;
    int year;
    int month;
    int day;
};

struct node
{
    signup data;
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
    int update(signup &newdata)
    {
        return update(head, newdata);
    }
    int update(node *&head, signup &newdata)
    {
        if (!head)
        {
            head = new node;
            head->data = newdata;
            head->next = NULL;
            return 1;
        }
        return update(head->next, newdata);
    }
    int remove(string toremove)
    {
        if (!head)
            return 0;
        return remove(head, toremove);
    }
    int remove(node *&head, string toremove)
    {
        if (!head)
            return 0;
        if (data.name == toremove)
        {
            node *temp = head->next;
            delete head;
            head = temp;
            return 1;
        }
        return remove(head->next, toremove);
    }

private:
    node *head;
};

int main()
{
    list signup_list;

    signup user_1;
    signup user_2;
    signup user_3;
    signup user_4;

    if(user_1.create() == 1)
        cout << "create test 1 passed" << endl;
    else
        cout << "create test 1 failed" << endl;
    if(user_2.create() == 1)
        cout << "create test 2 passed" << endl;
    else
        cout << "create test 2 failed" << endl;
    if(user_3.create() == 1)
        cout << "create test 3 passed" << endl;
    else
        cout << "create test 3 failed" << endl;
    if(user_4.create() == 1)
        cout << "create test 4 passed" << endl;
    else
        cout << "create test 4 failed" << endl;

    user_1.retrieve(user_2);
    user_3.retrieve(user_4);

    if(user_1 == user_2)
        cout << "retrieve test 1 passed" << endl;
    else
        cout << "retrieve test 1 failed" << endl;
    if(user_3 == user_4)
        cout << "retrieve test 2 passed" << endl;
    else
        cout << "retrieve test 2 failed" << endl;


    if(signup_list.update(user_1) == 1)
        cout << "update test 1 passed" << endl;
    else
        cout << "update test 1 failed" << endl;
    if(signup_list.update(user_2) == 1)
        cout << "update test 2 passed" << endl;
    else
        cout << "update test 2 failed" << endl;
    if(signup_list.update(user_3) == 1)
        cout << "update test 3 passed" << endl;
    else
        cout << "update test 3 failed" << endl;
    if(signup_list.update(user_4) == 1)
        cout << "update test 4 passed" << endl;
    else
        cout << "update test 4 failed" << endl;


    if(signup_list.remove(user_1) == 1)
        cout << "remove test 1 passed" << endl;
    else
        cout << "remove test 1 failed" << endl;
    if(signup_list.remove(user_2) == 1)
        cout << "remove test 2 passed" << endl;
    else
        cout << "remove test 2 failed" << endl;
    if(signup_list.remove(user_3) == 1)
        cout << "remove test 3 passed" << endl;
    else
        cout << "remove test 3 failed" << endl;
    if(signup_list.remove(user_4) == 1)
        cout << "remove test 4 passed" << endl;
    else
        cout << "remove test 4 failed" << endl;


    return 0;
}