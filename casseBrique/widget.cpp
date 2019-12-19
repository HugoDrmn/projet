#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene.setSceneRect(0,0,LARGEUR,HAUTEUR);

    //creation de la raquette
    laRaquette=new QGraphicsRectItem(LARGEUR/2-LARGEURRAQUETTE/2,HAUTEUR-60,LARGEURRAQUETTE,HAUTEURRAQUETTE);
    QPen contour(Qt::RoundJoin);
    laRaquette->setPen(contour);
    QPixmap monImageRaquette("/home/USERS/ELEVES/SNIR2018/hdarmon/casseBrique/raquette.png");
    laRaquette->setBrush(monImageRaquette);
    scene.addItem(laRaquette);

    //creation ma balle
    maBoule=new QGraphicsBalleCollisionItem(0,0,LARGEURBALLE,LARGEURBALLE,laRaquette);
    maBoule->setBrush(QBrush(Qt::green));
    maBoule->setPos(LARGEUR/2,HAUTEUR-85);
    scene.addItem(maBoule);

maVue = new QGraphicsViewPerso(this);

    connect(&timer,&QTimer::timeout,&scene,&QGraphicsScene::advance);
    connect(maVue, &QGraphicsViewPerso::positionSouris, this, &Widget::onQGraphicsView_obtenirPositionSouris);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{




    if(ui->radioButton_gradient->isChecked())
    {
           QColor invisible(0,0,0,0);
           QColor noir(0,0,0);
           QColor roseSombre(80,5,20);
           QColor rose(170,18,50);
           QColor rouge(255,25,40);
           QColor orange(255,130,25);
           QColor orangeJaune(255,200,0);
           QColor jaune(255,255,50);
           QColor blanc(255,255,255);

           QGraphicsRectItem *flammesItem = new QGraphicsRectItem(0,0,1100,720);
           QGraphicsRectItem *fondItem = new QGraphicsRectItem(0,0,1100,720);

           QLinearGradient colorGradientFond(QPointF(550,720) , QPointF(550,0));
           colorGradientFond.setColorAt(0,blanc);
           //colorGradientFond.setColorAt(0.05,jaune);
           colorGradientFond.setColorAt(0.1,orangeJaune);
           //colorGradientFond.setColorAt(0.15,orange);
           colorGradientFond.setColorAt(0.3,rouge);
           colorGradientFond.setColorAt(0.45,rose);
           colorGradientFond.setColorAt(0.7,roseSombre);
           colorGradientFond.setColorAt(1,noir);
           fondItem->setBrush(colorGradientFond);

           QPen contourFond(invisible);
           fondItem->setPen(contourFond);

           QPen contourFlammes(invisible);
           flammesItem->setPen(contourFlammes);

           QPixmap textureFlammes("/home/USERS/ELEVES/SNIR2018/hdarmon/casseBrique/Flammes.png");
           flammesItem->setBrush(textureFlammes);
           scene.addItem(fondItem);
           scene.addItem(flammesItem);
    }
    timer.start(10);

    int num=0;
        int numLigne = 0;

        QColor blanc(255,255,255);
        QColor rouge(Qt::red);
        QColor vert(Qt::green);
        QColor bleu(Qt::blue);
        QColor noir(Qt::black);
        QColor mauve(220, 27, 208);
        QColor jaune(247, 237, 0);
        QColor cyan(11, 220, 226);

        QRadialGradient degrader(QPointF(0,0),150);
        degrader.setColorAt(0,blanc);
        degrader.setColorAt(1,rouge);
        QBrush fondBrique0(degrader);

        QRadialGradient degrader2(QPointF(0,0),150);
        degrader2.setColorAt(0,blanc);
        degrader2.setColorAt(1,vert);
        QBrush fondBrique1(degrader2);

        QRadialGradient degrader3(QPointF(0,0),150);
        degrader3.setColorAt(0,blanc);
        degrader3.setColorAt(1,bleu);
        QBrush fondBrique2(degrader3);

        QRadialGradient degrader4(QPointF(0,0),150);
        degrader4.setColorAt(0,blanc);
        degrader4.setColorAt(1,noir);
        QBrush fondBrique3(degrader4);

        QRadialGradient degrader5(QPointF(0,0),150);
        degrader5.setColorAt(0,blanc);
        degrader5.setColorAt(1,mauve);
        QBrush fondBrique4(degrader5);

        QRadialGradient degrader6(QPointF(0,0),150);
        degrader6.setColorAt(0,blanc);
        degrader6.setColorAt(1,jaune);
        QBrush fondBrique5(degrader6);

        QRadialGradient degrader7(QPointF(0,0),150);
        degrader7.setColorAt(0,blanc);
        degrader7.setColorAt(1,cyan);
        QBrush fondBrique6(degrader7);


        for (int j=20;j<=320;j+=50) {


            for(int i=20;i<=980;i+=120)
            {
                obstacles[num]=new QGraphicsRectItem(0,0,100,30);
                obstacles[num]->setPos(i,j);

                switch (numLigne)
                {
                case 0:

                    obstacles[num]->setBrush(fondBrique0);
                    break;
                case 1:

                    obstacles[num]->setBrush(fondBrique1);
                    break;
                case 2:

                    obstacles[num]->setBrush(fondBrique2);
                    break;
                case 3:

                    obstacles[num]->setBrush(fondBrique3);
                    break;
                case 4:

                    obstacles[num]->setBrush(fondBrique4);
                    break;
                case 5:

                    obstacles[num]->setBrush(fondBrique5);
                    break;
                case 6:

                    obstacles[num]->setBrush(fondBrique6);
                    break;
                }

                scene.addItem(obstacles[num]);
                num++;
            }
            numLigne++;
        }
        //creation vue

        maVue->fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
        maVue->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        maVue->fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
        maVue->setCursor(Qt::BlankCursor);
        maVue->setScene(&scene);
        maVue->show();
        debut=true;

}
void Widget::onQGraphicsView_obtenirPositionSouris(QPointF _positionSouris)
{
    if(_positionSouris.rx() > LARGEURRAQUETTE/2 && _positionSouris.rx()<LARGEUR-LARGEURRAQUETTE/2 )
    {
        laRaquette->setX(_positionSouris.rx()-LARGEUR/2);
        if(debut==false)
        {
            maBoule->setPos(_positionSouris.rx()-10,HAUTEUR-85);
        }
    }
    ui->label_score->setText(QString::number(Score));
    qDebug()<<Score;
}
