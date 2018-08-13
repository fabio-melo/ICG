#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
	pixel a = {{100, 255}, RED};
	pixel b = {{255 , 400}, GREEN};
	pixel c = {{255, 450 }, BLUE};
	pixel d = {{400, 100 }, RED};

	drawLine(a,b);
	drawLine(c,d);

	//drawTriangle(a,b,c);
	//drawLine(a,b); drawLine(b,c);
	//drawLine(c,d), drawLine(d,a);
	//randomLines();

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

