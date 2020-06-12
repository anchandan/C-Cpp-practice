#include <iostream>
#include <unordered_map>

using namespace std;

int compute_score(int number);

int main()
{
	int number = 96785233;

	cout << compute_score(number) << endl;
}

int compute_score(int number)
{
	int score = 0;
	int found_five = 0;
	int found_consecutive_3s = 0;
	bool cons_three = 0;
	int previous_digit = 0;
	int odd_digit = 0;
	int current_digit = 0;
	int sequence = 1;

	if(number % 5 == 0)
	{
	    cout << "Adding 6" << endl;
		score += 6;
	}
	while(number)
	{
		current_digit = number % 10;
		number = number / 10;
		
		if (current_digit % 2)
		{
		    cout << "Adding 1"<< endl;
			score += 1;
		}

		if (current_digit == 5)
		{
		    cout << "Adding 2" << endl;
			score += 2;
		}
		
		if (current_digit == 3)
		{
			if (cons_three)
			{
			    cout << "Adding 4" << endl;
				score += 4;
			}
			else
			{
				cons_three = true;
			}
		}
		else
		{
			cons_three = false;
		}

		if ((previous_digit - 1) == current_digit)
		{
		    cout << "Found sequence"<<endl;
		    cout << "previous_digit " << previous_digit << " current_digit " << current_digit << endl;
			sequence++;
			cout << "sequence " << sequence << endl;
		}
		else
		{
		    cout << "previous_digit " << previous_digit << " current_digit " << current_digit << endl;
		    cout << "Adding " << sequence*sequence << endl; 
			score += sequence * sequence;
			sequence = 1;
		}
		previous_digit = current_digit;
	}
	return score;
}