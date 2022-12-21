#include <bits/stdc++.h>

using namespace std;

class Node
{
    /* data */
public:
    int data;
    Node *next;
};

class Operations : Node
{
public:
    Node *head = NULL;
    Node *s = NULL;
    Node *front = head;
    Node *rear = head;

    void createQ(int n)
    {
        front = rear = s = head = NULL;
        int i = 0;
        while (i <= n)
        {
            cout << i << endl;
            Node *temp = new Node();

            if (i == 0)
            {
                s = head = temp;
                temp->data = -1;
            }
            else
            {
                temp->data = -1;
                head->next = temp;
                head = temp;
            }
            temp->next = s;

            i++;
        }

        rear = head;
        front = head;
        }

    void enQ(int d)
    {
        if (head == NULL)
        {
            cout << "Create a Q first";
        }
        else
        {

            if (rear->next != front)
            {
                rear->data = d;
                rear = rear->next;
            }

            else
            {
                cout << "Q is Full delete some elements";
                return;
            }
        }
    }
    void Print()
    {
        cout << "The Q contains:" << endl;
        Node *p = front;
        while (p->next != rear->next)
        {
            cout << p->data << ' ';
            p = p->next;
        }
        // cout << (p->next)->data;
    }

    void deQ()
    {
        if (front != rear)
        {
            cout << "Element removed:" << front->data;
        }
        else
        {
            cout << "Q is Empty";
            return;
        }
        front->data = -1;
        front = front->next;
    }
};
int main()
{
    Operations L;

    int c, n;
    while (true)
    {
        cout << endl
             << "Enter Choice 1 to Create Q of size of N  / 2 to list out elements in Q / 3 to EnQ / 4 to DeQ" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter size of Q: ";
            cin >> n;
            L.createQ(n);
            break;

        case 2:
            L.Print();
            break;
        case 3:
            cout << "Enter the value: ";
            cin >> n;
            L.enQ(n);
            break;

        case 4:
            L.deQ();
            break;

        default:
            break;
        }
    }
}