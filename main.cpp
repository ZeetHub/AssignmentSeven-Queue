#include<iostream>
using namespace std;

#include "queueArrayImplementation.cpp"
int main()
{
    queue<int> q;
    create(q, 50);
    cout<<isEmpty(q);
    cout<<isFull(q);

    cout<<endl;

    enqueue(q, 32);
    enqueue(q, 30);
    enqueue(q, 33);
    cout<<isEmpty(q);
    cout<<isFull(q);

    cout<<peekFront(q)<<endl;
    cout<<peekRear(q)<<endl;
}