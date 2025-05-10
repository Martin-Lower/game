#ifndef MAN_H
#define MAN_H

#include <QPixmap>
#include <QRect>
#include <QKeyEvent>
#include <QTimer>

class man
{
public:
    man();

    void move(int key);

    void judge();

    void update();

    void walking();


public:
    //人物对象
    QPixmap m_man;

    bool m_man_life;

    bool m_man_jumping;

    bool m_man_downing;

    bool m_man_walking;
    int m_man_iswalking;

    //人物坐标
    int m_X;
    int m_Y;

    //速度
    double jumpSpeed;

    //判定框
    QRect m_Manrect;

};

#endif // MAN_H
