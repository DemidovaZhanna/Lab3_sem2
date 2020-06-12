#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>

#include "my_chart.h"

QT_BEGIN_NAMESPACE
using namespace QtCharts;

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
	QScatterSeries *ser(long long *count_x, double *time_y);

private:
	Ui::MainWindow *ui;
	MyChart *chrt;
	QValueAxis *axisX, *axisY;
};

#endif // MAINWINDOW_H
