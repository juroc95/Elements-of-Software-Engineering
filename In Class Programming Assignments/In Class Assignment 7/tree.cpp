// Juhwan Lee
// CS300: Elements of Software Engineering
// Professor Fei Xie
// In Class Programming Assignment 7

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class b_tree
{
public:
    b_tree()
    {
        root = NULL;
    }
    ~b_tree()
    {
        if (!root)
            return;
        else
            destroy(root);
    }
    void destroy(node *&root)
    {
        if (!root)
        {
            return;
        }
        destroy(root->left);
        destroy(root->right);
        delete root;
        root = NULL;
        return;
    }
    int insert(int newdata)
    {
        return insert(root, newdata);
    }
    int insert(node *&root, int newdata)
    {
        if (!root)
        {
            root = new node;
            root->data = newdata;
            root->left = NULL;
            root->right = NULL;
            cout << "data inserted" << endl;
            return 1;
        }
        else if (newdata < root->data)
        {
            return insert(root->left, newdata);
        }
        else
        {
            return insert(root->right, newdata);
        }
    }
    int remove(int toremove)
    {
        if (!root)
        {
            cout << "tree is empty" << endl;
            return 0;
        }
        else
        {
            return remove(root, toremove);
        }
    }
    int remove(node *&root, int toremove)
    {
        if (!root)
        {
            cout << "there is no match" << endl;
            return 1;
        }
        else if (toremove == root->data)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
                cout << "data removed" << endl;
                return 1;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                node *temp = root->left;
                delete root;
                root = temp;
                cout << "data removed" << endl;
                return 1;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                node *temp = root->right;
                delete root;
                root = temp;
                cout << "data removed" << endl;
                return 1;
            }
            else //if (root->left != NULL && root->right != NULL)
            {
                if (root->right->left == NULL)
                {
                    node *temp1 = root->right;
                    node *temp2 = root->left;
                    delete root;
                    root = temp1;
                    root->left = temp2;
                    cout << "data removed" << endl;
                    return 1;
                }
                else // in order successor
                {
                    int ios = inorder_successor(root->right);
                    root->data = ios;
                    cout << "data removed" << endl;
                    return 1;
                }
            }
        }
        else if (toremove < root->data)
        {
            return remove(root->left, toremove);
        }
        else
        {
            return remove(root->right, toremove);
        }
    }
    int inorder_successor(node *& root)
    {
        if(!root->left)
        {
            int data = root->data;
            if(root->right)
            {
                node * temp = root->right;
                delete root;
                root = temp;
                return data;
            }
            else
            {
                delete root;
                root = NULL;
                return data;
            }
        }
        else
        {
            return inorder_successor(root->left);
        }
    }
    int display_inorder()
    {
        if (!root)
        {
            cout << "tree is empty" << endl;
            return 1;
        }
        else
        {
            cout << "inorder: ";
            return display_inorder(root);
        }
    }
    int display_inorder(node *root)
    {
        if (!root)
            return 1;
        display_inorder(root->left);
        cout << root->data << " ";
        display_inorder(root->right);
        return 1;
    }
    int display_preorder()
    {
        if (!root)
        {
            cout << "tree is empty" << endl;
            return 1;
        }
        else
        {
            cout << "preorder: ";
            return display_preorder(root);
        }
    }
    int display_preorder(node *root)
    {
        if (!root)
            return 1;
        cout << root->data << " ";
        display_preorder(root->left);
        display_preorder(root->right);
        return 1;
    }
    int display_postorder()
    {
        if (!root)
        {
            cout << "tree is empty" << endl;
            return 1;
        }
        else
        {
            cout << "postorder: ";
            return display_postorder(root);
        }
    }
    int display_postorder(node *root)
    {
        if (!root)
            return 1;
        display_postorder(root->left);
        display_postorder(root->right);
        cout << root->data << " ";
        return 1;
    }
    int search(int tosearch)
    {
        if (!root)
        {
            cout << "tree is empty" << endl;
            return 1;
        }
        else
        {
            return search(root, tosearch);
        }
    }
    int search(node *root, int tosearch)
    {
        if (!root)
        {
            cout << "there is no match" << endl;
            return 1;
        }
        if (root->data == tosearch)
        {
            cout << "there is a match" << endl;
            return 1;
        }
        else if (tosearch < root->data)
        {
            return search(root->left, tosearch);
        }
        else
        {
            return search(root->right, tosearch);
        }
    }

private:
    node *root;
};

int main()
{
    b_tree mytree;
    int input = 0;
    int menu = 0;

    while (menu != 7)
    {

        cout << endl
             << "1. insert" << endl
             << "2. remove" << endl
             << "3. display inorder" << endl
             << "4. display preorder" << endl
             << "5. display postorder" << endl
             << "6. search" << endl
             << "7. exit" << endl
             << endl;
        cout << "please enter (1-7): ";
        cin >> menu;
        cin.ignore(100, '\n');

        if (menu == 1)
        {
            cout << "please enter new data: ";
            cin >> input;
            cin.ignore(100, '\n');
            mytree.insert(input);
        }

        if (menu == 2)
        {
            cout << "please enter data to remove: ";
            cin >> input;
            cin.ignore(100, '\n');
            mytree.remove(input);
        }

        if (menu == 3)
        {
            mytree.display_inorder();
            cout << endl;
        }

        if (menu == 4)
        {
            mytree.display_preorder();
            cout << endl;
        }

        if (menu == 5)
        {
            mytree.display_postorder();
            cout << endl;
        }

        if (menu == 6)
        {
            cout << "please enter data to search: ";
            cin >> input;
            cin.ignore(100, '\n');
            mytree.search(input);
        }
    }
    return 0;
}