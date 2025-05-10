#include "mainscene.h"
#include "ui_mainscene.h"
#include "man.h"
#include <QPainter>
#include "config.h"
#include <QKeyEvent>
#include <QRandomGenerator>

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    // 调用初始化场景
    initScene();

    //启动游戏
    playGame();
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::initScene()
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //定时器初始化
    m_Timer.setInterval(GAME_RATE);
    m_man_Timer.setInterval(500);

    //障碍物出场时间间隔 初始化
    m_ground_recorder = 0;

    //记录走路时间变化
    m_man_cnt=0;

    //结束图标加载
    gg.load(GAME_OVER);
    cartoon1.load(GAME_OVER_1);
    cartoon2.load(GAME_OVER_2);
    cnt=0;
    number=1;
}

void MainScene::playGame()
{
    //这个函数是重复运行的

    //启动定时器
    m_Timer.start();
    m_man_Timer.start();

    //监听信号
    connect(&m_Timer, &QTimer::timeout, [=](){

        sky_randomInt = QRandomGenerator::global()->bounded(1000);

        //障碍物出现
        barrierToScene();

        //更新游戏中元素坐标
        updatePosition();

        //绘制到屏幕
        update();

        //碰撞检测
        collisionDetection();
    });


}

void MainScene::updatePosition()
{
    //更新地图坐标
    m_map.mapPosition();

    //障碍物出场
    for(int i=0;i<BARRIER_NUM;i++){
        if(m_groundbarrier[i].m_groundbarrier_Free == false){
            m_groundbarrier[i].updatePosition();
        }
        if(m_skybarrier[i].m_skybarrier_Free == false){
            m_skybarrier[i].updatePosition();
        }
    }
}

void MainScene::paintEvent(QPaintEvent *)
{
    if(m_man.m_man_jumping == false)
        m_man_cnt++;
    //第一次运行窗口时 和 update 会触发这个函数
    QPainter painter(this);

    if(m_man.m_man_life == true){
        //绘图  X,Y,属性
        painter.drawPixmap(m_map.m_map1_posX, 0, m_map.m_map1);
        painter.drawPixmap(m_map.m_map2_posX, 0, m_map.m_map2);
        painter.drawPixmap(m_man.m_X,m_man.m_Y,m_man.m_man);

        //走路
        if(m_man.m_man_walking == true && m_man_cnt == 15){
            m_man_cnt = 0;
            m_man.walking();
            painter.drawPixmap(m_man.m_X,m_man.m_Y,m_man.m_man);
        }

        //跳跃
        if(m_man.m_man_jumping == true){
            m_man.update();
            painter.drawPixmap(m_man.m_X,m_man.m_Y,m_man.m_man);
        }


        //绘制障碍物
        for(int i=0;i<BARRIER_NUM;i++){
            if(m_groundbarrier[i].m_groundbarrier_Free == false){
                painter.drawPixmap(m_groundbarrier[i].m_groundbarrier_X,m_groundbarrier[i].m_groundbarrier_Y,m_groundbarrier[i].m_groundbarrier);
            }
        }
        for(int i=0;i<BARRIER_NUM;i++){
                if(m_skybarrier[i].m_skybarrier_Free == false ){
                    painter.drawPixmap(m_skybarrier[i].m_skybarrier_X,m_skybarrier[i].m_skybarrier_Y,m_skybarrier[i].m_skybarrier);
            }
        }

    }
    else{
        painter.drawPixmap(125,100,gg);
        if(number == 1){
            number=2;
            painter.drawPixmap(150,250,cartoon1);
        }
        else{
            number=1;
              painter.drawPixmap(150,250,cartoon2);
        }
    }
}

void MainScene::barrierToScene()
{
    m_ground_recorder++;
    //没达到出场间隔
    if(m_ground_recorder == 230 ){
        m_ground_recorder = 0;

        for(int i=0;i<BARRIER_NUM;i++){
            //如果是空闲的 出场
            if(m_groundbarrier[i].m_groundbarrier_Free){
                m_groundbarrier[i].m_groundbarrier_Free = false;

                //坐标
                m_groundbarrier[i].m_groundbarrier_X = GAME_WIDTH;
                m_groundbarrier[i].m_groundbarrier_Y = 340;
                break;
            }
        }
    }

    if(sky_randomInt == 5 || sky_randomInt == 50 || sky_randomInt == 150){
        for(int i=0;i<BARRIER_NUM;i++){
            //如果是空闲的 出场
            if(m_skybarrier[i].m_skybarrier_Free ){
                 m_skybarrier[i].m_skybarrier_Free = false;
                //坐标
                m_skybarrier[i].m_skybarrier_X = GAME_WIDTH;
                m_skybarrier[i].m_skybarrier_Y = 100;
                break;
            }
        }
    }
}

void MainScene::collisionDetection()
{
    //遍历所有的空闲的障碍物
    for(int i=0;i<BARRIER_NUM;i++){
        if(m_groundbarrier[i].m_groundbarrier_Free == false){

            //人物和地面障碍物相撞
            if(m_groundbarrier[i].m_Groundrect.intersects(m_man.m_Manrect)){
                m_man.m_man_life = false;
            }
        }
    }

    for(int i=0;i<BARRIER_NUM;i++){
        if(m_skybarrier[i].m_skybarrier_Free == false){
            //如果与空中障碍物相撞
            if(m_skybarrier[i].m_Skyrect.intersects(m_man.m_Manrect)){
                m_man.m_man_life = false;
            }
        }
    }
}


void MainScene::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Up:
        //按下了上键，修改人物的高度参数
        m_man.move(event->key());
        // qDebug()<<"aaa";
        break;
    case Qt::Key_Down:
        //按下了下键，修改人物的高度参数
        m_man.move(event->key());
        break;
    }
}

