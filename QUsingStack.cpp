// QUsingStack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

class Queue {
	stack<int> s;
public:
	void enque(int data) {
		s.push(data);
	}

	int dequeue() {
		
		if (s.empty())		 //if stack is empty
		{
			cout << "Underflow!!";
			exit(0);
		}

		
		int top = s.top();	 //pop an item from the stack
		s.pop();
		if (s.empty())
			return top;
		
		
		int item = dequeue(); //recur

		s.push(top);
		return item;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 

	int keys[] = { 1,2,3,4,5 };
	Queue q;

	for (int key : keys)
		q.enque(key);
	cout << q.dequeue() << '\n';    // print 1
	cout << q.dequeue() << '\n';    // print 2

	return 0;
}

