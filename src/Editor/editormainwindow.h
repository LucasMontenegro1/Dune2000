#ifndef EDITORMAINWINDOW_H
#define EDITORMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class EditorMainWindow; }
QT_END_NAMESPACE

struct Game{
    std::string name;
    int x;
    int y;
    int players;
};


class EditorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    EditorMainWindow(std::string&,int&,int&,int&,int&,QWidget *parent = nullptr);
    ~EditorMainWindow();

private slots:
    void on_new_2_clicked();

    void on_back1_clicked();

    void on_load_clicked();

    void on_back_2_clicked();

    void on_startLoad_clicked();

    void on_startnew_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    std::vector<Game> games;
    int& x;
    int& y;
    int& mode;
    std::string& name;
    int& nOfPlayers;
    Ui::EditorMainWindow *ui;
};
#endif // EDITORMAINWINDOW_H
