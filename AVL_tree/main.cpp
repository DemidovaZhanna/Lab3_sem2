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
}
