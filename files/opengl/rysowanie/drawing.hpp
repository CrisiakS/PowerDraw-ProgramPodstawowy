#ifndef drawing_hpp
#define drawing_hpp

    #include <GL/freeglut.h>
    #include <vector>

     namespace drawing
        {
            void DrawAt(int x,int y, int r, int g, int b, int pointsize);
            void PrepareBackground();
            void ShowDraw();
        }
#endif // drawing_hpp
