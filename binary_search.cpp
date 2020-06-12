#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int> arr , int key)
{
	sort(arr.begin() , arr.end());
	int left = 0;
	int right = arr.size() - 1;
	int mid = (left + right) / 2;

	while(left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == key)
		{
			return mid;
		}
		else if(key > arr[mid])
		{
			left = mid + 1;
		}
		else if(key < arr[mid])
		{
			right = mid - 1;
		}
	}
	return -1;
}


int main()
{ 
	vector<int> v;
	v.push_back(9);
	v.push_back(1);
	v.push_back(5);
	v.push_back(2);
	v.push_back(10);
	v.push_back(13);

	cout << "Finding key " << 6 << endl;

	int result = binary_search(v , 6);

	cout << "Result:" << result << endl;
	return 0;
}