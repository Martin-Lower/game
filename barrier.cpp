#include "barrier.h"
#include "config.h"
#include <QDebug>

barrier::barrier() {

    //障碍物资源加载
    m_groundbarrier.load(BARRIER_GROUND);
    m_skybarrier.load(BARRIER_SKY);

    //障碍物位置
    m_groundbarrier_X = GAME_WIDTH;
    m_groundbarrier_Y = 340;

    m_skybarrier_X = GAME_WIDTH;
    m_skybarrier_Y = 100;

    //障碍物状态
    m_groundbarrier_Free = true;
    m_skybarrier_Free =true;

    //障碍物速度
    m_Speed = MAP_SCROLL_SPEED;
    skySpeed = 2.3 * MAP_SCROLL_SPEED;

    //矩形框（碰撞体积）
    m_Groundrect.setWidth(0.25*m_groundbarrier.width());
    m_Groundrect.setHeight(0.25*m_groundbarrier.height());
    m_Groundrect.moveTo(m_groundbarrier_X+25,m_groundbarrier_Y+25);

    m_Skyrect.setWidth(0.25*m_skybarrier.width());
    m_Skyrect.setHeight(0.25*m_skybarrier.height());
    m_Skyrect.moveTo(m_skybarrier_X+50,m_skybarrier_Y+25);

}

void barrier::updatePosition()
{

    //空闲状态的障碍物是不需要计算坐标的
    if(m_groundbarrier_Free == false){
        m_groundbarrier_X += m_Speed;
        m_Groundrect.moveTo(m_groundbarrier_X,m_groundbarrier_Y);
    }

    if(m_skybarrier_Free == false){
        m_skybarrier_X +=skySpeed;
        m_Skyrect.moveTo(m_skybarrier_X,m_skybarrier_Y);
    }

    //超出屏幕 销毁
    if(m_groundbarrier_X <= 0){
        m_groundbarrier_Free = true;
        m_groundbarrier_X = GAME_WIDTH;
    }
    if(m_skybarrier_X <= 0){
        m_skybarrier_Free = true;
        m_skybarrier_X = GAME_WIDTH;
    }
}
