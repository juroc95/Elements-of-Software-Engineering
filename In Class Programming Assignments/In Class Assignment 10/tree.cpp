// Juhwan Lee
// CS300: Elements of Software Engineering
// Professor Fei Xie
// In Class Programming Assignment 10

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
            else // if (root->left != NULL && root->right != NULL)
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
    int inorder_successor(node *&root)
    {
        if (!root->left)
        {
            int data = root->data;
            if (root->right)
            {
                node *temp = root->right;
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
            cout << "tree is empty";
            return 1;
        }
        else
        {
            cout << "in order: ";
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
            cout << "tree is empty";
            return 1;
        }
        else
        {
            cout << "pre order: ";
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
            cout << "tree is empty";
            return 1;
        }
        else
        {
            cout << "post order: ";
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
    void display_levelorder()
    {
        if (!root)
        {
            cout << "tree is empty";
            return;
        }
        else
        {
            cout << "level order: ";
            int h = height(root);
            for (int i = 1; i <= h; ++i)
            {
                display_current_level(root, i);
            }
        }
    }
    int height(node *root)
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            int lheight = height(root->left);
            int rheight = height(root->right);
            if (lheight > rheight)
            {
                return lheight + 1;
            }
            else
            {
                return rheight + 1;
            }
        }
    }
    void display_current_level(node *root, int level)
    {
        if (!root)
        {
            return;
        }
        if (level == 1)
        {
            cout << root->data << " ";
        }
        else if (level > 1)
        {
            display_current_level(root->left, level - 1);
            display_current_level(root->right, level - 1);
        }
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
    int max_depths()
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            return max_depths(root);
        }
    }
    int max_depths(node *root)
    {
        if (!root)
        {
            return 0;
        }
        int ldepth = max_depths(root->left);
        int rdepth = max_depths(root->right);
        if (ldepth > rdepth)
        {
            return ldepth + 1;
        }
        else
        {
            return rdepth + 1;
        }
    }
    int find_lca(int ldata, int rdata)
    {
        if (!root)
        {
            cout << "tree is empty";
            return 0;
        }
        else
        {
            return find_lca(root, ldata, rdata);
        }
    }
    int find_lca(node *root, int ldata, int rdata)
    {
        if (!root)
        {
            return 0;
        }
        if (ldata < root->data && rdata < root->data)
        {
            return find_lca(root->left, ldata, rdata);
        }
        if (ldata > root->data && rdata > root->data)
        {
            return find_lca(root->right, ldata, rdata);
        }
        return root->data;
    }

private:
    node *root;
};

int main()
{
    b_tree mytree;
    int input = 0;
    int menu = 0;

    while (menu != 10)
    {

        cout << endl
             << "1. insert" << endl
             << "2. remove" << endl
             << "3. display in order" << endl
             << "4. display pre order" << endl
             << "5. display post order" << endl
             << "6. display level order" << endl
             << "7. search" << endl
             << "8. max depths" << endl
             << "9. find lowest common ancestor" << endl
             << "10. exit" << endl
             << endl;
        cout << "please enter (1-10): ";
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
            mytree.display_levelorder();
            cout << endl;
        }

        if (menu == 7)
        {
            cout << "please enter data to search: ";
            cin >> input;
            cin.ignore(100, '\n');
            mytree.search(input);
        }

        if (menu == 8)
        {
            cout << "max depths: " << mytree.max_depths() << endl;
        }

        if (menu == 9)
        {
            int ldata;
            int rdata;
            cout << "please enter left data: ";
            cin >> ldata;
            cin.ignore(100, '\n');
            cout << "please enter right data: ";
            cin >> rdata;
            cin.ignore(100, '\n');
            cout << "lowest common ancestor: " << mytree.find_lca(ldata, rdata) << endl;
        }
    }
    return 0;
}