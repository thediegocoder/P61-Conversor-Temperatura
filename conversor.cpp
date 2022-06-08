#include "conversor.h"
#include "ui_conversor.h"

Conversor::Conversor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Conversor)
{
    ui->setupUi(this);
    // Conectarel dial de Centigrados con el slot de ESTA clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2fahr(int)));
    connect(ui->inFahr, SIGNAL(valueChanged(int)),
            this, SLOT (fahr2cent(int)));
}

Conversor::~Conversor()
{
    delete ui;
}

void Conversor::cent2fahr(int grados)
{
    if (ui->inCent->hasFocus()){
        int f = (grados * 9.0/5) + 32;
        ui->inFahr->setValue(f);
    }

}

void Conversor::fahr2cent(int grados)
{
    if (ui->inFahr->hasFocus()){
        int c = (grados - 32) * 5.0/9;
        ui->inCent->setValue(c);
    }
}

