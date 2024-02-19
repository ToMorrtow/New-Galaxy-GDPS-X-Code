#include <random>
#include "includes.h"
#include "custom-layer.hpp"
#include "hooks.hpp"
#include "mod_utils.hpp"
#include "LoadingLayer.hpp"
#include <windows.h>
#include <shellapi.h>
#include <gd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;
using namespace std;

const char* MenuLayerExt::onFacebook = "https://discord.gg/THmJJ75Kcc";
const char* MenuLayerExt::onTwitter = "https://discord.gg/THmJJ75Kcc";
const char* MenuLayerExt::onYouTube = "https://discord.gg/THmJJ75Kcc";

bool write_bytes(
    const std::uintptr_t address,
    std::vector<uint8_t> const& bytes)
{
    return WriteProcessMemory(
        GetCurrentProcess(),
        reinterpret_cast<LPVOID>(address),
        bytes.data(),
        bytes.size(),
        nullptr);
}

const char* getEventTimeString()
{
    switch (rand() % 3)
    {
    case 0:
        return "gjFont09.fnt";
    case 1:
        return  "gjFont07.fnt";
    default:
        return "bigFont.fnt";
    }
}

//const char* getEventTimeString();

bool (__thiscall* MenuLayer_init)(CCLayer* self);
bool __fastcall MenuLayer_init_H(CCLayer* self, void*) {

    if (!MenuLayer_init(self)) return false;

    auto allBtns = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(1));

    auto themap = CCSprite::createWithSpriteFrameName("GJ_eventBtn_001.png");
    themap->setScale(0.85f);
    auto TheMapBtn = gd::CCMenuItemSpriteExtra::create(themap, self, menu_selector(ToMorritowCode::switchToToMorritowCodeButton));
    allBtns->addChild(TheMapBtn);

    // Botones de la CreatorLayer
    auto CreateBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(0));
    auto SaveBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(1));
    auto ScoresBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(2));
    auto QuestsBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(3));
    auto DailyBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(4));
    auto WeeklyBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(5));
    auto SearchBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(9));
    auto GauntletshBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(10));
    auto mapPackBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(8));
    auto TheSafeBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(6));
    auto feacturedBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(7));

    CreateBtn->setPosition({-150, 97});
    SaveBtn->setPosition({-50, 97});
    ScoresBtn->setPosition({50, 97});
    QuestsBtn->setPosition({150, 97});

    TheMapBtn->setPosition({-150, 0});

    return true;
}

class Team : public cocos2d::CCLayer {

public:
    void WowTime(cocos2d::CCObject* pSender) {
        auto GM = gd::GameManager::sharedState();
        gd::FLAlertLayer::create(nullptr, "Team GDPSWow", "ToMorritowCode")->show();
    }
};

bool (__thiscall* GatoSexoLayer_init)(CCLayer* self);
bool __fastcall GatoSexoLayer_init_H(CCLayer* self, void*) {

    if (!GatoSexoLayer_init(self)) return false;

    auto LogoSprite = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(1));
    auto MenuBotones = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(2));

    LogoSprite->setPositionX({266});
    LogoSprite->setScale({0.925f});

    auto uwu = CCLabelBMFont::create("Mods Modificados by ToMorritowCode", getEventTimeString());
    uwu->setScale({0.275f});

    auto owo = CCLabelBMFont::create("GDPS by Maxxo", "bigFont.fnt");
    owo->setScale({0.275f});
    owo->setOpacity(180);

    auto button1 = gd::CCMenuItemSpriteExtra::create(
        uwu,
        self,
        menu_selector(Team::WowTime)
    );

    auto button2 = gd::CCMenuItemSpriteExtra::create(
        owo,
        self,
        menu_selector(Team::WowTime)
    );

    button1->setPosition({0, 138});
    button2->setPosition({0, 129});
    ///button1->setScale(0.375f);

    MenuBotones->addChild(button1);
    MenuBotones->addChild(button2);
    

    return true;
}

const char* (__thiscall* LoadingLayer_getString_org)(LoadingLayer*);
const char* __fastcall LoadingLayer_getString_h(LoadingLayer* self, void*) {

    const char* s[1] = { 
    "Bienvenido a New Galaxy X"};

    srand(time(NULL));

    return s[rand() % 1];

}

