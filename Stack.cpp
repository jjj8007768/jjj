#include <iostream>
using namespace std;

class Stack
{
    int cap;
    int *arr;
    int top;

public:
    Stack(int c)
    {
        cap = c;
        arr = new int[c];
        top = -1;
    }

    void resize(){
        cap *=2;
        int* newArr = new int[cap];
        for(int i = 0; i < top; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    void push(int data)
    {
        if (top == cap - 1)
        {
            cout << "Bhar Gaya Abb Add nhi ho sakta" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        top--;
    }

    void getTop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << arr[top] << endl;
    }

    int Size()
    {
        return top + 1;
    }

    void display(){
        for(int i=top; i>=0; i--){
            cout << arr[i]<<" ";
        }
        cout <<endl;
    }
};
int main()
{
    Stack st(5);
    st.push(5);
    st.push(4);
    st.push(3);
    st.getTop();
    st.push(2);
    st.push(1);
    st.display();
    st.getTop();
    cout << st.Size() << endl;
    st.pop();
    st.getTop();
    cout << st.Size() << endl;
    st.push(2);
    st.push(1);
    return 0;
}
