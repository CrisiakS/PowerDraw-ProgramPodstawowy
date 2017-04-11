 #include "modyfikator.hpp"
 #include "../biblioteki.hpp"

 namespace Video
        {
            void Modyfikator::GetFrame(Mat &OriginalFrame)
                    {MainFrame=OriginalFrame;}

            void Modyfikator::GoHSV()
                {
                    cvtColor(MainFrame,TempFrame, CV_RGB2HSV);
                    flip(TempFrame,MainFrame,0);
                }

            void Modyfikator::SaveChangesHSV()
                {
                    inRange(MainFrame, Scalar(HueLow, SaturationLow, ValueLow), Scalar(HueHigh, SaturationHigh, ValueHigh), TempFrame);
                    flip(TempFrame,MainFrame,0);
                }

            void Modyfikator::ExportFrame(Mat &OriginalFrame)
                {
                    flip(MainFrame,OriginalFrame,0);
                }

            void Modyfikator::Show()
                {
                    imshow("Parametry",MainFrame);
                }

            Modyfikator::Modyfikator()
                {
                    namedWindow("Opcje",WINDOW_AUTOSIZE);

                        cvCreateTrackbar("Hue","Opcje",&HueLow,HueHigh);
                        cvCreateTrackbar("Saturacja","Opcje",&SaturationLow,SaturationHigh);
                        cvCreateTrackbar("Wartosc","Opcje",&ValueLow,ValueHigh);
                }
        }
