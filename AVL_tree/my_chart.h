#ifndef MY_CHART_H
#define MY_CHART_H

#include <QtCharts>

class MyChart : public QChart {
	Q_OBJECT
public:
	MyChart(int start_x, int end_x, int start_y, int end_y);
	void addSeries(QAbstractSeries *a);

private:
	QValueAxis *axisX, *axisY;
};


#endif // MY_CHART_H
