#include "CMainWindow.h"
#include "qcustomplot.h"
#include <QtWidgets>

CMainWindow::CMainWindow()
{

    this->showMaximized();
    QWidget* centralWidget  = new QWidget(this);
    QHBoxLayout* mainLayout = new QHBoxLayout();

    QWidget* left = new QWidget();
    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(3);
    left->setSizePolicy(spLeft);
    mainLayout->addWidget(left);

    QWidget* right = new QWidget();
    QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spRight.setHorizontalStretch(1);
    right->setSizePolicy(spRight);
    mainLayout->addWidget(right);

    QVBoxLayout* vbox = new QVBoxLayout;
    right->setLayout(vbox);

    mButton = new QPushButton("Click");
    vbox->addWidget(mButton);
    connect(mButton, SIGNAL(clicked()),
            this, SLOT(buttonClicked()));


    mSensorPlotGrid = new CSensorPlotGrid();

    bool ret = connect(&mRxTask, SIGNAL(sensorDataReceived(CSensorData)),
            mSensorPlotGrid, SLOT(onSensorDataReceived(CSensorData)));

    mRxTask.start();

    left->setLayout(mSensorPlotGrid);

    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);

}
void CMainWindow::buttonClicked()
{
    this->update();
}

void CMainWindow::update()
{
    static float time = 0.0F;
    time += 1.0F;
    CSensorData data;
    data.mTime = time;
    data.mPhi1__d = 0;
    data.mPhi2__d = 1;
    data.mX1__dd  = 2;
    data.mX2__dd  = 3;
    data.mY1__dd  = 4;
    data.mY2__dd  = 5;

    mSensorPlotGrid->addSensorData(data);
}
