#include <QErrorMessage>
#include <filesystem>
#include <iostream>
#include "editormainwindow.h"
#include "./ui_editormainwindow.h"
#include "MapLoader.h"




EditorMainWindow::EditorMainWindow(std::string& name,int& x, int& y, int& mode, int& nOfPlayers,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditorMainWindow)
    , x(x)
    , y(y)
    , mode(mode)
    , nOfPlayers(nOfPlayers)
    , name(name)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->MapX->setValidator( new QIntValidator(0, 9999, this) );
    ui->MapY->setValidator( new QIntValidator(0, 9999, this) );

    MapLoader loader;
    std::string path = "../map/";

    for (const auto & entry : std::filesystem::directory_iterator(path)){
        std::string path = entry.path();
        if (path.find("yaml")){
            Game newGame;
            loader.loadMap(path,newGame.map,newGame.players, newGame.name);
            newGame.y = newGame.map.size();
            newGame.x = newGame.map[0].size();
            games.push_back(newGame);
        }
    }
    for (int i = 0; i < games.size() ; ++i) {
        QString n = QString::fromStdString(games[i].name);
        ui->comboBox->addItem(n);
    }

}

EditorMainWindow::~EditorMainWindow()
{
    delete ui;
}


void EditorMainWindow::on_new_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void EditorMainWindow::on_back1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void EditorMainWindow::on_load_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void EditorMainWindow::on_back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void EditorMainWindow::on_startLoad_clicked()
{
    for (int i = 0; i < games.size() ; ++i) {
        if (games[i].name == ui->comboBox->currentText().toStdString()){
            x = games[i].x;
            y = games[i].y;
            name = games[i].name;
            mode = 2;
            nOfPlayers = games[i].players;
            this->close();
        }
    }
}


void EditorMainWindow::on_startnew_clicked()
{
    QString _name(ui->gameName->text());
    if (!ui->MapX->text().isEmpty() || !ui->MapX->text().isEmpty() || !_name.isEmpty() ) {
        QString _name(ui->gameName->text());
         x = ui->MapX->text().toInt();
         y = ui->MapY->text().toInt();
        name = _name.toStdString();
        mode = 1;
        nOfPlayers = ui->spinBox->value();
        this->close();
    }else{
        QErrorMessage msg;
        msg.showMessage("FILL ITEMS CORRECTLY");
        msg.exec();
    }
}

void EditorMainWindow::on_comboBox_currentIndexChanged(int index) {
    for (int i = 0; i < games.size() ; ++i) {
        if (games[i].name == ui->comboBox->currentText().toStdString()){
            std::string rows = std::to_string(games[i].x);
            QString x = QString::fromStdString(rows);
            ui->MapX_2->setText(x);
            std::string cols = std::to_string(games[i].y);
            QString y = QString::fromStdString(cols);
            ui->MapY_2->setText(y);
            std::string players = std::to_string(games[i].players);
            QString n = QString::fromStdString(players);
            ui->MapY_3->setText(n);
        }
    }
}


