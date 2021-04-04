/*
Build Heap from Array (Vector).
*/

#include <bits/stdc++.h>
using namespace std;

//Max Heap
/*
Method 1:
Time Complexity of this method = O(NlogN)
*/
void buildHeap(vector <int> &v) {

    for (int i = 2; i < v.size(); i++) {
        int idx = i;
        int parent = i / 2;

        while (idx > 1 and v[idx] > v[parent]) {
            swap(v[idx] , v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

/*
Method 2:
Time Complexity = O(N)
*/

void heapify(vector <int> &v, int i) {
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
        heapify(v, max_i);
    }
}

void buildHeapOptimised(vector <int> &v) {

    for (int i = ((v.size() - 1) / 2); i >= 1; i--) {
        heapify(v, i);
    }
}

void print(vector <int> v) {
    for (int e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    //vector <int> v{-1,4 , 1, 3,7,8,17,2,9,10};
    vector <int> v{ -1, 10, 20, 5, 6, 1, 8, 9, 4};
    buildHeap(v);
    print(v);
}
