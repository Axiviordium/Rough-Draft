// StackUsingQRecursive.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

// Implement Stack using single queue and recursion
class Stack
{
	queue<int> q;

public:
	
	void push(int x) {		// Insert an item into the stack
		q.push(x);
	}

	// Utility function to reverse contents of a queue
	void reverseQueue()
	{
		
		if (q.empty())		// base case
			return;

		// hold front element in recursion call stack and insert it back into the queue after recursive call is over
		int front = q.front();
		q.pop();

		reverseQueue();

		q.push(front);
	}

	// Remove the top item from the stack
	int pop()
	{
		if (q.empty()) {
			cout << "Underflow!!";
			exit(0);
		}

		reverseQueue();

		// pop front element of reversed queue
		int front = q.front();
		q.pop();

		reverseQueue();	// revert the queue to original state

		return front;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 

	vector<int> keys = { 1, 2, 3, 4, 5 };

	// insert above keys into the stack
	Stack s;
	for (int key : keys) {
		s.push(key);
	}

	for (int i = 0; i <= keys.size(); i++)
		cout << s.pop() << '\n';

	return 0;
}

