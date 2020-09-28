#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FrmMain; }
QT_END_NAMESPACE

class FrmMain : public QMainWindow
{
    Q_OBJECT

public:
    FrmMain(QWidget *parent = nullptr);
    ~FrmMain();

private slots:
    void on_btnklausurEintragen_clicked();

    void btnHoleDatum_triggered(QAction *arg1);

    void on_btnEintragLoeschen_clicked();

    void on_btnDurchschnittZumFach_clicked();

    void on_btnAuswahlAufheben_clicked();

    void on_btnNoteEintragen_clicked();

    void on_btnSuchen_clicked();

    void clickedItemOnLwAnzeige();

private:
    Ui::FrmMain *ui;
};
#endif // FRMMAIN_H
