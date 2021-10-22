#include<stdio.h>
#include<stdlib.h>
//#include <SDL2/SDL.h>
#include "bulltricker.h"
//////////

///////
int testPssibleMouveKingCase(int x , int y , int xMouse , int yMouse ){
        x = x/68 ;
        y = y/68 ;
        xMouse = xMouse/68 ;
        yMouse = yMouse/68 ;
        if( x == xMouse ){
            if( y == yMouse+1 || y == yMouse-1) return 1 ;
        }
        if( y == yMouse ){
            if( x == xMouse+1 || x == xMouse-1) return 1 ;
        }
    return 0 ;
}
///////////// horizontale
int conditionwinroicasehaut(int Xroi , int  Yroi , int x , int  y ){
        if (x == Xroi ){
            if(y == Yroi - 24) return 1 ;
        }
        return 0 ;
}
int conditionwinroicasebas(int Xroi , int  Yroi , int x , int  y ){
        if (x == Xroi ){
            if(y == Yroi +44) return 1 ;
        }
        return 0 ;
}
/////////// verticale
int conditionwinroicasegauch(int Xroi , int  Yroi , int x , int  y ){
        if (y == Yroi ){
            if(x == Xroi - 24) return 1 ;
        }
        return 0 ;
}
int conditionwinroicasedroit(int Xroi , int  Yroi , int x , int  y ){
        if (y == Yroi ){
            if(x == Xroi +44) return 1 ;
        }
        return 0 ;
}
/////
int Nouvx_roi( int x ){
    int m=x/68 + 1    , r ;
    int n = x - m*24 - (m - 1 ) *44 ;
        r = 26 + ((m - 1 )*68) ;
        return r ;
}
/////////

