#include "RongMapMainWindow.h"
#include <QtCore>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>

#include <qgsapplication.h>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>
#include <qgsproject.h>
#include <qgsrendererpropertiesdialog.h>
#include <qgsstyle.h>
#include <QgsMapLayerStore.h>
#include <qgsmapcanvas.h>
#include <qgsvectorlayer.h>

RongMapMainWindow::RongMapMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	this->resize(800, 600);
	canvas = new QgsMapCanvas(this);
	ui.setupUi(this);
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
	this->setCentralWidget(canvas);
}

RongMapMainWindow::~RongMapMainWindow()
{

}

void RongMapMainWindow::openFile()
{
	QString path = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), "ESRI Shapefile(*.shp)");
	if (path.isEmpty())
		return;

	QgsVectorLayer *layer = new QgsVectorLayer(path, QFileInfo(path).completeBaseName(), "ogr");
	/*if (!layer->isValid())
	{
	QMessageBox::critical(this,tr("Error"),tr("Open file failed!\nReason:%1").arg(layer->error()));
	return;
	}*/

	canvas->setLayers(QList<QgsMapLayer *>() << layer);
	QgsProject::instance()->addMapLayers(QList<QgsMapLayer *>() << layer);

	canvas->setExtent(layer->extent());

	// refresh and wait for rendering
	canvas->refresh();

}