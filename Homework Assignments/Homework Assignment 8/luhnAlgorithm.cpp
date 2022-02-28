//Juhwan Lee
//CS300: Elements of Software Engineering
//Professor Fei Xie
//Homework 8

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string cardNumber;
    int result = 0;
    bool isSecond = false;
    cout << "Please enter card number: ";
    cin >> cardNumber;
    cin.ignore(100, '\n');
    int size = cardNumber.size();
    if (size != 16)
        cout << "Invalid card number" << endl;
    else
    {
        for (int i = 0; i < size; ++i)
        {
            int temp = cardNumber[i] - '0'; // char to int
            if (isSecond == true)
                temp = temp * 2;    
            result += temp / 10;
            result += temp % 10;
            isSecond = !isSecond;
        }
        if (result % 10 == 0)
            cout << "The card number is valid" << endl;
        else
            cout << "Invalid card number" << endl;
    }
    return 0;
}