#include<iostream>
#include<vector>
using namespace std;

//node, insert, deletion, search

class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void insertathead(node* &head, int n){
    node* temp=new node(n);
    temp->next=head;
    head=temp;
}

void insertattail(node* &head,int n){
    node* temp=head;
    node* new_Node=new node(n);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_Node;
}

void deletenode(node* &head,int index){
    node* current=head;
    if(index==1){
        head=head->next;
        delete current;
        return;
    }
    node* previous=NULL;
    for(int i=1;i<index;i++){
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
    delete current;
}

void insertNode(node* &head,int n,int index){
    node* temp=new node(n);
    node* current=head;
    node* previous=NULL;
    if(index==0){
        insertathead(head,n);
        return;
    }
    for(int i=0;i<index;i++){
        previous=current;
        current=current->next;
    }
    previous->next=temp;
    temp->next=current;
}

int numberofnodes(node* &head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

void printfromhead(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* head=new node(5);
    insertathead(head,0);
    printfromhead(head);
    insertattail(head,10);
    printfromhead(head);
    deletenode(head,2);
    printfromhead(head);
    insertNode(head,15,1);
    printfromhead(head);
    cout<<numberofnodes(head)<<endl;
    return 0;
}