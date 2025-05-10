#include "man.h"
#include "config.h"

man::man()
{    
    //加载人物对象
    m_man.load(MAN_PATH1);
    m_man_iswalking=1;

    //初始化人物动作
    m_man_walking = true;

    //人物存活状态
    m_man_life = true;

    //初始化坐标
    m_X = 80;
    m_Y = 320;

    //初始化速度
    jumpSpeed = 0.0;

    //初始化跳跃状态
    m_man_jumping = false;

    //初始化趴下状态
    m_man_downing = false;

    //初始化矩形边框
    m_Manrect.setWidth(m_man.width()*0.75);
    m_Manrect.setHeight(m_man.height()*0.75);
    m_Manrect.moveTo(m_X+25,m_Y+25);

}

void man::move(int key) {
    if (key == Qt::Key_Up && m_Y == 320) { // 只有在地面时才能开始跳跃
        m_man_walking = false;
        m_man_jumping = true;
        jumpSpeed = -10.0; // 向上运动
    }
    if (key == Qt::Key_Down ){ // 在地面的时候趴下
        m_man_walking = false;
        m_man_downing = true;
        jumpSpeed = 5.0;
    }
}

void man::update() {
    //跳跃
    if (m_man_jumping) {
        m_Y += jumpSpeed; // 更新Y坐标
        jumpSpeed += 0.2; // 添加重力影响（下降速度逐渐增加）
        if(jumpSpeed <= 0){
            m_man.load(MAN_JUMP1);
        }
        else{
            m_man.load(MAN_JUMP2);
        }
        // 检查是否落到地面
        if (m_Y >= 320) {
            m_Y = 320;  // 调整为地面高度
            m_man_jumping = false; // 结束跳跃
            m_man_downing = false;
            m_man_walking = true;
            jumpSpeed = 0.0; // 重置速度
        }
    }

    // 更新矩形位置
    m_Manrect.moveTo(m_X, m_Y);
}

void man::walking()
{
    if(m_man_walking == true){
        m_man_iswalking++;
        if(m_man_iswalking <= 4){
            if(m_man_iswalking == 2)
                m_man.load(MAN_PATH2);
            else if(m_man_iswalking == 3)
                m_man.load(MAN_PATH3);
            else
                m_man.load(MAN_PATH4);
        }
        else{
            m_man_iswalking=1;
            m_man.load(MAN_PATH1);
        }
    }
}





