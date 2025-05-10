#ifndef MAP_H
#define MAP_H
#include <QPixmap>
#include <QPointF>

class Map
{

public:
    Map();

    //地图滚动坐标计算
    void mapPosition();


public:

    //线条对象
    QPointF lineRect;

    //地图图片对象
    QPixmap m_map1;
    QPixmap m_map2;


    //地图X轴坐标
    int m_map1_posX;
    int m_map2_posX;


    //地图滚动速度
    int m_scroll_speed;

};

#endif // MAP_H
