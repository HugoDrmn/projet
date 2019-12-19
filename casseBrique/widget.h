#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QRandomGenerator>
#include "qgraphicsballecollisionitem.h"
#include "qgraphicsviewperso.h"
#include "scorevie.h"

#define LARGEUR 1100
#define HAUTEUR 720
#define NBOBSTACLES 50
#define LARGEURRAQUETTE 85
#define HAUTEURRAQUETTE 15
#define LARGEURBALLE 25
#define LARGEURBRIQUE 100
#define HAUTEURBRIQUE 30


namespace Ui {
class Widget;
}

class Widget : public QWidget, ScoreVie
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void onQGraphicsView_obtenirPositionSouris(QPointF _positionSouris);
private slots:
    void on_pushButton_clicked();
private:
    Ui::Widget *ui;
    QGraphicsScene scene;
    QGraphicsViewPerso *maVue;
    QGraphicsBalleCollisionItem *maBoule;
    QTimer timer;
    QGraphicsRectItem *laRaquette;
    QGraphicsRectItem *obstacles[NBOBSTACLES];
    bool debut=false;

};

#endif // WIDGET_H
