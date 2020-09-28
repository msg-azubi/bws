#include "frmmain.h"
#include "ui_frmmain.h"
#include <QString>
#include <QVector>
#include <QTime>
#include <QApplication>
#include <QCalendarWidget>



//void KlausurEintragen();
//    QString fachEingeben;
//    int noteEingeben;
//    QString datum;
//    fachEingeben = ui->edtFach->text();
//    noteEingeben = ui->edtNotenEingeben->text().toInt();
//    datum = ui->edtDatum->text();

//    ui->lwAnzeige->addItem(QString(datum) + " " + QString(fachEingeben) + " " + QString::number(noteEingeben));


FrmMain::FrmMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FrmMain)
{
    ui->setupUi(this);

    // Wenn Eitragen Button gedrückt wird, muss die Box Desible werden
    ui->grpBoxAenderungLoeschen->setEnabled(false);

    // Verbinde die Signale mit ihren Slots
    this->connect(ui->lwAnzeige, SIGNAL(itemClicked(QListWidgetItem)),   // sender
                  this, SLOT(clickedItemOnLwAnzeige));

}

FrmMain::~FrmMain()
{
    delete ui;
}


void FrmMain::on_btnklausurEintragen_clicked()
{

    //UI leeren.
    ui->lwAnzeige->clear();
    ui->lwSuchtextAnzeige->clear();

//    //Wenn Eitragen Button gedrückt wird, muss die Box Desible werden
//    ui->grpBoxAenderungLoeschen->setEnabled(false);

    // Variablen zu Eingabe zuweisen
    QString fachEingeben = ui->edtFach->text();
    int noteEingeben = ui->edtNotenEingeben->text().toInt();
    QString datum = ui->edtDatum->text();

    // Die Klausr mit Datum, Name und note anzeigen lassen
    ui->lwAnzeige->addItem(QString(datum) + " " + QString(fachEingeben) + " " + QString::number(noteEingeben));


    /*
        Klausur neuerEintrag = new Klausur();
                neuerEintrag.setFach(ui->edtFach->text());

        Klausur neuerEintrag = new Klausur(ui->edtFach->text(), ui->edtDatum->text());
   */
}

void FrmMain::btnHoleDatum_triggered(QAction *arg1)
{
    QDate date;
    QCalendarWidget *calendar;
    calendar->setGridVisible(true);
    calendar->setMaximumDate(QDate(2006, 7, 3));
//    double kalender;
//    kalender = ui->QCalendarWidget->show();
//    ui->calendarWidget->show();
//    ui->gbEintragen->setEnabled(false);
//    ui->lwAnzeige->setEnabled(false);
}


void FrmMain::on_btnNoteEintragen_clicked()
{

}


void FrmMain::on_btnEintragLoeschen_clicked()
{

}


void FrmMain::on_btnDurchschnittZumFach_clicked()
{

}


void FrmMain::on_btnAuswahlAufheben_clicked()
{

}


void FrmMain::on_btnSuchen_clicked()
{

}

void FrmMain:: clickedItemOnLwAnzeige()
{
  qDebug(" clickedItemOnLwAnzeige()") ;
  ui->grpBoxAenderungLoeschen->setEnabled(true);
}
