#ifndef modyfikator_hpp
#define modyfkator_hpp

    #include "../biblioteki.hpp"
     namespace Video
        {
        ////////////////////////////////////////////////
            class Modyfikator
                {
                    friend void Video::CaptureIDLE();
                    private:
                        int HueLow=146;
                        int HueHigh=179;

                        int SaturationLow=42;
                        int SaturationHigh=255;

                        int ValueLow=213;
                        int ValueHigh=255;

                        string nazwa="Opcje";

                        Mat TempFrame;
                    public:
                        Modyfikator();
                            void GetFrame(Mat &OriginalFrame);
                            void GoHSV();
                            void SaveChangesHSV();
                            void ExportFrame(Mat &OriginalFrame);
                            void Show();
                        Mat MainFrame;
                };

        ////////////////////////////////////////////////
        }

#endif // modyfikator_hpp
