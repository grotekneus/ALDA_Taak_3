#include "graph.h"
#include "graphwidget.h"
#include "mainwindow.h"
#include "secondgraph.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    graph* g = new graph("A,B,C");
    GraphWidget *widget = new GraphWidget;
    QObject::connect(g,&graph::matrixCreated,widget,&GraphWidget::createFromMatrix);
    g->makeInfectionMatrixFromString("A,B");
    g->fillMatrixFromString("A->B,A->C,B->A,B->C,C->A");

    MainWindow w;


    w.setCentralWidget(widget);
    w.show();
    auto solutions = g->findSource1(2);
    auto solutionsBFS = g->findSourcesBFS(2);

    if(solutions.empty()){
        qDebug() << "there is no solution ;(";
    }
    for(auto ch : solutions){
        qDebug() << "the source could be " << ch;
    }

    secondGraph secGraph;
    /*
    secGraph.addEdge('A', 'B');
    secGraph.addEdge('A', 'C');
    secGraph.addEdge('B', 'D');
    secGraph.addEdge('C', 'D');
    secGraph.addEdge('C', 'E');
    secGraph.addEdge('D', 'E');

    unordered_set<char> infectedNodes = {'B', 'C', 'D'};
    */

    secGraph.addEdge('A', 'B');
    secGraph.addEdge('A', 'C');
    secGraph.addEdge('A', 'D');
    secGraph.addEdge('B', 'E');
    secGraph.addEdge('C', 'F');
    secGraph.addEdge('C', 'G');
    secGraph.addEdge('D', 'H');
    secGraph.addEdge('E', 'I');
    secGraph.addEdge('F', 'J');
    secGraph.addEdge('G', 'K');
    secGraph.addEdge('H', 'L');
    secGraph.addEdge('I', 'M');
    secGraph.addEdge('J', 'N');
    secGraph.addEdge('K', 'O');
    secGraph.addEdge('L', 'P');
    secGraph.addEdge('M', 'P');
    secGraph.addEdge('N', 'P');
    secGraph.addEdge('O', 'P');

    unordered_set<char> infectedNodes = {'A', 'D'};

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
