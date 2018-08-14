#ifndef ROUGE_DEMO_LEVELMANAGER_H
#define ROUGE_DEMO_LEVELMANAGER_H
#include "./IoCContainer.h"
struct Level{
    int levelNumber;
    int row_size;        // размерности текущего уровня
    int col_size;
    double prevSeconds;
    double secondsUsed;
};
class LevelManager : public IObject{
 public:
    explicit LevelManager(IoCContainer* container, int newId);
    void loadLevel(IoCContainer* container, int level);
    void setStructLevel(int *variables, int levelNumber);
    int getLevelNumber();
    void setLevelNumber(int newLevelNumber);
    void setSizeRow(int newSizeRow);
    int getSizeRow();
    void setSizeCol(int newSizeCol);
    int getSizeCol();
    void setSecondsUsed(double newSecondsUsed);
    double getSecondsUsed();
    void IncreaseSecondsUsed(double newSecondsUsed);
    double getPrevSeconds();
    void setPrevSeconds(double newPrevSeconds);
    size_t ConvertTileToObject(IoCContainer* container, char tile);
    //  bool nextLevel();
    void setTickCounter(int newTickCounter);
    int getTickCounter();
    void IncreaseTickCounter(int newTickCounter);
    void setLastSecond(int newLastSecond);
    int getLastSecond();
    int GetId();
    void SetId(int newId);
    size_t GetType();
    void SetType(size_t newType);
    void SetIsNewSecondNow(bool newIsNewSecondNow);
    bool GetIsNewSecondNow();
    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type);
    void Delete();
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);

 private:
    bool isNewSecondNow = true;
    const int START_LEVEL = 1;
    Level level;
    int lastSecond;
    int tickCounter;
};
#endif  // ROUGE_DEMO_LEVELMANAGER_H
