#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void putPixel(pixel px)
{
        u8 ptr = (IMAGE_WIDTH*px.p.y + px.p.x)*4;
        FBptr[ptr] = px.c.r;
        FBptr[ptr+1] = px.c.g;
        FBptr[ptr+2] = px.c.b;
        FBptr[ptr+3] = px.c.a;
           
}

/*
void randomPixels(){
    pixel x = {{std::rand() % IMAGE_WIDTH, std::rand() % IMAGE_HEIGHT}, {std::rand() % 256, std::rand() % 256,std::rand() % 256}};
    putPixel(x);
} 
*/


void drawLine(pixel start, pixel end){
    /* desempacotando o pixel */
    s8 x0 = start.p.x, y0 = start.p.y; 
    s8 x1 = end.p.x, y1 = end.p.y;
    /* dx e dy */
    s8 dx =  abs(x1-x0); 
    s8 dy = -abs(y1-y0);
    /* incremento/decremento de x e y */
    s8 ix = x0<x1 ? 1 : -1;
    s8 iy = y0<y1 ? 1 : -1; 
    s8 err = dx+dy;

    /* interpolacao de cor */

    f8 var = sqrt(pow(dx,2) + pow(dy,2));        
    f8 r0 = start.c.r, g0 = start.c.g, b0 = start.c.b;
    f8 mod_r = ((end.c.r - start.c.r) / var);
    f8 mod_g = ((end.c.g - start.c.g) / var);
    f8 mod_b = ((end.c.b - start.c.b) / var);

    /* loop principal */

    while(true){ 
        color cx = {round(r0 += mod_r), round(g0 += mod_g), round(b0 += mod_b), 255};
        pixel px = {{x0, y0}, cx};
        putPixel(px);
        if (x0==x1 && y0==y1) break;
        s8 er2 = 2*err;
        if (er2 >= dy) { err += dy; x0 += ix; } 
        if (er2 <= dx) { err += dx; y0 += iy; } 
    }
}

/*

void randomLines(){
    pixel x = {{std::rand() % IMAGE_WIDTH, std::rand() % IMAGE_HEIGHT}, {std::rand() % 256, std::rand() % 256,std::rand() % 256}};
    pixel y = {{std::rand() % IMAGE_WIDTH, std::rand() % IMAGE_HEIGHT}, {std::rand() % 256, std::rand() % 256,std::rand() % 256}};
    drawLine(x,y);

}*/

void drawTriangle(pixel a, pixel b, pixel c){
    drawLine(a,b);
    drawLine(b,c);
    drawLine(c,a);
}

#endif // _MYGL_H_

