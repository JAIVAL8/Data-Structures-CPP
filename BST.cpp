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
    // Create tree
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

    // Print the bst tree
    //  Post order traversal.
    /*Time C O(n)
    Space
    best o(1) (whole tree one sigle child in same directin)
    worst/avg O(n)
    */
    void Level_O(Node *p)
    {
        queue<Node *> q;
        if (p == NULL)
        {
            return;
        }
        q.push(root);
        while (!q.empty())
        {
            Node *cur = q.front();
            cout << cur->data << endl;
            if (cur->left != NULL)
            {
                q.push(cur->left);
            }
            if (cur->right != NULL)
            {
                q.push(cur->right);
            }
            q.pop();
        }
    }
    void In_O(Node *p)
    {

        if (p->left != NULL)
        {
            In_O(p->left);
        }
        cout << p->data << ' ' << endl;
        if (p->right != NULL)
        {
            In_O(p->right);
        }
    }
    void Post_O(Node *p)
    {

        if (p->left != NULL)
        {
            Post_O(p->left);
        }
        if (p->right != NULL)
        {
            Post_O(p->right);
        }
        cout << p->data << ' ' << endl;
    }
    void P()
    {
        cout << " Level order" << endl;
        Level_O(root);
        cout << " In order" << endl;
        In_O(root);
        cout << " Post order" << endl;
        Post_O(root);
    }
    // Find min in bst
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
    // Is it a bst

    // NOTE: BST in order will give elements in sorted order
    /*
    bool gbst(Node *g, int d)
    {
        if (g == NULL)
        {
            return true;
        }
        if (g->data > d && gbst(g->left, g->data) && gbst(g->right, g->data))
        {
            return true;
        }
        else
        {
            cout << "1";
            return false;
        }
    }
    bool lbst(Node *l, int d)
    {
        if (l == NULL)
        {
            return true;
        }
        if (l->data <= d && lbst(l->left, l->data) && lbst(l->right, l->data))
        {
            return true;
        }
        else
        {
            cout << "2";
            return false;
        }
    }
    */

    bool Isbst(Node *p, int minv, int maxv)
    {
        if (p == NULL)
        {
            return true;
        }
        if (p->data > minv && p->data < maxv && Isbst(p->left, minv, p->data) && Isbst(p->right, p->data, maxv))
        {
            return true;
        }
        else
        {
            cout << "3";
            return false;
        }
    }
    void isbst()
    {
        cout << "Is it a binary ST: " << ((Isbst(root, INT_MIN, INT_MAX)) ? "True" : "False");
    }

    // Height check
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
    // Deleting an element from bst
    Node *Util_Del(Node *p, int d)
    {
        if (p == NULL)
        {
            return p;
        }
        else if (d > p->data)
        {
            p->right = Util_Del(p->right, d);
        }
        else if (d < p->data)
        {
            p->left = Util_Del(p->left, d);
        }
        else
        {
            if (p->left == NULL && p->right == NULL)
            {
                delete p;
                p = NULL;
                return p;
            }
            else if (!(p->left != NULL) || !(p->right != NULL))
            {
                Node *temp;
                if (p->left != NULL)
                {
                    temp = p;
                    p = p->left;

                    delete temp;
                    return p;
                }
                else
                {
                    temp = p;
                    p = p->right;
                    delete temp;
                    return p;
                }
            }
            else
            {
                p->data = M(p->right);
                p->right = Util_Del(p->right, p->data);
            }
        }
    }
    void Del(int d)
    {
        root = Util_Del(root, d);
    }
};
int main()
{
    Operations L;

    int c, n, v;
    while (true)
    {
        cout << endl
             << "Enter Choice 1 to add / 2 to list out / 3 to find min / 4 to find height of Tree / 5 to check if tree is bst/ 6 to del data" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter amount of val: ";
            cin >> n;
            cout << endl
                 << "Enter the val: ";
            while (n > 0)
            {
                cin >> v;
                L.in(v);
                n--;
            }
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
        case 5:
            L.isbst();
            break;
        case 6:
            cout << "Enter Data to be deleted: ";
            cin >> n;
            L.Del(n);
            break;
        default:
            break;
        }
    }
}