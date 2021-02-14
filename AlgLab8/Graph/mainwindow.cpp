#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"
#include "QQueue"
#include "QErrorMessage"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinWayBox->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool init = false;

void MainWindow::printArrow(float x1, float y1, float x2, float y2, QGraphicsScene &scene)
{
    float x, y;
    float f1x2 , f1y2;
    float lons, ugol;
    const float ostr = 0.5;// острота стрелки
    scene.addLine(x1, y1, x2, y2);
    x = x2 - x1;
    y = y2 - y1;
    lons = 10;
    ugol = atan2(y, x); // угол наклона линии
    f1x2 = x2 - lons * cos(ugol - ostr);
    f1y2 = y2 - lons * sin(ugol - ostr);
    scene.addLine(x2, y2, f1x2, f1y2);
    f1x2 = x2 - lons * cos(ugol + ostr);
    f1y2 = y2 - lons * sin(ugol + ostr);
    scene.addLine(x2, y2, f1x2, f1y2);
}

void MainWindow::printGraph(){
    if(init == true){
        scene->clear();
    }
    QPen blackPen(Qt::black);
    QBrush whiteBrush(Qt::white);
    QBrush blackBrush(Qt::black);
    blackPen.setWidth(1);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-235, -195, 470, 390);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    QFont font;
    font.setPixelSize(10);
    font.setBold(false);
    font.setFamily("Calibri");
    int X = 0, Y = 0;
    int count = ui->spinBox->value();
    for (int i = 1;i <= count;i++) {
        X = 30 - trunc(100 * qCos(2 * i * M_PI/count));
        Y = 30 - trunc(100 * qSin(2 * i * M_PI/count));
        ellipse = scene->addEllipse(X, Y, 30, 30, blackPen, whiteBrush);
        text = scene->addText(QString::number(i));
        text->setPos(X, Y);
        text->setDefaultTextColor(Qt::black);
    }

    int info;
    int X1, X2, Y1, Y2;
    int R = 15;

    for(int i = 0;i < count;i++)
        for (int j = 0;j < count; j++) {
            info = ui->tableWidget->item(i, j)->text().toInt();
            if( i != j ){
                if(info > 0){
                    X1 = 30 - trunc(100 * qCos(2 * (i + 1) * M_PI/count)) + 15;
                    Y1 = 30 - trunc(100 * qSin(2 * (i + 1) * M_PI/count)) + 15;
                    X2 = 30 - trunc(100 * qCos(2 * (j + 1) * M_PI/count)) + 15;
                    Y2 = 30 - trunc(100 * qSin(2 * (j + 1) * M_PI/count)) + 15;

                    double d1 = qSqrt(qPow((X2 - X1), 2) + qPow((Y2 - Y1), 2));
                    double d2 = qSqrt(qPow((X1 - X2), 2) + qPow((Y1 - Y2), 2));

                    X = X1;
                    Y = Y1;
                    X1 = X + (X2 -X)/d1*R;
                    Y1 = Y + (Y2 -Y)/d1*R;

                    X2 = X2 + (X - X2)/d2*R;
                    Y2 = Y2 + (Y - Y2)/d2*R;
                    printArrow(X1, Y1, X2, Y2, *scene);
                }
            }else{
                if(info > 0){
                    X = 30 - trunc(100 * qCos(2 * (i + 1) * M_PI/count)) + 15;
                    Y = 30 - trunc(100 * qSin(2 * (i + 1) * M_PI/count));

                    scene->addLine(X, Y, X - 15, Y - 15);
                    scene->addLine(X - 15, Y - 15, X + 15, Y - 15);
                    printArrow(X + 15, Y - 15, X, Y, *scene);
                }
            }
        }
}

void MainWindow::bfs(int n){
    int count = ui->spinBox->value();
    bool *used = new bool[count];
    QQueue<int> q;
    for(int i = 0;i < count;i++)
        used[i] = false;
    used[n] = true;
    q.enqueue(n);
    ui->tableWidget_2->setRowCount(1);
    while(!q.isEmpty()){
        int tmp = q.dequeue();
        ui->tableWidget_2->insertColumn(ui->tableWidget_2->columnCount());
        ui->tableWidget_2->setColumnWidth(ui->tableWidget_2->columnCount() - 1, 10);
        ui->tableWidget_2->setItem(0, ui->tableWidget_2->columnCount() - 1, new QTableWidgetItem(QString::number(tmp + 1)));
        for (int i = 0;i < count;i++) {
            int item = ui->tableWidget->item(tmp,i)->text().toInt();
            if(item > 0 && !used[i]){
                q.enqueue(i);
                used[i] = true;
            }
        }
    }
};

