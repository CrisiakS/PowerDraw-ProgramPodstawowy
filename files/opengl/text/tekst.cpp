#include "tekst.hpp"
#include <vector>
#include <GL/glut.h>

        void stworz_napis(std::string napis,
                          float x, float y,
                          void *czczionka,
                          float r,float g,float b)
                                {
                                    float z=0;
                                    glColor3f(r,g,b);
                                    for(float i=0;i<napis.length();i++)
                                        {
                                            z+=12;
                                            char znak=napis[i];
                                            glRasterPos2d(x+z,y);

                                            glutBitmapCharacter(czczionka,znak);

                                        }
                                }
