#include "raylib.h"
#include "src/player/Player.h"

#define MAX_COLUMNS 20

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Simple FPS with raylib!");

    Player player;

    float heights[MAX_COLUMNS] = {0};
    Vector3 positions[MAX_COLUMNS] = {0};
    Color colors[MAX_COLUMNS] = {0};

    for (int i = 0; i < MAX_COLUMNS; i++) {
        heights[i] = (float) GetRandomValue(1, 12);
        positions[i] = (Vector3) {(float) GetRandomValue(-15, 15), heights[i] / 2.0f, (float) GetRandomValue(-15, 15)};
        colors[i] = (Color) {static_cast<unsigned char>(GetRandomValue(20, 255)), static_cast<unsigned char>(GetRandomValue(10, 55)), 30, 255};
    }

    DisableCursor();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        player.Tick();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(player._camera);

        DrawPlane((Vector3) {0.0f, 0.0f, 0.0f}, (Vector2) {32.0f, 32.0f}, LIGHTGRAY); // Draw ground
        DrawCube((Vector3) {-16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
        DrawCube((Vector3) {16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
        DrawCube((Vector3) {0.0f, 2.5f, 16.0f}, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall

        for (int i = 0; i < MAX_COLUMNS; i++) {
            DrawCube(positions[i], 2.0f, heights[i], 2.0f, colors[i]);
            DrawCubeWires(positions[i], 2.0f, heights[i], 2.0f, MAROON);
        }

        EndMode3D();

        player.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}