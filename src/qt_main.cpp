#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QBrush>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextCursor>
#include <QtMath>
#include <cmath>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawAurora(QPainter &painter);
};

#endif // MAINWINDOW_Hmanzini@fedora:~/ProjectFiles/C++Projects/manager/src$ 
