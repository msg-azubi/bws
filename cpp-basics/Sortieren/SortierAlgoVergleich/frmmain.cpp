#include "frmmain.h"
#include "ui_frmmain.h"

FrmMain::FrmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resetTimerLabels();
}

FrmMain::~FrmMain()
{
    delete ui;
}

void FrmMain::resetTimerLabels()
{
    QString initTimerLabel = QString(" --- ms");
    ui->lblTimeBubbleSort->setText(initTimerLabel);
    ui->lblTimeBubbleSortOptm->setText(initTimerLabel);
    ui->lblTimeSelectionSort->setText(initTimerLabel);
    ui->lblTimeInsertSort->setText(initTimerLabel);
    ui->lblTimeQuickSortGruening->setText(initTimerLabel);
    ui->lblTimeQuickSort->setText(initTimerLabel);


}

void FrmMain::on_btnBubbleSort_clicked()
{

}
