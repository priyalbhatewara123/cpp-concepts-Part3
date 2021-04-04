//Max Heap

#include <bits/stdc++.h>
using namespace std;

class Heap {

	vector <int> v;

	void heapify(int i) {
		int left = 2 * i;
		int right = left + 1;

		int max_i = i;

		if (left < v.size() and v[left] > v[max_i]) {
			max_i = left;
		}
		if (right < v.size() and v[right] > v[max_i]) {
			max_i = right;
		}

		if (max_i != i) {
			//kind of base case + rec case
			swap(v[max_i], v[i]);
			heapify(max_i);
		}
	}

public:
	Heap(int ds = 100) {
		v.reserve(ds);
		v.push_back(-1); //block 0th position
	}

	void push(int data) {

		v.push_back(data);
		int idx = v.size() - 1;
		int parent = idx / 2;

		while (idx > 1 or v[parent] < v[idx]) {
			swap(v[parent] , v[idx]);
			idx = parent;
			parent = parent / 2;
		}

	}

	int top() {
		return v[1];
	}

	void pop() {
		int last_idx = v.size() - 1;
		swap(v[last_idx], v[1]);
		v.pop_back();
		heapify(1);
	}

	bool empty() {
		return v.size() == 1;
	}
};

int main() {

	Heap h;

	int d;
	cin >> d;
	while (d != -1) {
		h.push(d);
		cin >> d;
	}
	while (!h.empty()) {
		cout << h.top() << endl;
		h.pop();
	}
}