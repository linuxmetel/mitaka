/**************************************************************************************************

Copyright (c) 2007   Tsunehiko Kato  and  4D2U Project, National Astronomical Observatory of Japan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

以下に定める条件に従い、本ソフトウェアおよび関連文書のファイル（以下「ソフトウェア」）の複製を取得す
るすべての人に対し、ソフトウェアを無制限に扱うことを無償で許可します。これには、ソフトウェアの複製を
使用、複写、変更、結合、掲載、頒布、サブライセンス、および/または販売する権利、およびソフトウェアを
提供する相手に同じことを許可する権利も無制限に含まれます。

上記の著作権表示および本許諾表示を、ソフトウェアのすべての複製または重要な部分に記載するものとしま
す。

ソフトウェアは「現状のまま」で、明示であるか暗黙であるかを問わず、何らの保証もなく提供されます。ここ
でいう保証とは、商品性、特定の目的への適合性、および権利非侵害についての保証も含みますが、それに限定
されるものではありません。 作者または著作権者は、契約行為、不法行為、またはそれ以外であろうと、ソフ
トウェアに起因または関連し、あるいはソフトウェアの使用またはその他の扱いによって生じる一切の請求、損
害、その他の義務について何らの責任も負わないものとします。
***************************************************************************************************/
#ifndef __MTK_COMMAND_H__
#define __MTK_COMMAND_H__
#include  "../common/math/vector3.h"
#include  <string>


void	OnCommandDraw();
void	OnUpdateViewCtrl();
void	OnUpdateViewCtrl2();



//---------------
//  Display Mode
//---------------
void	OnDispMode(char ty);


//----------
//  TARGET
//----------
void	OnTargetMoveControler();
void	OnTargetByKey(const char* target_key);


//--------
//  VIEW
//--------


//-- DispSwitch
void	OnDispSwitch(char idx, char sw);
void	OnDispSwitchSetBit(char idx, char mask, bool bFlg);
void	OnDispSwitchToggle(char idx, char mask);

//-- Planet
void	OnEclipse(char sw);
void	OnEclipseSet(char mask, bool bFlg);
void	OnPlanetAtmosphere(char val);
void	OnZoomMode(char val);
void	OnSetZoom(double val);
void	OnTopoZoomMode(char val);
void	OnSurfacePointer(bool bFlg);
void	OnLandingMode(char val);	
void	OnOortCloud(bool bFlg);

//-- Star
void	OnStar(char sw);
void	OnStarSet(char mask, bool bFlg);
void	OnStarMark(char idx);
void	OnSetLRef(float val);
void	OnLRef(float dL);

//-- Constellation
void	OnConstellation(char sw);
void	OnCnstSet(char mask, bool bFlg);

//-- Extragalactic Object
void	OnGalaxy(char sw);
void	OnGalaxySet(char mask, bool bFlg);
void	OnGalCenterBG(bool bFlg);

void	OnMarkVirgoCluster(bool bFlg);
void	OnCMB(bool bFlg);
void	OnNGC(bool bFlg);

//-- Spacecraft
void	OnSpacecraft(bool bFlg);

//-- Spacecraft Path
void	OnSpacecraftPath(char idx, bool bFlg);

//-- Lighting
void	OnSideLight(bool bFlg);


//-- Milkyway
void	OnMilkyWay(char type_MilkyWay);

//-- Guide Line
void	OnCelestialGrid(bool bFlg);
void	OnEcliptic(bool bFlg);
void	OnGalacticGrid(bool bFlg);
void	OnHorizonCoord(bool bFlg);
void	OnDistScale(char sw);

//-- Object Info
void	OnObjectInfo(bool bFlg);

//-- View
void	OnViewInfo(bool bFlg);
void	OnResetViewangle();

//-- TIME
void	OnDate(bool bFlg);
void	OnTimeStep(char type_timestep);
void	OnPresentTime();
void	OnRealTimeMode(bool bFlg);

//-- Scale
void	OnPresetScale(char ty);

//-- Scale line
void	OnDistScaleSet(char mask, bool bFlg);

//-- FontSize
void	OnFontSize(const char idx);

//-- Language
void	OnChangeLanguage(char idx);

//-- Title
void	OnTitle(bool bFlg);

//-- About
void	OnCheckAbout(bool bFlg);
void	OnAbout();

//-- Debug
void	OnDebug(bool bFlg);

//-- Single Eye
void	OnSingleEye(bool bFlg);

//-- Path info
void	OnPathInfo(bool bFlg);

//-- Full Screen Mode
void	OnFullScreen(bool bFlg);

//-- Speed
void	OnSetSpeedFactor(float val);





//--------
//  Time
//--------
void	OnInitTime();
void	OnChangeTime(const double& JD);
void	OnTimeSetting();


//----------
//  Target
//----------
void	OnChangeTargetControler(int tgt_ID);
void	OnPlanetariumTarget(int tgt_ID);



//---------------
//  Planetarium
//---------------
void	OnPlanetariumAngle(float val);


//-----------
//  Landing
//-----------
void	OnLanding();
void	OnLandingInit();
void	OnSetLandingLon(float lon);
void	OnSetLandingLat(float lat);
void	OnTakeoff();



//------------
//  3D chart
//------------
void	OnOpen3DChart(char val);
void	OnClose3DChart();



//---------
//  Movie
//---------
void	OnMovieOpenControler(int idx);
void	OnMovieOpen(int idx);


//---------
//  Image
//---------
void	OnImageOpenControler(int idx);
void	OnImageOpen(int idx);

//---------
//  Audio
//---------
void	OnAudioOpenControler(int idx);
void	OnAudioOpen(int idx);



//-----------
//  Program
//-----------
void	OnProgram(char program_no);




//----------
//  Preset
//----------
void	OnPreset(int idx);



//------------
//  Subtitle
//------------
void	OnSubtitles(bool bFlg);



//---------
//  Popup
//---------
void	OnPopup(int popup_idx);


//--------
//  Test
//--------
void	OnTest(bool bFlg);



/*
//--------
//  Path
//--------
void	OnPlayFrame(bool bFlg);
void	OnSavePath();
void	OnLoadPath();
void	OnClearPath();
*/




//-------------
//  Subtitles
//-------------
void	OnChangeSubtitlesIndex(int idx);




//---------
//  Other
//---------
void	OnSaveImage();
void	OnSaveImageHighRes();
//void	OnSaveCubicImage();


//--------
//  Exit
//--------
void	OnExitAll();



#endif
