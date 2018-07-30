#include "./FileManager.h"
#include <cstdio>
#include "./Utility.h"
FileManager::FileManager(const char *fileName) {
    setFileName(fileName);
}

char** FileManager::read(int row, int col) {
    FILE *file = fopen(getFileName(), "r");
    auto ** result = new char *[row];
    char temp;
    for (int i = 0; i < row; i++) {
        result[i] = new char[col];
        for (int j = 0; j < col; j++) {
            fscanf(file, "%c", &temp);
            result[i][j] = temp;
        }
        fscanf(file, "%c", &temp);
    }
    return result;
}

char** FileManager::readWithParameters(int parametersLineSize, int parametersSize, int parametersNumber) {
    FILE *file = fopen(getFileName(), "r");
    auto *stringTemp = new char[parametersLineSize];
    fgets(stringTemp, parametersLineSize, file);
    auto *variables = convertStringToVariables(stringTemp, parametersNumber, parametersSize);
    // localRow
    // localCol
    // localLevelStepsLimit
    // localCoinValue
    // localCurrentCol
    // localCurrentRow
    auto ** result = new char *[variables[0] + 1];
    result[0] = new char[parametersLineSize];
    for (int i = 0; i< parametersLineSize; i++) {
        result[0][i] = stringTemp[i];
    }
    char temp;
    for (int i = 1; i < variables[0] + 1; i++) {
        result[i] = new char[variables[1]];
        for (int j = 0; j < variables[1]; j++) {
            fscanf(file, "%c", &temp);
            result[i][j] = temp;
        }
        fscanf(file, "%c", &temp);
    }
    // delete variables;
    fclose(file);
    return result;
}

int** FileManager::readConfig() {
//    FILE *file = fopen(getFileName(), "r");
//    auto *stringTemp = new char[10];
//    char temp;
//    fgets(stringTemp, 10, file);
//    auto *variables = convertStringToVariables(stringTemp, 3, 2);
//    auto **readFile = new int*[variables[0]];
//    auto **result = new int*[variables[2]];
//    for (int i = 0; i < variables[0]; i++) {
//        readFile[i] = new int[variables[1]];
//        for (int j = 0; j < variables[1]; j++) {
//            fscanf(file, "%c", &temp);
//            readFile[i][j] = temp;
//        }
//        fscanf(file, "%c", &temp);
//    }
//    for (int i = 0; i < variables[2]; i++) {
//        result[i] = new int[variables[0] + 1];
//        for (int j = 1; j < variables[0] + 1; j++) {
//            if(readFile[i][0] == i)
//            result[i][j] = readFile[i][j];
//        }
//    }
//    result[0][0] = variables[0];
//    fclose(file);
    auto **result = new int*[2];
    for (int i = 0; i < 2; i++) {
        result[i] = new int[6 + 1];
    }
    result[0][0] = 6;
    result[1][0] = -1;
    result[0][1] = 113;
    result[1][1] = 81;
    result[1][6] = 10;
    for (int i = 2; i < 5 + 1; i++) {
        result[0][i] = 256 + i;
        result[1][i] = 256 + i;
    }
    return result;
}


void FileManager::setFileName(const char *newFileName) {
    fileName = newFileName;
}

const char* FileManager::getFileName() {
    return  fileName;
}

void FileManager::write(int matrixRow, int matrixCol, char** matrix) {
    FILE *file = fopen(getFileName(), "w");
    for (int i = 0; i < matrixRow; i++) {
        for (int j = 0; j < matrixCol; j++) {
            char temp = matrix[i][j];
            fprintf(file, "%c" , temp);
        }
        fprintf(file, "%c" , '\n');
    }
    fclose(file);
}
void FileManager::write(int matrixRow, int matrixCol, char** matrix,
                        char* parametersLine, int parametersSize) {
}