int Nouvy_roi(int y ){
    y = y - 50  ;
    int m=y/68+1  , r  ;
   int n = y - m*24 - (m - 1 ) *44 ;
        r = 76 + ((m - 1 )*68) ;
        return r ;
}
///////
int moinCaseRoyale(int x1 , int y1 , int x2 , int y2){
        if(( x1 == x2 )&& (y1 == y2 ) )return  1 ;
        if ( x1 == x2 || x1 ==  x2 + 68 || x1 == x2 - 68 ){
            if ( y1 == y2 + 68 || y1 == y2 - 68 ) return 1 ;
        }
        if ( y1 == y2 || y1 ==  y2 + 68 || y1 == y2 - 68 ){
            if ( x1 == x2 + 68 || x1 == x2 - 68 ) return 1 ;
        }

return 0 ;
}
//////////////
int testMousePositionroi(int xRoi , int yROI , int xMouse , int yMouse  ){
     if (xRoi <= xMouse && xRoi+44 >= xMouse ) {
                        if (yROI <= yMouse && yROI+44 >= yMouse )
                                return 1 ;
     }
     return 0 ;
}
///////////////
/*int ConditionDujeu(){

    for(i=)


}*/
///////
int testMousePositiondamv(int x , int y , int xMouse , int yMouse  ){
     if (x-2 <= xMouse && x+22 >= xMouse ) {
                        if (y -2 <= yMouse && y+42 >= yMouse )
                                return 1 ;
     }
     return 0 ;
}
/////////
int testMousePositiondamh(int x , int y , int xMouse , int yMouse  ){
     if (x-2 <= xMouse && x+42 >= xMouse ) {
                        if (y -2 <= yMouse && y+22 >= yMouse )
                                return 1 ;
     }
     return 0 ;
}
//////////////
int Nouvx_damverticale( int x){
    int r , m = x/68  ;
           r = 2 + (m*68) ;
            return r ;
}
/////////////
int Nouvy_damverticale( int y){
    y = y-50 ;
    int r , m = y/68 ;
            r = 76 + (m*68) ;
            return r ;
}
int Nouvx_damhorizontale( int x){
    int m = x/68  ;
            int r = 26 + (m*68) ;
            return r ;
}
int Nouvy_damhorizontale( int y){
    y = y - 50 ;
    int m = y/68   ;
            int r = 52 + (m*68) ;
            return r ;
}
int testMousePositionvertToHoriz(int x , int y  , int xMouse , int yMouse){
      //y = y-50 ;
      yMouse = yMouse - 50 ;
      int m  = xMouse/68 ;
      int m1 = yMouse/68 ;
      x = x/68 ;
      y = y/68 ;
      if (  (m == x)  || (m == x -1 )){
            if ( ( m1 == y ) || (m1 == y -1)){
                    return 1 ;
            }
      }
     return 0 ;
}
////
int testMousePositionvertToHorizP(int x , int y  , int xMouse , int yMouse){
      y = y-50 ;
      yMouse = yMouse - 50 ;
      int m  = xMouse/68 ;
      int m1 = yMouse/68 ;
      x = x/68 ;
      y = y/68 ;
      if ((  (m == x)  || (m == x -1 )) && ( m1 == y )){

                    return 1 ;

      }
     return 0 ;
}
///////
int testMousePositionvertToHorizPh(int x , int y  , int xMouse , int yMouse){
      y = y-50 ;
      yMouse = yMouse - 50 ;
      int m  = xMouse/68 ;
      int m1 = yMouse/68 ;
      x = x/68 ;
      y = y/68 ;
      if ((  (m == x)  || (m == x -1 )) && ( m1 == y+1 )){

                    return 1 ;

      }
     return 0 ;
}
///////
int testMousePositionHorizonToVertic(int x , int y  , int xMouse , int yMouse){
      y = y-50 ;
      yMouse = yMouse - 50 ;
      int m  = xMouse/68 ;
      int m1 = yMouse/68 ;
      x = x/68 ;
      y = y/68 ;
      if (  (m == x)  || (m == x +1 )){
            if ( ( m1 == y ) || (m1 == y -1)){
                    return 1 ;
            }
      }
     return 0 ;
}
///////
int testMousePositionHorizonToVerticP(int x , int y  , int xMouse , int yMouse){
      y = y-50 ;
      yMouse = yMouse - 50 ;
      int m  = xMouse/68 ;
      int m1 = yMouse/68 ;
      x = x/68 ;
      y = y/68 ;
      if (  ((m == x)  || (m == x +1 ) ) && (m1 == y -1) ){

                    return 1 ;

      }
     return 0 ;
}
////////
int testMousePositionHorizonToVerticPh(int x , int y  , int xMouse , int yMouse){
      y = y-50 ;
      yMouse = yMouse - 50 ;
      int m  = xMouse/68 ;
      int m1 = yMouse/68 ;
      x = x/68 ;
      y = y/68 ;
      if (  ((m == x)  || (m == x +1 ) ) && (m1 == y ) ){

                    return 1 ;

      }
     return 0 ;
}
///////
int lmaklahorizontalehaut(int x , int y , int x1 , int y1 ){
    int  i ,  y2 ,m = (y-50) / 68 ;
    for( i = 1 ; i < m ; i++ ){
              y2 = 52 + 68*i ;
              if ( y1 == y2 ) {
                    if(x == x1) return 1 ;
             }
    }
    return 0 ;
}
int lmaklahorizontalebas(int x , int y , int x1 , int y1 ){
     int  i ,  y2 ,m = (y-50) / 68  ;
    for( i = m+1 ; i < 7 ; i++ ){
              y2 = 52 + 68*i ;
              if ( y1 == y2 ) {
                    if(x == x1) return 1 ;
             }
    }
    return 0 ;
}
int lmaklaVerticaledroit(int x , int y , int x1 , int y1 ){
     int  i ,  x2  , m = x/68  ;
    for( i = m+1 ; i < 7 ; i++ ){
              x2 = 2 + 68*i ;
              if ( x1 == x2 ) {
                    if(y == y1) return 1 ;
             }
    }

    return 0 ;
}
int lmaklaVerticalegauch(int x , int y , int x1 , int y1 ){
    int  i ,  x2  , m = x/68  ;
    for( i = 1 ; i < m ; i++ ){
              x2 = 2 + 68*i ;
              if ( x1 == x2 ) {
                    if(y == y1) return 1 ;
             }
    }

    return 0 ;
}
int testExistanceVerticaldroit(int x , int y , int x1 , int y1){
   if (y == y1){
            x = x + 68 ;
            if(x==x1){
                return 1 ;
        }
    }
return 0 ;
}
int testExistanceVerticalgauch(int x , int y , int x1 , int y1){
    if(y==y1){
        x = x - 68 ;
        if (x == x1){
                return 1 ;
        }
    }

return 0 ;
}
int testExistancehorizontalhaut(int x , int y , int x1 , int y1){
     y = y - 68 ;
        if (x == x1){
            if(y==y1){
                return 1 ;

        }
    }

return 0 ;
}
int testExistancehorizontalbas(int x , int y , int x1 , int y1){
   y = y + 68 ;
        if (y == y1){
            if(x==x1){
                return 1 ;

        }
    }
return 0 ;
}
int lmaklaVerticaledroitpion(int x , int y , int x1 , int y1 ){
     int  i ,  x2  , m = x/68 +1 ;
              x2 = 2 + 68*m ;
              if ( x1 == x2 ) {
                    if(y == y1) return 1 ;
             }
    return 0 ;
}
int lmaklaVerticalegauchpion(int x , int y , int x1 , int y1 ){
    int  i ,  x2  , m = x/68  ;
              x2 = 2 + 68*(m-1) ;
              if ( x1 == x2 ) {
                    if(y == y1) return 1 ;
             }
    return 0 ;
}
int testMousePosiblemove(int x , int y  , int xMouse , int yMouse){
      yMouse = yMouse - 50 ;
      y=y-50;
      int m  = xMouse/68 ;
      int m1 = yMouse/68 ;
      x = x/68 ;
      y = y/68 ;
      if (  (m == x) &&  ( m1 == y-1 ) ){
                    return 1 ;
      }
       if (  (m1 == y) && ( ( m == x+1 ) || (m == x -1)) ){
                    return 1 ;
      }
     return 0 ;
}
/////

