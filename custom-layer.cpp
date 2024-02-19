#include "includes.h"
#include "custom-layer.hpp"
#include "mod_utils.hpp"
#include <MinHook.h>
#include <gd.h>

//Sai
void jugarNivel(int levelID, const char* nombre = "", const char* descripcion = "") {
    auto lvl = gd::GJGameLevel::create();
    //auto dificutad = gd::GJDifficulty::create();
    lvl->m_nLevelID = levelID;
    lvl->m_nLevelID_seed = 5;
    lvl->m_nLevelID_rand = lvl->m_nLevelID + lvl->m_nLevelID_seed;
    lvl->m_eLevelType = gd::kGJLevelTypeSaved;
    lvl->m_bDontSave = true;
    lvl->m_nFeatured = true;
    lvl->m_sLevelName = nombre;
    lvl->m_sCreatorName = "BrazonHD";
    lvl->m_sLevelDesc = descripcion;
    lvl->m_nSongID = 709578;
    //dificutad = 4;

    CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, gd::LevelInfoLayer::scene(lvl)));
}

//ToMorritow

void Links::Link1(CCObject* object) {
    LPCWSTR a = L"https://www.youtube.com/channel/UCJ73MdeBMcrLuSRE-A5TQqg";
    ShellExecuteW(NULL, L"open", a, NULL, NULL, SW_SHOWNORMAL);
}

void ToMorritowCode::Anuncio(cocos2d::CCObject*) {CCApplication::sharedApplication()->openURL("https://www.youtube.com/channel/UCJ73MdeBMcrLuSRE-A5TQqg");}

void ToMorritowCode::IslaSi(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "Error", "ok", nullptr, "No puedes entrar.");
    flalert->show();
}

const char* ToMorritowCode::getEventTimeString()
{
    switch (rand() % 3)
    {
    case 0:
        return "Mods Developer by: ToMorritow";
    case 1:
        return  "Este mod está hecho por: <ToMorritow";
    case 2:
        return  "discord.gg/THmJJ75Kcc";
    default:
        return "Este mod está hecho por: ToMorritow";
    }
}

void ToMorritowCode::JugarLevelxdd(CCObject*) {
    jugarNivel(229, "The Map Level 1", "Level 1 The Map uwu");
    GameSoundManager::playEffect("chest07.ogg");
}

void ToMorritowCode::Alerta(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "Play Level", "ok", nullptr, "Quieres <cr>entrar</c>?");
    flalert->show();
}

void ToMorritowCode::Info(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "Info", "ok", nullptr, "Si no te carga el <cy>Nivel</c>\n significa que no hay <cg>Servers</c>.");
    flalert->show();
}

