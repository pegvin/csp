#ifndef __APP_H_INCLUDED
#define __APP_H_INCLUDED 1
#pragma once

#if CS_BUILD_STABLE == 0
	#define CS_BUILD_TYPE "dev"
#else
	#define CS_BUILD_TYPE "stable"
#endif

#define __STR_IMPL_(s) #s     // Stringify Argument
#define STR(s) __STR_IMPL_(s) // Expand Argument
#define CS_VERSION_STR "v" STR(CS_VERSION_MAJOR) "." STR(CS_VERSION_MINOR) "." STR(CS_VERSION_PATCH) "-" CS_BUILD_TYPE

bool App_Init();
void App_NewFrame();
void App_ProcessEvents();
void App_EndFrame();
void App_RequestClose();
void App_Quit();

#endif // __APP_H_INCLUDED

