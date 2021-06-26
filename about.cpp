#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{   
    ui->setupUi(this);
    QPixmap pm(":/images/Resume-logo-LEG.png");
    ui->label_7->setPixmap(pm);
    ui->label_7->setScaledContents(true);
}

About::~About()
{
    delete ui;
}
