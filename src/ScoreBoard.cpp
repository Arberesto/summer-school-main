#include "./ScoreBoard.h"
#include <string>
#include "./FileManager.h"
#include "./Utility.h"
ScoreBoard::ScoreBoard(int levelNumber, int row, int col) {
    setScoreBoard(levelNumber, row, col);
}

char ScoreBoard::getScoreBoardSymbol(int row, int col) {
    return scoreBoard[row][col];
}

int  ScoreBoard::getLevelNumber() {
    return levelNumber;
}

void  ScoreBoard::setLevelNumber(int newLevelNumber) {
    levelNumber = newLevelNumber;
}

void ScoreBoard::addPlayer(const char* name, int score) {
    int changedLine = whoseScoreChange(score, getScoresToCompare());
    std::string scoreTemp = std::to_string(score);
    if (changedLine != -1) {
        for (int i = 0; i < getScoreCol() - 3; i++) {
            char temp = name[i];
            scoreBoard[changedLine][i] = temp;
        }
        for (int i = getScoreCol() - 1; i > getScoreCol() - static_cast<int>(scoreTemp.size()) - 1; i--) {
            char temp = scoreTemp[i - getScoreCol() + 2];
            scoreBoard[changedLine][i] = temp;
        }
        for (int i = 0; i < 3 - static_cast<int>(scoreTemp.size()); i++) {
            scoreBoard[changedLine][getScoreCol() - 3 + i] = '0';
        }
        std::string stringPath = "./src/scores/1-";
        std::string fullPath = stringPath + std::to_string(getLevelNumber());
        const char *path = fullPath.c_str();
        auto *fileObject = new FileManager(path);
        fileObject->write(getScoreRow(), getScoreCol(), getScoreBoard());
    }
}

void ScoreBoard::setScoreBoard(int levelNumber, int rowSize, int colSize) {
    std::string stringPath = "./src/scores/1-";
    std::string fullPath = stringPath + std::to_string(levelNumber);
    const char *path = fullPath.c_str();
    auto *fileObject = new FileManager(path);
    scoreBoard = fileObject->read(rowSize, colSize);
    setScoreRow(rowSize);
    setScoreCol(colSize);
    setLevelNumber(levelNumber);
    // delete fileObject;
}

char** ScoreBoard::getScoreBoard() {
    return scoreBoard;
}

void ScoreBoard::setScoreRow(int newScoreRow) {
    scoreRow = newScoreRow;
}

int ScoreBoard::getScoreRow() {
    return scoreRow;
}

int ScoreBoard::getScoreCol() {
    return scoreCol;
}

int* ScoreBoard::getScoresToCompare() {
    auto *scoresToCompare = new int[getScoreRow()];
    auto *scoreTemp = new char[3]{' ', ' ', ' '};
    for (int i = 0; i < getScoreRow(); i++) {
        // name(10),score(3),/n(1)
        for (int j = 10; j < getScoreCol(); j++) {
            scoreTemp[j - 10] = getScoreBoardSymbol(i, j);
        }
        scoresToCompare[i] = convertCharToInt(scoreTemp, 3);
    }
    // delete scoreTemp;
    // Сортировка массива пузырьком
    sortByParameter(getScoreBoard(), scoresToCompare,
                    getScoreRow(), getScoreCol());
    //
    return scoresToCompare;
}


void ScoreBoard::setScoreCol(int newScoreCol) {
    scoreCol = newScoreCol;
}

int ScoreBoard::whoseScoreChange(int score, int *scoresToCompare) {  // Смотрим, перебили ли мы чей-то рекорд
    int index = -1;
    int minScore = 999;
    for (int i = 0; i < 10; i++) {
        if ((score > scoresToCompare[i]) &&
            (scoresToCompare[i] < minScore)) {  // ищем запись с самым малым количеством секунд
            index = i;
            minScore = scoresToCompare[i];
        }
    }
    return index;
}
