#ifndef RONGMAPMAINWINDOW_H
#define RONGMAPMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_RongMapMainWindow.h"

class QgsMapCanvas;
class RongMapMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	RongMapMainWindow(QWidget *parent = 0);
	~RongMapMainWindow();

private:
	Ui::RongMapMainWindowClass ui;
	QgsMapCanvas *canvas;

public slots:
	void openFile();//Open file
};

#endif // RONGMAPMAINWINDOW_H