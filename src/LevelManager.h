#ifndef ROUGE_DEMO_LEVELMANAGER_H
#define ROUGE_DEMO_LEVELMANAGER_H
#include "./Player.h"
#include "./IoCContainer.h"
struct Level{
    int current_row;      // текущие координаты персонажа
    int current_col;
    int levelNumber;
    int row_size;        // размерности текущего уровня
    int col_size;
    double levelSecondsLimit;  // шагов дано на уровне
    int coinValue;        // количество шагов,которые дает монетка
    int coinCount;
    double prevSeconds;
    double secondsUsed;
    char **Map;
};
class LevelManager : public IObject{
 public:
    explicit LevelManager(int newId);
    char **getMap();
    void loadLevel(int level);
    Level getStructLevel();
    void setStructLevel(int *variables, int levelNumber);
    int getLevelNumber();
    void setLevelNumber(int newLevelNumber);
    double getLevelSecondsLimit();
    void setLevelSecondsLimit(double newLevelSecondsLimit);
    void setCoinValue(int newCoinValue);
    int getCoinValue();
    void setMapSymbol(int row, int col, char symbol);
    char getMapSymbol(int row, int col);
    void setSizeRow(int newSizeRow);
    int getSizeRow();
    void setSizeCol(int newSizeCol);
    int getSizeCol();
    void setPlayerRow(int newPlayerRow);
    int getPlayerRow();
    void setPlayerCol(int newPlayerCol);
    int getPlayerCol();
    void setSecondsUsed(double newSecondsUsed);
    double getSecondsUsed();
    void setCoinCount(int newCoinCount);
    int getCoinCount();
    double getPrevSeconds();
    void setPrevSeconds(double newPrevSeconds);
    bool nextLevel();
    void DeclarePlayerMovement(int rowDirection, int colDirection);
    void setTickCounter(int newTickCounter);
    int getTickCounter();
    Player* getPlayer();
    void setLastSecond(int newLastSecond);
    int getLastSecond();
    int GetId();
    void SetId(int newId);
    bool IsA(size_t type);
    char GetSymbol();
    void Delete();
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);

 private:
    const int START_LEVEL = 1;
    Level level;
    int lastSecond;
    int tickCounter;
    Player* player;
};
#endif  // ROUGE_DEMO_LEVELMANAGER_H
