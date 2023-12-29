#include "graph.h"
#include "graphwidget.h"
#include "mainwindow.h"
#include "secondgraph.h"
#include "thirdgraph.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    graph* g = new graph("A,B,C,D,E,F,G,H,I,J");
    GraphWidget *widget = new GraphWidget;
    QObject::connect(g,&graph::matrixCreated,widget,&GraphWidget::createFromMatrix);
    g->makeInfectionMatrixFromString("A,B,C,D,E,F,G");
    g->fillMatrixFromString("A->B,A->C,B->A,B->D,C->A,C->D,C->E,D->B,D->C,D->E,D->F,E->C,E->D,E->G,F->D,F->G,F->H,G->E,G->F,G->H,H->F,H->G,H->I,I->H,I->J,J->I");
    //g->makeInfectionMatrixFromString("A,B");
    //g->fillMatrixFromString("A->B,A->C,B->A,B->C,C->A");


    MainWindow w;


    w.setCentralWidget(widget);
    w.show();
    auto solutions = g->findSource1(2);
    //auto solutionsBFS = g->findSourcesBFS(2);

    if(solutions.empty()){
        qDebug() << "there is no solution ;(";
    }
    for(auto ch : solutions){
        qDebug() << "the source could be " << ch;
    }
    auto third = new thirdgraph("A,B,C,D,E,F,G,H,I,J","A,B,C,D,E,F,G");
    third->addEdge('A', 'B');
    third->addEdge('A', 'C');
    third->addEdge('B', 'A');
    third->addEdge('B', 'D');
    third->addEdge('C', 'A');
    third->addEdge('C', 'D');
    third->addEdge('C', 'E');
    third->addEdge('D', 'E');
    third->addEdge('D', 'B');
    third->addEdge('D', 'C');
    third->addEdge('D', 'F');
    third->addEdge('E', 'G');
    third->addEdge('E', 'C');
    third->addEdge('E', 'D');
    third->addEdge('F', 'D');
    third->addEdge('F', 'H');
    third->addEdge('F', 'G');
    third->addEdge('G', 'E');
    third->addEdge('G', 'F');
    third->addEdge('G', 'H');
    third->addEdge('H', 'I');
    third->addEdge('H', 'F');
    third->addEdge('H', 'G');
    third->addEdge('I', 'H');
    third->addEdge('I', 'J');
    third->addEdge('J', 'I');
    third->searchInfectionStart(2);


    secondGraph secGraph;
    secGraph.addEdge('A', 'B');
    secGraph.addEdge('A', 'C');
    secGraph.addEdge('B', 'D');
    secGraph.addEdge('C', 'D');
    secGraph.addEdge('C', 'E');
    secGraph.addEdge('D', 'E');
    secGraph.addEdge('E', 'G');
    secGraph.addEdge('G', 'F');
    secGraph.addEdge('D', 'F');

    unordered_set<char> infectedNodes = {'A','B', 'C', 'D','E','F'};
    int daysPassed = 2;

    unordered_set<char> sources = secGraph.findSourcesBFS(infectedNodes, daysPassed);

    string test = "Possible sources: ";
    for (char source : sources) {
        test += source;
        test += " ";
    }
    qDebug() << test;

    return a.exec();
}
