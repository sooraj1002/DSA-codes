#include<bits/stdc++.h>
using namespace std; 

class mQueue{
    int* arr;
    int* front;
    int* rear;
    int* next;
    int freespace;
    int n,k;
    
    public:
    mQueue(int k,int n){
        this->n=k;
        this->k=n;
        arr = new int[n];
        next=new int[n];
        front=new int[k];
        rear=new int[k];
        freespace=0;
        
        for(int i=0;i<n;i++)
            next[i]=i+1;
        next[n-1]=-1;

        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }
    }

    void Enqueue(int data,int qn){
        if(freespace==-1){
            cout<<"no empty space"<<endl;
            return;
        }
        //find place to insert ele
        int index=freespace;
        //update to next free space
        freespace=next[index];
        if(front[qn-1]==-1)
            front[qn-1]=index;
        else{
            //link 
            next[rear[qn-1]]=index;
        }
        //update next
        next[index]=-1;

        // update rear
        rear[qn-1]=index;
        
        arr[index]=data;
        cout<<"success "<<endl;
    }

    int dequeue(int qn){
        //underflow
        if(front[qn-1]==-1){
            cout<<"underflow"<<endl;
            return -1;
        }
        
        int index=front[qn-1];
        front[qn-1]=next[index];
        next[index]=freespace;
        freespace=index;
        return arr[index];
    }
};

int main()
{
    mQueue obj(3,5);
    obj.Enqueue(5,1);
    obj.Enqueue(8,1);
    obj.Enqueue(9,2);
    obj.Enqueue(100,3);
    obj.Enqueue(69,1);
    obj.Enqueue(6969,1);
    cout<<obj.dequeue(1)<<endl;
    cout<<obj.dequeue(1)<<endl;
    cout<<obj.dequeue(1)<<endl;
    cout<<obj.dequeue(1)<<endl;
    return 0;
}