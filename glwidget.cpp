#include "glwidget.h"
#include <QDebug>
#include <math.h>

glWidget::glWidget(QWidget *parent) :QGLWidget(parent)
{
    initializeGL();
}
void glWidget::initializeGL(){
    draw=false;
    drawGLline=false;
    glClearColor(1.0f,0.0f,0.0f,1.0f);
}
void glWidget::resizeGL(int width, int height){
   glViewport(0,0,width,height);
   gluOrtho2D(0,640,480,0);

}
void glWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,1.0f,0.0f);

    if(draw){


    drawLine();



    }
    if(drawGLline){
        glLineWidth(2.5);
        glColor3f(0.0f,0.0f,1.0f);
        glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glEnd();
    }

}
void glWidget::ButtonClicked(){
    draw=true;
    updateGL();
}

void glWidget::drawLine(){
    int dx=x2-x1;
    int dy=y2-y1;
    int p;
    int twody;
    int twodyminusdx;
    int incr;
    int x,y,steps;
    int xincreament,yincreament;
    int * changingIncreament;
    x=x1;
    y=y1;
    if(abs(dx)>abs(dy)){

        changingIncreament=&yincreament;
        incr=abs(dy)/dy;
        xincreament=dx/abs(dx);
        steps=abs(dx);
        p=2*abs(dy)-abs(dx);

        twody=2*abs(dy);
        twodyminusdx=2*(abs(dy)-abs(dx));
          qDebug()<<twodyminusdx<<"\n";
    }
    else
    {
        yincreament=abs(dy)/dy;
          incr=dx/abs(dx);
          steps=abs(dy);
         changingIncreament=&xincreament;
         p=2*abs(dx)-abs(dy);
         twody=2*abs(dx);
         twodyminusdx=2*(abs(dx)-abs(dy));
    }

    for(int k=0;k<steps;k++){
        if(p<0){
            p+=twody;
            *changingIncreament=0;
        }
        else{
            p+=twodyminusdx;
            *changingIncreament=incr;
        }

        qDebug()<<x<<"\t"<<p<<y<<"\n";
        x+=xincreament;
        y+=yincreament;

        glColor3f(1.0f,1.0f,1.0f);
        glPointSize(2.5f);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();

    }


}
