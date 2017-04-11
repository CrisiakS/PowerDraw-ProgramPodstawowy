#include "debug.hpp"
#include <iostream>
#include <string>

#define DEBUGOWANIE true
using namespace std;

        void DebugMessage(string message)
            {
                if(DEBUGOWANIE)
                    {
                        cout<<message<<endl;
                    }
            }
