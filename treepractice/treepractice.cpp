// treepractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int data;
	struct node* left;
	struct node* right;

	node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	void insert(node *n) {
		if (n->data < data) {
			if (left) {
				left->insert(n);
			}
			else {
				left = n;
			}
		}
		else if (n->data > data) {
			if (right) {
				right->insert(n);
			}
			else {
				right = n;
			}
		}
	}
	int height() {
		if (!left && !right) {
			return 1;
		}

		if (!left && right) {
			return 1 + right->height();
		}
		else if (!right && left) {
			return 1 + left->height();
		}
		else {
			//return max of left and right
			return 1 + std::max(left->height(), right->height());
		}
	}

};


int main()
{
    std::cout << "Hello World!\n";
	node *Tree = new node(10);
	cout << "height:" << Tree->height() << endl;;
	Tree->insert(new node(7));
	cout << "height:" << Tree->height() << endl;;
	Tree->insert(new node(15));
	cout << "height:" << Tree->height() << endl;;
	
	cout << "left branch:" << Tree->left->data << ":" << endl;
	cout << "height:" << Tree->height() << endl;
	Tree->insert(new node(6));
	Tree->insert(new node(5));

	cout << "height:" << Tree->height() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
