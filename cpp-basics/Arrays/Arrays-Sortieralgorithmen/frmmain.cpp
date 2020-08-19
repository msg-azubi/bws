#include "frmmain.h"
#include "ui_frmmain.h"
#include <QString>
#include <QTime>
#include <random>
#include <stdlib.h>


FrmMain::FrmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FrmMain)
{
    ui->setupUi(this);
}

FrmMain::~FrmMain()
{
    delete ui;
}


void arrayAnzeigen(datentyp *array,int anz, QListWidget* lwAnzeige) {
    lwAnzeige->clear();
    lwAnzeige->setVisible(false); //sonst kostet die Anzeige zu viel Rechenzeit!
    for (int i=0; i<=anz; i++) {
        lwAnzeige->addItem(QString::number(array[i]));
    }
    lwAnzeige->setVisible(true);
}


void FrmMain::on_btnArrayErzeugen_clicked()
{
    // Welche Infos brauche ich hier?
    // a) Wieviele Elemente:
    const int  anzahlElemente = ui->edtAnzahlElemente->text().toUInt();
    const int groessteZufallszahl = ui->edtGroussteZufallszahl->text().toUInt();

    this->originArray = new datentyp[anzahlElemente];

    for (int i = 0; i < anzahlElemente; ++i) {
        originArray[i] = rand() % groessteZufallszahl;
    }

    arrayAnzeigen(this->originArray, anzahlElemente, ui->lwOriginal);
}


void bubbleSort(datentyp* feld, int anz) //aufsteigendes Sortieren
{
    datentyp tmp;

    for (int x=0; x < anz -1; x++) {
        for (int i=0; i <= anz -1; i++) {
            if (feld[i] > feld[i+1]) {
                tmp = feld[i];
                feld[i] = feld[i+1];
                feld[i+1] = tmp;
            } //if
        } //for i
    } // for x
}




void FrmMain::on_btnBubbleSort_clicked()
{

    this->setCursor(Qt::WaitCursor);
    QTime time;
    const int  anzahlElemente = ui->edtAnzahlElemente->text().toUInt();

    datentyp* tmpArray = new datentyp[anzahlElemente];
    tmpArray = this->originArray;
    time.start();
    bubbleSort(tmpArray, anzahlElemente);
    ui->edtTimeBubbleSort->setText(QString::number(time.elapsed())+ " ms");
    arrayAnzeigen(tmpArray,anzahlElemente,ui->lwKopie);
    delete tmpArray;
    this->setCursor(Qt::ArrowCursor);

}

void FrmMain::on_btnBubbleSortOptim_clicked()
{

}

void FrmMain::on_btnSelectionSort_clicked()
{

}


