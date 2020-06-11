#include "my_chart.h"


MyChart::MyChart(int start_x, int end_x, int start_y, int end_y)
{
	axisX = new QValueAxis;
	axisY = new QValueAxis;

	axisX->setRange(start_x, end_x);
	axisY->setRange(start_y, end_y);

	axisX->setLabelFormat("%.2f");
	axisY->setLabelFormat("%g");
}

void MyChart::addSeries(QAbstractSeries *a)
{
	this->QChart::addSeries(a);
	setAxisX(axisX, a);
	setAxisY(axisY, a);
}
