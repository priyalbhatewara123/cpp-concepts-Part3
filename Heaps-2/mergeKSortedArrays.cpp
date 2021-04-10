#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> node ; //we will store element , array index and element index

vector <int> mergeKSortedArrays(vector <vector<int>> arr) {

	vector<int> res;
	priority_queue <node , vector<node> , greater<node>> pq; //min priority queue

	//insert 0th element of every array in pq
	for (int i = 0; i < arr.size(); i++) {
		pq.push({arr[i][0] , { i , 0}});
	}

	//remove the elements one by one from the min heap and add to result vector
	while (!pq.empty()) {
		node current = pq.top();
		pq.pop();
		int element = current.first;
		int x = current.second.first; //row in which element is present
		int y = current.second.second; //column in which element is present

		res.push_back(element);

		//now push next element (x,y+1) of current
		if (y + 1 < arr[x].size()) {
			pq.push({arr[x][y + 1] , {x, y + 1}});
		}
	}

	return res;

}

int main() {

	vector <vector<int>> arr {
		{2, 6, 12, 15} ,
		{1, 3, 14, 20} ,
		{3, 5, 8, 10}
	};

	vector <int> output = mergeKSortedArrays(arr);
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << " ";
	}
	return 0;
}