void MainWindow::dfs(int n, bool used[]){
    used[n] = true;
    ui->tableWidget_2->setRowCount(1);
    ui->tableWidget_2->insertColumn(ui->tableWidget_2->columnCount());
    ui->tableWidget_2->setColumnWidth(ui->tableWidget_2->columnCount() - 1, 10);
    ui->tableWidget_2->setItem(0, ui->tableWidget_2->columnCount() - 1, new QTableWidgetItem(QString::number(n + 1)));
    for(int i = 0;i < ui->spinBox->value();i++){
        int item = ui->tableWidget->item(n,i)->text().toInt();
        if(item > 0 && !used[i])
            dfs(i, used);
    }
};

void MainWindow::dijkstra(int n){
    int count = ui->spinBox->value();
    int **graph = new int* [count];
    for(int i = 0;i < count;i++){
        graph[i] = new int[count];
    }
    for(int i = 0; i < count;i++){
        for (int j = 0;j < count;j++) {
            graph[i][j] = ui->tableWidget->item(i,j)->text().toInt();
        }
    }
    int *dist = new int[count];
    bool *used = new bool[count];
    for (int i = 0;i < count;i++) {
        dist[i] = INT32_MAX;
        used[i] = false;
    }
    dist[n] = 0;
    int index = 0, u = 0;
    for (int i = 0;i < count - 1;i++) {
        int min = INT32_MAX;
        for (int j = 0;j < count;j++) {
            if(!used[j] && dist[j] <= min){
                min = dist[j];
                index = j;
            }
        }
        u = index;
        used[u] = true;
        for (int j = 0;j < count;j++) {
            if(!used[j] && graph[u][j] > 0 && dist[u] != INT32_MAX && dist[u] + graph[u][j] < dist[j]){
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    //вывод
    ui->tableWidget_2->setRowCount(1);
    ui->tableWidget_2->setVerticalHeaderItem(0, new QTableWidgetItem(QString::number(n + 1)));
    for (int i = 0;i < count;i++) {
        if(dist[i] != INT32_MAX){
            ui->tableWidget_2->insertColumn(ui->tableWidget_2->columnCount());
            ui->tableWidget_2->setColumnWidth(ui->tableWidget_2->columnCount() - 1, 10);
            ui->tableWidget_2->setItem(0, ui->tableWidget_2->columnCount() - 1, new QTableWidgetItem(QString::number(dist[i])));
        }else{
            ui->tableWidget_2->insertColumn(ui->tableWidget_2->columnCount());
            ui->tableWidget_2->setColumnWidth(ui->tableWidget_2->columnCount() - 1, 10);
            ui->tableWidget_2->setItem(0, ui->tableWidget_2->columnCount() - 1, new QTableWidgetItem(QString("Нет")));
        }
    }
};

void MainWindow::floyd(){
    int count = ui->spinBox->value();
    int maxSum = 0;
    int **graph = new int* [count];
    for(int i = 0;i < count;i++){
        graph[i] = new int[count];
    }
    for(int i = 0; i < count;i++){
        for (int j = 0;j < count;j++) {
            graph[i][j] = ui->tableWidget->item(i,j)->text().toInt();
            maxSum += graph[i][j];
        }
    }
    for (int i = 0;i < count;i++)
        for (int j = 0;j < count;j++) {
            if(graph[i][j] == 0 && i != j){
                    graph[i][j] = maxSum;
            }
        }
    for (int i = 0;i < count;i++)
        for (int j = 0;j < count;j++)
            for (int k = 0;k < count;k++){
                if(graph[i][k] + graph[k][j] < graph[i][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
    //вывод
    ui->tableWidget_2->setRowCount(count);
    ui->tableWidget_2->setColumnCount(count);
    for(int i = 0;i < count;i++){
        for (int j = 0;j < count;j++){
            ui->tableWidget->setColumnWidth(j, 10);
            if(graph[i][j] != maxSum){
                ui->tableWidget_2->setItem(i, j, new QTableWidgetItem(QString::number(graph[i][j])));
            }else{
                ui->tableWidget_2->setItem(i, j, new QTableWidgetItem(QString("Нет")));
            }
        }
    }
}

void MainWindow::on_createButton_clicked()
{
    if(!init){
        int count = ui->spinBox->value();

        ui->tableWidget->setRowCount(count);
        ui->tableWidget->setColumnCount(count);
        for (int i =0;i < count;i++)
            for (int j = 0;j < count;j++) {
                ui->tableWidget->setColumnWidth(j, 10);
                ui->tableWidget->setItem(i,j, new QTableWidgetItem(QString::number(0)));
            }

        printGraph();

        init = true;
    }else{
        (new QErrorMessage(this))->showMessage("Граф уже создан");
    }
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    if(init){
        int i = ui->tableWidget->item(row, column)->text().toInt();
        if(i >= 0){
            printGraph();
        }else{
            (new QErrorMessage(this))->showMessage("Граф не создан");
        }
    }
}

void MainWindow::on_searchButton_clicked()
{
    switch (ui->comboBox->currentIndex()) {
    case 0:{
        if(init){
            if(ui->tableWidget_2->rowCount() > 0){
                ui->tableWidget_2->clear();
                ui->tableWidget_2->setRowCount(0);
                ui->tableWidget_2->setColumnCount(0);
            }
            if(ui->spinWayBox->value() <= ui->spinBox->value()){
                ui->label_5->setText("Результат поиска кротчайших путей");
                floyd();
            }else{
                (new QErrorMessage(this))->showMessage("Указана несуществующая вершина");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Граф не создан");
        }
        break;
    }
    case 1:{
        if(init){
            if(ui->tableWidget_2->rowCount() > 0){
                ui->tableWidget_2->clear();
                ui->tableWidget_2->setRowCount(0);
                ui->tableWidget_2->setColumnCount(0);
            }
            if(ui->spinWayBox->value() <= ui->spinBox->value()){
                ui->label_5->setText("Результат поиска кротчайших путей");
                dijkstra(ui->spinWayBox->value() - 1);
            }else{
                (new QErrorMessage(this))->showMessage("Указана несуществующая вершина");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Граф не создан");
        }
        break;
    }
    }
}

void MainWindow::on_deleteButton_clicked()
{
    if(init){
        scene->clear();
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(0);
        if(ui->tableWidget_2->columnCount() > 0){
            ui->tableWidget_2->clear();
            ui->tableWidget_2->setRowCount(0);
            ui->tableWidget_2->setColumnCount(0);
        }
        init = false;
    }else{
        (new QErrorMessage(this))->showMessage("Граф не создан");
    }
}

void MainWindow::on_execOrderButton_clicked()
{
    switch (ui->orderBox->currentIndex()) {
    case 0:{
        if(init){
            if(ui->tableWidget_2->columnCount() > 0){
                ui->tableWidget_2->clear();
                ui->tableWidget_2->setRowCount(0);
                ui->tableWidget_2->setColumnCount(0);
            }
            if(ui->spinOrderBox->value() <= ui->spinBox->value()){
                bfs(ui->spinOrderBox->value() - 1);
                ui->label_5->setText("Результат обхода");
            }else{
                (new QErrorMessage(this))->showMessage("Указана несуществующая вершина");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Граф не создан");
        }
        break;
    }
    case 1:{
        if(init){
            int count = ui->spinBox->value();
            bool *used = new bool[count];
            for(int i = 0;i < count;i++)
                used[i] = false;
            if(ui->tableWidget_2->columnCount() > 0){
                ui->tableWidget_2->clear();
                ui->tableWidget_2->setRowCount(0);
                ui->tableWidget_2->setColumnCount(0);
            }
            if(ui->spinOrderBox->value() <= ui->spinBox->value()){
                dfs(ui->spinOrderBox->value() - 1, used);
                ui->label_5->setText("Результат обхода");
            }else{
                (new QErrorMessage(this))->showMessage("Указана несуществующая вершина");
            }
        }else{
            (new QErrorMessage(this))->showMessage("Граф не создан");
        }
        break;
    }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:{
        ui->spinWayBox->setEnabled(false);
        break;
    }
    case 1:{
        ui->spinWayBox->setEnabled(true);
        break;
    }
    }
}
