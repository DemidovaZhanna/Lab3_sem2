#include "mainwindow.h"
//#include "measuring_time.hpp"
#include "ui_mainwindow.h"
#include "binary_search_tree.hpp"

#include <QLogValueAxis>
#include <QLineSeries>
#include <QValueAxis>
#include <QChartView>
#include <math.h>

std::pair<long long *,long long *> time_() {

	int64_t N = 1000000;
	AVL_tree<int, int> tree;
	int el = 1;
	int n = 1000;

	long long *y_time = new long long[N];
	long long *x_count = new long long[N];

	for(int i = 0; i < N/n; i++) {
		auto start = std::chrono::high_resolution_clock::now();

		for(int i = 0; i < n; i++) {
			tree.insert(el, el);
			el++;
		}

		auto stop = std::chrono::high_resolution_clock::now();
		long long time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

		long long time_one = time / n;

		y_time[i] = time_one;

		x_count[i] = tree.size();
		el++;
	}

	std::pair<long long *,long long *>p = {x_count, y_time};
	return p;
}

QLineSeries *MainWindow::ser(long long *time_y, long long *count_x)
{
	QLineSeries* series = new QLineSeries();

	for (int i = 0; i < 1000; i++)
		series->append(count_x[i], time_y[i]);

	return series;
}


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QChartView *chartView = new QChartView(this);
	QSize t = this->minimumSize();
	chartView->setMinimumSize(t.width(), t.height());

	chrt = new MyChart(0, 100000, 0, 1);

	chartView->setChart(chrt);
	chrt->setTitle("Time dependence of the occurrence of large amounts of data in 'insert':");

	std::pair<long long *, long long *>p = time_();

	QLineSeries* series = ser(p.first, p.second);
	chrt->addSeries(series);
}

MainWindow::~MainWindow()
{
	delete ui;
}

