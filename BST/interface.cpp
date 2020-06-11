#include <iostream>
#include <string>
#include <math.h>
#include "interface.h"

double mult (int val) {
	std::cout << "Enter x: ";
	double x;
	std::cin >> x;

	return val*x;
}

double degr (int val) {
	std::cout << "Enter x: ";
	double x;
	std::cin >> x;

	return pow(val, x);
}

double sum (int val) {
	std::cout << "Enter x: ";
	double x;
	std::cin >> x;

	return val + x;
}


template<typename K, typename V>
std::ostream& operator<< (std::ostream & out, const AVL_tree<K, V>& tree)
{
	tree.const_traversal(tree.LRtR, [&out] (K& key, V& val) {
		out << val << " ";
	});
	return out;
}


void interface_AVL_tree ()
{
	std::cout << "Choose a type of queue: Integer / Real / String" << std::endl;
	std::string cmd;
	std::cin >> cmd;

	while ( cmd != "Integer" && cmd != "Real" && cmd != "String") {
		std::cout << "Invalid keyword. Try again: ";
		std::cin >> cmd;
	}

	int data;
	std::cout << "Write down size of AVL tree: ";
	std::cin >> data;

	AVL_tree<int, int> tree; //ПОКА ЧТО ТОЛЬКО ДЛЯ ИНТА!!!!

	int val;
	int key;

	std::cout << "Enter the values of tree: ";

	for (int i = 0; i < data; i++) {
		std::cin >> key >> val;
		tree.insert(key, val);
	}
	//std::cout << tree << std::endl;

	std::cout << "What do you want to do with tree? (Select the item number)" << std::endl;
	std::cout << "1. Add an item by key\n" << "2. Get an item by key\n"
			  << "3. Get the length\n" << "4. Delete an item by key\n"
			  << "5. Map\n" << "6. Where\n" << "7. Reduce\n" << "8. Exit\n";

	int input;

	do {
		std::cout << "Select the item number: ";
		std::cin >> input;

		if (input == 1) {
			std::cout << "Write the key: ";
			int key;
			std::cin >> key;

			std::cout << "Write value: ";
			int val;
			std::cin >> val;

			tree.insert(key, val);
			std::cout << tree << std::endl;
		}

		if (input == 2) {
			std::cout << "Write the key: ";
			int key;
			std::cin >> key;

			std::cout << tree.get(key) << std::endl;
		}

		if (input == 3) {
			std::cout << "Length is " << tree.size() << std::endl;
		}

		if (input == 4) {
			std::cout << "Write the key: ";
			int key;
			std::cin >> key;

			tree.erase(key);

			std::cout << tree << std::endl;
		}

		if (input == 5) {
			std::cout << "What do you want to do with tree? (Select the item number)" << std::endl;
			std::cout << "1. Multiply by x\n" << "2. Raise to the power of x\n"
					  << "3. Add the x value\n";
			int oper;
			std::cin >> oper;

			AVL_tree<int, int> nov;

			if (oper == 1)
				nov = map(tree, mult);
			if (oper == 2)
				nov = map(tree, degr);
			if (oper == 3)
				nov = map(tree, sum);
			std::cout << nov << std::endl;
		}

		if (input == 6) {

		}

		if (input == 7) {

		}
	}
	while (input != 8);
}
