#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>
using namespace std;

class Resources {
public:
    Resources(int Width, int Height);

    const char *getRandomMusic();

    int getWidth();
    int getHeight();

    void setWidth(int Width);
    void setHeight(int Height);
private:
    int screenWidth;
    int screenHeight;
    vector<string> musicFiles;
};


//typedef struct {
//    int screenwidth;
//    int screenheight;
//    const char* musicfilepath;
//
//    vector<string> musicfiles;
//}resources;
//
//
//void initresources(resources& scr);
//const char* getrandommusic(resources &scr);