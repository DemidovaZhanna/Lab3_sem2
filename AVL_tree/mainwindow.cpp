#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "binary_search_tree.hpp"

#include <QLogValueAxis>
#include <QLineSeries>
#include <QValueAxis>
#include <QChartView>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>


int64_t N = 30000000;
int n = 5000;

std::pair<long long *,double *> time_() {

	std::ios_base::sync_with_stdio(false);
	int el = 0;
	AVL_tree<int, int> tree;

	std::vector<int> elements(N);
	std::iota(elements.begin(), elements.end(), 1);
	std::shuffle(elements.begin(), elements.end(), std::default_random_engine(time(nullptr)));


	double *y_time = new double[N/n];
	long long *x_count = new long long[N/n];

	for(int i = 0; i < N/n; i++) {
		auto start = std::chrono::high_resolution_clock::now();

		for(int j = 0; j < n; j++) {
			tree.insert(elements[el], elements[el]);
			el++;
		}

		auto stop = std::chrono::high_resolution_clock::now();
		long long time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

		double time_one = (double)time / (double)n;

		y_time[i] = time_one;
		x_count[i] = tree.size();
		std::cout << x_count[i] << ' ' << y_time[i] << '\n';
	}

	std::pair<long long *,double *>p = {x_count, y_time};
	return p;
}

QScatterSeries *MainWindow::ser(long long *count_x, double *time_y)
{
	QScatterSeries* series = new QScatterSeries();
	series->setMarkerSize(5);

	for (int i = 0; i < N/n; i ++)
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

	chrt = new MyChart(0, N, 0, 10);

	chartView->setChart(chrt);
	chrt->setTitle("Time dependence of the occurrence of large amounts of data in 'insert':");

	std::pair<long long *, double *>p = time_();

	QScatterSeries* series = ser(p.first, p.second);

	chrt->addSeries(series);
}

MainWindow::~MainWindow()
{
	delete ui;
}

