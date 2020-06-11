#include <iostream>
#include <QApplication>

#include "tests.hpp"
#include "interface.h"
#include "measuring_time.hpp"
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();

//	TestRunner runner;
//	runner.RunTest(tests_base_part_AVL_tree, "tests_base_part_AVL_tree");
//	runner.RunTest(tests_map_where_reduce, "tests_map_where_reduce");

//	cout << endl;
//	interface_AVL_tree();

//	return 0;
}
