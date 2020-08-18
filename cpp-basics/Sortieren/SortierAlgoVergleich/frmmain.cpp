#include "frmmain.h"
#include "ui_frmmain.h"

FrmMain::FrmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

FrmMain::~FrmMain()
{
    delete ui;
}

void FrmMain::on_btnBubbleSort_clicked()
{

}
