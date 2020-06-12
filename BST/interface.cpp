#include <iostream>
#include <string>
#include <math.h>
#include "interface.h"

using namespace std;


template<typename K, typename V>
ostream& operator<< (ostream & out, const AVL_tree<K, V>& tree)
{
	tree.const_traversal(tree.LRtR, [&out] (K& key, V& val) {
		out << val << " ";
	});
	return out;
}


void interface_AVL_tree ()
{
	cout << "Choose a type of queue: Integer" << endl;

	int data;
	cout << "Write down size of AVL tree: ";
	cin >> data;

	AVL_tree<int, int> tree;

	int val;
	int key;

	cout << "Enter the values of tree: Please enter the KEY separated by a space, then the VALUE" << endl;

	for (int i = 0; i < data; i++) {
		cin >> key >> val;
		tree.insert(key, val);
	}

	cout << "What do you want to do with tree? (Select the item number)" << endl;
	cout << "1. Add an item by key\n" << "2. Get an item by key\n"
			  << "3. Get the length\n" << "4. Delete an item by key\n"
			  << "5. Map\n" << "6. Where\n" << "7. Reduce\n" << "8. Exit\n";

	int input;

	do {
		cout << "Select the item number: ";
		cin >> input;

		if (input == 1) {
			cout << "Write the key: ";
			int key;
			cin >> key;

			cout << "Write value: ";
			int val;
			cin >> val;

			tree.insert(key, val);
			cout << tree << endl;
		}

		if (input == 2) {
			cout << "Write the key: ";
			int key;
			cin >> key;

			cout << tree.get(key) << endl;
		}

		if (input == 3) {
			cout << "Length is " << tree.size() << endl;
		}

		if (input == 4) {

			cout << "Write the key: ";
			int key;
			cin >> key;

			tree.erase(key);

			cout << tree << endl;
		}

		if (input == 5) {

			cout << "What do you want to do with tree? (Select the item number)" << endl;
			cout << "1. Multiply by x\n" << "2. Raise to the power of x\n"
					  << "3. Add the x value\n";
			int oper;
			cin >> oper;

			AVL_tree<int, int> nov;

			cout << "Enter x: ";
			double x;
			cin >> x;

				if (oper == 1)
					nov = map(tree, [x](int val) {return val * x;});
				if (oper == 2)
					nov = map(tree, [x](int val) {return pow(val, x);});
				if (oper == 3)
					nov = map(tree, [x](int val) {return val + x;});
				cout << nov << endl;
		}

		if (input == 6) {

			cout << "Select a condition" << endl;
			cout << "1. Divided without remainder by 'n'\n" << "2. Positive value\n"
					  << "3. Negative value\n";
			int oper;
			cin >> oper;
			AVL_tree<int, int> nov;

			if (oper == 1) {
				cout << "Enter the divisor: ";
				int div;
				cin >> div;

				while (div == 0) {
					cout << "Try again: ";
					cin >> div;
				}

				nov = where(tree, [div](int val) {
					return (val % div == 0);
				});
			}

			if (oper == 2) {
				nov = where(tree, [](int val) {
					return val > 0;
				});
			}

			if (oper == 3) {
				nov = where(tree, [](int val) {
					return val < 0;
				});
			}
			cout << nov << endl;
		}

		if (input == 7) {
			cout << "Selected action: " << endl;
			cout << "1. Multiply all values by 'n' and add\n"
					  << "2. Multiply the previous value in the crawl by 'n', the current value by 'm'\n";
			int oper;
			cin >> oper;
			AVL_tree<int, int> nov;

			if (oper == 1) {
				cout << "Enter 'n': ";
				int n;
				cin >> n;
				int r = 0;
				int res = reduce(tree, r, [n](int val, int r) {
					r += val * n;
					return r;
				});
				cout << res << endl;
			}

			if (oper == 2) {
				cout << "Enter 'n': ";
				int n;
				cin >> n;

				cout << "Enter 'm': ";
				int m;
				cin >> m;

				int r = 0;
				int res = reduce(tree, r, [n, m] (int val, int r){
					return val*n + r*m;
				});
				cout << res << endl;
			}
		}
	}
	while (input != 8);
}
