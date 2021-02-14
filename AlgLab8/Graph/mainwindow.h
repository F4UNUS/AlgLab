#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsPolygonItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_createButton_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    void printGraph();

    void printArrow(float x1, float y1, float x2, float y2, QGraphicsScene &scene);

    void on_searchButton_clicked();

    void on_deleteButton_clicked();

    void on_execOrderButton_clicked();

    void bfs(int n);

    void dfs(int n, bool used[]);

    void dijkstra(int n);

    void floyd();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;
    QGraphicsPolygonItem *polygon;
};
#endif // MAINWINDOW_H
