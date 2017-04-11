#include "main.hpp"

    int main(int argc,char *argv[])
        {
            glutInit(&argc,argv);
            OpenGL::init();

            gluOrtho2D(0,640,480,0);

            glutMainLoop();

        }
