/*
(5)
Unordered Map Example - Phonebook

Phonebook - Store multiple numbers of same contact.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

	unordered_map <string , vector<string> > phonebook;

	phonebook["Rahul"].push_back("9876");
	phonebook["Rahul"].push_back("9875");
	phonebook["Rahul"].push_back("9874");
	phonebook["Kajol"].push_back("876");
	phonebook["Kajol"].push_back("8761");
	phonebook["Kajol"].push_back("8762");
	phonebook["Pushpa"].push_back("7645");
	phonebook["Pushpa"].push_back("9801");

	for (auto p : phonebook) {
		cout << "Name : " << p.first << endl;
		cout << "Number : ";
		for (string s : p.second)
			cout << s << " ";
		cout << endl;
	}

	//query
	string name; cin >> name;
	if (phonebook.count(name) == 0) {
		cout << "Contact not present!";
	}
	else {
		for (string s : phonebook[name]) {
			cout << s << " ";
		}
	}

	return 0;
}