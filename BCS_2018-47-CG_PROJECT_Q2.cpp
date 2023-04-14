// ===========================LIVE SCENE=================================


#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

const double PI = 3.141592654;

int frameNumber = 0;

void drawDisk(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}

void drawtree(){
	glColor3f(0.417, 0.33, 0.195);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2,-0.35);
	glVertex2f(0,.8);
	glVertex2f(0.2,-0.35);
	glEnd();
	  glColor3f(0.25, 0.43, 0.214);
	glBegin(GL_POLYGON);
	glVertex2f(-0.38,0);
	glVertex2f(0,0.6);
	glVertex2f(0.38,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-0.35,0.25);
	glVertex2f(0,0.7);
	glVertex2f(0.35,0.25);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-0.3,0.45);
	glVertex2f(0,0.8);
	glVertex2f(.3,0.45);
	glEnd();
}

void drawmoon() {
	glColor3f(1,1,1);
	drawDisk(0.5);
	glColor3f(0,0,0);
}

void drawmoon1() {
	glColor3f(0,0,0);
	drawDisk(0.45);
	glColor3f(0,0,0);
}

void drawstars(){
	glPushMatrix();
	glTranslated(4,3,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.01);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(3,3,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.01);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2,3,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.01);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1,3,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.01);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(4.5,3.5,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.01);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.5,3.5,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.01);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.5,3.5,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.01);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.5,3.5,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.01);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(5,3,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.01);
	glColor3f(0,0,0);
	glPopMatrix();
	}

void drawWindmill() {
	int i;
	glColor3f(0.8f, 0.8f, 0.9f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	glRotated(frameNumber * (180.0/46), 0, 0, 1);
	glColor3f(0.4f, 0.4f, 0.8f);
	for (i = 0; i < 3; i++) {
		glRotated(120, 0, 0, 1);
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f,0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}
}

void drawBitmapText(char *string,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x, y,z);

	for (c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , *c);
	}
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

//==========================================MOONS==========================
	glPushMatrix();
	glTranslated(5.8,3,0);
	glRotated(-frameNumber*0.7,0,0,1);
	drawmoon();
	glPopMatrix();

	glPushMatrix();
	glTranslated(5.95,3.1,0);
	glRotated(-frameNumber*0.7,0,0,1);
	drawmoon1();
	glPopMatrix();
//=========================================MOON=====================

//=========================================STARS======================
	drawstars();

	glPushMatrix();
	glTranslated(-2,0,0);
	drawstars();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2,-2,0);
	drawstars();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1,-3,0);
	drawstars();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1,-1,0);
	drawstars();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2,-1,0);
	drawstars();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2,-2,0);
	drawstars();
	glPopMatrix();
//===============================================STARS===========================

//======================================MOUNTAINS============================
	glColor3f(0, 0.6f, 0.2f);
	glBegin(GL_POLYGON);
	glVertex2f(-3,-1);
	glVertex2f(1.5f,1.65f);
	glVertex2f(5,-1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-3,-1);
	glVertex2f(3,2.1f);
	glVertex2f(7,-1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0,-1);
	glVertex2f(6,1.2f);
	glVertex2f(20,-1);
	glEnd();
//========================================MOUNTAINS==========================

//=================================ROAD=============================
	glColor3f(0.4f, 0.4f, 0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(0,-0.4f);
	glVertex2f(7,-0.4f);
	glVertex2f(7,0.4f);
	glVertex2f(0,0.4f);
	glEnd();
//====================================ROAD===============================

//================================WHITE STRIPS ON ROAD=====================
	glLineWidth(4);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(0,0);
	glVertex2f(1,0);
	glEnd();
	glLineWidth(1);

	glLineWidth(4);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(1.5,0);
	glVertex2f(2.5,0);
	glEnd();
	glLineWidth(1);

	glLineWidth(4);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(3,0);
	glVertex2f(4,0);
	glEnd();
	glLineWidth(1);

	glLineWidth(4);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(4.5,0);
	glVertex2f(5.5,0);
	glEnd();
	glLineWidth(1);

	glLineWidth(4);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(6,0);
	glVertex2f(7,0);
	glEnd();
	glLineWidth(1);

//================================WHITE STRIPS ON ROAD=====================

//========================================WINDMILL=====================
	glPushMatrix();
	glTranslated(0.75,1,0);
	glScaled(0.6,0.6,1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.2,1.6,0);
	glScaled(0.4,0.4,1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.7,0.8,0);
	glScaled(0.7,0.7,1);
	drawWindmill();
	glPopMatrix();
//================================WINGMILL===========================

 //=============================================TREE======================
	glPushMatrix();
	glTranslated(0.5,0.8,0);
	drawtree();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.5,0.8,0);
	drawtree();
	glPopMatrix();

	glPushMatrix();
	glTranslated(4.5,0.8,0);
	drawtree();
	glPopMatrix();

	glPushMatrix();
	glTranslated(6.5,0.8,0);
	drawtree();
	glPopMatrix();

	glPushMatrix();
	glTranslated(6.5,-0.5,0);
	drawtree();
	glPopMatrix();

	glPushMatrix();
	glTranslated(4.5,-0.5,0);
	drawtree();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.5,-0.5,0);
	drawtree();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5,-0.5,0);
	drawtree();
	glPopMatrix();
