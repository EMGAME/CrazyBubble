//
//  GameWorld.cpp
//  CrazyBubble
//
//  Created by 王瑶华 on 14-4-14.
//
//

#include "GameWorld.h"

static GameWorld* sh;

CCScene* GameWorld::scene(){
    CCScene* scene = CCScene::create();
    GameWorld* layer = GameWorld::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool GameWorld::init(){
    if (!CCLayer::init()) {
        return false;
    }
    
    sh = this;
    
    //创建箭头列表
    arrayEnemy = CCArray::create();
    CC_SAFE_RETAIN(arrayEnemy);
    
    //创建主角
    HPlayer* player = HPlayer::create("bubble.png");
    this->addChild(player, 1, tag_player);
    
    //创建箭头逻辑
    this->schedule(schedule_selector(GameWorld::autoCreateArrow), 1);
    
}


CCArray* GameWorld::getArrayForEnemy(){
    return arrayEnemy;
}

void GameWorld::winGame(){

}

void GameWorld::lostGame(){

}

void GameWorld::autoCreateArrow(){

}

GameWorld* GameWorld::sharedWorld(){
    if (sh != NULL) {
        return sh;
    }
    
    return NULL;
}

GameWorld::~GameWorld(){
    CC_SAFE_DELETE(arrayEnemy);
}