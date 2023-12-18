#include "graph.h"
#include "graphwidget.h"
#include "mainwindow.h"
#include "iostream"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    graph* g = new graph("A,B,C,D,E,F,G,H,I,J");
    GraphWidget *widget = new GraphWidget;
    QObject::connect(g,&graph::matrixCreated,widget,&GraphWidget::createFromMatrix);
    g->makeInfectionMatrixFromString("A,B,C,D,E,F,G,H,I,J");
    g->fillMatrixFromString("A->B,A->C,B->A,B->D,C->A,C->D,C->E,D->B,D->C,D->E,D->F,E->C,E->D,E->G,F->D,F->G,F->H,G->E,G->F,G->H,H->F,H->G,H->I,I->H,I->J,J->I");

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
