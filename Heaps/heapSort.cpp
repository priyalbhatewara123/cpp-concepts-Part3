#include <bits/stdc++.h>
using namespace std;

void heapify(vector <int> &v, int i , int size) {
	int left = 2 * i;
	int right = left + 1;

	int max_i = i;

	if (left < size and v[left] > v[max_i]) {
		max_i = left;
	}
	if (right < size and v[right] > v[max_i]) {
		max_i = right;
	}

	if (max_i != i) {
		//kind of base case + rec case
		swap(v[max_i], v[i]);
		heapify(v, max_i, size);
	}
}

void buildHeapOptimised(vector <int> &v) {

	for (int i = ((v.size() - 1) / 2); i >= 1; i--) {
		heapify(v, i, v.size());
	}
}


void heapsort(vector<int> &v) {

	//Step 1: Build heap from vector
	buildHeapOptimised(v);

	int n = v.size();

	//remove n-1 elements
	while (n > 1) {
		swap(v[1], v[n - 1]);
		n--;
		heapify(v, 1, n); //manually pass the size of vector as we don't want to heapify whole vector
	}
}

void print(vector <int> v) {
	for (int i = 1; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}


int main() {
	vector <int> v;
	v.push_back(-1);

	int n; cin >> n;
	int temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	heapsort(v);
	print(v);

	return 0;
}