void(__thiscall* LoadingLayer_loadingFinished)(LoadingLayer*);//0x18C790
void __fastcall LoadingLayer_loadingFinished_H(LoadingLayer* self, void*) {
    LoadingLayer_loadingFinished(self);
    //title
    SetWindowTextW(GetForegroundWindow(), L"New Galaxy GDPS");
}

inline MenuLayerExt* (__cdecl* MenuLayer_onFacebook)(void*, CCObject*);
void __fastcall MenuLayer_onFacebook_H(void*, CCObject* pSender) {
    CCApplication::sharedApplication()->openURL(MenuLayerExt::onFacebook);
}
inline MenuLayerExt* (__cdecl* MenuLayer_onTwitter)(void*, CCObject*);
void __fastcall MenuLayer_onTwitter_H(void*, CCObject* pSender) {
    CCApplication::sharedApplication()->openURL(MenuLayerExt::onTwitter);
}
inline MenuLayerExt* (__cdecl* MenuLayer_onYouTube)(void*, CCObject*);
void __fastcall MenuLayer_onYouTube_H(void*, CCObject* pSender) {
    CCApplication::sharedApplication()->openURL(MenuLayerExt::onYouTube);
}

DWORD WINAPI thread_func(void* hModule) {

    MH_Initialize();

    auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));

    MH_CreateHook( // MenuLayer
        reinterpret_cast<void*>(base + 0x4DE40),
        reinterpret_cast<void*>(&MenuLayer_init_H),
        reinterpret_cast<void**>(&MenuLayer_init)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x1907b0),
        reinterpret_cast<void*>(&GatoSexoLayer_init_H),
        reinterpret_cast<void**>(&GatoSexoLayer_init)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x18cf40),
        reinterpret_cast<void*>(&LoadingLayer_getString_h),
        reinterpret_cast<void**>(&LoadingLayer_getString_org)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x18C790),
        reinterpret_cast<void*>(&LoadingLayer_loadingFinished_H),
        reinterpret_cast<void**>(&LoadingLayer_loadingFinished)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x191960),
        reinterpret_cast<void*>(&MenuLayer_onFacebook_H),
        reinterpret_cast<void**>(&MenuLayer_onFacebook)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x191980),
        reinterpret_cast<void*>(&MenuLayer_onTwitter_H),
        reinterpret_cast<void**>(&MenuLayer_onTwitter)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x1919A0),
        reinterpret_cast<void*>(&MenuLayer_onYouTube_H),
        reinterpret_cast<void**>(&MenuLayer_onYouTube)
    );

    MH_EnableHook(MH_ALL_HOOKS);

    auto libcocos2d = (DWORD)GetModuleHandleA("libcocos2d.dll");

    /// Practice Music

    ModUtils::write_bytes(base + 0x20C925, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
    ModUtils::write_bytes(base + 0x20D143, { 0x90, 0x90 });
    ModUtils::write_bytes(base + 0x20A563, { 0x90, 0x90 });
    ModUtils::write_bytes(base + 0x20A595, { 0x90, 0x90 });

    //Trails Cocos2d
    ModUtils::write_bytes(libcocos2d + 0xAE9BD, { 0xBB , 0xFF , 0x00 , 0x00 , 0x00 , 0x90 });
    
    ///Trail Bug Fix (Fixes trail cutting on high refresh rates)
    ModUtils::write_bytes((DWORD)GetModuleHandleA("libcocos2d.dll") + 0xAE9BD, { 0xBB , 0xFF , 0x00 , 0x00 , 0x00 , 0x90 });

    ///Icons Hacks
    ModUtils::write_bytes(base + 0xC50A8, { 0xB0, 0x01, 0x90, 0x90, 0x90 });

    ///Colors Hacks
    ModUtils::write_bytes(base + 0xC54BA, { 0xB0, 0x01, 0x90, 0x90, 0x90 });

    // Load Failed
    ModUtils::write_bytes(base + 0x18B2B4, { 0xB0 , 0x01 });

    return 0;
}

BOOL APIENTRY DllMain(HMODULE handle, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        auto h = CreateThread(0, 0, thread_func, handle, 0, 0);
        if (h)
            CloseHandle(h);
        else
            return FALSE;
    }
    return TRUE;
}