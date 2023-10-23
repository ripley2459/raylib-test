#include "Player.h"

class Bar;

Player::Player() {
    _camera.position = (Vector3) {0.0f, 2.0f, 4.0f};
    _camera.target = (Vector3) {0.0f, 2.0f, 0.0f};
    _camera.up = (Vector3) {0.0f, 1.0f, 0.0f};
    _camera.fovy = 60.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
    SetCameraMode(_camera, CAMERA_FIRST_PERSON);

    _maxExp = 1000;
    _maxLife = 100;
    _life = _maxLife;
    _exp = _maxExp;
    _lifeBar.Draw(_life, _maxLife);
    _expBar.Draw(_exp, _maxExp);
}

void Player::Tick() {
    UpdateCamera(&_camera);
    UpdateLife();
}

void Player::UpdateLife() {
    _life--;
    _exp++;
    if (_life < 0) _life = _maxLife;
    if (_exp > _maxExp) _exp = 0;
}

void Player::Draw() {
    _lifeBar.Draw(_life, _maxLife);
    _expBar.Draw(_exp, _maxExp);
}
