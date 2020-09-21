#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class FrmMain; }
QT_END_NAMESPACE

typedef int datentyp; //Datentyp des Arrays

class FrmMain : public QMainWindow
{
    Q_OBJECT

public:
    FrmMain(QWidget *parent = nullptr);
    ~FrmMain();

private slots:
    void on_btnBubbleSort_clicked();

    void on_btnBubbleSortOptim_clicked();

    void on_btnSelectionSort_clicked();

    void on_btnArrayErzeugen_clicked();

    void pflichtfeldHatSichVeraendert();

private:
    Ui::FrmMain *ui;
    // Type      Variablename
    datentyp* originArray;

    void deaktiviereButtons();

};
#endif // FRMMAIN_H
