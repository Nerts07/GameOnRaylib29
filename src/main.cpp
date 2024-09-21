#include <iostream>
#include <raylib.h>
#include <thread>
#include <raymath.h>

#include "Resources.h"

using namespace std;

float deltaTime = 0.f;

int main(void)
{
    Resources *res = new Resources(800, 600);

    res->getHeight();
    res->getWidth();
    res->getRandomMusic();

    const char* musicFilePath = res->getRandomMusic();
    bool f3IsPressed = false;
    bool fPressed = false;
    bool f11Pressed = false;
    bool musKey = false;

    InitWindow(res->getWidth(), res->getHeight(), "3d Cube");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    InitAudioDevice();

    Camera3D camera;
    camera.position = Vector3{ 10.0f, 1.0f, 10.0f };
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.fovy = 95.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Music sound = LoadMusicStream(musicFilePath);
    PlayMusicStream(sound);
    SetMusicVolume(sound, 0.3f);

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
    
    DisableCursor();
    SetTargetFPS(70);                  

    while (!WindowShouldClose())
    {
        deltaTime += GetFrameTime();
        if (!fPressed)
        {
            UpdateCamera(&camera, CAMERA_CUSTOM);
        }
        

        if (IsKeyPressed('Z')) 
        {
            camera.target = Vector3{ 0.0f, 1.f, 0.0f };

        }
        
        UpdateMusicStream(sound);
        BeginDrawing();
        ClearBackground(DARKPURPLE);

        BeginMode3D(camera);

        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, DARKBLUE);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, PURPLE);

        DrawGrid(100, 1.0f);
        EndMode3D();
        if (IsKeyPressed(KEY_F3)) {
            f3IsPressed = !f3IsPressed;
        }
        if (IsKeyPressed(KEY_F))
        {
            fPressed = !fPressed;
        }
        if (IsKeyPressed(KEY_F11))
        {
            f11Pressed = !f11Pressed;
        }

        if (f3IsPressed)
        { 
            DrawRectangle(10, 10, 320, 93, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines(10, 10, 320, 93, BLUE);
            DrawText(TextFormat("- Position: (%06.3f, %06.3f, %06.3f)", camera.position.x, camera.position.y, camera.position.z), 10, 60, 10, WHITE);
            DrawText(TextFormat("Music: %s ", musicFilePath), 10, 80, 10, WHITE);
            DrawFPS(10, 10);
        }
        if (fPressed)
        {
            ShowCursor();

        }
        if (!fPressed)
        {
            DisableCursor();
        }
        if (f11Pressed)
        {
            
            res->setWidth(GetScreenWidth());
            res->setHeight(GetScreenHeight());
            SetWindowState(FLAG_FULLSCREEN_MODE);
        }
        if (!f11Pressed)
        {
            SetWindowState(FLAG_WINDOW_RESIZABLE);
        }

        if (IsKeyPressed(KEY_P))
        {
            UnloadMusicStream(sound);
            CloseAudioDevice();
            InitAudioDevice();
            musicFilePath = res->getRandomMusic();
            sound = LoadMusicStream(musicFilePath);
            PlayMusicStream(sound);
            SetMusicVolume(sound, 0.3f);
        }

        EndDrawing();
    }

    CloseWindow();
    UnloadMusicStream(sound);
    CloseAudioDevice();

    return 0;
}
