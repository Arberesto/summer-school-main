#include "./InputController.h"
#include <ncurses.h>
#include <string>
#include <vector>
#include <iterator>
#include "./IoCContainer.h"
#include "./FileManager.h"
InputController::InputController(size_t type, IoCContainer *iocContainer, int newId) {
    setLastKey(32);
    setKeyCodes();
    setLastKeyCode(getLastKey());
    setDirection(-1);
    SetType(type);
    SetId(newId);
}

IObject* InputController::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new InputController(type,  iocContainer, newId);
}
void InputController::setKeyCodes() {
    std::string stringPath = "./src/keys_config.cfg";
    const char *path = stringPath.c_str();
    auto *fileObject = new FileManager(path);
    keyCodes = fileObject->readConfig();
    delete fileObject;
}

int** InputController::getKeyCodes() {
    return keyCodes;
}

void InputController::getKey() {
        setLastKey(getch());
        setLastKeyCode(getLastKey());
        if (getLastKeyCode() != -1) {
            addKeyBuffer(getLastKeyCode());
        }
}

void InputController::symbolInput() {
    getKey();
}

void InputController::setDirection(int keyCode) {
    switch (keyCode) {
        case 1: {
            setAxisY(1);
            setAxisX(0);
            break;
        }
        case 2: {
            setAxisY(-1);
            setAxisX(0);
            break;
        }
        case 3: {
            setAxisY(0);
            setAxisX(-1);
            break;
        }
        case 4: {
            setAxisY(0);
            setAxisX(1);
            break;
        }
        default:
            setAxisY(0);
            setAxisX(0);
            break;
    }
}

int InputController::getAxisY() {
    return axisY;
}

void InputController::setAxisY(int newAxisY) {
    axisY = newAxisY;
}

int InputController::getAxisX() {
    return axisX;
}

void InputController::setAxisX(int newAxisX) {
    axisX = newAxisX;
}

const char* InputController::getLineInput(int consoleRow, int consoleCol, int lineSize) {
    std::string stringLine = "";
    curs_set(1);
    int enteredChar = 32;
    int cursorPointer = 0;  // отображает координаты курсора,насколько возможно
    mvaddch(consoleRow + 2, consoleCol + 43 + cursorPointer - 1, ' ');
    while ((enteredChar != 10) || (stringLine.empty())) {
        enteredChar = getch();
        if (isInList(enteredChar)) {
            if (enteredChar == 263) {
                if (cursorPointer > 0) {
                    stringLine.erase(cursorPointer - 1, 1);
                    mvaddch(consoleRow + 2, consoleCol + 43 + cursorPointer - 1, ' ');
                    cursorPointer--;
                }
                if (cursorPointer == 0) {
                    mvaddch(consoleRow + 2, consoleCol + 43 + cursorPointer - 1, ' ');
                } else {
                    mvaddch(consoleRow + 2, consoleCol + 43 + cursorPointer - 1, stringLine[cursorPointer-1]);
                }
            } else if (cursorPointer < lineSize) {
                stringLine.append(1, static_cast<char>(enteredChar));
                mvaddch(consoleRow + 2, consoleCol + 43 + cursorPointer, enteredChar);
                cursorPointer++;
            }
        }
        // mvwprintw(stdscr, consoleRow + 4, consoleCol + 23, "           ");
        // mvwprintw(stdscr, consoleRow + 4, consoleCol + 10, "Entered name: %s", stringLine.c_str());
    }
    if (static_cast<int>(stringLine.size()) < lineSize) {
        int stringSize = stringLine.size();
        for (int i = 0; i < lineSize - stringSize; i++) {
            stringLine.append(1, ' ');
        }
    }
    curs_set(0);
    return stringLine.c_str();
}

int InputController::getLastKey() {
    return lastKey;
}

void InputController::setLastKey(int newLastKey) {
    lastKey = newLastKey;
}

const char* InputController::getPlayerName(int consoleRow, int consoleCol, int nameSize) {  // Input
    clear();
    mvwprintw(stdscr, consoleRow + 2, consoleCol, "Enter your name(use only a-z,A-Z symbols): ");
    return getLineInput(consoleRow, consoleCol, nameSize);
}

bool InputController::isInList(int checkedChar) {
    return ((checkedChar == 263) || ((checkedChar < 123) && (checkedChar > 96)) ||
            ((checkedChar < 91) && (checkedChar > 64)));
}

int InputController::getLastKeyCode() {
    return lastKeyCode;
}

void InputController::setLastKeyCode(int lastKey) {
    int newLastKeyCode = -1;
    for (int i = 0; i < keyCodes[0][0]; i++) {  // keyCodes[0][0] - количество игровых клавиш
            if (compareKeyCodes(lastKey, i + 1, 2)) {
                newLastKeyCode = i;
        }
    }
    lastKeyCode = newLastKeyCode;
}

bool InputController::compareKeyCodes(int key, int gameKeyIndex, int keyPatternsNumber) {
    for (int i = 0; i < keyPatternsNumber; i++) {
        if (getKeyCode(i, gameKeyIndex) == key) {
            return true;
        }
    }
    return false;
}

int InputController::getKeyCode(int pattern, int index) {
    return keyCodes[pattern][index];
}

void InputController::addKeyBuffer(int key) {
    keyBuffer.insert(keyBuffer.end(), key);
}

int InputController::getFirstKeyFromBuffer() {
    int result = keyBuffer[0];
    keyBuffer.erase(keyBuffer.begin());
    return result;
}

int InputController::getLastKeyFromBuffer() {
    int result = keyBuffer[keyBuffer.size() - 1];
    keyBuffer.erase(keyBuffer.end());
    return result;
}

bool InputController::isInBuffer(int key) {
    for (int i = 0; i <  static_cast<int>(keyBuffer.size()); i++) {
        if (keyBuffer[i] == key) {
            return true;
        }
    }
    return false;
}

std::vector<int> InputController::getKeyBuffer() {
    return keyBuffer;
}

void InputController::clearBuffer() {
    for (int i = 0; i <  static_cast<int>(keyBuffer.size()); i++) {
        keyBuffer.erase(keyBuffer.end());
    }
    setLastKeyCode(32);
}

int InputController::GetId() {
    return id;
}
void InputController::SetId(int newId) {
    id = newId;
}
void InputController::SetType(size_t newType) {
    type = newType;
}
size_t InputController::GetType() {
    return type;
}
bool InputController::IsA(size_t type) {
    return type == typeid(InputController).hash_code();
}
void InputController::Delete() {
}

int InputController::GetCurrentLine() {
    return currentLine;
}

void InputController::SetCurrentLine(int newCurrentLine) {
    currentLine = newCurrentLine;
}

void InputController::ShiftCurrentLine(int upOrDown, int MaxLineSize) {
    if ((upOrDown < 0)&&(currentLine > 0)) {
        currentLine += upOrDown;
    } else if ((upOrDown > 0)&&(currentLine < MaxLineSize - 1)) {
        currentLine += upOrDown;
    }
}