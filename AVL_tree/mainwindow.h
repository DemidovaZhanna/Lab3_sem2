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
	QLineSeries *ser(long long *time_y, long long *count_x);

private:
	Ui::MainWindow *ui;
	MyChart *chrt;
	QValueAxis *axisX, *axisY;
};

#endif // MAINWINDOW_H