//////
int testMousePosiblemove2(int x , int y  , int xMouse , int yMouse){
      yMouse = yMouse - 50 ;
      y=y-50;
      int m  = xMouse/68 ;
      int m1 = yMouse/68 ;
      x = x/68 ;
      y = y/68 ;
      if (  (m == x)  ){
            if ( ( m1 == y+1 )){ //|| (m1 == y -1)){
                    return 1 ;
            }
      }
       if (  (m1 == y)  ){
            if ( ( m == x+1 ) || (m == x -1)){
                    return 1 ;
            }
      }
     return 0 ;
}

int lmaklahorizontalehautpion(int x , int y , int x1 , int y1 ){
    int  i ,  y2 ,m = (y-50) / 68  ;
              y2 = 52 + 68*(m-1) ;
              if ( y1 == y2 ) {
                    if(x == x1) return 1 ;
    }
    return 0 ;
}
int lmaklahorizontalebaspion(int x , int y , int x1 , int y1 ){
     int  i ,  y2 ,m = ((y-50) / 68)   ;
              y2 = 52 + 68*(m+1) ;
              if ( y1 == y2 ) {
                    if(x == x1) return 1 ;
    }
    return 0 ;
}

int dampossibleMove( int x1 , int y1 , int x2 , int y2){
    int a = 0 ;
            if ( x1 == x2 ){
                if ( y2 = y1 - 68 )  a = 1 ;
                if ( y2 = y1 + 68 )  a = 3 ;
            }
            if ( y1 == y2 ){
                if ( x2 = x1 + 68 )  a = 2 ;
                if ( x2 = x1 - 68 )  a = 4  ;
            }
return a ;
}

