#include "mainwindow.h"

#include <QPixmap>
#include <QCursor>
#include <QDir>

const char *base = "/usr/share/icons/hicolor/32x32/apps/";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , b_("Hit Me", this)
{
    QDir d(base);
    paths = d.entryList(QDir::Files);

    b_.resize(b_.sizeHint());
    connect(&b_, &QPushButton::clicked, [=]() {
        auto path = paths[i++ % paths.size()];
        QPixmap p(base + path);
        QCursor c(p);
        b_.setCursor(c);
    });
}

MainWindow::~MainWindow()
{

}
