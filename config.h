#ifndef CONFIG_H
#define CONFIG_H

/*
一些信息

地图的界限位置是400左右，设置物件的时候要计算物件高度
地刺是340位置，但是本身高60
飞鸟是100，


*/
/*******  游戏配置数据 *******/
#define GAME_WIDTH 750  //宽度
#define GAME_HEIGHT  500  //高度
#define GAME_TITLE  "StayAway"  //标题名称
#define GAME_RATE 10  //定时器刷新间隔ms
#define GAME_OVER "D:\\code\\qtcode\\game\\images\\gameover.png"
#define GAME_OVER_1 "D:\\code\\qtcode\\game\\images\\man_down.png"
#define GAME_OVER_2 "D:\\code\\qtcode\\game\\images\\man_down2.png"


/*******  地图配置数据 *******/

#define MAP_PATH1 "D:\\code\\qtcode\\game\\images\\backmap1.png"
#define MAP_PATH2 "D:\\code\\qtcode\\game\\images\\backmap2.png"
#define MAP_SCROLL_SPEED -2

/*******  人物配置数据 *******/
#define MAN_PATH1 "D:\\code\\qtcode\\game\\images\\man1.png"
#define MAN_PATH2 "D:\\code\\qtcode\\game\\images\\man2.png"
#define MAN_PATH3 "D:\\code\\qtcode\\game\\images\\man3.png"
#define MAN_PATH4 "D:\\code\\qtcode\\game\\images\\man4.png"

#define MAN_JUMP1 "D:\\code\\qtcode\\game\\images\\manjump1.png"
#define MAN_JUMP2 "D:\\code\\qtcode\\game\\images\\manjump2.png"

#define MAN_DOWN "D:\\code\\qtcode\\game\\images\\"


/*******  障碍配置数据 *******/
#define BARRIER_GROUND "D:\\code\\qtcode\\game\\images\\groundbarrier.png"  //地上障碍物
#define BARRIER_SKY "D:\\code\\qtcode\\game\\images\\skybarrier.png"  //空中障碍物
#define BARRIER_NUM 20  //障碍物数量

#endif // CONFIG_H
