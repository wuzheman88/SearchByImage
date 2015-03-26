#include "HelloWorldScene.h"

USING_NS_CC;
using namespace  cocostudio;
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	
	auto  sprite =Sprite::create("background.png");
	sprite->setAnchorPoint(Point(0,0));
	this->addChild(sprite);

	ArmatureDataManager::getInstance()->addArmatureFileInfo("catArmature/catArmature.ExportJson");
	auto  _cat =this->insCatAnimation();
	this->addChild(_cat, 1, CATTAG);


	auto  label=LabelTTF::create("Let cat move","Arial",26);
	auto  item = MenuItemLabel::create(label,CC_CALLBACK_0(HelloWorld::catMove, this));

	auto  label2 = LabelTTF::create("Let cat pase", "Arial", 26);
	auto  item2 = MenuItemLabel::create(label2, CC_CALLBACK_0(HelloWorld::catPase, this));

	auto  menu =Menu::create(item,item2,NULL);
	menu->alignItemsVertically();
	menu->setPosition(Point(400, 400));
	this->addChild(menu);




   
    
    return true;
}
cocostudio::Armature*  HelloWorld::insCatAnimation()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto  cat = Armature::create("catArmature");
	cat->setPosition(Point(visibleSize.width * 0.6 + 250, visibleSize.height * 0.5 + 20));
	cat->getAnimation()->playWithIndex(0);

	return  cat;	
}


void  HelloWorld::catMove()
{
	auto cat=(Armature*)this->getChildByTag(CATTAG);
	cat->getAnimation()->playWithIndex(0);
	auto catM =MoveTo::create(24.0f,Point(150,cat->getPosition().y));
	cat->runAction(catM);
}

void HelloWorld::catPase()
{
	auto cat =(Armature*)this->getChildByTag(CATTAG);
	cat->stopAllActions();
	cat->getAnimation()->playWithIndex(1);//获取你需要的动画
}