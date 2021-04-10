/*
(1)
Implement HashMap - Separate Chaining technique
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node {
public:
	string key;
	T value;
	node<T>* next;

	//constructor
	node(string key , T val) {
		this -> key = key;
		value = val;
		next = NULL;
	}

	//destructor
	~node() {
		if (next != NULL)
			delete next;
	}
};

template <typename T>
class Hashtable {

	node<T>** table; //pointer to hashtable (array of pointers)
	int current_size;
	int table_size;

	int hashFn(string key) {
		int idx = 0;
		int p = 1;
		for (int j = 0; j < key.length(); j++) {
			idx = idx + (key[j] * p) % table_size;
			idx = idx % table_size;
			p = (p * 27) % table_size;
		}
		return idx;
	}

	void rehash() {

		node<T>** oldTable = table;
		int oldTableSize = table_size;

		table_size = 2 * table_size;
		table = new node<T>* [table_size];

		for (int i = 0; i < table_size; i++)
			table[i] = NULL;

		current_size = 0;

		//shift elements from old table to new table
		for (int i = 0; i < oldTableSize; i++) {
			node<T>* temp = oldTable[i];
			while (temp != NULL) {
				insert(temp->key , temp->value);
				temp = temp -> next;
			}
			//to save memory delete linked list present at that index
			//destructor will recursively delete the whole linked list
			if (oldTable[i] != NULL) {
				delete oldTable[i];
			}
		}

		//delete table
		delete [] oldTable;
	}

public:
	Hashtable(int ts = 7) {
		table_size = ts;
		table = new node<T> * [table_size];
		current_size = 0;
		for (int i = 0; i < table_size; i++)
			table[i] = NULL;
	}

	void insert(string key , T value) {

		//hash function will give us index at which we need to store the key - value pair
		int idx = hashFn(key);

		//make a new node
		node<T> * n = new node<T> (key, value);

		//insert at head of the linked list at index idx
		n -> next = table[idx];
		table[idx] = n;
		current_size++;

		//rehashing ...
		float load_factor = current_size / (1.0 * table_size);
		if (load_factor > 0.7) {
			rehash();
		}
	}

	void print() {
		for (int i = 0; i < table_size; i++) {
			cout << "Bucket " << i << " -->";

			//print linked list at that bucket
			node<T>* temp = table[i];
			while (temp != NULL) {
				cout << temp -> key << " " << temp -> value << " --> ";
				temp = temp -> next;
			}
			cout << endl;
		}
	}

	T* search(string key) {

		//we can get index of linked list in which that key is present by hash function
		int idx = hashFn(key);
		node<T>* temp = table[idx];
		while (temp != NULL) {
			if (temp -> key == key)
				return &temp->value; //return address of that box

			temp = temp -> next;
		}

		return NULL;
	}

	void erase(string key) {
		int idx = hashFn(key);
		node<T>* temp = table[idx];

		//delete at head of linked list
		if (temp->key == key) {
			table[idx] = temp->next;
			//delete temp;
			current_size --;
			return;
		}


		node<T>* prev = NULL;
		while (temp != NULL) {
			if (temp -> key == key) {
				prev -> next = temp -> next;
				delete temp;
				return;
			}
			prev = temp;
			temp = temp -> next;

		}

	}

	//operator overloading
	T& operator[](string key) {
		T* f = search(key);

		//if key is not present
		if (f == NULL) {
			//insert key , value(garbage) in table
			T garbage;
			insert(key, garbage);
			f = search(key);
		}
		return *f;
	}
};


int main() {

	Hashtable<int> price_menu;
	price_menu.insert("Burger" , 120);
	price_menu.insert("Pepsi" , 20);
	price_menu.insert("Pizza" , 150);
	price_menu.insert("Noodles" , 25);
	price_menu.insert("Coke" , 40);
	price_menu.insert("Cake" , 250);
	price_menu.insert("Pasta" , 170);

	//price_menu.print();

	int* price = price_menu.search("Noodle");
	if (price == NULL)
		cout << "Not found!";
	else
		cout << "Price is " << *price;

	price_menu.erase("Noodles");
	price_menu.erase("Cake");
	price_menu.print();

	//operator overloading

	//insert
	price_menu["Dosa"] = 60;
	//update
	price_menu["Dosa"] += 10;

	//search
	cout << "Price of Dosa -> " << price_menu["Dosa"];

	return 0;
}

/*
Rehashing is an expensive operation. Therefore to avoid frequent call to rehashing
keep the table size big in starting only.
*/