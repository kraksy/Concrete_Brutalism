//
// Created by kraks on 04/08/2024.
//

#include <iostream>
#include <raylib.h>

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 1200

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "smolgame");

    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 2.0f, 4.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    Model map = LoadModel("C:\\Users\\kraks\\Desktop\\smolgame\\resources\\base.obj");
    Texture2D texture = LoadTexture("C:\\Users\\kraks\\Desktop\\smolgame\\resources\\texture.png");
    map.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    Vector3 pos = {0.0f, 0.0f, 0.0f};

    if (map.meshes == NULL) {
        TraceLog(LOG_ERROR, "Failed to load model: %s", "resources/map.obj");
        CloseWindow();
        return -1;
    }

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        Vector3 movement = {
                (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) * 0.1f -
                (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) * 0.1f,
                (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) * 0.1f -
                (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) * 0.1f,
                0.0f
        };
        Vector3 rotation = {
                GetMouseDelta().x * 0.05f,
                GetMouseDelta().y * 0.05f,
                0.0f
        };
        float zoom = GetMouseWheelMove() * 2.0f;
        UpdateCameraPro(&camera, movement, rotation, zoom);
        DisableCursor();


        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
            DrawModel(map, pos, 1.0f, WHITE);
            DrawGrid(10, 10.0f);
            EndMode3D();
        EndDrawing();
    }
    UnloadTexture(texture);
    UnloadModel(map);
    CloseWindow();
    return 0;
}