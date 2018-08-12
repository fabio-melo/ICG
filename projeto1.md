## Desenhando linhas e figuras geométricas no Computador: Computação Gráfica na Prática!

Este artigo irá documentar uma das atividades executadas na disciplina "Introdução á Computação Gráfica", Ministrada pelo professor Christan Azambuja Pagot


## Parte 1: Setup.
Para podermos rodar o código de forma satisfatória no Windows 10, precisamos ativar a funcionalidade do Windows Subsystem for Linux, e baixar uma distribuição compatível, como o [Ubuntu 18.10](https://www.microsoft.com/store/productId/9N9TNGVNDL3Q), disponível gratuitamente na loja da microsoft.

Antes de compilar o framework usando o make, precisamos instalar algumas bibliotecas:

```sh
sudo apt install libglu1-mesa-dev freeglut3-dev
```
E também ferramenta [VcxSrv](https://sourceforge.net/projects/vcxsrv/) para podermos abrir um display X11 no sistema de janelas do Windows.

Sem mais delongas, vamos ao código!

## Parte II: Desenhando na Tela
Para este projeto, utilizamos o framework desenvolvido para simular o acesso direto ao Frame Buffer do monitor.


Para podermos pintar um pixel na tela, devemos seguir esses passos:
* Neste framework, cada Pixel possui 4 bytes, sendo cada um deles responsável por uma caracteristica de cor (RGBA), indicados por posições no array **FBptr[]**
* Precisamos calcular o offset de cada pixel que precisamos pintar, utilizamos a seguinte fórmula:
<img src="https://latex.codecogs.com/svg.latex?(x&plus;y*4)*4" title="(x+y*4)*4" />
(onde (x, y) são as coordenadas horizontais e verticais da tela, respectivamente. )

Em código:


```c++
typedef unsigned char u1;
typedef unsigned short int u2;
typedef float f8;
typedef struct{u2 r,g,b,a;}color;
typedef struct{u2 x,y;}pos;
typedef struct{pos p; color c;}pixel;
```


* Para
