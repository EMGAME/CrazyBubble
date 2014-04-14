//
//  GameWorld.h
//  CrazyBubble
//
//  Created by 王瑶华 on 14-4-14.
//
//

#ifndef __CrazyBubble__GameWorld__
#define __CrazyBubble__GameWorld__

#include "cocos2d.h"
//#include "HPlayer.h"

USING_NS_CC;

typedef enum{
    tag_player,//主角
    tag_scoreTTF,//分数
}tagWorld;//枚举变量



class GameWorld : public cocos2d::CCLayer
{
public:
    static cocos2d::CCScene* scene();
    
    //获取当前HWorld的静态实例
    static GameWorld * sharedWorld();
    
    //获取主角
    //HPlayer* getPlayer();
    
    
    //获取存放箭头的数组
    CCArray* getArrayForEnemy();
    
    void winGame();
    void lostGame();
    
private:
    virtual bool init();
    CREATE_FUNC(GameWorld);
    
    CCArray * arrayEnemy;//存放敌怪的数组
    void autoCreateArrow(); //创建箭头
    void backMenu();//返回主菜单
    virtual ~GameWorld();//析构函数
};



#endif /* defined(__CrazyBubble__GameWorld__) */
