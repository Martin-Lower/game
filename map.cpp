#include "map.h"
#include "config.h"

Map::Map() {
    //初始化加载地图
    m_map1.load(MAP_PATH1);
    m_map2.load(MAP_PATH2);


    //初始化X轴坐标
    m_map1_posX = GAME_WIDTH;
    m_map2_posX = 0;

    //地图滚动速度
    m_scroll_speed = MAP_SCROLL_SPEED;

}

void Map::mapPosition() {
    // 更新第一张图片的滚动位置
    m_map1_posX += m_scroll_speed; // 向左移动

    // 检查第一张图片是否完全离开视口
    if (m_map1_posX <= -GAME_WIDTH) {
        m_map1_posX = m_map2_posX + GAME_WIDTH; // 重置到第二张图的右边
    }

    // 更新第二张图片
    m_map2_posX += m_scroll_speed; // 向左移动

    // 检查第二张是否完全离开视口
    if (m_map2_posX <= -GAME_WIDTH) {
        m_map2_posX = m_map1_posX + GAME_WIDTH; // 重置到第一张图的右边
    }
}