//=========================TREE========================

	//==========================CAR==================
	glPushMatrix();
	glTranslated(3.78,0.39,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.05);
	glColor3f(0,0,0);
	glPopMatrix();

	glColor3f(0.57,0.59,0.62);
	glBegin(GL_POLYGON);
	glVertex2f(3,0.45);
	glVertex2f(3.8,0.45);
	glVertex2f(3.8,0.25);
	glVertex2f(3,0.25);
	glEnd();

	glColor3f(0.57,0.59,0.62);
	glBegin(GL_POLYGON);
	glVertex2f(3.2,0.45);
	glVertex2f(3.6,0.45);
	glVertex2f(3.6,0.55);
	glVertex2f(3.2,0.55);
	glEnd();

	glPushMatrix();
	glTranslated(3.6,0.25,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(0,0,0);
	drawDisk(0.05);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.2,0.25,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(0,0,0);
	drawDisk(0.05);
	glColor3f(0,0,0);
	glPopMatrix();
	//-------------------------------------car1---------------------------

		glPushMatrix();
	glTranslated(6.78,0.39,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.05);
	glColor3f(0,0,0);
	glPopMatrix();

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(6,0.45);
	glVertex2f(6.8,0.45);
	glVertex2f(6.8,0.25);
	glVertex2f(6,0.25);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(6.2,0.45);
	glVertex2f(6.6,0.45);
	glVertex2f(6.6,0.55);
	glVertex2f(6.2,0.55);
	glEnd();

	glPushMatrix();
	glTranslated(6.6,0.25,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(0,0,0);
	drawDisk(0.05);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(6.2,0.25,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(0,0,0);
	drawDisk(0.05);
	glColor3f(0,0,0);
	glPopMatrix();
//-------------------------------------------car-2---------------------------------------


	glPushMatrix();
	glTranslated(5.02,-0.11,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.05);
	glColor3f(0,0,0);
	glPopMatrix();

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(5,-0.05);
	glVertex2f(5.8,-0.05);
	glVertex2f(5.8,-0.25);
	glVertex2f(5,-0.25);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(5.2,0.05);
	glVertex2f(5.6,0.05);
	glVertex2f(5.6,-0.05);
	glVertex2f(5.2,-0.05);
	glEnd();

	glPushMatrix();
	glTranslated(5.6,-0.25,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(0,0,0);
	drawDisk(0.05);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(5.2,-0.25,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(0,0,0);
	drawDisk(0.05);
	glColor3f(0,0,0);
	glPopMatrix();

//================================CAR-3===================================

    glPushMatrix();
	glTranslated(1.02,-0.11,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.05);
	glColor3f(0,0,0);
	glPopMatrix();

	glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(1,-0.05);
	glVertex2f(1.8,-0.05);
	glVertex2f(1.8,-0.25);
	glVertex2f(1,-0.25);
	glEnd();

	glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(1.2,0.05);
	glVertex2f(1.6,0.05);
	glVertex2f(1.6,-0.05);
	glVertex2f(1.2,-0.05);
	glEnd();

	glPushMatrix();
	glTranslated(1.6,-0.26,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(0,0,0);
	drawDisk(0.05);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.2,-0.26,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(0,0,0);
	drawDisk(0.05);
	glColor3f(0,0,0);
	glPopMatrix();
//=====================================car-4====================================

    glPushMatrix();
    glTranslated(2.13,0.34,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(1,1,1);
	drawDisk(0.05);
	glColor3f(0,0,0);
	glPopMatrix();

	glColor3f(0.957, 0.57, 0.21);
	glBegin(GL_POLYGON);
	glVertex2f(0.9,0.25);
	glVertex2f(1.8,0.25);
	glVertex2f(1.8,0.6);
	glVertex2f(0.9,0.6);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(2.15,0.25);
	glVertex2f(1.9,0.25);
	glVertex2f(1.9,0.55);
	glVertex2f(2.15,0.55);
	glEnd();

	glPushMatrix();
	glTranslated(1.65,0.25,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(0,0,0);
	drawDisk(0.07);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.1,0.25,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(0,0,0);
	drawDisk(0.07);
	glColor3f(0,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.03,0.25,0);
	glRotated(-frameNumber*0.7,0,0,1);
	glColor3f(0,0,0);
	drawDisk(0.065);
	glColor3f(0,0,0);
	glPopMatrix();

	glLineWidth(4);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(1.8,0.26);
	glVertex2f(1.9,0.26);
	glEnd();
	glLineWidth(1);
//=====================================TRUCK=======================


	glColor3f(1,1,1);
    drawBitmapText(" SALIL BCS2018-47",6,3.8,0);

    glColor3f(0,0,0);
    drawBitmapText(" SALIL IS GREAT",1,0.4,0);

	glutSwapBuffers();

}

void doFrame(int v) {
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("BCS2018_47_CG_PROJECT");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(200,doFrame,0);

    glutMainLoop();
    return 0;
}


