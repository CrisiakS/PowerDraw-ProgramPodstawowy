#include "drawing.hpp"
#include "../../opencv/biblioteki.hpp"
#include <vector>
#include "../../opencv/point/point.hpp"
#include <iostream>
using namespace std;

extern Mat frame;
extern Video::Point punkt;
extern int VideoMode;
Mat DrawingMask(480,640,CV_8UC3);
Mat ReadyMask;
    namespace drawing
        {
            void PrepareBackground()
                {
                    DrawingMask=Scalar(0,0,0);
                    ReadyMask=DrawingMask;

                }



            void DrawAt(int x,int y, int r, int g, int b, int pointsize)
                {
                    if(punkt.y>5 and punkt.y<475 and punkt.x>5 and punkt.x<635 and VideoMode==1)
                        for(int y=(punkt.y-pointsize/2);y<(punkt.y+pointsize/2);y++)
                        {
                            for(int x=((punkt.x-pointsize/2));x<(punkt.x+(pointsize/2));x++)
                            {
                                   Vec3b color = DrawingMask.at<Vec3b>(Point(x,y));
                                   color[0]=r;
                                   color[1]=g;
                                   color[2]=b;
                                   DrawingMask.at<Vec3b>(Point(x,y)) = color;
                            }
                        }

                    if(punkt.y>5 and punkt.y<475 and punkt.x>5 and punkt.x<635 and VideoMode==2)
                        for(int y=(punkt.y-pointsize/2);y<(punkt.y+pointsize/2);y++)
                        {
                            for(int x=((punkt.x-pointsize/2));x<(punkt.x+(pointsize/2));x++)
                            {
                                   Vec3b color = DrawingMask.at<Vec3b>(Point(x,y));
                                   color[0]=NULL;
                                   color[1]=NULL;
                                   color[2]=NULL;
                                   DrawingMask.at<Vec3b>(Point(x,y)) = color;
                            }
                        }

                        Mat rgbFrame(640, 480, CV_8UC3);
                        cvtColor(DrawingMask, rgbFrame, CV_BGR2RGB);

                        // ...now let it convert it to RGBA
                        Mat newSrc = Mat(rgbFrame.rows, rgbFrame.cols, CV_8UC4);
                            int from_to[] = { 0,0, 1,1, 2,2, 3,3 };
                        mixChannels(&rgbFrame, 2, &newSrc, 1, from_to, 4);

                        ReadyMask=newSrc;
                            frame+=ReadyMask;

                        imshow("Podglad",rgbFrame);

                    //   frame+=DrawingMask;
                }

            void ShowDraw()
                {
                    if(!ReadyMask.empty())
                        frame+=ReadyMask;
                }

        }



