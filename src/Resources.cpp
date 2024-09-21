#include <stdlib.h>
#include <ctime>
#include "Resources.h"

using namespace std;

Resources::Resources(int Width, int Height) 
{
    this->screenWidth = Width;
    this->screenHeight = Height;  

    musicFiles = {
    RESOURCES_PATH "backinthea.mp3",
    RESOURCES_PATH "Cons.mp3",
    RESOURCES_PATH "Once You Gone.mp3",
    RESOURCES_PATH "music.mp3"
    };

    //srand(time(nullptr));
    srand(static_cast<unsigned int>(time(0)));
}

const char* Resources::getRandomMusic() 
{
    if (musicFiles.empty())
    {
        return nullptr;
    }
    srand(static_cast<unsigned int>(time(0)));
    int randomSeed = rand() % musicFiles.size();
    return musicFiles[randomSeed].c_str();
}

int Resources::getWidth() 
{
    return screenWidth;
}

int Resources::getHeight() 
{
    return screenHeight;
}

void Resources::setWidth(int Width)
{
    this->screenWidth = Width;
}

void Resources::setHeight(int Height)
{
    this->screenHeight = Height;
}


//void InitResources(Resources &scr)
//{
//    scr.screenHeight = 1080;
//    scr.screenWidth = 720;
//
//    scr.musicFiles = {
//        RESOURCES_PATH "backinthea.mp3",
//        RESOURCES_PATH "Cons.mp3",
//        RESOURCES_PATH "Once You Gone.mp3",
//        RESOURCES_PATH "music.mp3"
//    };
//
//    srand(time(nullptr));
//}
//
//const char *getRandomMusic(Resources &scr)
//{
//    if (scr.musicFiles.empty())
//    {
//        return nullptr;
//    }
//    int randomSeed = rand() % scr.musicFiles.size();
//    return scr.musicFiles[randomSeed].c_str();
//}

/*const char* musicFilePath = RESOURCES_PATH "Cons.mp3";


std::cout << "Music file path: " << musicFilePath << std::endl;

if (!FileExists(musicFilePath)) {
    TraceLog(LOG_ERROR, "Music file does not exist: %s", musicFilePath);
    CloseAudioDevice();
    CloseWindow();
    return -1;
}
*/

