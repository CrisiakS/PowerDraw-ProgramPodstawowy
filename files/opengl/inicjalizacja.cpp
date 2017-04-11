#include <GL/freeglut.h>
#include <string>

#include "inicjalizacja.hpp"
#include "ekran/ekran.hpp"
#include "../mouse and keyboard/keyboard/keyboard.hpp"

#include "../debug/debug.hpp"

    namespace OpenGL
    {
        void init()
            {
                glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE| GLUT_RGBA);
                glutInitWindowSize(640,480);
                glutCreateWindow("PowerDraw");
                glutDisplayFunc(display);
                glutIdleFunc(display);
                glutKeyboardFunc(keyboard);
            }

    }
