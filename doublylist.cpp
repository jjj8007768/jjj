#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int d){
        data=d;
        node* prev=NULL;
        node* next=NULL;
    }
};

void insertathead(node* &head,int n){
    node* temp=new node(n);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertattail(node* &tail,int n){
    node* temp=new node(n);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
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
    current->next->prev=previous;
    delete current;
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

void insertatposition(node* &head, int pos, int new_data) {
    node* nn = new node(new_data);
    if (pos == 1) {
        nn->next = head;
        if (head != NULL)
            head->prev = nn;
        head = nn;
        return;
    }
    node* curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; ++i) {
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << "Position is out of bounds." << endl;
        delete nn;
        return;
    }
    nn->prev = curr;
    nn->next = curr->next;
    curr->next = nn;
    if (nn->next != NULL)
        nn->next->prev = nn;
}

int main(){
    
}