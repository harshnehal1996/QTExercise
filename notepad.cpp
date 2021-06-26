#include "notepad.h"
#include "ui_notepad.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QAbstractButton>
#include "about.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this_filename = "";
    QObject::connect(ui->textEdit, &QTextEdit::currentCharFormatChanged, this, &Notepad::on_text_format_change);
    setCentralWidget(ui->textEdit);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_actionNew_triggered()
{
    this_filename = "";
    ui->textEdit->setText(QString(""));
}

void Notepad::on_text_format_change(const QTextCharFormat &f){
    if(f.fontWeight() == QFont::Bold)
        this->ui->actionBold->setChecked(true);
    else
        this->ui->actionBold->setChecked(false);

    switch(f.verticalAlignment()){
        case QTextCharFormat::AlignSubScript:
        {
            this->ui->actionsubscript->setChecked(true);
            this->ui->actionsuperscript->setChecked(false);
            break;
        }
        case QTextCharFormat::AlignSuperScript:
        {   this->ui->actionsuperscript->setChecked(true);
            this->ui->actionsubscript->setChecked(false);
            break;
        }
        default:
        {
            this->ui->actionsubscript->setChecked(false);
            this->ui->actionsuperscript->setChecked(false);
            break;
        }
    }
}

void Notepad::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, QString("Open location"));
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QFile::Text);
    if(!file.isOpen()){
        QMessageBox::warning(this, "Warning Message", "Not able to open");
        return;
    }
    this_filename = filename;
    QTextStream ins(&file);
    ui->textEdit->setText(ins.readAll());
    setWindowTitle(this_filename);
    file.close();
}

void Notepad::on_actionSave_triggered()
{
    if(this_filename == ""){
        on_actionSave_As_triggered();
        return;
    }
    QFile file(this_filename);
    file.open(QFile::WriteOnly | QFile::Text);
    if(!file.isOpen()){
        QMessageBox::warning(this, "Warning Message", "Not able to save");
        return;
    }
    QTextStream ins(&file);
    ins << ui->textEdit->toPlainText();
    file.close();
}

void Notepad::on_actionSave_As_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, QString("save file location"));
    QFile file(filename);
    file.open(QFile::WriteOnly | QFile::Text);
    if(!file.isOpen()){
        QMessageBox::warning(this, "Warning Message", "Not able to save");
        return;
    }
    this_filename = filename;
    QTextStream ins(&file);
    ins << ui->textEdit->toPlainText();
    setWindowTitle(this_filename);
    file.close();
}

void Notepad::on_actionExit_triggered()
{
    QMessageBox box;
    box.setText("Are you sure");
    box.setInformativeText("Do you want to save your changes?");
    box.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    box.setDefaultButton(QMessageBox::Save);
    box.setParent(this);
    int ret = box.exec();

    switch (ret) {
      case QMessageBox::Save:
          on_actionSave_triggered();
          break;
      case QMessageBox::Discard:
          break;
      case QMessageBox::Cancel:
          return;
          break;
      default:
          break;
    }
    QApplication::exit();
}

void Notepad::on_actionsuperscript_triggered(bool checked)
{
    QTextCharFormat format;
    int alignment;
    if(!checked)
        alignment = QTextCharFormat::AlignNormal;
    else
        alignment = QTextCharFormat::AlignSuperScript;

    format.setVerticalAlignment((QTextCharFormat::VerticalAlignment)alignment);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}

void Notepad::on_actionsubscript_triggered(bool checked)
{
    QTextCharFormat format;
    int alignment;
    if(!checked)
        alignment = QTextCharFormat::AlignNormal;
    else
        alignment = QTextCharFormat::AlignSubScript;

    format.setVerticalAlignment((QTextCharFormat::VerticalAlignment)alignment);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}

void Notepad::on_actionBold_triggered(bool checked)
{
    QTextCharFormat format;
    if(checked)
        format.setFontWeight(QFont::Bold);
    else
        format.setFontWeight(QFont::Normal);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}

void Notepad::on_actionAbout_triggered()
{
    About a(this);
    a.setModal(true);
    a.exec();
}
