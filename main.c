#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <sdl2/SDL_mixer.h>
#include "bulltricker.h"
//#include "jeux.h"
int main(int argc, char * argv[]){

     //l'Error
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        fprintf(stderr, "SDL Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT,2, 2048);
    Mix_Chunk * jump = Mix_LoadWAV("Arabesque.wav");
    Mix_Chunk * jump1 = Mix_LoadWAV("12.wav");
    //window
    SDL_Window* window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 550,0); //SDL_WINDOW_FULLSCREEN
    SDL_Renderer*rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //menu
    SDL_Rect  rect;
    SDL_Surface *Sur = SDL_LoadBMP("img/menu.bmp");
    SDL_Texture *Tex = SDL_CreateTextureFromSurface(rend, Sur);
    SDL_QueryTexture(Tex, NULL, NULL, &rect.w, &rect.h);
    rect.x = rect.y = 0;
    //tour 1
    SDL_Rect  rect_tour1;
    SDL_Surface *Sur_tour1 = SDL_LoadBMP("img/tour1.bmp");
    SDL_Texture *Tex_tour1 = SDL_CreateTextureFromSurface(rend, Sur_tour1);
    SDL_QueryTexture(Tex_tour1, NULL, NULL, &rect_tour1.w, &rect_tour1.h);
    rect_tour1.x = rect_tour1.y = 0;
    //tour 2
    SDL_Rect  rect_tour2;
    SDL_Surface *Sur_tour2 = SDL_LoadBMP("img/tour2.bmp");
    SDL_Texture *Tex_tour2 = SDL_CreateTextureFromSurface(rend, Sur_tour2);
    SDL_QueryTexture(Tex_tour2, NULL, NULL, &rect_tour2.w, &rect_tour2.h);
    rect_tour2.x = rect_tour2.y = 0;

    //win1
    SDL_Rect rect_win1 ;
    SDL_Surface *Sur_win1 = SDL_LoadBMP("img/win1.bmp");
    SDL_Texture *Tex_win1 = SDL_CreateTextureFromSurface(rend, Sur_win1);
    SDL_QueryTexture(Tex_win1, NULL, NULL, &rect_win1.w, &rect_win1.h);
    rect_win1.x = rect_win1.y  = 0;
    //win2
    SDL_Rect rect_win2 ;
    SDL_Surface *Sur_win2 = SDL_LoadBMP("img/win2.bmp");
    SDL_Texture *Tex_win2 = SDL_CreateTextureFromSurface(rend, Sur_win2);
    SDL_QueryTexture(Tex_win2, NULL, NULL, &rect_win2.w, &rect_win2.h);
    rect_win2.x = rect_win2.y = 0;

    //table de jeu :
    SDL_Rect rect_tab  ;
    SDL_Surface * Sur_tab = SDL_LoadBMP("img/table.bmp");
    SDL_Texture * Tex_tab = SDL_CreateTextureFromSurface(rend, Sur_tab);
    SDL_QueryTexture(Tex_tab, NULL, NULL, &rect_tab.w, &rect_tab.h);
    rect_tab.x = 0 , rect_tab.y = 50;

     //roi 1 :
    SDL_Rect rect2_roi1 ;
    SDL_Surface *Sur_roi1 = SDL_LoadBMP("img/roi1.bmp");
    SDL_Texture *Tex_roi1 = SDL_CreateTextureFromSurface(rend, Sur_roi1);
    SDL_QueryTexture(Tex_roi1, NULL, NULL, &rect2_roi1.w, &rect2_roi1.h);
    rect2_roi1.x = 230 ;
    rect2_roi1.y = 483 ;

    //roi2 :
    SDL_Rect  rect2_roi2 ;
    SDL_Surface *Sur_roi2 = SDL_LoadBMP("img/roi2.bmp");
    SDL_Texture *Tex_roi2 = SDL_CreateTextureFromSurface(rend, Sur_roi2);
    SDL_QueryTexture(Tex_roi2, NULL, NULL, &rect2_roi2.w, &rect2_roi2.h);
    rect2_roi2.x = 230 ;
    rect2_roi2.y =  76 ;

    //dam Playrs 1 verticale
    SDL_Surface * Sur_dam1_v[23];
    SDL_Texture * Tex_dam1_v[23];
    SDL_Rect rect2_dam1_v[23]  ;
    int  i =0 ;
    for(i=0 ; i<8 ; i++){
        Sur_dam1_v[i] = SDL_LoadBMP("img/dam1v.bmp");
        Tex_dam1_v[i] = SDL_CreateTextureFromSurface(rend, Sur_dam1_v[i]);
        SDL_QueryTexture(Tex_dam1_v[i], NULL, NULL, &rect2_dam1_v[i].w, &rect2_dam1_v[i].h);
        rect2_dam1_v[i].x = 2 + i *68 ;
        rect2_dam1_v[i].y = 484;

    }
    for(i=8 ; i<23 ; i++){
        Sur_dam1_v[i] = SDL_LoadBMP("img/dam1v.bmp");
        Tex_dam1_v[i] = SDL_CreateTextureFromSurface(rend, Sur_dam1_v[i]);
        SDL_QueryTexture(Tex_dam1_v[i], NULL, NULL, &rect2_dam1_v[i].w, &rect2_dam1_v[i].h);
        rect2_dam1_v[i].x = rect2_dam1_v[i].y = NULL ;

    }
    // dam 1 horizontale
    SDL_Surface * Sur_dam1_h[23];
    SDL_Texture * Tex_dam1_h[23];
    SDL_Rect rect2_dam1_h[23]  ;
    for(i=0 ; i<23 ; i++){
        Sur_dam1_h[i] = SDL_LoadBMP("img/dam1h.bmp");
        Tex_dam1_h[i] = SDL_CreateTextureFromSurface(rend, Sur_dam1_h[i]);
        SDL_QueryTexture(Tex_dam1_h[i], NULL, NULL, &rect2_dam1_h[i].w, &rect2_dam1_h[i].h);
        rect2_dam1_h[i].x = rect2_dam1_h[i].y = NULL;
    }

    //pions Playrs 1 verticale
    SDL_Surface * Sur_pion1_v[15];
    SDL_Texture * Tex_pion1_v[15];
    SDL_Rect rect2_pion1_v[15]  ;
    for(i=0 ; i<8 ; i++){
        Sur_pion1_v[i] = SDL_LoadBMP("img/pion1v.bmp");
        Tex_pion1_v[i] = SDL_CreateTextureFromSurface(rend, Sur_pion1_v[i]);
        SDL_QueryTexture(Tex_pion1_v[i], NULL, NULL, &rect2_pion1_v[i].w, &rect2_pion1_v[i].h);
        rect2_pion1_v[i].x = 2 + i *68 ;rect2_pion1_v[i].y = 416;
    }
    for(i=8 ; i<15 ; i++){
        Sur_pion1_v[i] = SDL_LoadBMP("img/pion1v.bmp");
        Tex_pion1_v[i] = SDL_CreateTextureFromSurface(rend, Sur_pion1_v[i]);
        SDL_QueryTexture(Tex_pion1_v[i], NULL, NULL, &rect2_pion1_v[i].w, &rect2_pion1_v[i].h);
        rect2_pion1_v[i].x = rect2_pion1_v[i].y = 0;
        }
    //pions Playrs 1 horizontale
    SDL_Surface * Sur_pion1_h[15];
    SDL_Texture * Tex_pion1_h[15];
    SDL_Rect rect2_pion1_h[15]  ;
    for(i=0 ; i<7 ; i++){
        Sur_pion1_h[i] = SDL_LoadBMP("img/pion1h.bmp");
        Tex_pion1_h[i] = SDL_CreateTextureFromSurface(rend, Sur_pion1_h[i]);
        SDL_QueryTexture(Tex_pion1_h[i], NULL, NULL, &rect2_pion1_h[i].w, &rect2_pion1_h[i].h);
        rect2_pion1_h[i].x = 26 + i *68 ;rect2_pion1_h[i].y = 460;
    }
    for(i=7 ; i<15 ; i++){
        Sur_pion1_h[i] = SDL_LoadBMP("img/pion1h.bmp");
        Tex_pion1_h[i] = SDL_CreateTextureFromSurface(rend, Sur_pion1_h[i]);
        SDL_QueryTexture(Tex_pion1_h[i], NULL, NULL, &rect2_pion1_h[i].w, &rect2_pion1_h[i].h);
        rect2_pion1_h[i].x =rect2_pion1_h[i].y = NULL ;
        }

     //dam Playrs 2 vrticalles
    SDL_Surface * Sur_dam2_v[23];
    SDL_Texture * Tex_dam2_v[23];
    SDL_Rect  rect2_dam2_v[23] ;
    for(i=0 ; i<8 ; i++){
        Sur_dam2_v[i] = SDL_LoadBMP("img/dam2v.bmp");
        Tex_dam2_v[i] = SDL_CreateTextureFromSurface(rend, Sur_dam2_v[i]);
        SDL_QueryTexture(Tex_dam2_v[i], NULL, NULL, &rect2_dam2_v[i].w, &rect2_dam2_v[i].h);
        rect2_dam2_v[i].x = 2 + i *68 ;
        rect2_dam2_v[i].y = 76;
        }
    for(i=8 ; i<23 ; i++){
        Sur_dam2_v[i] = SDL_LoadBMP("img/dam2v.bmp");
        Tex_dam2_v[i] = SDL_CreateTextureFromSurface(rend, Sur_dam2_v[i]);
        SDL_QueryTexture(Tex_dam2_v[i], NULL, NULL, &rect2_dam2_v[i].w, &rect2_dam2_v[i].h);
        rect2_dam2_v[i].x = rect2_dam2_v[i].y = NULL ;
        }
    // dam player 2 horizontale
    SDL_Surface * Sur_dam2_h[23];
    SDL_Texture * Tex_dam2_h[23];
    SDL_Rect rect2_dam2_h[23] ;
    for(i=0 ; i<23 ; i++){
        Sur_dam2_h[i] = SDL_LoadBMP("img/dam2h.bmp");
        Tex_dam2_h[i] = SDL_CreateTextureFromSurface(rend, Sur_dam2_h[i]);
        SDL_QueryTexture(Tex_dam1_h[i], NULL, NULL, &rect2_dam2_h[i].w, &rect2_dam2_h[i].h);
        rect2_dam2_h[i].x = rect2_dam2_h[i].y = NULL;
    }
    //pions Playrs 2 verticale
    SDL_Surface * Sur_pion2_v[15];
    SDL_Texture * Tex_pion2_v[15];
    SDL_Rect  rect2_pion2_v[15] ;
    for(i=0 ; i<8 ; i++){
        Sur_pion2_v[i] = SDL_LoadBMP("img/pion2v.bmp");
        Tex_pion2_v[i] = SDL_CreateTextureFromSurface(rend, Sur_pion2_v[i]);
        SDL_QueryTexture(Tex_pion2_v[i], NULL, NULL, &rect2_pion2_v[i].w, &rect2_pion2_v[i].h);
        rect2_pion2_v[i].x = 2 + i *68 ;rect2_pion2_v[i].y = 144;
    }
    for(i=8 ; i<15 ; i++){
        Sur_pion2_v[i] = SDL_LoadBMP("img/pion2v.bmp");
        Tex_pion2_v[i] = SDL_CreateTextureFromSurface(rend, Sur_pion2_v[i]);
        SDL_QueryTexture(Tex_pion2_v[i], NULL, NULL, &rect2_pion2_v[i].w, &rect2_pion2_v[i].h);
        rect2_pion2_v[i].x =rect2_pion2_v[i].y = NULL ;
    }
    //pions Playrs 2 horizontale
    SDL_Surface * Sur_pion2_h[15];
    SDL_Texture * Tex_pion2_h[15];
    SDL_Rect rect2_pion2_h[15]  ;
    for(i=0 ; i<7 ; i++){
        Sur_pion2_h[i] = SDL_LoadBMP("img/pion2h.bmp");
        Tex_pion2_h[i] = SDL_CreateTextureFromSurface(rend, Sur_pion2_h[i]);
        SDL_QueryTexture(Tex_pion2_h[i], NULL, NULL, &rect2_pion2_h[i].w , &rect2_pion2_h[i].h);
        rect2_pion2_h[i].x = 26 + i *68 ; rect2_pion2_h[i].y = 120 ;
        }
    for(i=7 ; i<15 ; i++){
        Sur_pion2_h[i] = SDL_LoadBMP("img/pion2h.bmp");
        Tex_pion2_h[i] = SDL_CreateTextureFromSurface(rend, Sur_pion2_h[i]);
        SDL_QueryTexture(Tex_pion2_h[i], NULL, NULL, &rect2_pion2_h[i].w, &rect2_pion2_h[i].h);
        rect2_pion2_h[i].x =rect2_pion2_h[i].y = NULL ;

    }

   //evenment
    int quit = 0 ,k=0 ,dmm , q=0 , tour =1 , z=1 , w ,w1, x1 , y1 , x2 , y2 , pi=0 , pi1, li , wi=0 ,wi1=0,vhi=0,vhi1=0,opi , li1;
    int vh1 , vh2 , zw=0 ,zw1=0, p = 0 , r=0 , p1 = 0 , r1 =0 , j =0 , l=1 ,l1=1 , op=0,faulsv,h=1,h1=1 ;
    int win1=0 ,win2=0 ,a1 = 0 , a2 = 0 , b1 = 0 , b2 = 0 ,c1 = 0 , c2 = 0 ,d1=0 , d2=0 ,ri =0, ri1=0,hi=1,hi1=1,opi1=0,vhi21=0 ,yi=0 , yi1=0 , opi2=0;
    int a3 = 0 , a4 = 0 , b3 = 0 , b4 = 0 ,c3 = 0 , c4 = 0 ,d3=0 , d4=0 ,a=0 , b=0 , c=0 , d=0 , f1,f2,f3,f4;
    SDL_Event  event ,e ;
    while(quit == 0 ){
        SDL_WaitEvent (&event);
        switch(event.type){
        case SDL_QUIT :
            quit = 1;
            break;
        case SDL_KEYDOWN :
            q=0;
            switch(event.key.keysym.sym){
            case SDLK_ESCAPE :
                quit = 1;
                break;
                break;
            case SDLK_SPACE :
                while(q == 0 ){
                    vh1 = 0, vh2=0  , w=0 , zw=0 ,zw1=0, p = 0 , r=0 , p1 = 0 , r1 =0 , j =0 , l=1 ,l1=1 , op=0 , opi=0,faulsv,h=1,h1=1;
                    pi=0 , pi1=0 , li=1 ,li1=1, wi=0 ,wi1=0,vhi=0,vhi1=0 ,ri =0, ri1=0,hi=1,hi1=1,opi1=0,vhi21=0 ,yi=0 ,yi1=0;opi2=0;
                    a1 = 0 , a2 = 0 , b1 = 0 , b2 = 0 ,c1 = 0 , c2 = 0 ,d1=0 , d2=0 ;
                    a3 = 0 , a4 = 0 , b3 = 0 , b4 = 0 ,c3 = 0 , c4 = 0 ,d3=0 , d4=0 , a=0 , b=0 , c=0 , d=0 ;
                    SDL_WaitEvent (&event);
                    switch(event.type){
                    case SDL_QUIT :
                        q = 1;
                        quit = 1;
                        break;
                    case SDL_KEYDOWN :
                        switch(event.key.keysym.sym){
                        case SDLK_ESCAPE :
                        q = 1;
                        break;
                        }
                    case SDL_MOUSEBUTTONDOWN :
                    //////roi 1

                        if( tour%2 == 1){                           ////// tour 1
                            w=0;w1=0;zw=0;zw1=0;
                            if (testMousePositionroi(rect2_roi1.x , rect2_roi1.y , event.motion.x , event.motion.y  )){
                                  z = 0 ; a=0 ; b=0 ; c=0 ; d=0 ;
                                while( z == 0 && tour > 1){
                                SDL_WaitEvent(&event);
                                switch(event.type){
                                case SDL_QUIT :
                                    tour = tour+1;
                                    z=1;
                                    q = 1;
                                    quit = 1 ;
                                    break ;
                                case SDL_MOUSEBUTTONDOWN :

                                    if (testPssibleMouveKingCase(rect2_roi1.x , rect2_roi1.y ,event.motion.x , event.motion.y )){
                                        x1 =  rect2_roi1.x ;
                                        y1 =  rect2_roi1.y ;
                                        rect2_roi1.x =  Nouvx_roi(event.motion.x);
                                        rect2_roi1.y =  Nouvy_roi(event.motion.y);
                                        tour = tour+1 ;w=1;

                                        if (  moinCaseRoyale(rect2_roi1.x , rect2_roi1.y , rect2_roi2.x , rect2_roi2.y)){
                                            rect2_roi1.x = x1 ;  rect2_roi1.y = y1;tour = tour - 1 ;
                                        }

                                        if( Nouvx_roi(event.motion.x) ==  x1 ){
                                                if ( Nouvy_roi(event.motion.y) ==  y1 + 68 ){
                                                        for(i=0 ; i<23 ; i++){
                                                            if(conditionwinroicasebas( x1 ,  y1 ,  rect2_dam1_h[i].x , rect2_dam1_h[i].y )) b=1;
                                                            if(conditionwinroicasebas( x1 ,  y1 ,  rect2_dam2_h[i].x , rect2_dam2_h[i].y )) b=1;

                                                            }
                                                     for(i=0 ; i<15 ; i++){
                                                            if(conditionwinroicasebas( x1 ,  y1 ,  rect2_pion1_h[i].x , rect2_pion1_h[i].y )) b=1;
                                                            if(conditionwinroicasebas( x1 ,  y1 ,  rect2_pion2_h[i].x , rect2_pion2_h[i].y )) b=1;
                                                            if(  b == 1){rect2_roi1.x = x1 ;  rect2_roi1.y = y1;}
                                                    }if(  b == 1){rect2_roi1.x = x1 ;  rect2_roi1.y = y1;tour = tour - 1 ;}
                                                }

                                                if ( Nouvy_roi(event.motion.y)  ==  y1 - 68 ){
                                                        for(i=0 ; i<23 ; i++){
                                                            if(conditionwinroicasehaut( x1 ,  y1 ,  rect2_dam1_h[i].x , rect2_dam1_h[i].y )) a=1;
                                                            if(conditionwinroicasehaut( x1 ,  y1 ,  rect2_dam2_h[i].x , rect2_dam2_h[i].y )) a=1;
                                                            }
                                                     for(i=0 ; i<15 ; i++){
                                                            if(conditionwinroicasehaut( x1 ,  y1 ,  rect2_pion1_h[i].x , rect2_pion1_h[i].y )) a=1;
                                                            if(conditionwinroicasehaut( x1 ,  y1 ,  rect2_pion2_h[i].x , rect2_pion2_h[i].y )) a=1;
                                                    }if(  a == 1){rect2_roi1.x = x1 ;  rect2_roi1.y = y1;tour = tour - 1 ; }
                                                }

                                                }
                                        if( Nouvy_roi(event.motion.y) ==  y1 ){
                                                if ( Nouvx_roi(event.motion.x) ==  x1 - 68 ){
                                                        for(i=0 ; i<23 ; i++){
                                                            if(conditionwinroicasegauch( x1 ,  y1 ,  rect2_dam1_v[i].x , rect2_dam1_v[i].y )) c=1;
                                                            if(conditionwinroicasegauch( x1 ,  y1 ,  rect2_dam2_v[i].x , rect2_dam2_v[i].y )) c=1;
                                                            }
                                                     for(i=0 ; i<15 ; i++){
                                                            if(conditionwinroicasegauch( x1 ,  y1 ,  rect2_pion1_v[i].x , rect2_pion1_v[i].y )) c=1;
                                                            if(conditionwinroicasegauch( x1 ,  y1 ,  rect2_pion2_v[i].x , rect2_pion2_v[i].y )) c=1;
                                                    } if( c == 1){ rect2_roi1.x = x1 ;  rect2_roi1.y = y1;tour = tour - 1 ;}
                                                }
                                                if ( Nouvx_roi(event.motion.x) ==  x1 + 68 ){
                                                        for(i=0 ; i<23 ; i++){
                                                            if(conditionwinroicasedroit( x1 ,  y1 ,  rect2_dam1_v[i].x , rect2_dam1_v[i].y )) d=1;
                                                            if(conditionwinroicasedroit( x1 ,  y1 ,  rect2_dam2_v[i].x , rect2_dam2_v[i].y )) d=1;
                                                            }
                                                     for(i=0 ; i<15 ; i++){
                                                            if(conditionwinroicasedroit( x1 ,  y1 ,  rect2_pion1_v[i].x , rect2_pion1_v[i].y )) d=1;
                                                            if(conditionwinroicasedroit( x1 ,  y1 ,  rect2_pion2_v[i].x , rect2_pion2_v[i].y )) d=1;
                                                    } if( d == 1){ rect2_roi1.x = x1 ;  rect2_roi1.y = y1;tour = tour - 1 ;}
                                                }
                                                }
                                   }z=1;
                                }
                             }
                            }
                            //////////////dam 1 :
                    /////////////////// verticale
                    if(w==0){
                        for (i = 0 ; i < 23 ; i++){              /////click sur une dame verticale
                            if (testMousePositiondamv(rect2_dam1_v[i].x  , rect2_dam1_v[i].y  ,event.motion.x ,event.motion.y  )){
                                p  = i +1;break;
                            }
                        }
                        if (p != 0 ){                            /////test dyal lmakla
                                 for(i=0 ; i<23 ; i++){
                                    if (lmaklaVerticaledroit( rect2_dam1_v[p-1].x ,rect2_dam1_v[p-1].y , rect2_dam2_v[i].x , rect2_dam2_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticaldroit(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                p1 = 0 ;l=0;break;
                                            }if(l==0) break ;
                                            if( testExistanceVerticaldroit(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                p1 = 0 ;l=0;break;
                                            }if(l==0) break ;
                                            if( testExistanceVerticaldroit(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                                p1 = 0 ;l=0;break;
                                            }if(l==0) break ;
                                            if( testExistanceVerticaldroit(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                                p1 = 0 ;l=0;break;
                                            }if(l==0) break ;
                                        }if (l==0) break;
                                    }if (l==0) break;
                                    if (lmaklaVerticaledroit( rect2_dam1_v[p-1].x ,rect2_dam1_v[p-1].y , rect2_pion2_v[i].x , rect2_pion2_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticaldroit(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                p1 = 0 ;l=0;break;
                                            }if(l==0) break ;
                                            if( testExistanceVerticaldroit(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                p1 = 0 ;l=0;break;
                                            }if(l==0) break ;
                                            if( testExistanceVerticaldroit(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                                p1 = 0;l=0;break;
                                            }if(l==0) break ;
                                            if( testExistanceVerticaldroit(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                                p1 = 0 ;l=0;break;
                                            }if(l==0) break ;
                                        }if (l==0) break;
                                    }if (l==0) break;
                                    if (lmaklaVerticalegauch( rect2_dam1_v[p-1].x ,rect2_dam1_v[p-1].y , rect2_dam2_v[i].x , rect2_dam2_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticalgauch(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                p1 = 0;l=0;break;
                                            }if (l==0) break;
                                            if( testExistanceVerticalgauch(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                                 p1 = 0;l=0 ;break;
                                            }if (l==0) break;
                                            if( testExistanceVerticalgauch(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                p1 = 0;l=0 ;break;
                                            }if (l==0) break;
                                            if( testExistanceVerticalgauch(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                                 p1 = 0;l=0 ;break;
                                            }if (l==0) break;
                                        }if (l==0) break;
                                    }if (l==0) break;
                                    if (lmaklaVerticalegauch( rect2_dam1_v[p-1].x ,rect2_dam1_v[p-1].y , rect2_pion2_v[i].x , rect2_pion2_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticalgauch(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                p1 = 0;l=0 ;break;
                                            }if (l==0) break;
                                            if( testExistanceVerticalgauch(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                                 p1 = 0;l=0 ;break;
                                            }if (l==0) break;
                                            if( testExistanceVerticalgauch(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                p1 = 0;l=0 ;break;
                                            }if (l==0) break;
                                            if( testExistanceVerticalgauch(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                                 p1 = 0;l=0 ;break;
                                            }if (l==0) break;
                                        }if (l==0) break;
                                    }if (l==0) break;
                                }
                         }
                          if (l != 0 ){                             /////l obligation  dyal lmakla
                              for(i=0 ; i<23 ; i++){
                                 if (lmaklaVerticaledroit( rect2_dam1_v[p-1].x ,rect2_dam1_v[p-1].y , rect2_dam2_v[i].x , rect2_dam2_v[i].y )){
                                    rect2_dam1_v[p-1].x = rect2_dam2_v[i].x + 68 ;
                                    rect2_dam2_v[i].x = NULL;
                                    rect2_dam2_v[i].y = NULL;
                                    p=0; p1 = 0 ;tour=tour+1 ;l=0 ;w1=1;break;
                                 }}}

                        if (l != 0 ){
                            for(i=0 ; i<15 ; i++){
                                 if (lmaklaVerticaledroit( rect2_dam1_v[p-1].x ,rect2_dam1_v[p-1].y , rect2_pion2_v[i].x , rect2_pion2_v[i].y )){
                                    rect2_dam1_v[p-1].x = rect2_pion2_v[i].x + 68 ;
                                    rect2_pion2_v[i].x = NULL;
                                    rect2_pion2_v[i].y = NULL;
                                    p=0; p1 = 0 ;tour=tour+1 ;l=0 ;w1=1;break;
                                 }}}

                         if (l != 0 ){
                            for(i=0 ; i<23 ; i++){
                                if (lmaklaVerticalegauch( rect2_dam1_v[p-1].x ,rect2_dam1_v[p-1].y , rect2_dam2_v[i].x , rect2_dam2_v[i].y )){
                                    rect2_dam1_v[p-1].x = rect2_dam2_v[i].x  - 68 ;
                                    rect2_dam2_v[i].x = NULL;
                                    rect2_dam2_v[i].y = NULL;
                                   p=0; p1 = 0 ;tour=tour+1 ;l=0 ;w1=1;break;
                                }}}

                            if (l != 0 ){
                            for(i=0 ; i<15 ; i++){
                                 if (lmaklaVerticalegauch( rect2_dam1_v[p-1].x ,rect2_dam1_v[p-1].y , rect2_pion2_v[i].x , rect2_pion2_v[i].y )){
                                    rect2_dam1_v[p-1].x = rect2_pion2_v[i].x - 68 ;
                                    rect2_pion2_v[i].x = NULL;
                                    rect2_pion2_v[i].y = NULL;
                                   p=0; p1 = 0 ;tour=tour+1 ;l=0 ;w1=1;break;
                                 }}}

                            while ( p != 0 ){          //// mouvement
                                SDL_WaitEvent(&event);
                                    switch(event.type){
                                    case SDL_QUIT :
                                        tour=tour+1;
                                        q = 1;
                                        quit = 1;
                                         p=0 ;
                                        break ;
                                    case SDL_MOUSEBUTTONDOWN :
                                        faulsv = 0 ;
                                        if ((event.motion.x  % 68 ) <= 24 && ((event.motion.y-50) % 68) >= 24 && (((event.motion.x/68) == (rect2_dam1_v[p-1].x/68))||((event.motion.y/68) == (rect2_dam1_v[p-1].y/68)))){
                                            for(i=0 ; i < 15 ; i++){

                                                if(Nouvx_damverticale(event.motion.x) == rect2_dam1_v[i].x &&(( Nouvy_damverticale(event.motion.y) == rect2_dam1_v[i].y) )){
                                                    faulsv = 1;break;
                                                    }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_dam2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam2_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                                    if(Nouvx_damverticale(event.motion.x) == rect2_pion1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion1_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_pion2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion2_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                            }
                                                if ( faulsv != 1 ){   ////// saut
                                                    for ( i = 0 ; i < 23 ; i++ ){
                                                        if( rect2_dam1_v[p-1].x == rect2_dam1_v[i].x && rect2_dam1_v[p-1].y == rect2_dam1_v[i].y + 68){
                                                            if( Nouvx_damverticale(event.motion.x) == rect2_dam1_v[i].x && Nouvy_damverticale(event.motion.y) < rect2_dam1_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam1_v[p-1].x == rect2_dam1_v[i].x && rect2_dam1_v[p-1].y == rect2_dam1_v[i].y - 68){
                                                            if( Nouvx_damverticale(event.motion.x) == rect2_dam1_v[i].x && Nouvy_damverticale(event.motion.y) > rect2_dam1_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                         if( rect2_dam1_v[p-1].y == rect2_dam1_v[i].y && rect2_dam1_v[p-1].x == rect2_dam1_v[i].x + 68){
                                                            if( Nouvx_damverticale(event.motion.x) < rect2_dam1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam1_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam1_v[p-1].y == rect2_dam1_v[i].y && rect2_dam1_v[p-1].x == rect2_dam1_v[i].x - 68){
                                                            if( Nouvx_damverticale(event.motion.x) > rect2_dam1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam1_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                    }
                                                    for ( i = 0 ; i < 15 ; i++ ){
                                                        if( rect2_dam1_v[p-1].x == rect2_pion1_v[i].x && rect2_dam1_v[p-1].y == rect2_pion1_v[i].y + 68){
                                                            if( Nouvx_damverticale(event.motion.x) == rect2_pion1_v[i].x && Nouvy_damverticale(event.motion.y) < rect2_pion1_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam1_v[p-1].x == rect2_pion1_v[i].x && rect2_dam1_v[p-1].y == rect2_pion1_v[i].y - 68){
                                                            if( Nouvx_damverticale(event.motion.x) == rect2_pion1_v[i].x && Nouvy_damverticale(event.motion.y) > rect2_pion1_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam1_v[p-1].y == rect2_pion1_v[i].y && rect2_dam1_v[p-1].x == rect2_pion1_v[i].x + 68){
                                                            if( Nouvx_damverticale(event.motion.x) < rect2_pion1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion1_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam1_v[p-1].y == rect2_pion1_v[i].y && rect2_dam1_v[p-1].x == rect2_pion1_v[i].x - 68){
                                                            if( Nouvx_damverticale(event.motion.x) > rect2_pion1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion1_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                    }}
                                                     if (faulsv != 1 ){

                                                            for (i = 0  ; i <= (7 - rect2_dam1_v[p-1].x /68) ; i++){
                                                        if(( (rect2_dam1_v[p-1].y == rect2_roi1.y) && ( rect2_dam1_v[p-1].x +(24 + 68*i) == rect2_roi1.x )) ||( (rect2_dam1_v[p-1].y == rect2_roi2.y) && ( rect2_dam1_v[p-1].x +(24 + 68*i) == rect2_roi2.x ))){
                                                            if( Nouvx_damverticale(event.motion.x) > rect2_roi1.x && Nouvy_damverticale(event.motion.y) == rect2_roi1.y || Nouvx_damverticale(event.motion.x) > rect2_roi2.x && Nouvy_damverticale(event.motion.y) == rect2_roi2.y ){
                                                                faulsv = 1 ; break ; }
                                                        }}}
                                                    if (faulsv != 1 ){
                                                        for (i = 0 ; i <= ( rect2_dam1_v[p-1].x /68 + 1 ) ; i++){
                                                          if( ((rect2_dam1_v[p-1].y == rect2_roi1.y) && ( rect2_dam1_v[p-1].x - (44 + 68*i)== rect2_roi1.x )) || ((rect2_dam1_v[p-1].y == rect2_roi2.y) && ( rect2_dam1_v[p-1].x - (44 + 68*i) == rect2_roi2.x ))){

                                                            if(( Nouvx_damverticale(event.motion.x) < rect2_roi1.x && Nouvy_damverticale(event.motion.y) == rect2_roi1.y )|| (Nouvx_damverticale(event.motion.x) < rect2_roi2.x && Nouvy_damverticale(event.motion.y) == rect2_roi2.y)){
                                                                faulsv = 1 ; break ; }
                                                        }
                                                      }
                                                     }
                                                 /////////////////
                                            if (faulsv == 0 ){
                                                rect2_dam1_v[p-1].x=Nouvx_damverticale(event.motion.x) ;
                                                rect2_dam1_v[p-1].y=Nouvy_damverticale(event.motion.y) ;
                                                p=0 ;p1=0;tour=tour+1;w1=1;
                                           }
                                        } faulsv = 0;
                                        if ((event.motion.x  % 68 ) > 24 && ((event.motion.y-50) % 68) < 24 ){
                                            if ( testMousePositionvertToHoriz(rect2_dam1_v[p-1].x ,rect2_dam1_v[p-1].y , event.motion.x , event.motion.y)){
                                                 for(i=0 ; i < 15 ; i++){
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_dam1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam1_h[i].x){
                                                        faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_dam2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam2_h[i].x){
                                                         faulsv = 1; break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_pion1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion1_h[i].x){
                                                        faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_pion2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion2_h[i].x){
                                                         faulsv = 1; break;
                                                }
                                            }
                                            if (faulsv == 0 ){

                                            rect2_dam1_h[p-1].x = Nouvx_damhorizontale(event.motion.x) ;
                                            rect2_dam1_h[p-1].y = Nouvy_damhorizontale(event.motion.y) ;
                                            rect2_dam1_v[p-1].x = NULL;
                                            rect2_dam1_v[p-1].y = NULL;
                                            vh1 = 1 ;  p1=0; tour=tour+1;w1=1; // pour break le suivant

                                            }}}
                                            p=0 ;
                                    }
                                }
                                /////////////////// horizontale
                    if(w1==0){
                       for (i = 0 ; i < 23 ; i++){
                            if (testMousePositiondamh(rect2_dam1_h[i].x  , rect2_dam1_h[i].y  ,event.motion.x ,event.motion.y  )){
                                p1  = i +1 ;
                            }
                        }
                        if (p1 != 0 ){
                                 for(i=0 ; i<23 ; i++){
                                if (lmaklahorizontalehaut( rect2_dam1_h[p1-1].x ,rect2_dam1_h[p1-1].y , rect2_dam2_h[i].x , rect2_dam2_h[i].y )){
                                   for(j=0 ; j<23 ; j++ ){
                                        if( testExistancehorizontalhaut(rect2_dam2_h[i].x , rect2_dam2_h[i].y , rect2_dam1_h[j].x , rect2_dam1_h[j].y)){
                                         l1=0;op= 1;break;
                                      }if(l1==0) break;
                                      if( testExistancehorizontalhaut(rect2_dam2_h[i].x , rect2_dam2_h[i].y , rect2_dam2_h[j].x , rect2_dam2_h[j].y)){
                                         l1=0;op=1;break;
                                      }if(l1==0) break;
                                      if( testExistancehorizontalhaut(rect2_dam2_h[i].x , rect2_dam2_h[i].y  , rect2_pion1_h[j].x , rect2_pion1_h[j].y)){
                                         l1=0;op=1;break;
                                      }if(l1==0) break;
                                      if( testExistancehorizontalhaut(rect2_dam2_h[i].x , rect2_dam2_h[i].y , rect2_pion2_h[j].x , rect2_pion2_h[j].y)){
                                         l1=0;op=1 ;break;
                                      }if(l1==0) break;
                                  }if(l1==0) break;
                                }if(l1==0) break;
                                 if (lmaklahorizontalehaut( rect2_dam1_h[p1-1].x ,rect2_dam1_h[p1-1].y , rect2_pion2_h[i].x , rect2_pion2_h[i].y )){
                                   for(j=0 ; j<23 ; j++ ){
                                        if( testExistancehorizontalhaut(rect2_pion2_h[i].x , rect2_pion2_h[i].y , rect2_dam1_h[j].x , rect2_dam1_h[j].y)){
                                         l1=0;op=1 ;break;
                                      }if(l1==0) break;
                                      if( testExistancehorizontalhaut(rect2_pion2_h[i].x , rect2_pion2_h[i].y, rect2_dam2_h[j].x , rect2_dam2_h[j].y)){
                                         l1=0;op=1; ;break;
                                      }if(l1==0) break;
                                      if( testExistancehorizontalhaut(rect2_pion2_h[i].x , rect2_pion2_h[i].y , rect2_pion1_h[j].x , rect2_pion1_h[j].y)){
                                         l1=0;op=1;break;
                                      }if(l1==0) break;
                                      if( testExistancehorizontalhaut(rect2_pion2_h[i].x , rect2_pion2_h[i].y , rect2_pion2_h[j].x , rect2_pion2_h[j].y)){
                                         l1=0;op=1;break;
                                      }if(l1==0) break;
                                  }if(l1==0) break;
                                }if(l1==0) break;

                                 if (lmaklahorizontalebas( rect2_dam1_h[p1-1].x ,rect2_dam1_h[p1-1].y , rect2_dam2_h[i].x , rect2_dam2_h[i].y )){
                                    for(j=0 ; j<23 ; j++ ){
                                        if( testExistancehorizontalbas(rect2_dam2_h[i].x , rect2_dam2_h[i].y , rect2_dam2_h[j].x , rect2_dam2_h[j].y)){
                                        l1=0 ;op=1 ;break;
                                      }if(l1==0) break;
                                        if( testExistancehorizontalbas(rect2_dam2_h[i].x , rect2_dam2_h[i].y , rect2_dam1_h[j].x , rect2_dam1_h[j].y)){
                                        l1=0 ;op=1 ;break;
                                      }if(l1==0) break;
                                      if( testExistancehorizontalbas(rect2_dam2_h[i].x , rect2_dam2_h[i].y , rect2_pion2_h[j].x , rect2_pion2_h[j].y)){
                                        l1=0 ;op=1 ;break;
                                      }if(l1==0) break;
                                        if( testExistancehorizontalbas(rect2_dam2_h[i].x , rect2_dam2_h[i].y , rect2_pion1_h[j].x , rect2_pion1_h[j].y)){
                                        l1=0 ;op=1 ;break;
                                      }if(l1==0) break;
                                   }if(l1==0) break;
                                }if(l1==0) break;
                                 if (lmaklahorizontalebas( rect2_dam1_h[p1-1].x ,rect2_dam1_h[p1-1].y , rect2_pion2_h[i].x , rect2_pion2_h[i].y )){
                                    for(j=0 ; j<23 ; j++ ){
                                        if( testExistancehorizontalbas( rect2_pion2_h[i].x , rect2_pion2_h[i].y , rect2_dam2_h[j].x , rect2_dam2_h[j].y)){
                                        l1=0 ;op=1 ;break;
                                      }if(l1==0) break;
                                        if( testExistancehorizontalbas( rect2_pion2_h[i].x , rect2_pion2_h[i].y , rect2_dam1_h[j].x , rect2_dam1_h[j].y)){
                                        l1=0 ;op=1 ;break;
                                      }if(l1==0) break;
                                      if( testExistancehorizontalbas( rect2_pion2_h[i].x , rect2_pion2_h[i].y, rect2_pion2_h[j].x , rect2_pion2_h[j].y)){
                                        l1=0 ;op=1 ;break;
                                      }if(l1==0) break;
                                        if( testExistancehorizontalbas( rect2_pion2_h[i].x , rect2_pion2_h[i].y , rect2_pion1_h[j].x , rect2_pion1_h[j].y)){
                                        l1=0 ;op=1;break;
                                      }if(l1==0) break;
                                   }if(l1==0) break;
                                }if(l1==0) break;
                            }
                        }
                        if (l1 != 0 ){
                                for(i=0 ; i<23 ; i++){
                                if (lmaklahorizontalehaut( rect2_dam1_h[p1-1].x ,rect2_dam1_h[p1-1].y , rect2_dam2_h[i].x , rect2_dam2_h[i].y )){
                                    rect2_dam1_h[p1-1].y = rect2_dam2_h[i].y - 68 ;
                                    rect2_dam2_h[i].x = NULL;
                                    rect2_dam2_h[i].y = NULL;tour=tour+1 ;
                                    p1 = 0 ;op=1;break;
                                }}}
                        if (l1 != 0 ){
                                for(i=0 ; i<15 ; i++){
                                if (lmaklahorizontalehaut( rect2_dam1_h[p1-1].x ,rect2_dam1_h[p1-1].y , rect2_pion2_h[i].x , rect2_pion2_h[i].y )){
                                    rect2_dam1_h[p1-1].y = rect2_pion2_h[i].y - 68 ;
                                    rect2_pion2_h[i].x = NULL;
                                    rect2_pion2_h[i].y = NULL;tour=tour+1 ;
                                    p1 = 0 ;op=1;break;
                                }}}
                        if (l1 != 0 ){
                                for(i=0 ; i<23 ; i++){
                                    if (lmaklahorizontalebas( rect2_dam1_h[p1-1].x ,rect2_dam1_h[p1-1].y , rect2_dam2_h[i].x , rect2_dam2_h[i].y )){
                                        rect2_dam1_h[p1-1].y = rect2_dam2_h[i].y + 68 ;
                                        rect2_dam2_h[i].x = NULL;
                                        rect2_dam2_h[i].y = NULL;tour=tour+1 ;
                                        p1 = 0 ;op=1;break;
                                    }}}
                        if (l1 != 0 ){
                        for(i=0 ; i<15 ; i++){
                                    if (lmaklahorizontalebas( rect2_dam1_h[p1-1].x ,rect2_dam1_h[p1-1].y , rect2_pion2_h[i].x , rect2_pion2_h[i].y )){
                                        rect2_dam1_h[p1-1].y = rect2_pion2_h[i].y + 68 ;
                                        rect2_pion2_h[i].x = NULL;
                                        rect2_pion2_h[i].y = NULL;tour=tour+1 ;
                                        p1 = 0 ;op=1;break;
                                    }}}

                        }
                            while ( p1 != 0 ){
                                SDL_WaitEvent(&event);
                                    switch(event.type){
                                    case SDL_QUIT :
                                        quit = 1;
                                         p1=0;
                                         q=1;
                                        break ;

                                    case SDL_MOUSEBUTTONDOWN :
                                        faulsv = 0 ;
                                        if ((event.motion.x  % 68 ) >= 24 && ((event.motion.y-50) % 68) <= 24 && (((event.motion.y  /68) == ((rect2_dam1_h[p1-1].y )/68) )||((event.motion.x )/68) == ((rect2_dam1_h[p1-1].x )/68))) {
                                        for(i=0 ; i < 23 ; i++){
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_dam1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam1_h[i].x){
                                                           faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_dam2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam2_h[i].x){
                                                           faulsv = 1; break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_pion1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion1_h[i].x){
                                                           faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_pion2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion2_h[i].x){
                                                           faulsv = 1; break;
                                                }
                                            }
                                            if ( faulsv != 1 ){
                                                    for ( i = 0 ; i < 23 ; i++ ){
                                                        if( rect2_dam1_h[p1-1].x == rect2_dam1_h[i].x && rect2_dam1_h[p1-1].y == rect2_dam1_h[i].y + 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) == rect2_dam1_h[i].x && Nouvy_damhorizontale(event.motion.y) < rect2_dam1_h[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam1_h[p1-1].x == rect2_dam1_h[i].x && rect2_dam1_h[p1-1].y == rect2_dam1_h[i].y - 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) == rect2_dam1_h[i].x && Nouvy_damhorizontale(event.motion.y) > rect2_dam1_h[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam1_h[p1-1].y == rect2_dam1_h[i].y && rect2_dam1_h[p1-1].x == rect2_dam1_h[i].x + 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) < rect2_dam1_h[i].x && Nouvy_damhorizontale(event.motion.y) == rect2_dam1_h[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam1_h[p1-1].y == rect2_dam1_h[i].y && rect2_dam1_h[p1-1].x == rect2_dam1_h[i].x - 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) > rect2_dam1_h[i].x && Nouvy_damhorizontale(event.motion.y) == rect2_dam1_h[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                    }
                                                    for ( i = 0 ; i < 23 ; i++ ){
                                                        if( rect2_dam1_h[p1-1].x == rect2_pion1_h[i].x && rect2_dam1_h[p1-1].y == rect2_pion1_h[i].y + 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) == rect2_pion1_h[i].x && Nouvy_damhorizontale(event.motion.y) < rect2_pion1_h[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam1_h[p1-1].x == rect2_pion1_h[i].x && rect2_dam1_h[p1-1].y == rect2_pion1_h[i].y - 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) == rect2_pion1_h[i].x && Nouvy_damhorizontale(event.motion.y) > rect2_pion1_h[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam1_h[p1-1].y == rect2_pion1_h[i].y && rect2_dam1_h[p1-1].x == rect2_pion1_h[i].x + 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) < rect2_pion1_h[i].x && Nouvy_damhorizontale(event.motion.y) == rect2_pion1_h[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam1_h[p1-1].y == rect2_pion1_h[i].y && rect2_dam1_h[p1-1].x == rect2_pion1_h[i].x - 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) > rect2_pion1_h[i].x && Nouvy_damhorizontale(event.motion.y) == rect2_pion1_h[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                    }

                                                }
                                                /////
                                                if (faulsv != 1 ){
                                                        if(( (rect2_dam1_h[p1-1].x == rect2_roi1.x) && ( rect2_dam1_h[p1-1].y +24 == rect2_roi1.y )) ||( (rect2_dam1_h[p1-1].x == rect2_roi2.x) && ( rect2_dam1_h[p1-1].y +24 == rect2_roi2.y ))){
                                                            if( Nouvy_damhorizontale(event.motion.y) > rect2_dam1_h[p1-1].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam1_h[p1-1].x ){
                                                                faulsv = 1 ; break ; }
                                                        }
                                                        if(( (rect2_dam1_h[p1-1].x == rect2_roi1.x) && ( rect2_dam1_h[p1-1].y -44 == rect2_roi1.y )) ||( (rect2_dam1_h[p1-1].x == rect2_roi2.x) && ( rect2_dam1_h[p1-1].y -44 == rect2_roi2.y ))){
                                                            if( Nouvy_damhorizontale(event.motion.y) < rect2_dam1_h[p1-1].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam1_h[p1-1].x ){
                                                                faulsv = 1 ; break ; }
                                                        }

                                                     }
                                                /////
                                            if (faulsv == 0 ){
                                                rect2_dam1_h[p1-1].x=Nouvx_damhorizontale(event.motion.x) ;
                                                rect2_dam1_h[p1-1].y=Nouvy_damhorizontale(event.motion.y) ;op=1;;tour=tour+1 ;w1=1;p1=0 ;break;
                                            }

                                        }
                                        if ((event.motion.x  % 68 ) < 24 && ((event.motion.y -50 ) % 68) > 24 ){
                                        if ( testMousePositionHorizonToVertic(rect2_dam1_h[p1-1].x ,rect2_dam1_h[p1-1].y , event.motion.x , event.motion.y)){
                                         for(i=0 ; i < 15 ; i++){
                                                if(Nouvx_damverticale(event.motion.x) == rect2_dam1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam1_v[i].y){
                                                          faulsv = 1;break;
                                                }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_dam2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam2_v[i].y){
                                                            faulsv = 1;break;
                                                }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_pion1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion1_v[i].y){
                                                          faulsv = 1;break;
                                                }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_pion2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion2_v[i].y){
                                                            faulsv = 1;break;
                                                }
                                            }
                                            if (faulsv == 0 ){
                                                    rect2_dam1_v[p1-1].x = Nouvx_damverticale(event.motion.x) ;
                                                    rect2_dam1_v[p1-1].y = Nouvy_damverticale(event.motion.y) ;
                                                    rect2_dam1_h[p1-1].x = NULL;
                                                    rect2_dam1_h[p1-1].y = NULL;
                                                    op=1;tour=tour+1 ;p1=0;w1=1;wi=1;break;
                                            } } }
                                    p1=0;
                                }
                            }
                            ///////pion 1 verticale :
                            if(wi==0){
                            for (i = 0 ; i < 15 ; i++){              /////click sur une pion verticale
                            if (testMousePositiondamv(rect2_pion1_v[i].x  , rect2_pion1_v[i].y  ,event.motion.x ,event.motion.y  )){
                                pi  = i +1 ;break;
                            }
                        }
                        if (pi != 0 ){                            /////test dyal lmakla
                                 for(i=0 ; i<23 ; i++){
                                    if (lmaklaVerticaledroitpion( rect2_pion1_v[pi-1].x ,rect2_pion1_v[pi-1].y , rect2_pion2_v[i].x , rect2_pion2_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticaldroit(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                pi1 = 0 ;li=0;break;
                                            }if(li==0) break ;
                                                if( testExistanceVerticaldroit(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                pi1 = 0 ;li=0;break;
                                            }if(li==0) break ;
                                            if( testExistanceVerticaldroit(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                                pi1 = 0 ;li=0;break;
                                            }if(li==0) break ;
                                            if( testExistanceVerticaldroit(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                                pi1 = 0;li=0;break;
                                            }if(li==0) break ;
                                        }
                                    if (li==0) break;
                                    }if (li==0) break;
                                    if (lmaklaVerticalegauchpion( rect2_pion1_v[pi-1].x ,rect2_pion1_v[pi-1].y , rect2_pion2_v[i].x , rect2_pion2_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticalgauch(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                pi1 = 0;li=0 ;break;
                                            }if (li==0) break;
                                             if( testExistanceVerticalgauch(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                pi1 = 0;li=0 ;break;
                                            }if (li==0) break;
                                            if( testExistanceVerticalgauch(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                                 pi1 = 0;li=0 ;break;
                                            }if (li==0) break;
                                            if( testExistanceVerticalgauch(rect2_pion2_v[i].x , rect2_pion2_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                                 pi1 = 0;li=0 ;break;
                                            }if (li==0) break;
                                        }
                                    if (li==0) break;
                                    }if (li==0) break;
                                  if (lmaklaVerticaledroitpion( rect2_pion1_v[pi-1].x ,rect2_pion1_v[pi-1].y , rect2_dam2_v[i].x , rect2_dam2_v[i].y )){
                                      for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticaldroit(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                pi1 = 0 ;li=0;break;
                                            }if(li==0) break ;
                                                if( testExistanceVerticaldroit(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                pi1 = 0 ;li=0;break;
                                            }if(li==0) break ;
                                            if( testExistanceVerticaldroit(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                                pi1 = 0 ;li=0;break;
                                            }if(li==0) break ;
                                            if( testExistanceVerticaldroit(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                                pi1 = 0 ;li=0;break;
                                            }if(li==0) break ;
                                        }
                                    if (li==0) break;
                                    }if (li==0) break;
                                    if (lmaklaVerticalegauchpion( rect2_pion1_v[pi-1].x ,rect2_pion1_v[pi-1].y , rect2_dam2_v[i].x , rect2_dam2_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticalgauch(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                pi1 = 0;li=0 ;break;
                                            }if (li==0) break;
                                             if( testExistanceVerticalgauch(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                pi1 = 0;li=0 ;break;
                                            }if (li==0) break;
                                            if( testExistanceVerticalgauch(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                                 pi1 = 0;li=0;break;
                                            }if (li==0) break;
                                            if( testExistanceVerticalgauch(rect2_dam2_v[i].x , rect2_dam2_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                                 pi1 = 0;li=0 ;break;
                                            }if (li==0) break;
                                        }if (li==0) break;
                                    }if (li==0) break;
                                    if (li==0) break;
                                 }
                         }
                          if (li != 0 ){                             /////l obligation  dyal lmakla
                              for(i=0 ; i<15 ; i++){
                                 if (lmaklaVerticaledroitpion( rect2_pion1_v[pi-1].x ,rect2_pion1_v[pi-1].y , rect2_pion2_v[i].x , rect2_pion2_v[i].y )){

                                    rect2_pion1_v[pi-1].x = rect2_pion2_v[i].x + 68 ;
                                    rect2_pion2_v[i].x = NULL;
                                    rect2_pion2_v[i].y = NULL;
                                    pi=0; pi1 = 0 ;li=0;tour=tour+1;wi1=1;break;
                                 }
                            }}
                            if (li != 0 ){
                            for(i=0 ; i<23    ; i++){
                                 if (lmaklaVerticaledroitpion( rect2_pion1_v[pi-1].x ,rect2_pion1_v[pi-1].y , rect2_dam2_v[i].x , rect2_dam2_v[i].y )){
                                    rect2_pion1_v[pi-1].x = rect2_dam2_v[i].x + 68 ;
                                    rect2_dam2_v[i].x = NULL;
                                    rect2_dam2_v[i].y = NULL;
                                    pi=0; pi1 = 0 ;li=0;tour=tour+1;wi1=1;break;
                                 }
                            }}
                            if (li != 0 ){
                            for(i=0 ; i<15 ; i++){
                                if (lmaklaVerticalegauchpion( rect2_pion1_v[pi-1].x ,rect2_pion1_v[pi-1].y , rect2_pion2_v[i].x , rect2_pion2_v[i].y )){
                                    rect2_pion1_v[pi-1].x = rect2_pion2_v[i].x  - 68 ;
                                    rect2_pion2_v[i].x = NULL;
                                    rect2_pion2_v[i].y = NULL;
                                    pi=0 , pi1 = 0 ;li=0;tour=tour+1;wi1=1;break;
                                }
                            }}
                            if (li != 0 ){
                                for(i=0 ; i<23 ; i++){
                                 if (lmaklaVerticalegauchpion( rect2_pion1_v[pi-1].x ,rect2_pion1_v[pi-1].y , rect2_dam2_v[i].x , rect2_dam2_v[i].y )){
                                    rect2_pion1_v[pi-1].x = rect2_dam2_v[i].x - 68 ;
                                    rect2_dam2_v[i].x = NULL;
                                    rect2_dam2_v[i].y = NULL;
                                    pi=0; pi1 = 0 ;tour=tour+1;wi1=1;li=0;break;
                                 }
                            }
                          }
                          while ( pi != 0 ){          //// mouvement
                                SDL_WaitEvent(&event);
                                    switch(event.type){
                                    case SDL_QUIT :
                                        tour=tour+1;
                                        q = 1;
                                        quit = 1;
                                         pi=0 ;
                                        break ;
                                    case SDL_MOUSEBUTTONDOWN :
                                        faulsv = 0 ;
                                        if ((event.motion.x  % 68 ) <= 24 && ((event.motion.y-50) % 68) >= 24 && (((event.motion.x/68) == (rect2_pion1_v[pi-1].x/68))||(((event.motion.y-50)/68) == ((rect2_pion1_v[pi-1].y-50)/68)))){
                                                if ( testMousePosiblemove(rect2_pion1_v[pi-1].x ,rect2_pion1_v[pi-1].y , event.motion.x , event.motion.y)){
                                            for(i=0 ; i < 23 ; i++){
                                                if(Nouvx_damverticale(event.motion.x) == rect2_dam1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam1_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_dam2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam2_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_pion1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion1_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_pion2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion2_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                            }
                                            if (faulsv == 0 ){
                                                rect2_pion1_v[pi-1].x=Nouvx_damverticale(event.motion.x) ;
                                                rect2_pion1_v[pi-1].y=Nouvy_damverticale(event.motion.y) ;
                                                pi=0 ;pi1=0;tour=tour+1;wi1=1;
                                           }
                                        }} faulsv = 0;
                                        if ((event.motion.x  % 68 ) > 24 && ((event.motion.y-50) % 68) < 24 ){
                                            if ( testMousePositionvertToHorizP(rect2_pion1_v[pi-1].x ,rect2_pion1_v[pi-1].y , event.motion.x , event.motion.y)){
                                                         for(i=0 ; i < 23 ; i++){
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_dam1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam1_h[i].x){
                                                        faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_dam2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam2_h[i].x){
                                                         faulsv = 1; break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_pion1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion1_h[i].x){
                                                        faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_pion2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion2_h[i].x){
                                                         faulsv = 1; break;
                                                }
                                            }
                                            if (faulsv == 0 ){
                                                if(pi <= 7){
                                                   if(Nouvy_damhorizontale(event.motion.y) - 50 <= 24 && Nouvy_damhorizontale(event.motion.y) - 50 >= 0 ){
                                                        rect2_dam1_h[pi-1+7].x = Nouvx_damhorizontale(event.motion.x) ;
                                                        rect2_dam1_h[pi-1+7].y = Nouvy_damhorizontale(event.motion.y) ;
                                                        rect2_pion1_v[pi-1].x = NULL;
                                                        rect2_pion1_v[pi-1].y = NULL;
                                                    }
                                                    else{
                                                        rect2_pion1_h[pi-1+7].x = Nouvx_damhorizontale(event.motion.x) ;
                                                        rect2_pion1_h[pi-1+7].y = Nouvy_damhorizontale(event.motion.y) ;
                                                        rect2_pion1_v[pi-1].x = NULL;
                                                        rect2_pion1_v[pi-1].y = NULL;
                                                    }
                                                    vhi1 = 1 ;  pi1=0; tour=tour+1;wi1=1; // pour break le suivant
                                                    }

                                                else {
                                                    if(Nouvy_damhorizontale(event.motion.y) - 50 <= 20 && Nouvy_damhorizontale(event.motion.y) - 50 >= 0 ){
                                                        rect2_dam1_h[pi-1+7].x = Nouvx_damhorizontale(event.motion.x) ;
                                                        rect2_dam1_h[pi-1+7].y = Nouvy_damhorizontale(event.motion.y) ;
                                                        rect2_pion1_v[pi-1].x = NULL;
                                                        rect2_pion1_v[pi-1].y = NULL;
                                                    }
                                                    else{
                                                    rect2_pion1_h[pi-1-8].x = Nouvx_damhorizontale(event.motion.x) ;
                                                    rect2_pion1_h[pi-1-8].y = Nouvy_damhorizontale(event.motion.y) ;
                                                    rect2_pion1_v[pi-1].x = NULL;
                                                    rect2_pion1_v[pi-1].y = NULL;
                                                    vhi1 = 1 ;  pi1=0; tour=tour+1;wi1=1; // pour break le suivant
                                                }}
                                            } }}
                                            pi=0 ;
                                    }
                                }
                                ///////////// pion 1 horizontale :
                                if(wi1==0){
                       for (i = 0 ; i < 15 ; i++){
                            if (testMousePositiondamh(rect2_pion1_h[i].x  , rect2_pion1_h[i].y  ,event.motion.x ,event.motion.y  )){
                                pi1  = i +1 ;
                            }
                        }
                        if (pi1 != 0 ){
                                 for(i=0 ; i<23 ; i++){
                                if (lmaklahorizontalehautpion( rect2_pion1_h[pi1-1].x ,rect2_pion1_h[pi1-1].y , rect2_pion2_h[i].x , rect2_pion2_h[i].y )){
                                   for(j=0 ; j<23 ; j++ ){
                                        if( testExistancehorizontalhaut(rect2_pion2_h[i].x , rect2_pion2_h[i].y , rect2_pion1_h[j].x , rect2_pion1_h[j].y)){
                                         li1=0;opi=1 ;break;
                                      }if(li1==0) break;
                                      if( testExistancehorizontalhaut(rect2_pion2_h[i].x , rect2_pion2_h[i].y , rect2_pion2_h[j].x , rect2_pion2_h[j].y)){
                                         li1=0;opi=1 ;break;
                                      }if(li1==0) break;
                                       if( testExistancehorizontalhaut(rect2_pion2_h[i].x , rect2_pion2_h[i].y , rect2_dam1_h[j].x , rect2_dam1_h[j].y)){
                                         li1=0;opi=1 ;break;
                                      }if(li1==0) break;
                                      if( testExistancehorizontalhaut(rect2_pion2_h[i].x , rect2_pion2_h[i].y , rect2_dam2_h[j].x , rect2_dam2_h[j].y)){
                                         li1=0;opi=1 ;break;
                                      }if(li1==0) break;
                                  }if(li1==0) break;
                                }if(li1==0) break;

                                 if (lmaklahorizontalehautpion( rect2_pion1_h[pi1-1].x ,rect2_pion1_h[pi1-1].y , rect2_dam2_h[i].x , rect2_dam2_h[i].y )){
                                   for(j=0 ; j<23 ; j++ ){
                                        if( testExistancehorizontalhaut(rect2_dam2_h[i].x , rect2_dam2_h[i].y , rect2_pion1_h[j].x , rect2_pion1_h[j].y)){
                                         li1=0;opi=1 ;break;
                                      }if(li1==0) break;
                                      if( testExistancehorizontalhaut(rect2_dam2_h[i].x , rect2_dam2_h[i].y , rect2_pion2_h[j].x , rect2_pion2_h[j].y)){
                                         li1=0;opi=1 ;break;
                                      }if(li1==0) break;
                                       if( testExistancehorizontalhaut(rect2_dam2_h[i].x , rect2_dam2_h[i].y , rect2_dam1_h[j].x , rect2_dam1_h[j].y)){
                                         li1=0;opi=1 ;break;
                                      }if(li1==0) break;
                                      if( testExistancehorizontalhaut(rect2_dam2_h[i].x , rect2_dam2_h[i].y , rect2_dam2_h[j].x , rect2_dam2_h[j].y)){
                                         li1=0;opi=1 ;break;
                                      }if(li1==0) break;
                                  }if(li1==0) break;
                                }if(li1==0) break;
                            }
                        }
                        if (li1 != 0 ){
                                for(i=0 ; i<23 ; i++){
                                if (lmaklahorizontalehautpion( rect2_pion1_h[pi1-1].x ,rect2_pion1_h[pi1-1].y , rect2_pion2_h[i].x , rect2_pion2_h[i].y )){
                                    rect2_pion1_h[pi1-1].y = rect2_pion2_h[i].y - 68 ;
                                    rect2_pion2_h[i].x = NULL;
                                    rect2_pion2_h[i].y = NULL;tour=tour+1 ;
                                    pi1 = 0 ;opi=1;li1=0 ;break;
                                }}}
                        if (li1 != 0 ){
                                for(i=0 ; i<23 ; i++){
                                if (lmaklahorizontalehautpion( rect2_pion1_h[pi1-1].x ,rect2_pion1_h[pi1-1].y , rect2_dam2_h[i].x , rect2_dam2_h[i].y )){
                                    rect2_pion1_h[pi1-1].y = rect2_dam2_h[i].y - 68 ;
                                    rect2_dam2_h[i].x = NULL;
                                    rect2_dam2_h[i].y = NULL;tour=tour+1 ;
                                    pi1 = 0 ;opi=1;li1=0 ;break;
                                }
                            }
                        }
                        while ( pi1 != 0 ){
                                SDL_WaitEvent(&event);
                                    switch(event.type){
                                    case SDL_QUIT :
                                        quit = 1;
                                         pi1=0;
                                         q=1;
                                        break ;

                                    case SDL_MOUSEBUTTONDOWN :
                                        faulsv = 0 ;
                                        if ((event.motion.x  % 68 ) >= 24 && ((event.motion.y-50) % 68) <= 24 && ((((event.motion.y -50 ) /68) == ((rect2_pion1_h[pi1-1].y -50 )/68) )||((event.motion.x )/68) == ((rect2_pion1_h[pi1-1].x )/68))) {
                                           if ( testMousePosiblemove(rect2_pion1_h[pi1-1].x ,rect2_pion1_h[pi1-1].y , event.motion.x , event.motion.y)){
                                            for(i=0 ; i < 23 ; i++){
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_dam1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam1_h[i].x){
                                                           faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_dam2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam2_h[i].x){
                                                           faulsv = 1; break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_pion1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion1_h[i].x){
                                                           faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_pion2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion2_h[i].x){
                                                           faulsv = 1; break;
                                                }
                                            }
                                            if (faulsv == 0 ){
                                                    if(Nouvy_damhorizontale(event.motion.y) - 50 <= 20 && Nouvy_damhorizontale(event.motion.y) - 50 >= 0 ){
                                                        rect2_dam1_h[pi1-1+7].x = Nouvx_damhorizontale(event.motion.x) ;
                                                        rect2_dam1_h[pi1-1+7].y = Nouvy_damhorizontale(event.motion.y) ;
                                                        rect2_pion1_h[pi1-1].x = NULL;
                                                        rect2_pion1_h[pi1-1].y = NULL;opi=1;;tour=tour+1 ;wi1=1;pi1=0 ;break;
                                                    }
                                                    else{
                                                        rect2_pion1_h[pi1-1].x=Nouvx_damhorizontale(event.motion.x) ;
                                                        rect2_pion1_h[pi1-1].y=Nouvy_damhorizontale(event.motion.y) ;opi=1;;tour=tour+1 ;wi1=1;pi1=0 ;z=0;break;
                                            }}

                                        }}
                                        if ((event.motion.x  % 68 ) < 24 && ((event.motion.y -50 ) % 68) > 24 ){
                                        if ( testMousePositionHorizonToVerticP(rect2_pion1_h[pi1-1].x ,rect2_pion1_h[pi1-1].y , event.motion.x , event.motion.y)){
                                         for(i=0 ; i < 15 ; i++){
                                                if(Nouvx_damverticale(event.motion.x) == rect2_dam1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam1_v[i].y){
                                                          faulsv = 1;break;
                                                }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_dam2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam2_v[i].y){
                                                            faulsv = 1;break;
                                                }
                                                 if(Nouvx_damverticale(event.motion.x) == rect2_pion1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion1_v[i].y){
                                                          faulsv = 1;break;
                                                }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_pion2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion2_v[i].y){
                                                            faulsv = 1;break;
                                                }
                                            }
                                            if (faulsv == 0 ){
                                                    if(pi1 <= 8){
                                                    rect2_pion1_v[pi1-1+8].x = Nouvx_damverticale(event.motion.x) ;
                                                    rect2_pion1_v[pi1-1+8].y = Nouvy_damverticale(event.motion.y) ;
                                                    rect2_pion1_h[pi1-1].x = NULL;
                                                    rect2_pion1_h[pi1-1].y = NULL;
                                                    opi=1;tour=tour+1 ;pi1=0;wi1=1;wi=1;break;
                                                    }
                                                    else {
                                                        rect2_pion1_v[pi1-1-7].x = Nouvx_damverticale(event.motion.x) ;
                                                        rect2_pion1_v[pi1-1-7].y = Nouvy_damverticale(event.motion.y) ;
                                                        rect2_pion1_h[pi1-1].x = NULL;
                                                        rect2_pion1_h[pi1-1].y = NULL;
                                                        opi=1;tour=tour+1 ;pi1=0;wi1=1;wi=1;break;

                                                    }
                                            } } }
                                    pi1=0;
                                }
                              }
                            }
                          }
                       }
                    }
                        /////////////////////// tour 2
                        ////////roi2
                        if(tour%2 == 0 && op==0 ){
                        if (testMousePositionroi(rect2_roi2.x , rect2_roi2.y , event.motion.x , event.motion.y  )){
                               k = 0 ; a = 0 ; b = 0 ; c = 0 ; d = 0 ;
                            while( k == 0){
                            SDL_WaitEvent(&event);
                                switch(event.type){
                                case SDL_QUIT :
                                    k=1;
                                    q = 1;
                                    quit = 1;
                                    tour = tour+1;
                                    break ;
                                case SDL_MOUSEBUTTONDOWN :
                                    if (testPssibleMouveKingCase(rect2_roi2.x , rect2_roi2.y ,event.motion.x , event.motion.y )){
                                        x2 = rect2_roi2.x ;
                                        y2 = rect2_roi2.y ;
                                        rect2_roi2.x = Nouvx_roi(event.motion.x);
                                        rect2_roi2.y = Nouvy_roi(event.motion.y);tour=tour+1;zw=1;

                                        if (  moinCaseRoyale(rect2_roi2.x , rect2_roi2.y , rect2_roi1.x , rect2_roi1.y)){
                                            rect2_roi2.x = x2 ;  rect2_roi2.y = y2;tour = tour - 1 ;
                                        }
                                        if( Nouvx_roi(event.motion.x) ==  x2 ){

                                                if ( Nouvy_roi(event.motion.y)  ==  y2 - 68 ){
                                                        for(i=0 ; i<23 ; i++){
                                                            if(conditionwinroicasehaut( x2 ,  y2 ,  rect2_dam1_h[i].x , rect2_dam1_h[i].y )) a=1;
                                                            if(conditionwinroicasehaut( x2 ,  y2 ,  rect2_dam2_h[i].x , rect2_dam2_h[i].y )) a=1;
                                                            }
                                                     for(i=0 ; i<15 ; i++){
                                                            if(conditionwinroicasehaut( x2 ,  y2 ,  rect2_pion1_h[i].x , rect2_pion1_h[i].y )) a=1;
                                                            if(conditionwinroicasehaut( x2 ,  y2 ,  rect2_pion2_h[i].x , rect2_pion2_h[i].y )) a=1;
                                                    }if(  a == 1){rect2_roi2.x = x2 ;  rect2_roi2.y = y2;tour = tour - 1 ; }
                                                }
                                                if ( Nouvy_roi(event.motion.y) ==  y2 + 68 ){
                                                        for(i=0 ; i<23 ; i++){
                                                            if(conditionwinroicasebas( x2 ,  y2 ,  rect2_dam1_h[i].x , rect2_dam1_h[i].y )) b=1;
                                                            if(conditionwinroicasebas( x2 ,  y2 ,  rect2_dam2_h[i].x , rect2_dam2_h[i].y )) b=1;

                                                            }
                                                     for(i=0 ; i<15 ; i++){
                                                            if(conditionwinroicasebas( x2 ,  y2 ,  rect2_pion1_h[i].x , rect2_pion1_h[i].y )) b=1;
                                                            if(conditionwinroicasebas( x2 ,  y2 ,  rect2_pion2_h[i].x , rect2_pion2_h[i].y )) b=1;
                                                            if(  b == 1){rect2_roi2.x = x2 ;  rect2_roi2.y = y2;tour = tour - 1 ;}
                                                    }if(  b == 1){rect2_roi2.x = x2 ;  rect2_roi2.y = y2;tour = tour - 1 ;}
                                                }
                                                }
                                        if( Nouvy_roi(event.motion.y) ==  y2 ){
                                                if ( Nouvx_roi(event.motion.x) ==  x2 - 68 ){
                                                        for(i=0 ; i<23 ; i++){
                                                            if(conditionwinroicasegauch( x2 ,  y2 ,  rect2_dam1_v[i].x , rect2_dam1_v[i].y )) c=1;
                                                            if(conditionwinroicasegauch( x2 ,  y2 ,  rect2_dam2_v[i].x , rect2_dam2_v[i].y )) c=1;
                                                            }
                                                     for(i=0 ; i<15 ; i++){
                                                            if(conditionwinroicasegauch( x2 ,  y2 ,  rect2_pion1_v[i].x , rect2_pion1_v[i].y )) c=1;
                                                            if(conditionwinroicasegauch( x2 ,  y2 ,  rect2_pion2_v[i].x , rect2_pion2_v[i].y )) c=1;
                                                    } if( c == 1){ rect2_roi2.x = x2 ;  rect2_roi2.y = y2;tour = tour - 1 ;}
                                                }
                                                if ( Nouvx_roi(event.motion.x) ==  x2 + 68 ){
                                                        for(i=0 ; i<23 ; i++){
                                                            if(conditionwinroicasedroit( x2 ,  y2 ,  rect2_dam1_v[i].x , rect2_dam1_v[i].y )) d=1;
                                                            if(conditionwinroicasedroit( x2 ,  y2 ,  rect2_dam2_v[i].x , rect2_dam2_v[i].y )) d=1;
                                                            }
                                                     for(i=0 ; i<15 ; i++){
                                                            if(conditionwinroicasedroit( x2 ,  y2 ,  rect2_pion1_v[i].x , rect2_pion1_v[i].y )) d=1;
                                                            if(conditionwinroicasedroit( x2 ,  y2 ,  rect2_pion2_v[i].x , rect2_pion2_v[i].y )) d=1;
                                                    } if( d == 1){ rect2_roi2.x = x2 ;  rect2_roi2.y = y2;tour = tour - 1 ;}
                                                }
                                                }
                                    }k=1;
                                }
                            }
                          }
                       ///////////// dam 2 :
                       ////////verticale :
                       if(zw==0){

                        for (i = 0 ; i < 8 ; i++){
                            if (testMousePositiondamv(rect2_dam2_v[i].x  ,rect2_dam2_v[i].y  ,event.motion.x ,event.motion.y  )){
                                    r  = i +1;
                            }
                        }
                        if (r != 0 ){                            /////test dyal lmakla
                                 for(i=0 ; i<23 ; i++){
                                    if (lmaklaVerticaledroit( rect2_dam2_v[r-1].x ,rect2_dam2_v[r-1].y , rect2_dam1_v[i].x , rect2_dam1_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticaldroit(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                            r1=0 ; h=0;h1=0 ;r=0;break;
                                            }if(h==0) break ;
                                            if( testExistanceVerticaldroit(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                              r1=0 ;h1=0 ;h=0 ;r=0;break;
                                            }if(h==0)break ;
                                            if( testExistanceVerticaldroit(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                            r1=0 ; h=0;h1=0 ;r=0;break;
                                            }if(h==0) break ;
                                            if( testExistanceVerticaldroit(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                              r1=0 ;h1=0 ;h=0 ;r=0;break;
                                            }if(h==0)break ;
                                        }if(h==0)break ;
                                    if (h==0) break;
                                    }if(h==0)break ;
                                     if (lmaklaVerticaledroit( rect2_dam2_v[r-1].x ,rect2_dam2_v[r-1].y , rect2_pion1_v[i].x , rect2_pion1_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticaldroit(rect2_pion1_v[i].x , rect2_pion1_v[i].y  , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                            r1=0 ; h=0;h1=0 ;r=0;break;
                                            }if(h==0) break ;
                                            if( testExistanceVerticaldroit(rect2_pion1_v[i].x , rect2_pion1_v[i].y  , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                              r1=0 ;h1=0 ;h=0 ;r=0;break;
                                            }if(h==0)break ;
                                            if( testExistanceVerticaldroit(rect2_pion1_v[i].x , rect2_pion1_v[i].y  , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                            r1=0 ; h=0;h1=0 ;r=0;break;
                                            }if(h==0) break ;
                                            if( testExistanceVerticaldroit(rect2_pion1_v[i].x , rect2_pion1_v[i].y  , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                              r1=0 ;h1=0 ;h=0 ;r=0;break;
                                            }if(h==0)break ;
                                        }if(h==0)break ;
                                    if (h==0) break;
                                    }if(h==0)break ;
                                    if (lmaklaVerticalegauch( rect2_dam2_v[r-1].x ,rect2_dam2_v[r-1].y , rect2_dam1_v[i].x , rect2_dam1_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticalgauch(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                           r1=0 ; h=0;h1=0 ; r=0 ;break;
                                            }if(h==0) break ;
                                            if( testExistanceVerticalgauch(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                 r1=0 ;h=0 ; r=0 ;h1=0 ;break;
                                            }if(h==0) break ;
                                            if( testExistanceVerticalgauch(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                           r1=0 ; h=0;h1=0 ; r=0 ;break;
                                            }if(h==0) break ;
                                            if( testExistanceVerticalgauch(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                 r1=0 ;h=0 ; r=0 ;h1=0 ;break;
                                            }if(h==0) break ;
                                        }if(h==0) break ;
                                    }if(h==0) break ;
                                    if(h==0) break ;
                                    if (lmaklaVerticalegauch( rect2_dam2_v[r-1].x ,rect2_dam2_v[r-1].y , rect2_pion1_v[i].x , rect2_pion1_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticalgauch(rect2_pion1_v[i].x , rect2_pion1_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                           r1=0 ; h=0;h1=0 ; r=0 ;break;
                                            }if(h==0) break ;
                                            if( testExistanceVerticalgauch(rect2_pion1_v[i].x , rect2_pion1_v[i].y, rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                 r1=0 ;h=0 ; r=0 ;h1=0 ;break;
                                            }if(h==0) break ;
                                            if( testExistanceVerticalgauch(rect2_pion1_v[i].x , rect2_pion1_v[i].y, rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                           r1=0 ; h=0;h1=0 ; r=0 ;break;
                                            }if(h==0) break ;
                                            if( testExistanceVerticalgauch(rect2_pion1_v[i].x , rect2_pion1_v[i].y, rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                 r1=0 ;h=0 ; r=0 ;h1=0 ;break;
                                            }if(h==0) break ;
                                        }if(h==0) break ;
                                    }if(h==0) break ;
                                }
                         }
                          if (h != 0 ){                             /////l obligation  dyal lmakla
                              for(i=0 ; i<23 ; i++){
                                 if (lmaklaVerticaledroit( rect2_dam2_v[r-1].x ,rect2_dam2_v[r-1].y , rect2_dam1_v[i].x , rect2_dam1_v[i].y )){
                                    rect2_dam2_v[r-1].x = rect2_dam1_v[i].x + 68 ;
                                    rect2_dam1_v[i].x = NULL;
                                    rect2_dam1_v[i].y = NULL;tour=tour+1;
                                  r1=0 ;vh2=1;h1=0 ;r=0 ;yi=1;break;
                                 }}}
                        if (h != 0 ){                             /////l obligation  dyal lmakla
                              for(i=0 ; i<15 ; i++){
                                 if (lmaklaVerticaledroit( rect2_dam2_v[r-1].x ,rect2_dam2_v[r-1].y , rect2_pion1_v[i].x , rect2_pion1_v[i].y )){
                                    rect2_dam2_v[r-1].x = rect2_pion1_v[i].x + 68 ;
                                    rect2_pion1_v[i].x = NULL;
                                    rect2_pion1_v[i].y = NULL;tour=tour+1;
                                  r1=0 ;vh2=1;h1=0 ;r=0 ;yi=1;break;
                                 }}}
                         if (h != 0 ){
                            for(i=0 ; i<23 ; i++){
                                if (lmaklaVerticalegauch( rect2_dam2_v[r-1].x ,rect2_dam2_v[r-1].y , rect2_dam1_v[i].x , rect2_dam1_v[i].y )){
                                    rect2_dam2_v[r-1].x = rect2_dam1_v[i].x  - 68 ;
                                    rect2_dam1_v[i].x = NULL;
                                    rect2_dam1_v[i].y = NULL;tour=tour+1;
                                   r1=0 ;vh2=1;h1=0 ; r=0 ;yi=1;break;
                                }}}
                        if (h != 0 ){
                            for(i=0 ; i<15 ; i++){
                                if (lmaklaVerticalegauch( rect2_dam2_v[r-1].x ,rect2_dam2_v[r-1].y , rect2_pion1_v[i].x , rect2_pion1_v[i].y )){
                                    rect2_dam2_v[r-1].x = rect2_pion1_v[i].x  - 68 ;
                                    rect2_pion1_v[i].x = NULL;
                                    rect2_pion1_v[i].y = NULL;tour=tour+1;
                                   r1=0 ;vh2=1;h1=0 ; r=0 ;yi=1;break;
                                }}}


                            while ( r != 0 ){                       ////mouvement
                                SDL_WaitEvent(&event);
                                switch(event.type){
                                case SDL_QUIT :
                                        q=1;
                                        tour=tour+1;
                                        quit = 1;
                                        r=0;
                                        break ;
                                case SDL_MOUSEBUTTONDOWN :
                                    faulsv = 0;
                                       if ((event.motion.x  % 68 ) <= 24 && ((event.motion.y-50) % 68) >= 24 && (((event.motion.x/68) == (rect2_dam2_v[r-1].x/68))||((event.motion.y/68) == (rect2_dam2_v[r-1].y/68)))){
                                            for(i=0 ; i < 23 ; i++){
                                                if(Nouvx_damverticale(event.motion.x) == rect2_dam1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam1_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_dam2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam2_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_pion1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion1_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_pion2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion2_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                            }
                                            if ( faulsv != 1 ){
                                                    for ( i = 0 ; i < 23 ; i++ ){
                                                        if( rect2_dam2_v[r-1].x == rect2_dam2_v[i].x && rect2_dam2_v[r-1].y == rect2_dam2_v[i].y + 68){
                                                            if( Nouvx_damverticale(event.motion.x) == rect2_dam2_v[i].x && Nouvy_damverticale(event.motion.y) < rect2_dam2_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam2_v[r-1].x == rect2_dam2_v[i].x && rect2_dam2_v[r-1].y == rect2_dam2_v[i].y - 68){
                                                            if( Nouvx_damverticale(event.motion.x) == rect2_dam2_v[i].x && Nouvy_damverticale(event.motion.y) > rect2_dam2_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam2_v[r-1].y == rect2_dam2_v[i].y && rect2_dam2_v[r-1].x == rect2_dam2_v[i].x + 68){
                                                            if( Nouvx_damverticale(event.motion.x) < rect2_dam2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam2_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam2_v[r-1].y == rect2_dam2_v[i].y && rect2_dam2_v[r-1].x == rect2_dam2_v[i].x - 68){
                                                            if( Nouvx_damverticale(event.motion.x) > rect2_dam2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam2_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                    }
                                                    for ( i = 0 ; i < 23 ; i++ ){
                                                        if( rect2_dam2_v[r-1].x == rect2_pion2_v[i].x && rect2_dam2_v[r-1].y == rect2_pion2_v[i].y + 68){
                                                            if( Nouvx_damverticale(event.motion.x) == rect2_pion2_v[i].x && Nouvy_damverticale(event.motion.y) < rect2_pion2_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam2_v[r-1].x == rect2_pion2_v[i].x && rect2_dam2_v[r-1].y == rect2_pion2_v[i].y - 68){
                                                            if( Nouvx_damverticale(event.motion.x) == rect2_pion2_v[i].x && Nouvy_damverticale(event.motion.y) > rect2_pion2_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam2_v[r-1].y == rect2_pion2_v[i].y && rect2_dam2_v[r-1].x == rect2_pion2_v[i].x + 68){
                                                            if( Nouvx_damverticale(event.motion.x) < rect2_pion2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion2_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam2_v[r-1].y == rect2_pion2_v[i].y && rect2_dam2_v[r-1].x == rect2_pion2_v[i].x - 68){
                                                            if( Nouvx_damverticale(event.motion.x) > rect2_pion2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion2_v[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                    }
                                                }
                                                if (faulsv != 1 ){

                                                            for (i = 0  ; i <= (7 - rect2_dam2_v[r-1].x /68) ; i++){
                                                        if(( (rect2_dam2_v[r-1].y == rect2_roi1.y) && ( rect2_dam2_v[r-1].x +(24 + 68*i) == rect2_roi1.x )) ||( (rect2_dam2_v[r-1].y == rect2_roi2.y) && ( rect2_dam2_v[r-1].x +(24 + 68*i) == rect2_roi2.x ))){
                                                            if( Nouvx_damverticale(event.motion.x) > rect2_roi1.x && Nouvy_damverticale(event.motion.y) == rect2_roi1.y || Nouvx_damverticale(event.motion.x) > rect2_roi2.x && Nouvy_damverticale(event.motion.y) == rect2_roi2.y ){
                                                                faulsv = 1 ; break ; }
                                                        }}}
                                                    if (faulsv != 1 ){
                                                        for (i = 0 ; i <= ( rect2_dam1_v[r-1].x /68 + 1 ) ; i++){
                                                          if( ((rect2_dam2_v[r-1].y == rect2_roi1.y) && ( rect2_dam2_v[r-1].x - (44 + 68*i)== rect2_roi1.x )) || ((rect2_dam2_v[r-1].y == rect2_roi2.y) && ( rect2_dam2_v[r-1].x - (44 + 68*i) == rect2_roi2.x ))){
                                                          if(( Nouvx_damverticale(event.motion.x) < rect2_roi1.x && Nouvy_damverticale(event.motion.y) == rect2_roi1.y )|| (Nouvx_damverticale(event.motion.x) < rect2_roi2.x && Nouvy_damverticale(event.motion.y) == rect2_roi2.y)){
                                                               faulsv = 1 ; break ; }
                                                        }
                                                      }
                                                     }
                                            if (faulsv == 0 ){
                                                rect2_dam2_v[r-1].x=Nouvx_damverticale(event.motion.x) ;
                                                rect2_dam2_v[r-1].y=Nouvy_damverticale(event.motion.y) ;tour=tour+1;vh2=1;
                                                r=0;r1=0;yi=1;
                                           }}faulsv=0;
                                        if ((event.motion.x  % 68 ) > 24 && ((event.motion.y-50) % 68) < 24 ){
                                            if ( testMousePositionvertToHoriz(rect2_dam2_v[r-1].x ,rect2_dam2_v[r-1].y , event.motion.x , event.motion.y)){
                                                for(i=0 ; i < 23 ; i++){
                                                    if(Nouvy_damhorizontale(event.motion.y) == rect2_dam1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam1_h[i].x){
                                                        faulsv = 1;break;
                                                    }
                                                    if(Nouvy_damhorizontale(event.motion.y) == rect2_dam2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam2_h[i].x){
                                                         faulsv = 1; break;
                                                    }
                                                    if(Nouvy_damhorizontale(event.motion.y) == rect2_pion1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion1_h[i].x){
                                                        faulsv = 1;break;
                                                    }
                                                    if(Nouvy_damhorizontale(event.motion.y) == rect2_pion2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion2_h[i].x){
                                                         faulsv = 1; break;
                                                    }
                                                }
                                                if (faulsv == 0 ){
                                                    rect2_dam2_h[r-1].x = Nouvx_damhorizontale(event.motion.x) ;
                                                    rect2_dam2_h[r-1].y = Nouvy_damhorizontale(event.motion.y) ;
                                                    rect2_dam2_v[r-1].x = NULL;
                                                    rect2_dam2_v[r-1].y = NULL;tour=tour+1;
                                                    vh2 = 1 ;yi=1;
                                                }
                                            }
                                        }
                                        r=0; break ;
                                }
                            }
                        //////////// dam 2 horizontale
                        if (vh2 == 0 ){
                        for (i = 0 ; i < 23 ; i++){
                         if (testMousePositiondamh(rect2_dam2_h[i].x  , rect2_dam2_h[i].y  ,event.motion.x ,event.motion.y  )){
                                r1  = i +1 ;
                            }
                        }
                        if (r1 != 0 ){
                                 for(i=0 ; i<23 ; i++){
                                if (lmaklahorizontalehaut( rect2_dam2_h[r1-1].x ,rect2_dam2_h[r1-1].y , rect2_dam1_h[i].x , rect2_dam1_h[i].y )){
                                   for(j=0 ; j<23 ; j++ ){
                                        if( testExistancehorizontalhaut(rect2_dam1_h[i].x , rect2_dam1_h[i].y , rect2_dam2_h[j].x , rect2_dam2_h[j].y)){
                                        r1=0  ; h1=0;break;
                                      }if(h1==0) break;
                                 if( testExistancehorizontalhaut(rect2_dam1_h[i].x , rect2_dam1_h[i].y , rect2_dam1_h[j].x , rect2_dam1_h[j].y)){
                                      r1=0  ; h1=0;break;
                                      }if(h1==0) break;
                                      if( testExistancehorizontalhaut(rect2_dam1_h[i].x , rect2_dam1_h[i].y , rect2_pion2_h[j].x , rect2_pion2_h[j].y)){
                                        r1=0  ; h1=0;break;
                                      }if(h1==0) break;
                                 if( testExistancehorizontalhaut(rect2_dam1_h[i].x , rect2_dam1_h[i].y , rect2_pion1_h[j].x , rect2_pion1_h[j].y)){
                                      r1=0  ; h1=0;break;
                                      }if(h1==0) break;
                                  }if(h1==0) break;
                                }if(h1==0) break;
                                if (lmaklahorizontalehaut( rect2_dam2_h[r1-1].x ,rect2_dam2_h[r1-1].y , rect2_pion1_h[i].x , rect2_pion1_h[i].y )){
                                   for(j=0 ; j<23 ; j++ ){
                                        if( testExistancehorizontalhaut(rect2_pion1_h[i].x , rect2_pion1_h[i].y  , rect2_dam2_h[j].x , rect2_dam2_h[j].y)){
                                        r1=0  ; h1=0;break;
                                      }if(h1==0) break;
                                 if( testExistancehorizontalhaut(rect2_pion1_h[i].x , rect2_pion1_h[i].y  , rect2_dam1_h[j].x , rect2_dam1_h[j].y)){
                                      r1=0  ; h1=0;break;
                                      }if(h1==0) break;
                                      if( testExistancehorizontalhaut(rect2_pion1_h[i].x , rect2_pion1_h[i].y , rect2_pion2_h[j].x , rect2_pion2_h[j].y)){
                                        r1=0  ; h1=0;break;
                                      }if(h1==0) break;
                                 if( testExistancehorizontalhaut(rect2_pion1_h[i].x , rect2_pion1_h[i].y  , rect2_pion1_h[j].x , rect2_pion1_h[j].y)){
                                      r1=0  ; h1=0;break;
                                      }if(h1==0) break;
                                  }if(h1==0) break;
                                }if(h1==0) break;
                                 if (lmaklahorizontalebas( rect2_dam2_h[r1-1].x ,rect2_dam2_h[r1-1].y , rect2_dam1_h[i].x , rect2_dam1_h[i].y )){
                                    for(j=0 ; j<23 ; j++ ){
                                        if( testExistancehorizontalbas(rect2_dam1_h[i].x , rect2_dam1_h[i].y , rect2_dam2_h[j].x , rect2_dam2_h[j].y)){
                                        r1=0 ; h1=0 ;break;
                                      }if(h1==0) break;
                                      if( testExistancehorizontalbas(rect2_dam1_h[i].x , rect2_dam1_h[i].y , rect2_dam1_h[j].x , rect2_dam1_h[j].y)){
                                        r1=0 ; h1=0 ;break;
                                      }if(h1==0) break;
                                      if( testExistancehorizontalbas(rect2_dam1_h[i].x , rect2_dam1_h[i].y , rect2_pion2_h[j].x , rect2_pion2_h[j].y)){
                                        r1=0 ; h1=0 ;break;
                                      }if(h1==0) break;
                                      if( testExistancehorizontalbas(rect2_dam1_h[i].x , rect2_dam1_h[i].y , rect2_pion1_h[j].x , rect2_pion1_h[j].y)){
                                        r1=0 ; h1=0 ;break;
                                      }if(h1==0) break;
                                   }if(h1==0) break;
                                }if(h1==0) break;
                                 if (lmaklahorizontalebas( rect2_dam2_h[r1-1].x ,rect2_dam2_h[r1-1].y , rect2_pion1_h[i].x , rect2_pion1_h[i].y )){
                                    for(j=0 ; j<23 ; j++ ){
                                        if( testExistancehorizontalbas(rect2_pion1_h[i].x , rect2_pion1_h[i].y, rect2_dam2_h[j].x , rect2_dam2_h[j].y)){
                                        r1=0 ; h1=0 ;break;
                                      }if(h1==0) break;
                                      if( testExistancehorizontalbas(rect2_pion1_h[i].x , rect2_pion1_h[i].y , rect2_dam1_h[j].x , rect2_dam1_h[j].y)){
                                        r1=0 ; h1=0 ;break;
                                      }if(h1==0) break;
                                      if( testExistancehorizontalbas(rect2_pion1_h[i].x , rect2_pion1_h[i].y , rect2_pion2_h[j].x , rect2_pion2_h[j].y)){
                                        r1=0 ; h1=0 ;break;
                                      }if(h1==0) break;
                                      if( testExistancehorizontalbas(rect2_pion1_h[i].x , rect2_pion1_h[i].y , rect2_pion1_h[j].x , rect2_pion1_h[j].y)){
                                        r1=0 ; h1=0 ;break;
                                      }if(h1==0) break;
                                   }if(h1==0) break;
                                }if(h1==0) break;
                            }if(h1==0) break;
                        }
                        if (h1 != 0 ){
                                for(i=0 ; i<23 ; i++){
                                    if (lmaklahorizontalehaut( rect2_dam2_h[r1-1].x ,rect2_dam2_h[r1-1].y , rect2_dam1_h[i].x , rect2_dam1_h[i].y )){
                                        rect2_dam2_h[r1-1].y = rect2_dam1_h[i].y - 68 ;
                                        rect2_dam1_h[i].x = NULL;
                                        rect2_dam1_h[i].y = NULL;tour=tour+1;
                                        r1=0 ; h1=0 ;yi=1;
                                    }}}
                         if (h1 != 0 ){
                                for(i=0 ; i<15 ; i++){
                                    if (lmaklahorizontalehaut( rect2_dam2_h[r1-1].x ,rect2_dam2_h[r1-1].y , rect2_pion1_h[i].x , rect2_pion1_h[i].y )){
                                        rect2_dam2_h[r1-1].y = rect2_pion1_h[i].y - 68 ;
                                        rect2_pion1_h[i].x = NULL;
                                        rect2_pion1_h[i].y = NULL;tour=tour+1;
                                        r1=0 ; h1=0 ;yi=1;
                                    }}}
                        if (h1 != 0 ){
                                for(i=0 ; i<23 ; i++){
                                    if (lmaklahorizontalebas( rect2_dam2_h[r1-1].x ,rect2_dam2_h[r1-1].y , rect2_dam1_h[i].x , rect2_dam1_h[i].y )){
                                        rect2_dam2_h[r1-1].y = rect2_dam1_h[i].y + 68 ;
                                        rect2_dam1_h[i].x = NULL;
                                        rect2_dam1_h[i].y = NULL;tour=tour+1;
                                        r1=0 ; h1=0 ;yi=1;
                                    }}}
                         if (h1 != 0 ){
                                for(i=0 ; i<15 ; i++){
                                    if (lmaklahorizontalebas( rect2_dam2_h[r1-1].x ,rect2_dam2_h[r1-1].y , rect2_pion1_h[i].x , rect2_pion1_h[i].y )){
                                        rect2_dam2_h[r1-1].y = rect2_pion1_h[i].y + 68 ;
                                        rect2_pion1_h[i].x = NULL;
                                        rect2_pion1_h[i].y = NULL;tour=tour+1;
                                        r1=0 ; h1=0 ;yi=1;
                                    }}}
                        }
                            while ( r1 != 0 ){
                                SDL_WaitEvent(&event);
                                    switch(event.type){
                                    case SDL_QUIT :
                                        q=0;
                                        tour=tour+1;
                                        quit = 1;
                                         r1=0;
                                        break ;

                                    case SDL_MOUSEBUTTONDOWN :
                                        faulsv = 0 ;
                                        if ((event.motion.x  % 68 ) >= 24 && ((event.motion.y-50) % 68) <= 24 && (((event.motion.y  /68) == ((rect2_dam2_h[r1-1].y )/68) )||((event.motion.x )/68) == ((rect2_dam2_h[r1-1].x )/68))) {
                                        for(i=0 ; i < 23 ; i++){
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_dam1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam1_h[i].x){
                                                           faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_dam2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam2_h[i].x){
                                                           faulsv = 1; break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_pion1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion1_h[i].x){
                                                           faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_pion2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion2_h[i].x){
                                                           faulsv = 1; break;
                                                }
                                                //////
                                                if ( faulsv != 1 ){
                                                    for ( i = 0 ; i < 23 ; i++ ){
                                                        if( rect2_dam2_h[r1-1].x == rect2_dam2_h[i].x && rect2_dam2_h[r1-1].y == rect2_dam2_h[i].y + 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) == rect2_dam2_h[i].x && Nouvy_damhorizontale(event.motion.y) < rect2_dam2_h[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if(rect2_dam2_h[r1-1].x == rect2_dam2_h[i].x && rect2_dam2_h[r1-1].y == rect2_dam2_h[i].y - 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) == rect2_dam2_h[i].x && Nouvy_damhorizontale(event.motion.y) > rect2_dam2_h[i].y    ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam2_h[r1-1].y == rect2_dam2_h[i].y && rect2_dam2_h[r1-1].x == rect2_dam2_h[i].x + 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) < rect2_dam2_h[i].x && Nouvy_damhorizontale(event.motion.y) == rect2_dam2_h[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam2_h[r1-1].y == rect2_dam2_h[i].y && rect2_dam2_h[r1-1].x == rect2_dam2_h[i].x - 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) > rect2_dam2_h[i].x && Nouvy_damhorizontale(event.motion.y) == rect2_dam2_h[i].y    ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                    }
                                                    for ( i = 0 ; i < 23 ; i++ ){
                                                        if( rect2_dam2_h[r1-1].x == rect2_pion2_h[i].x && rect2_dam2_h[r1-1].y == rect2_pion2_h[i].y + 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) == rect2_pion2_h[i].x && Nouvy_damhorizontale(event.motion.y) < rect2_pion2_h[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam2_h[r1-1].x == rect2_pion2_h[i].x && rect2_dam2_h[r1-1].y == rect2_pion2_h[i].y - 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) == rect2_pion2_h[i].x && Nouvy_damhorizontale(event.motion.y) > rect2_pion2_h[i].y    ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam2_h[r1-1].y == rect2_pion2_h[i].y && rect2_dam2_h[r1-1].x == rect2_pion2_h[i].x + 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) < rect2_pion2_h[i].x && Nouvy_damhorizontale(event.motion.y) == rect2_pion2_h[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                        if( rect2_dam2_h[r1-1].y == rect2_pion2_h[i].y && rect2_dam2_h[r1-1].x == rect2_pion2_h[i].x  - 68){
                                                            if( Nouvx_damhorizontale(event.motion.x) > rect2_pion2_h[i].x && Nouvy_damhorizontale(event.motion.y) == rect2_pion2_h[i].y   ){
                                                            faulsv = 1 ; break ; }
                                                        }
                                                    }

                                                }
                                                //////
                                            }
                                            if (faulsv == 0 ){
                                            rect2_dam2_h[r1-1].x=Nouvx_damhorizontale(event.motion.x) ;
                                            rect2_dam2_h[r1-1].y=Nouvy_damhorizontale(event.motion.y) ;tour=tour+1;yi=1;
                                        }}faulsv=0 ;
                                        if ((event.motion.x  % 68 ) < 24 && ((event.motion.y - 50 ) % 68) > 24 ){
                                            if ( testMousePositionHorizonToVertic(rect2_dam2_h[r1-1].x ,rect2_dam2_h[r1-1].y , event.motion.x , event.motion.y)){
                                              for(i=0 ; i < 23 ; i++){
                                                if(Nouvx_damverticale(event.motion.x) == rect2_dam1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam1_v[i].y){
                                                          faulsv = 1;break;
                                                }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_dam2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam2_v[i].y){
                                                            faulsv = 1;break;
                                                }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_pion1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion1_v[i].y){
                                                          faulsv = 1;break;
                                                }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_pion2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion2_v[i].y){
                                                            faulsv = 1;break;
                                                }
                                            }
                                                if (faulsv == 0 ){
                                                rect2_dam2_v[r1-1].x = Nouvx_damverticale(event.motion.x) ;
                                                rect2_dam2_v[r1-1].y = Nouvy_damverticale(event.motion.y) ;
                                                rect2_dam2_h[r1-1].x = NULL;
                                                rect2_dam2_h[r1-1].y = NULL;tour=tour+1;ri=1;yi=1;
                                                }
                                            }
                                        }
                                        r1=0;
                                    }
                                }
                            }
                            ////////pions 2 :
                            if(yi==0){
                            for (i = 0 ; i < 15 ; i++){              /////click sur une pion verticale
                            if (testMousePositiondamv(rect2_pion2_v[i].x  , rect2_pion2_v[i].y  ,event.motion.x ,event.motion.y  )){
                                ri  = i +1 ;break;
                            }
                        }
                        if (ri != 0 ){                            /////test dyal lmakla
                                 for(i=0 ; i<23 ; i++){
                                    if (lmaklaVerticaledroitpion( rect2_pion2_v[ri-1].x ,rect2_pion2_v[ri-1].y , rect2_pion1_v[i].x , rect2_pion1_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticaldroit(rect2_pion1_v[i].x , rect2_pion1_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                                ri1 = 0 ;hi=0;break;
                                            }if(hi==0) break ;
                                            if( testExistanceVerticaldroit(rect2_pion1_v[i].x , rect2_pion1_v[i].y , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                ri1 = 0 ;hi=0;break;
                                            }if(hi==0) break ;
                                             if( testExistanceVerticaldroit(rect2_pion1_v[i].x , rect2_pion1_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                                ri1 = 0 ;hi=0;break;
                                            }if(hi==0) break ;
                                            if( testExistanceVerticaldroit(rect2_pion1_v[i].x , rect2_pion1_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                ri1 = 0 ;hi=0;break;
                                            }if(hi==0) break ;
                                        }if(hi==0) break ;
                                    if (hi==0) break;
                                    }if(hi==0) break ;
                                    if (lmaklaVerticaledroitpion( rect2_pion2_v[ri-1].x ,rect2_pion2_v[ri-1].y , rect2_dam1_v[i].x , rect2_dam1_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticaldroit(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                                ri1 = 0 ;hi=0;break;
                                            }if(hi==0) break ;
                                            if( testExistanceVerticaldroit(rect2_dam1_v[i].x , rect2_dam1_v[i].y, rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                ri1 = 0;hi=0;break;
                                            }if(hi==0) break ;
                                             if( testExistanceVerticaldroit(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                                ri=0;hi=0;break;
                                            }if(hi==0) break ;
                                            if( testExistanceVerticaldroit(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                ri1 = 0 ;hi=0;break;
                                            }if(hi==0) break ;
                                        }if(hi==0) break ;
                                    if (hi==0) break;
                                    }if(hi==0) break ;
                                    if (lmaklaVerticalegauchpion( rect2_pion2_v[ri-1].x ,rect2_pion2_v[ri-1].y , rect2_pion1_v[i].x , rect2_pion1_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticalgauch(rect2_pion1_v[i].x , rect2_pion1_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                                ri1 = 0;hi=0 ;break;
                                            }if (hi==0) break;
                                            if( testExistanceVerticalgauch(rect2_pion1_v[i].x , rect2_pion1_v[i].y , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                 ri1 = 0;hi=0 ;break;
                                            }if (hi==0) break;
                                            if( testExistanceVerticalgauch(rect2_pion1_v[i].x , rect2_pion1_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                                ri1 = 0;hi=0 ;break;
                                            }if (hi==0) break;
                                            if( testExistanceVerticalgauch(rect2_pion1_v[i].x , rect2_pion1_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                 ri1 = 0;hi=0 ;break;
                                            }if (hi==0) break;
                                        }if (hi==0) break;
                                        if (lmaklaVerticalegauchpion( rect2_pion2_v[ri-1].x ,rect2_pion2_v[ri-1].y , rect2_dam1_v[i].x , rect2_dam1_v[i].y )){
                                        for(j=0 ; j<23 ; j++ ){
                                            if( testExistanceVerticalgauch(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_pion2_v[j].x , rect2_pion2_v[j].y)){
                                                ri1 = 0;hi=0 ;break;
                                            }if (hi==0) break;
                                            if( testExistanceVerticalgauch(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_pion1_v[j].x , rect2_pion1_v[j].y)){
                                                 ri1 = 0;hi=0 ;break;
                                            }if (hi==0) break;
                                            if( testExistanceVerticalgauch(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_dam2_v[j].x , rect2_dam2_v[j].y)){
                                                ri1 = 0;hi=0 ;break;
                                            }if (hi==0) break;
                                            if( testExistanceVerticalgauch(rect2_dam1_v[i].x , rect2_dam1_v[i].y , rect2_dam1_v[j].x , rect2_dam1_v[j].y)){
                                                 ri1 = 0;hi=0;break;
                                            }if (hi==0) break;
                                        }if (hi==0) break;
                                    }if (hi==0) break;
                                }if (hi==0) break;
                         }
                          if (hi != 0 ){                             /////l obligation  dyal lmakla
                              for(i=0 ; i<15 ; i++){
                                 if (lmaklaVerticaledroitpion( rect2_pion2_v[ri-1].x ,rect2_pion2_v[ri-1].y , rect2_pion1_v[i].x , rect2_pion1_v[i].y )){
                                    rect2_pion2_v[ri-1].x = rect2_pion1_v[i].x + 68 ;
                                    rect2_pion1_v[i].x = NULL;
                                    rect2_pion1_v[i].y = NULL;
                                    ri=0; ri1 = 0 ;tour=tour+1;break;yi1=1;
                                 }}}
                        if (hi != 0 ){                             /////l obligation  dyal lmakla
                              for(i=0 ; i<23 ; i++){
                                 if (lmaklaVerticaledroitpion( rect2_pion2_v[ri-1].x ,rect2_pion2_v[ri-1].y , rect2_dam1_v[i].x , rect2_dam1_v[i].y )){
                                    rect2_pion2_v[ri-1].x = rect2_dam1_v[i].x + 68 ;
                                    rect2_dam1_v[i].x = NULL;
                                    rect2_dam1_v[i].y = NULL;
                                    ri=0; ri1 = 0 ;tour=tour+1;break;yi1=1;
                                 }}}
                       if (hi != 0 ){
                        for(i=0 ; i<15 ; i++){
                                if (lmaklaVerticalegauchpion( rect2_pion2_v[ri-1].x ,rect2_pion2_v[ri-1].y , rect2_pion1_v[i].x , rect2_pion1_v[i].y )){
                                    rect2_pion2_v[ri-1].x = rect2_pion1_v[i].x  - 68 ;
                                    rect2_pion1_v[i].x = NULL;
                                    rect2_pion1_v[i].y = NULL;
                                    ri=0 , ri1 = 0 ;tour=tour+1;break;yi1=1;
                                }}}
                        if (hi != 0 ){
                        for(i=0 ; i<23 ; i++){
                                if (lmaklaVerticalegauchpion( rect2_pion2_v[ri-1].x ,rect2_pion2_v[ri-1].y , rect2_dam1_v[i].x , rect2_dam1_v[i].y )){
                                    rect2_pion2_v[ri-1].x = rect2_dam1_v[i].x  - 68 ;
                                    rect2_dam1_v[i].x = NULL;
                                    rect2_dam1_v[i].y = NULL;
                                    ri=0 , ri1 = 0 ;tour=tour+1;break;yi1=1;
                                }}}

                          }
                          while ( ri != 0 ){          //// mouvement
                                SDL_WaitEvent(&event);
                                    switch(event.type){
                                    case SDL_QUIT :
                                        tour=tour+1;
                                        q = 1;
                                        quit = 1;
                                         ri=0 ;
                                        break ;
                                    case SDL_MOUSEBUTTONDOWN :
                                        faulsv = 0 ;
                                        if ((event.motion.x  % 68 ) <= 24 && ((event.motion.y-50) % 68) >= 24 && (((event.motion.x/68) == (rect2_pion2_v[ri-1].x/68))||(((event.motion.y-50)/68) == ((rect2_pion2_v[ri-1].y-50)/68)))){
                                                if ( testMousePosiblemove2(rect2_pion2_v[ri-1].x ,rect2_pion2_v[ri-1].y , event.motion.x , event.motion.y)){
                                            for(i=0 ; i < 23 ; i++){
                                                if(Nouvx_damverticale(event.motion.x) == rect2_pion2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion2_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_pion1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion1_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                                 if(Nouvx_damverticale(event.motion.x) == rect2_dam2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam2_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                                if(Nouvx_damverticale(event.motion.x) == rect2_dam1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam1_v[i].y){
                                                    faulsv = 1;break;
                                                    }
                                            }
                                            if (faulsv == 0 ){
                                                rect2_pion2_v[ri-1].x=Nouvx_damverticale(event.motion.x) ;
                                                rect2_pion2_v[ri-1].y=Nouvy_damverticale(event.motion.y) ;
                                                ri=0 ;ri1=0;tour=tour+1;yi1=1;
                                           }
                                        }} faulsv = 0;
                                        if ((event.motion.x  % 68 ) > 24 && ((event.motion.y-50) % 68) < 24 ){
                                            if ( testMousePositionvertToHorizPh(rect2_pion2_v[ri-1].x ,rect2_pion2_v[ri-1].y , event.motion.x , event.motion.y)){
                                                 for(i=0 ; i < 23 ; i++){
                                                if(Nouvy_damhorizontale(event.motion.y)  == rect2_pion2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion2_h[i].x){
                                                        faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y)  == rect2_pion1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion1_h[i].x){
                                                         faulsv = 1; break;
                                                }
                                                 if(Nouvy_damhorizontale(event.motion.y) == rect2_dam2_h[i].y && Nouvx_damhorizontale(event.motion.x)  == rect2_dam2_h[i].x){
                                                        faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y)  == rect2_dam1_h[i].y && Nouvx_damhorizontale(event.motion.x)  == rect2_dam1_h[i].x){
                                                         faulsv = 1; break;
                                                }
                                                 }
                                            if (faulsv == 0 ){
                                                if(ri <= 7){
                                                    if(Nouvy_damhorizontale(event.motion.y) - 50 <= 500 && Nouvy_damhorizontale(event.motion.y) - 50 >= 476 ){
                                                        rect2_dam2_h[ri-1+7].x = Nouvx_damhorizontale(event.motion.x) ;
                                                        rect2_dam2_h[ri-1+7].y = Nouvy_damhorizontale(event.motion.y) ;
                                                        rect2_pion2_v[ri-1].x = NULL;
                                                        rect2_pion2_v[ri-1].y = NULL;
                                                        vhi21 = 1 ;  ri1=0; tour=tour+1;yi1=1;
                                                    }
                                                    else{
                                                    rect2_pion2_h[ri-1+7].x = Nouvx_damhorizontale(event.motion.x) ;
                                                    rect2_pion2_h[ri-1+7].y = Nouvy_damhorizontale(event.motion.y) ;
                                                    rect2_pion2_v[ri-1].x = NULL;
                                                    rect2_pion2_v[ri-1].y = NULL;
                                                    vhi21 = 1 ;  ri1=0; tour=tour+1;yi1=1; // pour break le suivant
                                                    }}
                                                else {
                                                    rect2_pion2_h[ri-1-8].x = Nouvx_damhorizontale(event.motion.x) ;
                                                    rect2_pion2_h[ri-1-8].y = Nouvy_damhorizontale(event.motion.y) ;
                                                    rect2_pion2_v[ri-1].x = NULL;
                                                    rect2_pion2_v[ri-1].y = NULL;
                                                    vhi21 = 1 ;  ri1=0; tour=tour+1;yi1=1; // pour break le suivant
                                                }
                                            } }
                                            ri=0 ;
                                    }
                                }}
                                ///////////// pion 2 horizontale :
                                if(yi1==0){
                       for (i = 0 ; i < 15 ; i++){
                            if (testMousePositiondamh(rect2_pion2_h[i].x  , rect2_pion2_h[i].y  ,event.motion.x ,event.motion.y  )){
                                ri1  = i +1 ;
                            }
                        }
                        if (ri1 != 0 ){
                                 for(i=0 ; i<23 ; i++){
                                 if (lmaklahorizontalebaspion( rect2_pion2_h[ri1-1].x ,rect2_pion2_h[ri1-1].y , rect2_pion1_h[i].x , rect2_pion1_h[i].y )){
                                    for(j=0 ; j<23 ; j++ ){
                                        if( testExistancehorizontalbas(rect2_pion1_h[i].x , rect2_pion1_h[i].y , rect2_pion2_h[j].x , rect2_pion2_h[j].y)){
                                        hi1=0 ;opi2=1 ;break;
                                      }if(li1==0) break;
                                        if( testExistancehorizontalbas(rect2_pion1_h[i].x , rect2_pion1_h[i].y , rect2_pion1_h[j].x , rect2_pion1_h[j].y)){
                                        hi1=0 ;opi2=1 ;break;
                                      }if(hi1==0) break;
                                      if( testExistancehorizontalbas(rect2_pion1_h[i].x , rect2_pion1_h[i].y , rect2_dam2_h[j].x , rect2_dam2_h[j].y)){
                                        hi1=0 ;opi2=1;break;
                                      }if(li1==0) break;
                                        if( testExistancehorizontalbas(rect2_pion1_h[i].x , rect2_pion1_h[i].y , rect2_dam1_h[j].x , rect2_dam1_h[j].y)){
                                        hi1=0 ;opi2=1 ;break;
                                      }if(hi1==0) break;
                                   }if(hi1==0) break;
                                }if(hi1==0) break;
                                if (lmaklahorizontalebaspion( rect2_pion2_h[ri1-1].x ,rect2_pion2_h[ri1-1].y , rect2_dam1_h[i].x , rect2_dam1_h[i].y )){
                                    for(j=0 ; j<23 ; j++ ){
                                        if( testExistancehorizontalbas(rect2_dam1_h[i].x , rect2_dam1_h[i].y , rect2_pion2_h[j].x , rect2_pion2_h[j].y)){
                                        hi1=0 ;opi2=1 ;break;
                                      }if(li1==0) break;
                                        if( testExistancehorizontalbas(rect2_dam1_h[i].x , rect2_dam1_h[i].y , rect2_pion1_h[j].x , rect2_pion1_h[j].y)){
                                        hi1=0 ;opi2=1 ;break;
                                      }if(hi1==0) break;
                                      if( testExistancehorizontalbas(rect2_dam1_h[i].x , rect2_dam1_h[i].y , rect2_dam2_h[j].x , rect2_dam2_h[j].y)){
                                        hi1=0 ;opi2=1;break;
                                      }if(li1==0) break;
                                        if( testExistancehorizontalbas(rect2_dam1_h[i].x , rect2_dam1_h[i].y , rect2_dam1_h[j].x , rect2_dam1_h[j].y)){
                                        hi1=0 ;opi2=1;break;
                                      }if(hi1==0) break;
                                   }if(hi1==0) break;
                                }if(hi1==0) break;
                            }
                        if (hi1 != 0 ){
                                for(i=0 ; i<15 ; i++){
                                    if (lmaklahorizontalebaspion( rect2_pion2_h[ri1-1].x ,rect2_pion2_h[ri1-1].y , rect2_pion1_h[i].x , rect2_pion1_h[i].y )){
                                        rect2_pion2_h[ri1-1].y = rect2_pion1_h[i].y + 68 ;
                                        rect2_pion1_h[i].x = NULL;
                                        rect2_pion1_h[i].y = NULL;tour=tour+1 ;
                                        ri1 = 0 ;opi2=1;break;
                                    }}}
                        if (hi1 != 0 ){
                                for(i=0 ; i<23 ; i++){
                                    if (lmaklahorizontalebaspion( rect2_pion2_h[ri1-1].x ,rect2_pion2_h[ri1-1].y , rect2_dam1_h[i].x , rect2_dam1_h[i].y )){
                                        rect2_pion2_h[ri1-1].y = rect2_dam1_h[i].y + 68 ;
                                        rect2_dam1_h[i].x = NULL;
                                        rect2_dam1_h[i].y = NULL;tour=tour+1 ;
                                        ri1 = 0 ;opi2=1;break;
                                    }}}

                        }
                        while ( ri1 != 0 ){
                                SDL_WaitEvent(&event);
                                    switch(event.type){
                                    case SDL_QUIT :
                                        quit = 1;
                                         ri1=0;
                                         q=1;
                                        break ;

                                    case SDL_MOUSEBUTTONDOWN :
                                        faulsv = 0 ;
                                        if ((event.motion.x  % 68 ) >= 24 && ((event.motion.y-50) % 68) <= 24 && ((((event.motion.y -50 ) /68) == ((rect2_pion2_h[ri1-1].y -50 )/68) )||((event.motion.x )/68) == ((rect2_pion2_h[ri1-1].x )/68))) {
                                           if ( testMousePosiblemove2(rect2_pion2_h[ri1-1].x ,rect2_pion2_h[ri1-1].y , event.motion.x , event.motion.y)){
                                            for(i=0 ; i < 23 ; i++){
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_pion2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion2_h[i].x){
                                                           faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_pion1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_pion1_h[i].x){
                                                           faulsv = 1; break;
                                                }
                                                 if(Nouvy_damhorizontale(event.motion.y) == rect2_dam2_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam2_h[i].x){
                                                           faulsv = 1;break;
                                                }
                                                if(Nouvy_damhorizontale(event.motion.y) == rect2_dam1_h[i].y && Nouvx_damhorizontale(event.motion.x) == rect2_dam1_h[i].x){
                                                           faulsv = 1; break;
                                                }
                                            }
                                            if (faulsv == 0 ){
                                                     if(Nouvy_damhorizontale(event.motion.y) - 50 <= 500 && Nouvy_damhorizontale(event.motion.y) - 50 >= 476 ){
                                                        rect2_dam2_h[ri1-1+7].x = Nouvx_damhorizontale(event.motion.x) ;
                                                        rect2_dam2_h[ri1-1+7].y = Nouvy_damhorizontale(event.motion.y) ;
                                                        rect2_pion2_h[ri1-1].x = NULL;
                                                        rect2_pion2_h[ri1-1].y = NULL;
                                                        opi2=1;tour=tour+1 ;yi1=1;ri1=0 ;break;
                                                    }
                                                    else{
                                                        rect2_pion2_h[ri1-1].x=Nouvx_damhorizontale(event.motion.x) ;
                                                        rect2_pion2_h[ri1-1].y=Nouvy_damhorizontale(event.motion.y) ;
                                                        opi2=1;tour=tour+1 ;yi1=1;ri1=0 ;break;
                                            }}

                                        }}
                                            if ((event.motion.x  % 68 ) < 24 && ((event.motion.y -50 ) % 68) > 24 ){
                                            if ( testMousePositionHorizonToVerticPh(rect2_pion2_h[ri1-1].x ,rect2_pion2_h[ri1-1].y , event.motion.x , event.motion.y)){
                                                for(i=0 ; i < 23 ; i++){
                                                    if(Nouvx_damverticale(event.motion.x) == rect2_pion2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion2_v[i].y){
                                                          faulsv = 1;break;
                                                }
                                                    if(Nouvx_damverticale(event.motion.x) == rect2_pion1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_pion1_v[i].y){
                                                            faulsv = 1;break;
                                                }
                                                 if(Nouvx_damverticale(event.motion.x) == rect2_dam2_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam2_v[i].y){
                                                          faulsv = 1;break;
                                                }
                                                    if(Nouvx_damverticale(event.motion.x) == rect2_dam1_v[i].x && Nouvy_damverticale(event.motion.y) == rect2_dam1_v[i].y){
                                                            faulsv = 1;break;
                                                }
                                            }
                                            if (faulsv == 0 ){
                                                    if(ri1 <= 8){
                                                    rect2_pion2_v[ri1-1+8].x = Nouvx_damverticale(event.motion.x) ;
                                                    rect2_pion2_v[ri1-1+8].y = Nouvy_damverticale(event.motion.y) ;
                                                    rect2_pion2_h[ri1-1].x = NULL;
                                                    rect2_pion2_h[ri1-1].y = NULL;
                                                    opi2=1;tour=tour+1 ;ri1=0;yi1=1;yi=1;break;
                                                    }
                                                    else {
                                                        rect2_pion2_v[ri1-1-7].x = Nouvx_damverticale(event.motion.x) ;
                                                        rect2_pion2_v[ri1-1-7].y = Nouvy_damverticale(event.motion.y) ;
                                                        rect2_pion2_h[ri1-1].x = NULL;
                                                        rect2_pion2_h[ri1-1].y = NULL;
                                                        opi=1;tour=tour+1 ;ri1=0;yi1=1;yi=1;break;

                                                    }
                                            } } }
                                    ri1=0;
                                    }
                                }

                            }
                        }   }
                    }
                     /////// codition de win joueur 1 :
                    for(i=0 ; i<23 ; i++){
                            if(conditionwinroicasehaut( rect2_roi2.x ,  rect2_roi2.y ,  rect2_dam1_h[i].x , rect2_dam1_h[i].y )) a1=1;
                            if(conditionwinroicasehaut( rect2_roi2.x ,  rect2_roi2.y ,  rect2_dam2_h[i].x , rect2_dam2_h[i].y )) a2=1;
                            if(conditionwinroicasebas ( rect2_roi2.x ,  rect2_roi2.y ,  rect2_dam1_h[i].x , rect2_dam1_h[i].y )) b1=1;
                            if(conditionwinroicasebas ( rect2_roi2.x ,  rect2_roi2.y ,  rect2_dam2_h[i].x , rect2_dam2_h[i].y )) b2=1;
                    }
                     for(i=0 ; i<23 ; i++){
                            if(conditionwinroicasehaut( rect2_roi2.x ,  rect2_roi2.y ,  rect2_pion1_h[i].x , rect2_pion1_h[i].y )) a1=1;
                            if(conditionwinroicasehaut( rect2_roi2.x ,  rect2_roi2.y ,  rect2_pion2_h[i].x , rect2_pion2_h[i].y )) a2=1;
                            if(conditionwinroicasebas ( rect2_roi2.x ,  rect2_roi2.y ,  rect2_pion1_h[i].x , rect2_pion1_h[i].y )) b1=1;
                            if(conditionwinroicasebas ( rect2_roi2.x ,  rect2_roi2.y ,  rect2_pion2_h[i].x , rect2_pion2_h[i].y )) b2=1;
                     }
                     if ((a1 == 1 ||a2 == 1) && (b1 == 1 || b2 == 1)){
                         for(i=0 ; i<23 ; i++){
                            if(conditionwinroicasedroit( rect2_roi2.x ,  rect2_roi2.y ,  rect2_dam1_v[i].x , rect2_dam1_v[i].y )) c1=1;
                            if(conditionwinroicasedroit( rect2_roi2.x ,  rect2_roi2.y ,  rect2_dam2_v[i].x , rect2_dam2_v[i].y )) c2=1;
                            if(conditionwinroicasegauch( rect2_roi2.x ,  rect2_roi2.y ,  rect2_dam1_v[i].x , rect2_dam1_v[i].y )) d1=1;
                            if(conditionwinroicasegauch( rect2_roi2.x ,  rect2_roi2.y ,  rect2_dam2_v[i].x , rect2_dam2_v[i].y )) d2=1;
                    }
                        for(i=0 ; i<23 ; i++){
                             if(conditionwinroicasedroit( rect2_roi2.x ,  rect2_roi2.y ,   rect2_pion1_v[i].x , rect2_pion1_v[i].y )) c1=1;
                             if(conditionwinroicasedroit( rect2_roi2.x ,  rect2_roi2.y ,   rect2_pion2_v[i].x , rect2_pion2_v[i].y )) c2=1;
                             if(conditionwinroicasegauch( rect2_roi2.x ,  rect2_roi2.y ,   rect2_pion1_v[i].x , rect2_pion1_v[i].y )) d1=1;
                             if(conditionwinroicasegauch( rect2_roi2.x ,  rect2_roi2.y ,   rect2_pion2_v[i].x , rect2_pion2_v[i].y )) d2=1;
                       }
                       if ( (a1 == 1 || a2 == 1) && (b1 == 1 ||b2 == 1) && (c1 == 1 ||c2 == 1) && (d1 == 1 ||d2 == 1)) win1 = 1 ;
                       if ( (a2 == 1 ) && (b2 == 1 ) && (c2 == 1 ) && (d2 == 1 )) win1 = 0 ;
                     }

                      /////// codition de win joueur 2 :
                    for(i=0 ; i<23 ; i++){
                            if(conditionwinroicasehaut( rect2_roi1.x ,  rect2_roi1.y ,  rect2_dam1_h[i].x , rect2_dam1_h[i].y )) a3=1;
                            if(conditionwinroicasehaut( rect2_roi1.x ,  rect2_roi1.y ,  rect2_dam2_h[i].x , rect2_dam2_h[i].y )) a4=1;
                            if(conditionwinroicasebas ( rect2_roi1.x ,  rect2_roi1.y ,  rect2_dam1_h[i].x , rect2_dam1_h[i].y )) b3=1;
                            if(conditionwinroicasebas ( rect2_roi1.x ,  rect2_roi1.y ,  rect2_dam2_h[i].x , rect2_dam2_h[i].y )) b4=1;
                    }
                     for(i=0 ; i<23 ; i++){
                            if(conditionwinroicasehaut( rect2_roi1.x ,  rect2_roi1.y ,  rect2_pion1_h[i].x , rect2_pion1_h[i].y )) a3=1;
                            if(conditionwinroicasehaut( rect2_roi1.x ,  rect2_roi1.y ,  rect2_pion2_h[i].x , rect2_pion2_h[i].y )) a4=1;
                            if(conditionwinroicasebas ( rect2_roi1.x ,  rect2_roi1.y ,  rect2_pion1_h[i].x , rect2_pion1_h[i].y )) b3=1;
                            if(conditionwinroicasebas ( rect2_roi1.x ,  rect2_roi1.y ,  rect2_pion2_h[i].x , rect2_pion2_h[i].y )) b4=1;
                     }
                     if ((a3 == 1 ||a4 == 1) && (b3 == 1 || b4 == 1)){
                         for(i=0 ; i<23 ; i++){
                            if(conditionwinroicasedroit( rect2_roi1.x ,  rect2_roi1.y ,  rect2_dam1_v[i].x , rect2_dam1_v[i].y )) c3=1;
                            if(conditionwinroicasedroit( rect2_roi1.x ,  rect2_roi1.y ,  rect2_dam2_v[i].x , rect2_dam2_v[i].y )) c4=1;
                            if(conditionwinroicasegauch( rect2_roi1.x ,  rect2_roi1.y ,  rect2_dam1_v[i].x , rect2_dam1_v[i].y )) d3=1;
                            if(conditionwinroicasegauch( rect2_roi1.x ,  rect2_roi1.y ,  rect2_dam2_v[i].x , rect2_dam2_v[i].y )) d4=1;
                    }
                        for(i=0 ; i<23 ; i++){
                             if(conditionwinroicasedroit( rect2_roi1.x ,  rect2_roi1.y ,  rect2_pion1_v[i].x , rect2_pion1_v[i].y )) c3=1;
                             if(conditionwinroicasedroit( rect2_roi1.x ,  rect2_roi1.y ,  rect2_pion2_v[i].x , rect2_pion2_v[i].y )) c4=1;
                             if(conditionwinroicasegauch( rect2_roi1.x ,  rect2_roi1.y ,  rect2_pion1_v[i].x , rect2_pion1_v[i].y )) d3=1;
                             if(conditionwinroicasegauch( rect2_roi1.x ,  rect2_roi1.y ,  rect2_pion2_v[i].x , rect2_pion2_v[i].y )) d4=1;
                       }
                       if ( (a3 == 1 ||a4 == 1) && (b3 == 1 ||b4 == 1) && (c3 == 1 ||c4 == 1) && (d3 == 1 ||d4 == 1)) win2 = 1 ;
                       if ( (a3 == 1 ) && (b3 == 1 ) && (c3 == 1 ) && (d3 == 1 )) win2 = 0 ;
                     }


                    SDL_RenderClear(rend);
                    if(tour%2 == 1 ){
                    SDL_RenderCopy(rend, Tex_tour1, NULL , &rect_tour1);}
                    if(tour%2 == 0 ){
                    SDL_RenderCopy(rend, Tex_tour2, NULL , &rect_tour2);}
                    SDL_RenderCopy(rend, Tex_tab, NULL , &rect_tab);
                    SDL_RenderCopy(rend, Tex_roi1, NULL , &rect2_roi1);
                    SDL_RenderCopy(rend, Tex_roi2, NULL, &rect2_roi2);
                    for(i=0 ; i<23 ; i++){
                        if (rect2_dam1_v[i].x != 0 && rect2_dam1_v[i].y != 0 ){
                            SDL_RenderCopy(rend, Tex_dam1_v[i], NULL, &rect2_dam1_v[i]);
                        }
                    }
                    for(i=0 ; i<23 ; i++){
                        if (rect2_dam1_h[i].x != 0 && rect2_dam1_h[i].y != 0 ){
                            SDL_RenderCopy(rend, Tex_dam1_h[i], NULL, &rect2_dam1_h[i]);
                        }
                    }
                    for(i=0 ; i<15 ; i++){
                        if (rect2_pion1_v[i].x != 0 && rect2_pion1_v[i].y != 0 ){
                            SDL_RenderCopy(rend, Tex_pion1_v[i], NULL, &rect2_pion1_v[i]);
                        }
                    }
                     for(i=0 ; i<15 ; i++){
                        if (rect2_pion1_h[i].x != 0 && rect2_pion1_h[i].y != 0 ){
                            SDL_RenderCopy(rend, Tex_pion1_h[i], NULL, &rect2_pion1_h[i]);
                        }
                    }
                    for(i=0 ; i<23 ; i++){
                        if (rect2_dam2_v[i].x != 0 && rect2_dam2_v[i].y != 0 ){
                            SDL_RenderCopy(rend, Tex_dam2_v[i], NULL, &rect2_dam2_v[i]);
                        }
                    }
                    for(i=0 ; i<23 ; i++){
                        if (rect2_dam2_h[i].x != 0 && rect2_dam2_h[i].y != 0 ){
                            SDL_RenderCopy(rend, Tex_dam2_h[i], NULL, &rect2_dam2_h[i]);
                        }
                    }
                    for(i=0 ; i<15 ; i++){
                        if (rect2_pion2_v[i].x != 0 && rect2_pion2_v[i].y != 0 ){
                            SDL_RenderCopy(rend, Tex_pion2_v[i], NULL, &rect2_pion2_v[i]);
                        }
                    }
                     for(i=0 ; i<15 ; i++){
                        if (rect2_pion2_h[i].x != 0 && rect2_pion2_h[i].y != 0 ){
                            SDL_RenderCopy(rend, Tex_pion2_h[i], NULL, &rect2_pion2_h[i]);
                        }
                    }

                    SDL_RenderPresent(rend);
                    if( win1 == 1){

                        printf("win1");
                        SDL_Delay(500);
                        SDL_RenderClear(rend);
                        SDL_RenderCopy(rend, Tex_win1, NULL , &rect_win1 );
                        SDL_RenderPresent(rend);
                         Mix_FreeChunk(jump);
                        Mix_PlayChannel(-1 , jump1 , 0 );
                        SDL_Delay(10000);
                        q=1 ;
                        quit = 1 ;
                     }
                    if( win2 == 1 ){

                        printf("win2");
                        SDL_Delay(500);
                        SDL_RenderClear(rend);
                        SDL_RenderCopy(rend, Tex_win2, NULL , &rect_win2);
                        SDL_RenderPresent(rend);
                         Mix_FreeChunk(jump);
                        Mix_PlayChannel(-1 , jump1 , 0 );
                        SDL_Delay(10000);
                        q=1 ;
                        quit = 1 ;
                     }

                }
            }
        }
    SDL_SetRenderDrawColor(rend, 20, 24, 50, 205);
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, Tex , 0, &rect);
    SDL_RenderPresent(rend);
    Mix_PlayChannel(-1 , jump , 0 );

    }
    Mix_FreeChunk(jump);
    Mix_CloseAudio();
    SDL_Quit();
    return EXIT_SUCCESS ;
}
