#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::string&,std::string&, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

    void on_Background_linkActivated(const QString &link);

    void on_pushButton_clicked(bool checked);

    void on_radioButton_clicked();

    void on_frame_customContextMenuRequested(const QPoint &pos);

    void on_StartButton_clicked();

private:
    std::string& host;
    std::string& port;
    Ui::MainWindow *ui;
    QMediaPlayer *music;
    bool playing;
};
#endif // MAINWINDOW_H
