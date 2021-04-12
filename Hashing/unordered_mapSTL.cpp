/*
(3)
Unordered Map STL
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

	unordered_map<string, int> m;

	//1. Insert

	//Method 1
	m.insert(make_pair("Mango", 100));

	//Method 2
	pair <string, int> p;
	p.first = "Apple";
	p.second = 40;
	m.insert(p);

	//Method 3
	m["Banana"] = 80;

	//since apple is already present ,so it won't create a new key rather update the value of the old key
	m["Apple"] = 120;

	//2. Search
	string fruit;
	cin >> fruit;

	auto it = m.find(fruit);    //data type of iterator is map<string,int> :: iterator it
	if (it != m.end()) {
		cout << "Price of " << fruit << " is " << m[fruit] << endl;
	}
	else {
		cout << fruit << " is not present." << endl;
	}

	//3. Erase
	m.erase(fruit);

	//Another way to search
	if (m.count(fruit)) {
		cout << "Price of " << fruit << " is " << m[fruit] << endl;
	}
	else {
		cout << fruit << " is not present." << endl;
	}

	//only difference between count and find function is that find function returns an iterator while count function returns an integer

	m["Cherry"] = 50;
	m["Pinapple"] = 70;

	//4. Iterate over the map
	//keys are not sorted
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl;
		//cout << it -> first << " " << it->second << endl;
	}

	//we can iterate using for each loop
	for (auto p : m) {
		cout << p.first << " " << p.second << endl;
	}


}

