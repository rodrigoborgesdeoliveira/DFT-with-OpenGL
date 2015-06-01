/*
 *DFT calculus and graphics exhibition using OpenGL
 *
 *Rodrigo Borges de Oliveira
 */

#include<windows.h>
#include<GL/glut.h>
#include <iostream>
#include <math.h>
#include <complex>
#include <fstream>
#include<string>

#define FS 8000
#define N 18

using namespace std;

void Texto(void *fonte,char *str){
    while(*str)
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*str++);
}

void DesenhaReal(){
    double maior, real[N], x;
    char* buffer = new char[30];
    char valor[30];
    ifstream ler;
    ler.open("XmReal.txt");
    for(int m = 0; m<N; m++){
        ler >> real[m];
        //cout << real[m] << endl;
        if(m!=0){
            if(real[m]>real[m-1]){
                maior = real[m];
            }
        }
    }
    ler.close();
    glClear(GL_COLOR_BUFFER_BIT); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(-1,FS/1000+2,-(maior+1.2),maior+1.2); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    //X e Y
    glBegin(GL_LINES);
        glVertex2f(0,0);
        glVertex2f(FS/1000+1,0);
        glVertex2f(0,-(maior+0.7));
        glVertex2f(0,maior+0.7);
    glEnd();
    //Arrow at x and y
    glBegin(GL_TRIANGLES);
        //Flecha em x
        glVertex2f(FS/1000+1,0.05);
        glVertex2f(FS/1000+1.05,0);
        glVertex2f(FS/1000+1,-0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
        //Arrow at y
        glVertex2f(-0.05,maior+0.7);
        glVertex2f(0,maior+0.75);
        glVertex2f(0.05,maior+0.7);
    glEnd();

    //Text X(m)
    glColor3f(0,0,0);
    glRasterPos2f(0.1,maior+0.7);
    Texto(GLUT_BITMAP_TIMES_ROMAN_10,"X(m)");

    //Text KHz
    glColor3f(0,0,0);
    glRasterPos2f(FS/1000+1,0.1);
    Texto(GLUT_BITMAP_TIMES_ROMAN_10,"KHz");

    for(int i=0; i<N; i++){
        glColor3f(0,0,0); 
        glPointSize(2.5); 
        x = (i*FS/N); 
        x = x/1000; 
        glBegin(GL_LINES); 
            glVertex2f(x,0);
            glVertex2f(x,real[i]);
        glEnd(); 

        glBegin(GL_POINTS);
            glVertex2f(x,real[i]);
        glEnd();

        //Y values
        glColor3f(0,0,0);
        glRasterPos2f(-.7,real[i]);
        sprintf(buffer,"%.10g", real[i] );
        sprintf(valor,buffer);
        Texto(GLUT_BITMAP_TIMES_ROMAN_10,valor);

        //X values
        glColor3f(0,0,0);
        if(real[i]>=0){
            glRasterPos2f(x,-0.5);
        }
        else{
            glRasterPos2f(x,0.5);
        }
        sprintf(buffer,"%.10g", x);
        sprintf(valor,buffer);
        Texto(GLUT_BITMAP_TIMES_ROMAN_10,valor);

        glFlush(); 
    }
}

void DesenhaImag(){
    double maior, imag[N], x;
    char* buffer = new char[30];
    char valor[30];
    ifstream ler;
    ler.open("XmImag.txt");
    for(int m = 0; m<N; m++){
        ler >> imag[m];
        //cout << imag[m] << endl;
        if(m!=0){
            if(imag[m]>imag[m-1]){
                maior = imag[m];
            }
        }
    }
    ler.close();
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,FS/1000+2,-(maior+1.2),maior+1.2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    //X e Y
    glBegin(GL_LINES);
        glVertex2f(0,0);
        glVertex2f(FS/1000+1,0);
        glVertex2f(0,-(maior+0.7));
        glVertex2f(0,maior+0.7);
    glEnd();
    //Arrow at x and y
    glBegin(GL_TRIANGLES);
        //Arrow at x
        glVertex2f(FS/1000+1,0.05);
        glVertex2f(FS/1000+1.05,0);
        glVertex2f(FS/1000+1,-0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
        //Arrow at y
        glVertex2f(-0.05,maior+0.7);
        glVertex2f(0,maior+0.75);
        glVertex2f(0.05,maior+0.7);
    glEnd();

    //Text X(m)
    glColor3f(0,0,0);
    glRasterPos2f(0.1,maior+0.7);
    Texto(GLUT_BITMAP_TIMES_ROMAN_10,"X(m)");

    //Text KHz
    glColor3f(0,0,0);
    glRasterPos2f(FS/1000+1,0.1);
    Texto(GLUT_BITMAP_TIMES_ROMAN_10,"KHz");

    for(int i=0; i<N; i++){
        glColor3f(0,0,0);
        glPointSize(2.5);
        x = (i*FS/N);
        x = x/1000;
        glBegin(GL_LINES);
            glVertex2f(x,0);
            glVertex2f(x,imag[i]); 
        glEnd();

        glBegin(GL_POINTS);
            glVertex2f(x,imag[i]);
        glEnd();

        //y values
        glColor3f(0,0,0);
        glRasterPos2f(-.7,imag[i]);
        sprintf(buffer,"%.10g", imag[i] );
        sprintf(valor,buffer);
        Texto(GLUT_BITMAP_TIMES_ROMAN_10,valor);

        //x values
        glColor3f(0,0,0);
        if(imag[i]>=0){
            glRasterPos2f(x,-0.5);
        }
        else{
            glRasterPos2f(x,0.5);
        }
        sprintf(buffer,"%.10g", x);
        sprintf(valor,buffer);
        Texto(GLUT_BITMAP_TIMES_ROMAN_10,valor);

        glFlush(); 
    }
}

void DesenhaMag(){
    double maior, mag[N], x;
    char* buffer = new char[30];
    char valor[30];
    ifstream ler;
    ler.open("XmMag.txt");
    for(int m = 0; m<N; m++){
        ler >> mag[m];
        //cout << mag[m] << endl;
        if(m!=0){
            if(mag[m]>mag[m-1]){
                maior = mag[m];
            }
        }
    }
    ler.close();
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(-1,FS/1000+2,-(maior+1.2),maior+1.2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 
    glColor3f(0.5,0.5,0.5);
    //X e Y
    glBegin(GL_LINES);
        glVertex2f(0,0);
        glVertex2f(FS/1000+1,0);
        glVertex2f(0,-(maior+0.7));
        glVertex2f(0,maior+0.7);
    glEnd();
    //Arrow at x and y
    glBegin(GL_TRIANGLES);
        //Flecha em x
        glVertex2f(FS/1000+1,0.05);
        glVertex2f(FS/1000+1.05,0);
        glVertex2f(FS/1000+1,-0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
        //Arrow at y
        glVertex2f(-0.05,maior+0.7);
        glVertex2f(0,maior+0.75);
        glVertex2f(0.05,maior+0.7);
    glEnd();

    //Text X(m)
    glColor3f(0,0,0);
    glRasterPos2f(0.1,maior+0.7);
    Texto(GLUT_BITMAP_TIMES_ROMAN_10,"X(m)");

    //Text KHz
    glColor3f(0,0,0);
    glRasterPos2f(FS/1000+1,0.1);
    Texto(GLUT_BITMAP_TIMES_ROMAN_10,"KHz");

    for(int i=0; i<N; i++){
        glColor3f(0,0,0);
        glPointSize(2.5);
        x = (i*FS/N); 
        x = x/1000; 
        glBegin(GL_LINES); 
            glVertex2f(x,0);
            glVertex2f(x,mag[i]);
        glEnd(); 

        glBegin(GL_POINTS);
            glVertex2f(x,mag[i]);
        glEnd();

        //y values
        glColor3f(0,0,0);
        glRasterPos2f(-.7,mag[i]);
        sprintf(buffer,"%.10g", mag[i]);
        sprintf(valor,buffer);
        Texto(GLUT_BITMAP_TIMES_ROMAN_10,valor);

        //x values
        glColor3f(0,0,0);
        if(mag[i]>=0){
            glRasterPos2f(x,-0.5);
        }
        else{
            glRasterPos2f(x,0.5);
        }
        sprintf(buffer,"%.10g", x);
        sprintf(valor,buffer);
        Texto(GLUT_BITMAP_TIMES_ROMAN_10,valor);

        glFlush(); 
    }
}

void DesenhaFase(){
    double maior, fase[N], x;
    char* buffer = new char[30];
    char valor[30];
    ifstream ler;
    ler.open("XmFase.txt");
    for(int m = 0; m<N; m++){
        ler >> fase[m];
        //cout << fase[m] << endl;
        if(m!=0){
            if(fase[m]>fase[m-1]){
                maior = fase[m];
            }
        }
    }
    ler.close();
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(-1,FS/1000+2,-(maior+5),maior+5);
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
    glColor3f(0.5,0.5,0.5);
    //X e Y
    glBegin(GL_LINES);
        glVertex2f(0,0);
        glVertex2f(FS/1000+1,0);
        glVertex2f(0,-(maior+0.7));
        glVertex2f(0,maior+0.7);
    glEnd();
    //Arrow at x and y
    glBegin(GL_TRIANGLES);
        //Arrow at x
        glVertex2f(FS/1000+1,0.05);
        glVertex2f(FS/1000+1.05,0);
        glVertex2f(FS/1000+1,-0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
        //Arrow at y
        glVertex2f(-0.07,maior+0.7);
        glVertex2f(0,maior+0.75);
        glVertex2f(0.07,maior+0.7);
    glEnd();

    //Text= X(m)
    glColor3f(0,0,0);
    glRasterPos2f(0.1,maior+0.7);
    Texto(GLUT_BITMAP_TIMES_ROMAN_10,"X(m)");

    //Text KHz
    glColor3f(0,0,0);
    glRasterPos2f(FS/1000+1,0.1);
    Texto(GLUT_BITMAP_TIMES_ROMAN_10,"KHz");

    for(int i=0; i<N; i++){
        glColor3f(0,0,0); // Cor da linha
        glPointSize(2.5); //Tamanho do ponto
        x = (i*FS/N); //Resposta em Hz
        x = x/1000; //Transformar em KHz
        glBegin(GL_LINES); 
            glVertex2f(x,0);
            glVertex2f(x,fase[i]); 
        glEnd(); 

        glBegin(GL_POINTS);
            glVertex2f(x,fase[i]);
        glEnd();

        //y values
        glColor3f(0,0,0);
        glRasterPos2f(-.7,fase[i]);
        sprintf(buffer,"%.10g", fase[i]);
        sprintf(valor,buffer);
        Texto(GLUT_BITMAP_TIMES_ROMAN_10,valor);

        //x values
        glColor3f(0,0,0);
        if(fase[i]>=0){
            glRasterPos2f(x,-1.5);
        }
        else{
            glRasterPos2f(x,1.5);
        }
        sprintf(buffer,"%.10g", x);
        sprintf(valor,buffer);
        Texto(GLUT_BITMAP_TIMES_ROMAN_10,valor);

        glFlush(); 
    }
}

void Calcula(){
    ofstream gravarXn, gravarXmReal, gravarXmImag, gravarXmMag, gravarXmFase;
	double xn = 0, ts = (double) 1/FS, real = 0, imag = 0;
	gravarXn.open("xn.txt");
	gravarXmReal.open("XmReal.txt");
	gravarXmImag.open("XmImag.txt");
	gravarXmMag.open("XmMag.txt");
	gravarXmFase.open("XmFase.txt");

	for (int m = 0; m < N; m++){
		for (int n = 0; n < N; n++){
			xn = sin(2*M_PI*1000*n*ts) + 0.5*sin(2*M_PI*2000*n*ts+3*M_PI/4);
			real = real + xn*cos(2*M_PI*n*m/N);
			imag = imag - xn*sin(2*M_PI*n*m/N);
			//cout << "x(" << n << ") = " << xn << endl;

			if(m == 0){

				gravarXn << xn << endl;
			}
		}

		real = real * 10000;
		real = (int)real;
		real = real / 10000;

		imag = imag * 10000;
		imag = (int)imag;
		imag = imag / 10000;

		complex<double> ret (real,imag);
		//cout << "X(" << m << ") = " << real << " + j" << imag << " = ";

		gravarXmReal << real << endl;
		gravarXmImag << imag << endl;

		//cout << round(abs(ret)) << " |" << arg(ret)*180/M_PI << endl;

		gravarXmMag << round(abs(ret))<< endl;
		gravarXmFase << arg(ret)*180/M_PI << endl;

		real = 0;
		imag = 0;
	}
	gravarXn.close();
	gravarXmReal.close();
	gravarXmImag.close();
	gravarXmMag.close();
	gravarXmFase.close();
}

int main(void){
    Calcula();
    //Retangular - Real
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(800,400); 
    glutInitWindowPosition(0,0); 
    glutCreateWindow("DFT - OpenGL - Retangular (Real)"); 
    glutDisplayFunc(DesenhaReal); 
    glClearColor(1,1,1,0); 
    //Retangular - Image
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(800,400);
    glutInitWindowPosition(500,0);
    glutCreateWindow("DFT - OpenGL - Retangular (Imagem)"); 
    glutDisplayFunc(DesenhaImag); 
    glClearColor(1,1,1,0); 
    //Polar - Magnitude
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(800,400); 
    glutInitWindowPosition(0,384); 
    glutCreateWindow("DFT - OpenGL - Polar (Magnitude)"); 
    glutDisplayFunc(DesenhaMag); 
    glClearColor(1,1,1,0); 
    //Polar - Phase
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,400); 
    glutInitWindowPosition(500,384);
    glutCreateWindow("DFT - OpenGL - Polar (Fase)");
    glutDisplayFunc(DesenhaFase);
    glClearColor(1,1,1,0); 

    glutMainLoop(); 
    return 0;
}