ToMorritowCode* ToMorritowCode::create() {
    auto ret = new ToMorritowCode();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool ToMorritowCode::init() {

    AchievementNotifier::sharedState()->notifyAchievement("The Map", ("New The Map v1.0!."), "GJ_downloadsIcon_001.png", true);

    auto CustomSprite2 = CCSprite::create("GJ_IslasBtn_001.png");
    CustomSprite2->setScale({1.0f});

    auto CustomSprite = CCSprite::create("GJ_IslasBtn_lock_001.png");
    CustomSprite->setScale({1.0f});

    auto InfoSprite = CCSprite::create("GJ_infoBtn_001.png");
    InfoSprite->setScale({0.650f});

    auto SprteWxdd = CCSprite::create("GJ_arrow_01_001.png");
    
    SprteWxdd->setScale({0.420f});
    SprteWxdd->setRotation(-90);

    auto buttonMenu2 = CCMenu::create();
    auto CustomButton2 = gd::CCMenuItemSpriteExtra::create(CustomSprite2, this, menu_selector(ToMorritowCode::JugarLevelxdd));
    auto CustomButton3 = gd::CCMenuItemSpriteExtra::create(CustomSprite, this, menu_selector(ToMorritowCode::IslaSi));
    auto CustomButton4 = gd::CCMenuItemSpriteExtra::create(CustomSprite, this, menu_selector(ToMorritowCode::IslaSi));
    auto CustomButton5 = gd::CCMenuItemSpriteExtra::create(CustomSprite, this, menu_selector(ToMorritowCode::IslaSi));
    auto CustomButton = gd::CCMenuItemSpriteExtra::create(CustomSprite, this, menu_selector(ToMorritowCode::IslaSi));
    auto SpriteButton = gd::CCMenuItemSpriteExtra::create(SprteWxdd, this, menu_selector(ToMorritowCode::Alerta));
    auto InfoButton = gd::CCMenuItemSpriteExtra::create(InfoSprite, this, menu_selector(ToMorritowCode::Info));

    buttonMenu2->setPosition({116 , 139});

    ///Bottones

    CustomButton2->setPosition({3.660, 44});
    CustomButton3->setPosition({110.79, 85.2});
    CustomButton4->setPosition({287.28, 73.85});
    CustomButton5->setPosition({340.13, 1.22});
    CustomButton->setPosition({224.74, -96.81});
    SpriteButton->setPosition({6, 62});

    InfoButton->setPosition({393.1, 158.6});

    SpriteButton->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCScaleTo::create(1.0f, 1.05f)), 
    CCEaseSineInOut::create(CCScaleTo::create(1.0, 1.0f)), nullptr)));

    auto CustomSpritew = CCSprite::create("GJ_optionsBtn_001.png");
    CustomSpritew->setScale(0.6f);

    auto CustomButtonT = gd::CCMenuItemSpriteExtra::create(CustomSpritew, this, menu_selector(MenuLayer::onOptions));
    CustomButtonT->setPosition({428.630 , 158.6});
    
    gd::GameManager::sharedState()->fadeInMusic("menuLoop2.mp3"); // change of song on layer

    auto backgroundSprite = CCSprite::create("TheMap.png"); // bg ( background )
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({186, 186, 186});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(ToMorritowCode::backButtonCallback)
    );

    button->setPosition({-87.78, 149.12});

    buttonMenu2->addChild(CustomButton2);
    buttonMenu2->addChild(CustomButton3);
    buttonMenu2->addChild(CustomButton4);
    buttonMenu2->addChild(CustomButton5);
    buttonMenu2->addChild(CustomButton);
    buttonMenu2->addChild(button);
    buttonMenu2->addChild(CustomButtonT);
    buttonMenu2->addChild(SpriteButton);
    buttonMenu2->addChild(InfoButton);
    this->addChild(buttonMenu2);

    auto AnuncioMod = CCLabelBMFont::create(getEventTimeString(), "bigFont.fnt");
    AnuncioMod->setScale(0.325f);
    AnuncioMod->setOpacity(180);

    auto AnuncioLabelBtn = gd::CCMenuItemSpriteExtra::create(AnuncioMod, this, menu_selector(ToMorritowCode::Anuncio));
    AnuncioLabelBtn->setPosition({0, -150});
    buttonMenu2->addChild(AnuncioLabelBtn);

    AnuncioLabelBtn->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(10.0f),  CCEaseInOut::create(CCMoveBy::create(1.0f, { 150, 50 }), 1.0f)));

    setKeypadEnabled(true);

    //return true;
    return true;
}

void ToMorritowCode::onIconClicked(cocos2d::CCObject* pSender)
{

	switch(pSender->getTag())
	{
		// Info Badges
		case 1:
			ProfilePage::create(94, false)->show();
		break;
	}
}


void ToMorritowCode::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void ToMorritowCode::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void ToMorritowCode::switchToToMorritowCodeButton(CCObject* object) {

    auto layer = ToMorritowCode::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    auto transition = CCTransitionFade::create(0.5f, scene);
    CCDirector::sharedDirector()->pushScene(transition);
}