#include<iostream>
using namespace std; 

class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int n){
        if(top<size){
            top++;
            arr[top]=n;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }

    int topele(){
        if(top>-1 )
            return arr[top];
        else
            cout<<"stack is empty"<<endl;
    }

    bool empty(){
        if(top==-1)
            return false;
        else
            return true;
    }
};

int main()
{
    Stack st(5);

    st.push(5);
    st.push(6);
    st.push(2);
    st.push(1);
    st.push(8);
    st.push(51);

    cout<<st.empty()<<endl;
    cout<<st.topele()<<endl;

    return 0;
}