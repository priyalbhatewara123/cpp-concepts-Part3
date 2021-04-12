/*
(6)
Vertical order print of a binary tree.
*/

#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

//by default STL containers are passed by value.
void verticleOrderPrint(node* root , int d , map <int, vector<int>> &m) {

	//base case
	if (root == NULL)
		return;

	m[d].push_back(root -> data);

	//left traverse
	verticleOrderPrint(root -> left , d - 1 , m);

	//right traverse
	verticleOrderPrint(root -> right , d + 1 , m);

}

int main() {

	node* root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(4);
	root -> left -> right = new node(5);
	root -> left -> right -> right = new node(8);
	root -> right -> left = new node(6);
	root -> right -> right = new node(7);
	root -> right -> right -> right = new node(9);

	//key will be the distance and value will be a vector containing all nodes at distance = key
	map <int, vector<int>> m;
	int d = 0;
	verticleOrderPrint(root, d, m);

	for (auto p : m) {
		cout << p.first << " -> ";
		for (int x : p.second)
			cout << x << ", ";

		cout << endl;
	}

	return 0;
}


/*
Leetcode : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
*/