#ifndef point_hpp
#define point_hpp

#include "../biblioteki.hpp"
#include <iostream>

    namespace Video
    {
        struct Point
            {
                    int x;
                    int y;

                    int lastx;
                    int lasty;

                    bool ruch;

                    int CzyRuch();
                    int SetXY(int ix, int iy);
                    int Usun();
                    ~Point();
            };

    }

#endif // point_hpp
