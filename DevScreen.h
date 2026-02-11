#pragma once
#include<stdbool.h>
#include<SDL.h>
#include"Config.h"
#ifdef USE_SCRIPT_FOR_DEV_EMU
#include<lua.h>
#include <lauxlib.h>
#endif

extern bool RenderLoop;
extern SDL_Window* SDLWindow;
extern SDL_Renderer* SDLRenderer;
typedef void (DevScr_CustomMainUpdate_Func)();
typedef void (DevScr_CustomInit_Func)();
void DevScr_CreateDisplay(int width,int height,unsigned long vram_size);
void DevScr_SetCustomMainUpdateCB(DevScr_CustomMainUpdate_Func* mainupdate_cb);
void DevScr_SetCustomMainInit(DevScr_CustomInit_Func* maininit_cb);
void DevScr_GLBeginRenderLoop();
void DevScr_BeginRenderLoop();
#ifdef USE_SCRIPT_FOR_DEV_EMU
int DevScr_InitDeviceLua(lua_State* L);
int DevScr_ReadFromDeviceLua(lua_State* L);
int DevScr_WriteToDeviceLua(lua_State* L);

#endif