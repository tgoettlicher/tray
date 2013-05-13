#include <tray.h>
#include <QApplication>
#include <QPainter>

#define HAPPY ":)"
#define SAD ":("
#define INITIAL ":|"

Tray::Tray(int argc, char ** argv) 
: QApplication::QApplication( argc, argv) 
{

    tray = new QSystemTrayIcon();
    tray->setIcon(QIcon(renderText(INITIAL, Qt::red, Qt::gray)));
    tray->show();

    actionHappy = new QAction(HAPPY, &menu);
    actionSad = new QAction(SAD, &menu);

    connect(actionHappy, SIGNAL(triggered()), this, SLOT(setHappy()));  
    connect(actionSad, SIGNAL(triggered()), this, SLOT(setSad()));  

    menu.addAction(actionHappy);  
    menu.addAction(actionSad);  
    tray->setContextMenu(&menu); 

}

void Tray::setHappy()
{
    tray->setIcon(QIcon(renderText(HAPPY, Qt::black, Qt::yellow)));
}

void Tray::setSad()
{
    tray->setIcon(QIcon(renderText(SAD, Qt::white, Qt::darkGreen)));
}


QPixmap Tray::renderText(QString text, QColor textColor, QColor backgroundColor)
{
    QPixmap pixmap = QPixmap(22,22);
    pixmap.fill( backgroundColor );

    QPainter painter( &pixmap );
    painter.setPen( textColor );

    QRect rect = QRect(0, 0, 21, 21);
    painter.drawText( rect, Qt::AlignCenter, text);
    painter.drawRect( rect );

    return pixmap;
}
