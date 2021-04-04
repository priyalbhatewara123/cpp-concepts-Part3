#include <bits/stdc++.h>
using namespace std;

int main() {
    //by default priority queue is max heap
    //priority_queue <int> pq;

    //to convert it in minheap pass an inbuilt comparator
    priority_queue <int , vector <int> , greater <int> > pq;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        pq.push(d);
    }

    //Remove element from heap
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}
