#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <GL/glu.h>


class glWidget : public QGLWidget
{
    Q_OBJECT
private:
     void drawLine();

public:
    explicit glWidget(QWidget *parent = 0);
    bool draw;
    int x1,y1,x2,y2;

protected:
void initializeGL();
void paintGL();
void resizeGL(int width, int height);


signals:



public slots:
void ButtonClicked();
};

#endif // GLWIDGET_H
