#include <iostream>
using namespace std;

template <class T> class Node
{
	Node<T>* next = NULL;
    T data = NULL;
    public:
	Node(T data, Node<T>* next)
	{
		this->data = data;
		this->next = next;
	}

	T getData()
	{	return this->data;	}

	Node<T>* getNext()
	{   return this->next;  }
};

template <class T> class Stack
{
	Node<T> *top = NULL;

	bool isEmpty()
	{
		if(top == NULL)
		{	return true;	}

		return false;
	}

	public:
	void push(T data)
	{
		Node<T>* temp = new Node<T>(data,top);
		top = temp;
	}

	T pop()
	{
		T data;
		if(isEmpty())
		{
			cout<<"underflow!!!";
			data = NULL;
		}
		else
		{
            data = top->getData();
			top = top->getNext();
		}
		return data;
	}

	void display()
	{
		Node<T>* temp = new Node<T>(0,NULL);
		temp = top;
		if(isEmpty())
		{
			cout<<"Underflow!!!";
			return;
		}
		while(temp != NULL)
		{
			cout<<temp->getData();
			if(temp->getNext() != NULL)
				cout<<"->";

			temp = temp->getNext();
		}
		delete temp;
		cout<<endl;
	}

	Node<T>* getTop()
	{	return top;	  }
};

template <class T> class Queue
{
	Stack<T> pushStack,popStack;
	Node<T> *front = NULL, *rear = NULL;

	void isEmpty()
	{
		if(rear  == NULL )
		{	return true;	}

		return false;
	}

	void pushStackFlush()
	{
		while(pushStack.getTop() != NULL)
        {
            T data = pushStack.pop();
           // cout<<data<<" ";
			popStack.push(data);
        }//cout<<endl;
	}

	void popStackFlush()
	{
		while(popStack.getTop() != NULL)
		{
		    T data = popStack.pop();
           // cout<<data<<" ";
			pushStack.push(data);
		}//cout<<endl;
	}

	public:
	void frontDisplay()
	{	cout<<"something missing";	}

	void rearDisplay()
	{	cout<<"something missing";	}

	void enQueue(T data)
	{
	    pushStack.push(data);
	    front = pushStack.getTop();
    }

	T deQueue()
	{
		pushStackFlush();
		T data = popStack.pop();
		rear = popStack.getTop();
		popStackFlush();
		return data;
	}

	void display()
	{
		pushStackFlush();
		popStack.display();
		popStackFlush();
	}
};


int main()
{
    Queue<int> tryQueue;

	tryQueue.enQueue(1);
	tryQueue.enQueue(2);
	tryQueue.enQueue(3);
	tryQueue.enQueue(4);
	tryQueue.enQueue(5);
	tryQueue.enQueue(6);
	cout<<"Queue initially: ";
	tryQueue.display();

	tryQueue.deQueue();
	tryQueue.deQueue();
	cout<<"Test 1 result( 2 deletion): ";
	tryQueue.display();

	tryQueue.enQueue(7);
	tryQueue.enQueue(8);
	cout<<"Test 2 result( 2 insertion): ";
	tryQueue.display();


}
