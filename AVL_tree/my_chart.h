#ifndef MY_CHART_H
#define MY_CHART_H

#include <QtCharts>

class MyChart : public QChart {
	Q_OBJECT
public:
	MyChart(double start_x, double end_x, double start_y, double end_y);
	void addSeries(QAbstractSeries *a);

private:
	QValueAxis *axisX, *axisY;
};


#endif // MY_CHART_H
