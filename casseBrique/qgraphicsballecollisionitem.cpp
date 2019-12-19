#include "qgraphicsballecollisionitem.h"


QGraphicsBalleCollisionItem::QGraphicsBalleCollisionItem(qreal x, qreal y,
                                                         qreal width,
                                                         qreal height,
                                                         QGraphicsRectItem *_raquette,
                                                         QGraphicsItem *parent):QGraphicsEllipseItem (x,y,width,height,parent),raquette(_raquette),dx(-2),dy(-2)
{

}

void QGraphicsBalleCollisionItem::advance(int step)
{
    moveBy(dx,dy);
    qreal largeurBoule=rect().width();
    qreal largeurScene=scene()->width();
    qreal hauteurScene=scene()->height();

    if(x()<=0 || x()>=(largeurScene-largeurBoule))
    {
        dx=-dx;
    }
    if(y()<=0 || y()>=hauteurScene)
    {
        dy=-dy;
    }
    if(y()>=hauteurScene-largeurBoule )
    {
        //dy=0;
        //dx=0;
        //debut = false;
    }


    QList<QGraphicsItem*> listeDesObjetEnCollisions=this->collidingItems();
    if(listeDesObjetEnCollisions.count()>0)
    {
        foreach(QGraphicsItem *objet,listeDesObjetEnCollisions)
        {
            if(objet!=raquette)
            {
                scene()->removeItem(objet);
                if(objet->y()==20)
                               {
                                   Score += 200;
                               }
                               if(objet->y()==70)
                               {
                                   Score += 150;
                               }
                               if(objet->y()==120)
                               {
                                   Score += 100;
                               }
                               if(objet->y()==170)
                               {
                                   Score += 75;
                               }
                               if(objet->y()==220)
                               {
                                   Score += 40;
                               }
                               if(objet->y()==270)
                               {
                                   Score += 20;
                               }
                               if(objet->y()==320)
                               {
                                   Score += 10;
                               }

                if(y()<=objet->y()+largeurBoule&&y()>=objet->y()-HAUTEURBRIQUE-largeurBoule)
                {
                    dx=-dx;
                }else
                    if(x()>=objet->x()-largeurBoule&&x()<=objet->x()+LARGEURBRIQUE+largeurBoule)
                    {
                        dy=-dy;
                    }
            }else{
                int odd;
                if(dx<0)
                {
                    odd=-2;
                }else {
                    odd=2;
                }
                int angle=QRandomGenerator::global()->bounded(3);
                if (angle==0)
                {
                    dx=odd*2;
                    dy=-2;
                }
                if (angle==1)
                {
                    dx=odd*2.25;
                    dy=-1.5;
                }
                if (angle==2)
                {
                    dx=1.5*odd;
                    dy=-2.25;
                }

            }
        }
    }
}
