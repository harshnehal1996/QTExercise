#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QTextCharFormat>

QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionsuperscript_triggered(bool checked);

    void on_actionsubscript_triggered(bool checked);

    void on_actionBold_triggered(bool checked);

    void on_actionAbout_triggered();

public slots:

    void on_text_format_change(const QTextCharFormat &f);

private:
    QString this_filename = QString("");
    Ui::Notepad *ui;
};
#endif // NOTEPAD_H
