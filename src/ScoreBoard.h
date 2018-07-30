#ifndef ROUGE_DEMO_SCOREBOARD_H
#define ROUGE_DEMO_SCOREBOARD_H
class ScoreBoard {
 public:
    explicit ScoreBoard(int levelNumber, int row, int col);
    void addPlayer(const char* name, int score);
    void setScoreBoard(int levelNumber, int row, int col);
    char** getScoreBoard();
    char getScoreBoardSymbol(int row, int col);
    int whoseScoreChange(int score, int *scoresToCompare);
    int* getScoresToCompare();
    void setScoreRow(int newScoreRow);
    void setScoreCol(int newScoreCol);
    int getScoreRow();
    int getScoreCol();
    int getLevelNumber();
    void setLevelNumber(int newLevelNumber);
 private:
    char** scoreBoard;
    bool isShow;
    int scoreRow;
    int scoreCol;
    int levelNumber;
};
#endif  // ROUGE_DEMO_SCOREBOARD_H
