#include<stdlib.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}



void DDA(void) {
	glColor3f (0.0, 0.0, 1.0);
	float dx,dy,step,m,x,y,Xin,Yin,k;
	float x1=50, x2=150, y1=600, y2=750;
	
   dx = x2 - x1;
   dy = y2 - y1;
   m=dy/dx;
  if (abs(dx) > abs(dy)) {
     step = abs(dx);
  } else
    step = abs(dy);
  Xin = dx / step;
  Yin = dy / step;
  x = x1;
  y = y1;
  for (k = 1; k <= step; k++) {
    x = x + Xin;
    y = y + Yin;
    draw_pixel(x, y);
  }
  

}

 void BL(void){
 	glColor3f (1.0, 0.0, 0.0);
	int x1=150, x2=150, y1=750, y2=300;
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}

}

void plot(int x, int y)
{
	int pntx=400,pnty=500;
	glBegin(GL_POINTS);
	glVertex2i(x+pntx, y+pnty);
	glEnd();
}
void BC(void){
	glColor3f (1.0, 0.0, 1.0);
	int r=150;
	int x = 0;
	int y =r;
	float P = 3 - 2*r;
	plot(x, y);

	while (y >=x)
	{
		x++; 
		if (P > 0)
		{
			y--;
			P += 4*(x-y)+10;
		}
		else
		{
			P += 4*x+6;
		}
		plot(x, y);
		plot(x, -y);
		plot(y, -x);
		plot(-y, -x);
		plot(-x, -y);
		plot(-x, y);
		plot(-y, x);
		plot(y, x);
	}

}
void plot2(int x, int y)
{
	int pntx=800,pnty=500;
	glBegin(GL_POINTS);
	glVertex2i(x+pntx, y+pnty);
	glEnd();
}
void MP(void){
	glColor3f (1.0, 1.0, 1.0);
	int r=150;
	int x = 0;
	int y = r;
	float P = 1 - r;

	while (y > x)
	{
		x++;
		if (P < 0)
		{ 
			P += 2*x+1;
		}
		else
		{
			y--;
			P += 2*(x-y)+1;
		}
		plot2(x, y);
		plot2(x, -y);
		plot2(y, -x);
		plot2(-y, -x);
		plot2(-x, -y);
		plot2(-x, y);
		plot2(-y, x);
		plot2(y, x);
	}
}


void yuz(){
	glClear (GL_COLOR_BUFFER_BIT); 
	
	DDA();
	BL();
	BC();
	MP();
	glFlush();
}

void myInit(){
  glClearColor(0.0, 1.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glPointSize(10.0);
  gluOrtho2D(0.0, 1920.0, 0.0, 1080.0);
}                  



int main(int argc, char ** argv) {

  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(1920, 1080);
  glutInitWindowPosition(0,0);
  glutCreateWindow("");
  myInit ();   

  glutDisplayFunc(yuz); 
//  glutDisplayFunc(BL);
  glutMainLoop();
} 