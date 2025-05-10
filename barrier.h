#ifndef BARRIER_H
#define BARRIER_H

#include <QPixmap>

class barrier
{
public:
    barrier();

    //更新坐标
    void updatePosition();
public:
    //障碍物资源
    QPixmap m_groundbarrier;
    QPixmap m_skybarrier;

    //位置
    int m_groundbarrier_X;
    int m_groundbarrier_Y;

    int m_skybarrier_X;
    int m_skybarrier_Y;


    //障碍物边框
    QRect m_Groundrect;
    QRect m_Skyrect;

    //状态
    bool m_groundbarrier_Free;
    bool m_skybarrier_Free;

    //速度
    int m_Speed;
    int skySpeed;
};

#endif // BARRIER_H
