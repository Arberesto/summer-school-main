#include "./Player.h"
Player::Player(int row, int col, int speed, char symbol) {
    setIsMoving(true);
    setPlayerSpeed(speed);
    setSymbol(symbol);
    setPositionY(row);
    setPositionX(col);
}

void Player::setPlayerSpeed(int newPlayerSpeed) {
    playerSpeed = newPlayerSpeed;
}

int Player::getPlayerSpeed() {
    return playerSpeed;
}

void Player::setIsMoving(bool newIsMoving) {
    isMoving = newIsMoving;
}

bool Player::getIsMoving() {
    return isMoving;
}

void Player::setSymbol(char newSymbol) {
    symbol = newSymbol;
}

char Player::getSymbol() {
    return symbol;
}

int Player::getPositionY() {
    return positionY;
}

void Player::setPositionY(int newPositionY) {
    positionY = newPositionY;
}

int Player::getPositionX() {
    return positionX;
}

void Player::setPositionX(int newPositionX) {
    positionX = newPositionX;
}