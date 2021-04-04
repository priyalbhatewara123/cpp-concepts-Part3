/*
(1)
Inserting an element in heap. (vector implementation)
Time complexity : O(log N)
*/

#include <bits/stdc++.h>
using namespace std;

class Heap {

	vector<int> v;
	bool minHeap;

	bool compare(int a, int b) {
		if (minHeap)
			return a < b;

		else
			return a > b;
	}

public:
	Heap(int default_size = 10 , bool type = false) {
		v.reserve(default_size);
		v.push_back(-1); //block 0 index
		minHeap = type;
	}

	void push(int d) {
		//insert element at end
		v.push_back(d);

		//compare the element inserted with parent and shift if necessary
		int indx = v.size() - 1;
		int parent = indx / 2;

		//keep pushing to the top till you reach root node or stop midway because current element is already greater than parent(min heap)
		while (indx > 1 or compare(v[indx] , v[parent])) {
			swap(v[indx] , v[parent]);
			indx = parent;
			parent = parent / 2;
		}

	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	return 0;
}