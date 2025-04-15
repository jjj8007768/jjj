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

class Stack{
Node* head;
int cap;
int currsize;
public:
Stack(int c){
head = NULL;
cap = c;
currsize = 0;
}

void push(int data){
if(cap == currsize){
cout<<"Bhar Gya Bhai Abb Kuch Nhi Dall Sakta"<<endl;
return;
}
Node* new_node = new Node(data);
new_node -> next = head;
head = new_node;
currsize++;
}

void pop(){
if(head == NULL){
cout<<"Bhai Stack Khali Hai"<<endl;
}
Node* temp = head;
head = head->next;
delete temp;
currsize--;
}

void getTop(){
if(head == NULL){
cout<<"Stack is Empty"<<endl;
return;
}
cout<<head->val<<endl;
}

int Size(){
return currsize;
}
};

int main(){
Stack st(5);
st.push(5);
st.push(4);
st.push(3);
st.getTop();
st.push(2);
st.push(1);
st.getTop();
cout<<st.Size()<<endl;
st.pop();
st.getTop();
cout<<st.Size()<<endl;
st.push(2);
st.push(1);
return 0;
}