#ifndef ROUGE_DEMO_PLAYER_H
#define ROUGE_DEMO_PLAYER_H
class Player {
 public:
    explicit Player(int row, int col, int speed, char symbol);
    void setPlayerSpeed(int newPlayerSpeed);
    int getPlayerSpeed();
    void setIsMoving(bool newIsMoving);
    bool getIsMoving();
    void setSymbol(char newSymbol);
    char getSymbol();
    int getPositionY();
    void setPositionY(int newPositionY);
    int getPositionX();
    void setPositionX(int newPositionX);

 private:
    int playerSpeed = 10;  // раз в сколько тиков движется
    bool isMoving = true;
    int positionX;
    int positionY;
    char symbol = '@';
};
#endif  // ROUGE_DEMO_PLAYER_H
