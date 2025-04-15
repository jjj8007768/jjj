#include<iostream>
using namespace std;

class Node{
public:
int val;
Node* next;
Node(int data){
val = data;
next = NULL;
}
};

class queue{
Node *front, *back;
public:
queue(){
front = NULL;
back = NULL;
}

bool isEmpty(){
if(front == NULL) return true;
else return false;
}

void push(int x){
Node* new_node = new Node(x);
if(isEmpty()){
front = back = new_node;
return;
}
back->next = new_node;
back = new_node;
}

void pop(){
Node* temp = front;
front = front->next;
if(front == NULL){
front = back = NULL;
}
delete temp;
}

void enqueue(){
if(isEmpty()){
cout<<"Queue is Empty"<<endl;
return;
}
cout<<"Peek Value -"<<front->val<<endl;
}

void dequeue(){
if(isEmpty()){
cout<<"Queue is Empty"<<endl;
return;
}
cout<<"Last Value -"<<back->val<<endl;
}
};

int main(){
queue q;
q.push(1);
q.enqueue();
q.dequeue();
cout<<endl;
q.push(2);
q.enqueue();
q.dequeue();
cout<<endl;
q.push(3);
q.enqueue();
q.dequeue();
cout<<endl;
q.push(4);
q.enqueue();
q.dequeue();
cout<<endl;
q.push(5);
q.enqueue();
q.dequeue();
cout<<endl;
q.pop();
q.enqueue();
q.dequeue();
cout<<endl;
q.pop();
q.enqueue();
q.dequeue();
cout<<endl;
q.pop();
q.enqueue();
q.dequeue();
cout<<endl;
q.pop();
q.enqueue();
q.dequeue();
cout<<endl;
q.pop();
q.enqueue();
q.dequeue();
}
