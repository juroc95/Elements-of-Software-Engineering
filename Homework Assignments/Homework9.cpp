//Juhwan Lee
//CS300: Elements of Software Engineering
//Professor Fei Xie
//Homework 9

#include <iostream>
#include <vector>
using namespace std;

int summer(vector<int> arr) {
    int size = arr.size();
    int result = 0;
    for (int i = 0; i < size; ++i)
        result += arr[i];
    return result;
}

int main() {
    vector<int> array_1 = {1,2,3,4,5};
    vector<int> array_2 = {2,4,6,8,10};
    vector<int> array_3 = {1,3,5,7,9};

    if (summer(array_1) == 15)
        cout << "Test 1 : Passed" << endl;
    else
        cout << "Test 1: Failed" << endl;
    if (summer(array_2) == 30)
        cout << "Test 2 : Passed" << endl;
    else
        cout << "Test 2 : Failed" << endl;
    if (summer(array_3) == 25)
        cout << "Test 3 : Passed" << endl;
    else
        cout << "Test 3 : Failed" << endl;

    return 0;
}