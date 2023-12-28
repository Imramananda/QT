#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionnew_triggered();

    void on_actionope_triggered();

    void on_actionsave_triggered();

    void on_actionCut_triggered();

    void on_actioncopy_triggered();

    void on_actionpaste_triggered();

    void on_actionFont_triggered();

    void on_actioncolor_triggered();

    void on_actionbackgroundcolor_triggered();

    void on_actionBackgroundColor_textEdit_triggered();

    void on_actionPrint_triggered();

private:
    Ui::MainWindow *ui;
    QString filePath;
};
#endif // MAINWINDOW_H
