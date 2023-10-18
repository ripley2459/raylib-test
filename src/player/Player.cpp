#include "Player.h"

Player::Player() {
    _camera.position = (Vector3) {0.0f, 2.0f, 4.0f};
    _camera.target = (Vector3) {0.0f, 2.0f, 0.0f};
    _camera.up = (Vector3) {0.0f, 1.0f, 0.0f};
    _camera.fovy = 60.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
    SetCameraMode(_camera, CAMERA_FIRST_PERSON);
}

void Player::Tick() {
    UpdateCamera(&_camera);
}

void Player::DrawGUI() {
    DrawRectangle(5, 5, 330, 100, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines(5, 5, 330, 100, BLUE);

    DrawText("Camera controls:", 15, 15, 10, BLACK);
    DrawText(" - Move keys: W, A, S, D, Space, Left-Ctrl", 15, 30, 10, BLACK);
    DrawText(" - Look around: arrow keys or mouse", 15, 45, 10, BLACK);
    DrawText(" - Camera mode keys: 1, 2, 3, 4", 15, 60, 10, BLACK);
    DrawText(" - Zoom keys: num-plus, num-minus or mouse scroll", 15, 75, 10, BLACK);
    DrawText(" - Camera projection key: P", 15, 90, 10, BLACK);

    DrawRectangle(600, 5, 195, 100, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines(600, 5, 195, 100, BLUE);

    DrawText("Camera status:", 610, 15, 10, BLACK);
    DrawText(TextFormat(" - Position: (%06.3f, %06.3f, %06.3f)", _camera.position.x, _camera.position.y, _camera.position.z), 610, 60, 10, BLACK);
    DrawText(TextFormat(" - Target: (%06.3f, %06.3f, %06.3f)", _camera.target.x, _camera.target.y, _camera.target.z), 610, 75, 10, BLACK);
    DrawText(TextFormat(" - Up: (%06.3f, %06.3f, %06.3f)", _camera.up.x, _camera.up.y, _camera.up.z), 610, 90, 10, BLACK);
}
