#include <bits/stdc++.h>

using namespace std;

class Node
{
    /* data */
public:
    Node *left;
    int data;
    Node *right;
};

class Operations : Node
{
public:
    Node *root = NULL;
    Node *create(int d)
    {
        Node *temp = new Node();
        temp->data = d;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    Node *insert(Node *root, int d)
    {

        if (root == NULL)
        {
            root = create(d);
        }
        else if (root->data <= d)
        {
            root->right = insert(root->right, d);
        }
        else
        {
            root->left = insert(root->left, d);
        }
        return root;
    }
    void in(int d)
    {
        root = insert(root, d);
    }
    void Print(Node *p)
    {

        if (p->left != NULL)
        {
            Print(p->left);
        }
        if (p->right != NULL)
        {
            Print(p->right);
        }
        cout << p->data << ' ' << endl;
    }
    void P()
    {
        Print(root);
    }
    int M(Node *root)
    {
        if (root->left != NULL)
        {
            M(root->left);
        }
        else
        {
            return root->data;
        }
    }
    void m()
    {
        cout << "Min Val in tree is: " << M(root);
    }
    int H(Node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        else
        {
            return max(H(root->left), H(root->right)) + 1;
        }
    }
    void h()
    {
        cout << "Height of this BST is : " << H(root);
    }
};
int main()
{
    Operations L;

    int c, n;
    while (true)
    {
        cout << endl
             << "Enter Choice 1 to add / 2 to list out / 3 to find min / 4 to find height of Tree" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter the val: ";
            cin >> n;
            L.in(n);
            break;
        case 2:
            L.P();
            break;
        case 3:
            L.m();
            break;
        case 4:
            L.h();
            break;

        default:
            break;
        }
    }
}