#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  // connect(ui->pushButton,SIGNAL(clicked()),ui->widget,SLOT(ButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
  ui->widget->x1=ui->x1in->text().toInt();
  ui->widget->y1=ui->y1in->text().toInt();
  ui->widget->x2=ui->x2in->text().toInt();
  ui->widget->y2=ui->y2in->text().toInt();




  ui->widget->draw=true;
  ui->widget->updateGL();
}

void MainWindow::on_drawopengl_clicked()
{
    ui->widget->x1=ui->x1in->text().toInt();
    ui->widget->y1=ui->y1in->text().toInt();
    ui->widget->x2=ui->x2in->text().toInt();
    ui->widget->y2=ui->y2in->text().toInt();




    ui->widget->drawGLline=true;
    ui->widget->updateGL();
}
