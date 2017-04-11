#include "ekran.hpp"
#include <GL/freeglut.h>
#include "../../opencv/main/main.hpp"
#include "../text/tekst.hpp"
#include "../../opencv/biblioteki.hpp"
#include "../../opencv/point/point.hpp"
#include "../rysowanie/drawing.hpp"
#include <string>
#include <time.h>
#include <vector>
using namespace std;

extern Mat TextureFrame;
extern Mat frame;

extern int posX;
extern int posY;

extern int VideoMode;
bool once=false;

extern Video::Point punkt;
extern Mat ReadyMask;
void wait(int seconds)
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}

    namespace OpenGL
        {
            void display()
                {
                        glClear(GL_COLOR_BUFFER_BIT);

                        glClearColor(0,0,0,0);
                    ///////////////////////////////////////////////////////

                        Video::CaptureIDLE();




                                drawing::DrawAt(punkt.x,punkt.y,255,255,255,10);

                            glRasterPos2d(0,479);
                            flip(frame,frame,0);

                            glDrawPixels( frame.size().width, frame.size().height, GL_RGBA, GL_UNSIGNED_BYTE, frame.ptr() );  // Rysowanie kamery
                            if(once==false)
                            {
                                drawing::PrepareBackground();
                                once=true;
                            }

                            stworz_napis("'z' by rysowac | 'x' by wycierac",5,15,GLUT_BITMAP_9_BY_15,1,1,0);

                            if(VideoMode==1)
                                {
                                    stworz_napis("Teraz Rysujesz",5,31,GLUT_BITMAP_9_BY_15,0,1,0);
                                }
                            if(VideoMode==2)
                                {
                                    stworz_napis("Teraz Wycierasz",5,31,GLUT_BITMAP_9_BY_15,1,0,0);
                                }
                    ///////////////////////////////////////////////////////
                    glFlush();
                    glutSwapBuffers();
                }
        }


