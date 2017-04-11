#include <string>
#include <iostream>
#include "main.hpp"
#include "../biblioteki.hpp"                //  Wszystkie biblioteki OpenCV w jednym pliczku
#include "../modifier/modyfikator.hpp"      //  Biblioteka modyfikatora która sluzy do obslugi przeksztalcenia HSV
#include "../point/point.hpp"               //  Biblioteka obslugujaca obiekt 'punkt' i przetrzymujaca wartosci x,y
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
extern VideoCapture cap(0);

    Video::Modyfikator parametry;           // Konstruktor obiektu "parametry" - potrzebengo do obslugi pasków HSV

        Mat TextureFrame;                   // Powierzchnia pobierana przez FreeGlut
        Mat frame(480,640,CV_8UC3);         // Deklaracja zmiennej obrazu przechwytujacej obraz kamery usb

    int VideoMode=0;        // Tryb Wideo - jak na razie sluzy do zmiany z rysowania/wycierania
    Point punkt;            // Konstruktor struktury "punkt" która przetrzymuje wartości x,y punktu laserowego

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    namespace Video                     // Przestrzeń nazw "Video" - w tej przestrzeni nazw znajduja sie funkcje odpowiadajace
        {                               // za obsluge biblioteki OpenCV


            /////////--- Funkcja CaptureStart ---////////////
            //Funkcja ta inicjuje kamerke internetowa oznaczana jako cap(0) gdzie
            //'0' to numer kamerki. Zero oznacza kamerke ustawioną jako kaemra domyslna
            int CaptureStart()
                {
                    VideoCapture cap(0);
                    if(cap.isOpened())
                        {
                            DebugMessage("Zainicjowano przechwytywanie wideo");
                            return true;
                        }
                    else
                        {
                            DebugMessage("Blad przy inicjalizacji przechwytywania wideo");
                            return false;
                        }
                }

            void LiczXY()
                {
                      Moments oMoments = moments(parametry.MainFrame);

                        double dM01 = oMoments.m01;
                        double dM10 = oMoments.m10;
                        double dArea = oMoments.m00;


                        if (dArea > 1500)
                            {
                                punkt.x = dM10 / dArea;
                                punkt.y = dM01 / dArea;
                            }
                }

            void CaptureIDLE()
                {
                   cap >>  frame;               //Pobranie klatki z kamery i zapisanie jej do zmiennej tablicowej frame

                    flip(frame,TextureFrame,0);  //Flip sluzy do przerzucenia lustrzanego obrazu
                    cvtColor(frame, frame, CV_BGR2RGBA);
                  //  flip(frame,frame,0);

                        if(VideoMode==0)
                        {
                            cvtColor(TextureFrame, TextureFrame, CV_BGR2RGBA);
                        }
                        else
                        {
                            cvtColor(TextureFrame, TextureFrame, CV_BGR2HSV);

                            parametry.GetFrame(TextureFrame);
                            parametry.SaveChangesHSV();

                            LiczXY();

                            imshow("Podglad HSV", parametry.MainFrame);
                        }

                        // Biblioteka uzywa schematu kolorów BGR uzywanego dawniej przez kamery internetowe
                        // Aby przekonwertowac schemat kolorow z BGR na RGB uzywamy tego oto prostego wyrazenia :)

                }
            void GotoHSV()
                {
                    VideoMode=1;
                }
            void GotoRGB()
                {
                    VideoMode=0;

                }


        }
