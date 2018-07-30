#ifndef ROUGE_DEMO_FILEMANAGER_H
#define ROUGE_DEMO_FILEMANAGER_H
class FileManager {
 public:
    explicit FileManager(const char *fileName);
    char**  read(int row, int col);
    char** readWithParameters(int parametersLineSize, int parametersSize, int parametersNumber);
    void write(int matrixRow, int matrixCol, char** matrix);
    void write(int matrixRow, int matrixCol, char** matrix, char* parametersLine, int parametersSize);
    void setFileName(const char *newFileName);
    const char* getFileName();
    int** readConfig();
 private:
    const char* fileName;
};
#endif  // ROUGE_DEMO_FILEMANAGER_H
