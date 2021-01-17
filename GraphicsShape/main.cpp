#include "gsmainscene.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSize desktopSize = qApp->desktop()->screenGeometry().size();
    QSize MainWndSize = QSize(desktopSize.width() - 600, desktopSize.height() - 600);
    QScopedPointer<QGraphicsView> view(new QGraphicsView());
    QScopedPointer<GsMainScene> pScene(new GsMainScene(MainWndSize));
    view->setScene(pScene.data());
    view->resize(MainWndSize);
    view->show();

    return a.exec();
}
