#include "mainwindow.h"
#include "measuring_time.hpp"
#include "ui_mainwindow.h"

#include <QLogValueAxis>
#include <QLineSeries>
#include <QValueAxis>
#include <QChartView>
#include <math.h>

QScatterSeries *MainWindow::ser(long long *time_y, long long *count_x)
{
	QScatterSeries* series = new QScatterSeries();
	series->setMarkerSize(100);

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

	chrt = new MyChart(0, 1000, 0, 1000);

	chartView->setChart(chrt);
	chrt->setTitle("Time dependence of the occurrence of large amounts of data in 'insert':");

	std::pair<long long *, long long *>p = time_();

	QScatterSeries* series = ser(p.first, p.second);
	chrt->addSeries(series);
}

MainWindow::~MainWindow()
{
	delete ui;
}

