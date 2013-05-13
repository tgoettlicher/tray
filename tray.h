#ifndef tray_h
#define tray_h


#include <QApplication>
#include <QObject>
#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>


class Tray : public QApplication 
{
    Q_OBJECT

public:    
    Tray(int argc, char** argv);

private:
    QMenu menu;
    QSystemTrayIcon *tray;

    QAction* actionHappy;
    QAction* actionSad;

    QPixmap renderText(QString, QColor, QColor);

public slots:
    void setHappy();
    void setSad();

};


#endif

