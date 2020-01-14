// StackUsingQ.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

//Implement stack using two queues
class Stack
{
	queue<int> q1, q2;
public:
	
	void push(int data) {	// Insert an item into stack
		q1.push(data);
	}

	
	int pop() {				//Remove the top item from the stack
		
		if (q1.empty())
		{
			cout << "Stack Underflow!!";
			exit(0);
		}

		//Move all elements except last from first queue to the second queue
		int front;
		while (!q1.empty())
		{
			if (q1.size() == 1)
				front = q1.front();
			else
				q2.push(q1.front());
			q1.pop();
		}

		//Return the last element after moving all elements back to the first queue
		//Below loop can be replaced with a call to swap(q1, q2)
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}

		return front;
	}

};



int main()
{
    std::cout << "Hello World!\n"; 

	vector<int> keys = { 1,2,3,4,5 };

	//insert above keys into the stack
	Stack s;
	for (int key : keys) {
		s.push(key);
	}

	for (int i = 0; i <= keys.size(); i++)
		cout << s.pop() << '\n';
	return 0;
}

