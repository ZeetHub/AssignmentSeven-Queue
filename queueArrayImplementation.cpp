#include<iostream>
using namespace std;

const int NIL{-1};
template<class T>
struct queue
{
    T* baseArray;
	int capacity;
	int front;
	int rear;
	int count;
};

template <class T>
bool create(queue<T> & q, int capacity=20) 
{
	q.baseArray=new (nothrow) T[capacity];
	if(!q.baseArray)
		return false;
	q.capacity=capacity;
	q.rear = q.front=NIL;
	q.count=0;
	return true;
}

template<class T>
void clear(queue<T> &q)
{
    q.front = q.rear = NIL;
}

template <class T>
bool isEmpty (queue<T> q)
{
	return q.count==0;
}

template<class T>
bool isFull(queue<T> q)
{
    return q.count == q.capacity-1;
}

template <class T>
void destroy (queue<T> & q) {
		clear(q);
		q.capacity=0;
		delete q.baseArray;
}

template <class T>
bool enqueue (queue<T> & q, T item)
{	
	if (!isFull(q))
    {
		q.rear = (q.rear + 1)%q.capacity;
		q.baseArray[q.rear]=item;
		if (isEmpty(q)) 
			q.front=q.rear;	
		q.count++;
		return true;
	}
    else
		return false;
}

template<class T>
T dequeue(queue<T> &q)
{
    if (!isEmpty(q))
    {
		q.front = (q.front + 1)%q.capacity;	
		q.count--;
		return true;
	}
    else
		return false;
}

template <class T>
T peekFront (queue<T> q)
{
	return q.baseArray[q.front];
}

template<class T>
T peekRear(queue<T> &q)
{
    return q.baseArray[q.rear];
}

template <class T>
bool copy (queue<T> src, queue<T> dst)
{
    T * tmp;
    tmp= new (nothrow) T[src.capacity];
    if(!tmp)
        return false;
    destroy(dst);
    dst.baseArray=tmp;
    int j=src.front;
    for(int i=1; i<=src.count; i++)
    {
        dst.baseArray[j]= src.baseArray[j];
        j++;
        if(j==src.capacity) 
            j=0;
    }
    dst.front=src.front;  
    dst.rear=src.rear;
    dst.count=src.count;
    return true;
}

// template<class T>
// bool resize(int capacity)
// {

// }