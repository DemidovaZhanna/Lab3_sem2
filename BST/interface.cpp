#include <iostream>
#include <string>
#include "interface.h"


template<typename K, typename V>
std::ostream& operator<< (std::ostream & out, const AVL_tree<K, V>& tree)
{
	tree.traversal(tree.LRtR, [&out] (K& key, V& val) {
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

	AVL_tree<int, int> tree;




}
