#include <iostream>
#include <queue>

using namespace std;

class my_stack
{
private:
	queue <int> q1,q2;
	int curr_size;
public:
	my_stack()
	{
		curr_size = 0;
	}

	void push(int value)
	{
		q1.push(value);
		curr_size++;
	}

	void pop()
	{
		if (q1.empty())
		{
			return;
		}
		while(q1.size() != 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
		curr_size--;

		queue <int> q = q1;
		q1 = q2;
		q2 = q;
	}

	int top()
	{
		if (q1.empty())
		{
			return -1;
		}
		while(q1.size() != 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		int temp = q1.front();

		q1.pop();

		q2.push(temp);

		queue <int> q = q1;
		q1 = q2;
		q2 = q;	

		return temp;
	}
	int size()
	{
		return curr_size;
	}
	//~my_stack();
	
};

int main()
{
	my_stack s;

	s.push(1);
	cout << s.top() << endl;
	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;

	return 0;
}