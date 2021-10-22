#include<stdio.h>
#include<stdlib.h>
#include <SDL2/SDL.h>
//////////

///////
int testPssibleMouveKingCase(int x , int y , int xMouse , int yMouse );

///////////// horizontale
int conditionwinroicasehaut(int Xroi , int  Yroi , int x , int  y );
/////
int conditionwinroicasebas(int Xroi , int  Yroi , int x , int  y );
/////////// verticale
int conditionwinroicasegauch(int Xroi , int  Yroi , int x , int  y );
/////
int conditionwinroicasedroit(int Xroi , int  Yroi , int x , int  y );
/////
int Nouvx_roi( int x );
/////////

int Nouvy_roi(int y );
///////
int moinCaseRoyale(int x1 , int y1 , int x2 , int y2);
//////////////
int testMousePositionroi(int xRoi , int yROI , int xMouse , int yMouse  );
///////////////
int testMousePositiondamv(int x , int y , int xMouse , int yMouse  );
/////////
int testMousePositiondamh(int x , int y , int xMouse , int yMouse  );
//////////////
int Nouvx_damverticale( int x);
/////////////
int Nouvy_damverticale( int y);
/////
int Nouvx_damhorizontale( int x);
////////
int Nouvy_damhorizontale( int y);
/////
int testMousePositionvertToHoriz(int x , int y  , int xMouse , int yMouse);
////
int testMousePositionvertToHorizP(int x , int y  , int xMouse , int yMouse);
///////
int testMousePositionvertToHorizPh(int x , int y  , int xMouse , int yMouse);
///////
int testMousePositionHorizonToVertic(int x , int y  , int xMouse , int yMouse);
///////
int testMousePositionHorizonToVerticP(int x , int y  , int xMouse , int yMouse);

////////
int testMousePositionHorizonToVerticPh(int x , int y  , int xMouse , int yMouse);
///////
int lmaklahorizontalehaut(int x , int y , int x1 , int y1 );
/////
int lmaklahorizontalebas(int x , int y , int x1 , int y1 );
///
int lmaklaVerticaledroit(int x , int y , int x1 , int y1 );
/////
int lmaklaVerticalegauch(int x , int y , int x1 , int y1 );
/////
int testExistanceVerticaldroit(int x , int y , int x1 , int y1);
//////
int testExistanceVerticalgauch(int x , int y , int x1 , int y1);
/////////
int testExistancehorizontalhaut(int x , int y , int x1 , int y1);
//////
int testExistancehorizontalbas(int x , int y , int x1 , int y1);
//////
int lmaklaVerticaledroitpion(int x , int y , int x1 , int y1 );
//////////
int lmaklaVerticalegauchpion(int x , int y , int x1 , int y1 );
////////////
int testMousePosiblemove(int x , int y  , int xMouse , int yMouse);
/////
//////
int testMousePosiblemove2(int x , int y  , int xMouse , int yMouse);
//////
int lmaklahorizontalehautpion(int x , int y , int x1 , int y1 );
///////
int lmaklahorizontalebaspion(int x , int y , int x1 , int y1 );
/////////////////

int dampossibleMove( int x1 , int y1 , int x2 , int y2);
////////////
