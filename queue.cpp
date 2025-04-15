#include<iostream>
using namespace std;


class queue{
public:
int iniCap;
int* arr;
int front;
int back;
queue(int iniCap){
arr = new int[iniCap];
front = -1;
back = -1;
}


void resize(){
iniCap *=2;
int* newArr = new int[iniCap];
for(int i = front; i <= back; i++){
newArr[i] = arr[i];
}
delete[] arr;
arr = newArr;
}

void push(int x){
if(back == iniCap-1){
resize();
}
back++;
arr[back] = x;
if(front = -1){
front++;
}
}

void pop(){
if(front > back || front == -1){
cout<<"Queue is Empty"<<endl;
return;
}
front++;
}

void peek(){
if(front > back || front == -1){
cout<<"Queue is Empty"<<endl;
return;
}
cout<<arr[front]<<endl;
}

void display(){
if(front > back || front == -1){
cout<<"Queue is Empty"<<endl;
return;
}
for(int i = front; i <= back; i++){
cout<<arr[i]<<" ";
}
cout<<endl;
}
};

int main(){
queue q(5);
q.push(1);
q.display();
q.push(2);
q.display();
q.push(3);
q.display();
q.push(4);
q.display();
q.push(5);
q.display();
q.push(6);
q.display();
q.pop();
q.display();
q.pop();
q.display();
q.pop();
q.display();
q.pop();
q.display();
q.pop();
q.display();
q.pop();
q.display();
q.peek();
return 0;
}