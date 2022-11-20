#include <bits/stdc++.h>

using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
};

struct Node *head;

void insert(int d){
    Node *temp=new Node();
    temp->data=d;
    temp->next=head;
    head=temp;
    
}
void Print(){
     cout<<"The List contains:"<<endl;
    Node *p=head;
    while(p!=NULL){
        cout<<p->data<<' ';
        p=p->next;
    }
    
}
int main(){
    head=NULL;
    cout<<"Enter the total count:"<<endl;
    int n;
    cin>>n;
    int val;
    cout<<"Enter values separated by space:"<<endl;

    for(int i=0;i<n;i++){
       
        cin>>val;
        insert(val);

    }
    Print();


}