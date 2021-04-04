/*
Priority Queue for custom class:

Priority queue is better than sorting because sorting takes NlogN time while priority takes logN time for finding greatest / least element.
To find k highest element it will take klogN time.
*/

#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person() {
    }

    Person(string n , int a) {
        name = n;
        age = a;
    }

};

class PersonCompare {
public:
    bool operator()(Person A , Person B) {
        return A.age > B.age;
    }
};


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n; cin >> n;
    priority_queue <Person, vector <Person> , PersonCompare> pq; //PersonCompare is the comparator class not a function (this is how STL works xD)
    for (int i = 0; i < n; i++) {
        string name;
        int age;
        cin >> name >> age;
        Person p(name , age);
        pq.push(p);
    }
    int k = 3;
    for (int i = 1; i <= k; i++) {
        Person p = pq.top();
        cout << p.name << " " << p.age << endl;
        pq.pop();
    }
}
