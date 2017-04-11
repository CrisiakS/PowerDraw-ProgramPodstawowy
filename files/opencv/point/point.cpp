#include "point.hpp"

    namespace Video
    {
            int Point::CzyRuch()
                {
                    if(lastx!=x or lasty!=y)
                        {
                            lastx=x;
                            lasty=y;
                            return true;
                        }

                        else
                            return false;
                }

            int Point::SetXY(int ix, int iy)
                {
                    x=ix;
                    y=iy;
                }

    }
