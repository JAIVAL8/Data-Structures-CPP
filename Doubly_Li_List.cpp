#include <bits/stdc++.h>

using namespace std;

class Node
{
    /* data */
    public:
        Node *prev;
        int data;
        Node *next;
        
};


class Operations : Node{
    public:
    Node *head=NULL;
    // bool flag=true;
    void insert(int d ){
        
        Node *temp= new Node() ;
        if(head==NULL){
            temp->prev=NULL;
            temp->data=d;
            temp->next=NULL;
            head=temp;
            //flag=false;
        }
        else{
            Node *p = head;
            while(p->next!=NULL){
                p=p->next;
            }
            temp->prev=p;
            temp->data=d;
            temp->next=NULL;
            p->next=temp;
        }
        
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
            insert(val);

        }
    }
    void append(int pos){
       
        int val,c=0;
        cout<<"Enter value to be added at position "<<pos<<endl;
        cin>>val;
        
        Node *p=head;
        while(c<pos-1){
        cout<<c<<endl;
        if (p==NULL) return;
        p=p->next;
        c++;

        }
        
        Node *temp= new Node() ;
        
        
        temp->prev=p->prev;
        temp->data=val;
        temp->next=p;
        if ( pos==1){ p->prev=temp;head=temp;return;}

        (*(p->prev)).next=temp;
        p->prev=temp;
        

        
       
    }
    void deletel(int pos){
       
        int c=0;
       
       
        Node *p=head;
       
        if(pos==1){
            head=p->next;
            delete p;
            return;
        }
        while(c<pos-1 && p!=NULL){
            if (p==NULL) return;
            p=p->next;
            c++;

        }

        
        (*(p->prev)).next= p->next;
        if(p->next==NULL) return;
        (*(p->next)).prev=p->prev;

        delete p;

        
        
    }
    
};
int main(){
    Operations L;
    
    
    int c,n;
    while(true){
            cout<<endl<<"Enter Choice 1 to append / 2 to list out / 3 to append at nth postion / 4 to delete at nth postion"<<endl;
            cin>>c;
        switch (c)
        {
        case 1: L.append();
            break;
         case 2: L.Print();;
            break;
         case 3: cout<<"Enter the position if it is out of bounds it wont affect the list: ";
                cin>>n;
                L.append(n);
            break;
        case 4: cout<<"Enter the position if it is out of bounds it wont affect the list: ";
                cin>>n;
                L.deletel(n);
            break;
        
        
        default:
            break;
        }
    }
    
    


}