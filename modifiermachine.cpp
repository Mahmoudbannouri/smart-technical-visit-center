#include "modifiermachine.h"
#include "ui_modifiermachine.h"
#include "machine.h"
#include "QMessageBox"

ModifierMachine::ModifierMachine(int id,QWidget *parent) : QDialog(parent),
    ui(new Ui::ModifierMachine)
{
    ui->setupUi(this);
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select ID_SERVICE||'-'||TYPE from GESTION_SERVICES ORDER BY ID_SERVICE");
    ui->comboBox_IDSERVICE_Modifier->setModel(model);
    Machine M;
    M.charger(id);

    QString ID_Machine = QString::number(M.get_IdMachine());
    QString ID_Service = QString::number(M.get_IdService());
    ui->lineEdit_IDMACHINE_Mod->setText(ID_Machine);
    ui->comboBox_EtatM_Modifier->setCurrentText(M.get_Etat());
    ui->lineEdit_Description_Modif->setText(M.get_Description());
    ui->comboBox_IDSERVICE_Modifier->setCurrentText(ID_Service);

    this->repaint();
}

ModifierMachine::~ModifierMachine()
{
    delete ui;
}

void ModifierMachine::on_pushButton_Modifier_clicked()
{

    int ID_MACHINE = ui->lineEdit_IDMACHINE_Mod->text().toInt();
    QString ETAT = ui->comboBox_EtatM_Modifier->currentText();
    QString DESCRIPTION = ui->lineEdit_Description_Modif->text();
    QString IDS = ui->comboBox_IDSERVICE_Modifier->currentText();
    int ID_SERVICE=IDS.split("-")[0].toInt();

    Machine M(ID_MACHINE, ETAT, DESCRIPTION,ID_SERVICE);

    bool test = M.modifier(ID_MACHINE);

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                                 QObject::tr("Modification effectuee.\n"
                                             "Click Ok to exit."),
                                 QMessageBox::Ok);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modification"),
                              QObject::tr("Modification non effectuee.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);
    this->hide();
}
