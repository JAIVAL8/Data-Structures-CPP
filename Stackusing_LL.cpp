#include <bits/stdc++.h>

using namespace std;

class Node
{
    /* data */
    public:
        int data;
        Node *next;
        
};


class Operations : Node{
    public:
    Node *head=NULL;
    
    void push(int d){
        Node *temp= new Node() ;
     
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
    void append(){
        cout<<"Enter the total count:"<<endl;
        int n;
        cin>>n;
        int val;
        cout<<"Enter values separated by space:"<<endl;

        for(int i=0;i<n;i++){
        
            cin>>val;
            push(val);

        }
    }
    void peak(){
        cout<<head->data<<endl;

    }
    void pop(){
       
        Node *p=head;
        head=p->next;
        cout<<"Poped Element: "<<p->data<<endl;
        delete p;   
    }
    
};
int main(){
    Operations L;
    
    
    int c,n;
    while(true){
            cout<<endl<<"Enter Choice 1 to append / 2 to list out stack contents / 3 to peek / 4 to pop"<<endl;
            cin>>c;
        switch (c)
        {
        case 1: L.append();
            break;
         case 2: L.Print();;
            break;
         case 3: 
                L.peak();
            break;
        case 4:
                L.pop();
            break;
        
        
        default:
            break;
        }
    }
    
    


}