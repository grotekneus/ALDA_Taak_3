#include "graph.h"
#include "graphwidget.h"
#include "mainwindow.h"
#include "iostream"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    graph* g = new graph("A,B,C");
    GraphWidget *widget = new GraphWidget;
    QObject::connect(g,&graph::matrixCreated,widget,&GraphWidget::createFromMatrix);
    g->makeInfectionMatrixFromString("A,B");
    g->fillMatrixFromString("A->B,A->C,B->A,B->C,C->A,C->B");

    MainWindow w;


    w.setCentralWidget(widget);
    w.show();
    auto solutions = g->findSource1(2);
    if(solutions.empty()){
        qDebug() << "there is no solution ;(";
    }
    for(auto ch : solutions){
        qDebug() << "the source could be " << ch;
    }
    return a.exec();
}
