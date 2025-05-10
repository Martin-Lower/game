#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include <QPixmap>
#include <QRandomGenerator>
#include "map.h"
#include "man.h"
#include "barrier.h"
#include "config.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainScene;
}
QT_END_NAMESPACE

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //初始化场景
    void initScene();

    //启动游戏
    void playGame();

    //更新所有元素的坐标
    void updatePosition();

    //绘制到屏幕
    void paintEvent(QPaintEvent *);

    //键盘事件
    void keyboardEvent(QPaintEvent *);

    //障碍物出现
    void barrierToScene();

    //障碍物数组
    barrier m_groundbarrier[BARRIER_NUM];
    barrier m_skybarrier[BARRIER_NUM];


    //障碍物时间间隔
    int m_ground_recorder;
    int sky_randomInt;

    //碰撞检测
    void collisionDetection();

    //地图对象
    Map m_map;

    //人物对象
    man m_man;
    int m_man_cnt;

    //键盘事件
    void keyPressEvent(QKeyEvent *event);

    //游戏结束检测
    void gameOver();
    QPixmap gg;
    QPixmap cartoon1;
    QPixmap cartoon2;
    int cnt;
    int number;

    //定时器
    QTimer m_Timer;
    QTimer m_man_Timer;



private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
