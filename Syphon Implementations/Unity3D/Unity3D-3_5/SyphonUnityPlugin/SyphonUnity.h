//SyphonUnity.h
//  SyphonUnityPlugin
/*
 
 Copyright 2010-2011 Brian Chasalow, bangnoise (Tom Butterworth) & vade (Anton Marini).
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Syphon/Syphon.h>
#import "UnityPluginInterface.h"
#import "ServerWatcherUtility.mm"
#import "SyphonCacheData.h"
#import "SyphonServerUnity.mm"
#import "SyphonClientUnity.m"


#include "Unity/IUnityGraphics.h"

#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>

// --------------------------------------------------------------------------
// Include headers for the graphics APIs we support

#if SUPPORT_D3D9
#include <d3d9.h>
#include "Unity/IUnityGraphicsD3D9.h"
#endif
#if SUPPORT_D3D11
#include <d3d11.h>
#include "Unity/IUnityGraphicsD3D11.h"
#endif
#if SUPPORT_D3D12
#include <d3d12.h>
#include "Unity/IUnityGraphicsD3D12.h"
#endif

#if SUPPORT_OPENGLES
#if UNITY_IPHONE
#include <OpenGLES/ES2/gl.h>
#elif UNITY_ANDROID
#include <GLES2/gl2.h>
#endif
#elif SUPPORT_OPENGL
#if UNITY_WIN || UNITY_LINUX
#include <GL/gl.h>
#else
#include <OpenGL/gl.h>
#endif
#endif


extern "C" void SyphonUnityRenderEvent(int instanceID);