#include <iostream>
#include <stack>

using namespace std

class my_queue
{
private:
	stack<int> s1,s2;
	int current_size;
public:
	my_queue()
	{
		current_size = 0;
	}
	void enqueue(int value)
	{
		s1.push(value);
		current_size++;
	}
	int dequeue()
	{
		int temp;
		if(s1.empty() && s2.empty())
			return;
		if (s2.empty())
		{
			while(s1.size() != 1)
			{
				s2.push(s1.top);
				s1.pop();
			}
			temp = s1.top();
			s1.pop();
		}
		else
			temp = s2.top();
			s2.pop();
		current_size--;
	}
};