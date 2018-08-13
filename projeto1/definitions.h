#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#define IMAGE_WIDTH  512 // número de colunas da imagem.
#define IMAGE_HEIGHT 512 // número de linhas da imagem.
#include <cmath>

unsigned char * FBptr;

typedef unsigned char u1;
typedef unsigned int u8;
typedef signed int s8;
typedef float f8;

typedef struct{u1 r,g,b,a;}color;
typedef struct{u8 x,y;}pos;
typedef struct{pos p; color c;}pixel;

color RED = {255,0,0,255};
color GREEN = {0,255,0,255};
color BLUE = {0,0,255,255};
color WHITE = {255,255,255,255};
color BLACK = {0,0,0,255};
color LIME = {0,255,0,255};
color YELLOW = {255,255,255};
color CYAN = {0,255,255,255};
color MAGENTA = {255,0,255,255};
color SILVER = {192,192,192,255};
color GRAY ={128,128,128,255};
color MAROON = {128,0,0,255};
color OLIVE = {128,128,0,255};
color LIGHTGREEN = {0,128,0,255};
color PURPLE = {128,0,128,255};
color TEAL = {0,128,128,255};
color NAVY = {0,0,128,255};


#endif // _DEFINITIONS_H_

