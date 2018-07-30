#ifndef ROUGE_DEMO_INPUTCONTROLLER_H
#define ROUGE_DEMO_INPUTCONTROLLER_H
#include <vector>
class InputController {
 public:
    explicit InputController();
    void getKey();
    int getLastKey();
    void setLastKey(int newLastKey);
    void symbolInput();
    const char* getLineInput(int consoleRow, int consoleCol, int lineSize);
    const char* getPlayerName(int consoleRow, int consoleCol, int nameSize);
    bool isInList(int checkedChar);
    int getAxisY();
    void setAxisY(int newAxisY);
    int getAxisX();
    void setAxisX(int newAxisX);
    void setLastKeyCode(int lastKey);
    int getLastKeyCode();
    void setDirection(int keyCode);
    void setKeyCodes();
    int** getKeyCodes();
    int getFirstKeyFromBuffer();
    int getLastKeyFromBuffer();
    void addKeyBuffer(int key);
    std::vector<int> getKeyBuffer();
    void clearBuffer();
    bool isInBuffer(int key);
    int getKeyCode(int pattern, int index);
    bool compareKeyCodes(int key, int gameKeyIndex, int keyPatternsNumber);

 private:
    int lastKey = 32;
    int lastKeyCode = -1;  // 1-4 - arrows, 0 - exit
    int axisY = 0;
    int axisX = 0;
    int **keyCodes;
    std::vector<int> keyBuffer;  // буффер нажатых клавиш
};
#endif  // ROUGE_DEMO_INPUTCONTROLLER_H
