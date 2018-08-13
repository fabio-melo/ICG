## Desenhando linhas e figuras geométricas no Computador: Computação Gráfica na Prática!

Este artigo irá documentar uma das atividades executadas na disciplina "Introdução á Computação Gráfica", Ministrada pelo professor Christan Azambuja Pagot


## Parte 1: Setup.
Para podermos rodar o código de forma satisfatória no Windows 10, precisamos ativar a funcionalidade do Windows Subsystem for Linux, e baixar uma distribuição compatível, como o [Ubuntu 18.10](https://www.microsoft.com/store/productId/9N9TNGVNDL3Q), disponível gratuitamente na loja da microsoft.

Antes de compilar o framework usando o make, precisamos instalar algumas bibliotecas:

```sh
sudo apt install libglu1-mesa-dev freeglut3-dev
```
E também ferramenta [VcxSrv](https://sourceforge.net/projects/vcxsrv/) para podermos abrir um display X11 no sistema de janelas do Windows.

Sem mais delongas, vamos ao desenvolvimento!

## Parte II: Desenhando na Tela
Para este projeto, utilizamos o framework desenvolvido para simular o acesso direto ao Frame Buffer do monitor.


Para podermos pintar um pixel na tela, devemos seguir esses passos:
* Neste framework, cada Pixel possui 4 bytes, sendo cada um deles responsável por uma caracteristica de cor (RGBA), indicados por posições no array **FBptr[]**
* Precisamos calcular o offset de cada pixel que precisamos pintar, utilizamos a seguinte fórmula:
<img src="https://latex.codecogs.com/svg.latex?(x&plus;y*4)*4" title="(x+y*4)*4" />
(onde x e y são as coordenadas horizontais e verticais da tela, respectivamente. )

Para simplificar a representação dessas informações em código, criamos estas estruturas:

```c++
typedef unsigned short int u2; // para simplificar a escrita
typedef struct{u2 r,g,b,a;}color; //cor
typedef struct{u2 x,y;}pos; // posição (x,y)
typedef struct{pos p; color c;}pixel; //ambos
```

* Funçao putPixel():
```c++
void  putPixel(pixel px){
u2 ptr = (IMAGE_WIDTH*px.p.y + px.p.x)*4;
FBptr[ptr] = px.c.r;
FBptr[ptr+1] = px.c.g;
FBptr[ptr+2] = px.c.b;
FBptr[ptr+3] = px.c.a;
}
```

![desenhando quatro pontos](/images/1_quatro_pontos.png)
