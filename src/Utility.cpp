#include "./Utility.h"
#include <cmath>
#include <string>

int Pow(int value, int multiplier) {  // Utility
//    int result = 1;
//    for (int i = 0; i < multiplier; i++) {
//        result *= value;
//    }
    int result = static_cast<int>(std::pow(static_cast<double>(value), static_cast<double>(multiplier)));
    return result;
}

int convertCharToInt(char *symbols, int size) {  // Utility
    // возвращает size-разрядное число в массиве-char
    // как int (неиспользуемые разряды равны нулю)
    int result = 0;
    for (int i = 0; i < size; i++) {
        if ((symbols[i] > 47) && (symbols[i] < 58)) {
            result += (symbols[i] - 48) * Pow(10, (size - i - 1));
        }
    }
    return result;
}

int *convertStringToVariables(std::string stringTemp, int size, int variablesSize) {  // Render-Utility
    auto result = new int[size];
    auto intTemp  = new char[variablesSize];
    int j = 0;
    int i = 0;
    int counter = 0;
    bool intFulled = false;
    while (stringTemp[i] != '\n') {
        if ((stringTemp[i] > 47) && (stringTemp[i] < 58)) {
            if (j < variablesSize) {
                intTemp[j] = stringTemp[i];
                intFulled = true;
                j++;
            }
        }

        if (!((stringTemp[i + 1] > 47) && (stringTemp[i + 1] < 58))) {
            if (intFulled) {
                intFulled = false;
                result[counter] = convertCharToInt(intTemp, j);
                j = 0;
                counter++;
            }
        }
        i++;
    }
    return result;
}

void sortByParameter(char** matrix, int* parameters, int rowSize, int colSize) {
    char charTemp;
    int intTemp;
    for (int i = 0; i < rowSize - 1; i++) {
        for (int j = 0; j < rowSize - i - 1; j++) {
            if (parameters[j] < parameters[j + 1]) {
                intTemp = parameters[j];
                parameters[j] = parameters[j + 1];
                parameters[j + 1] = intTemp;
                for (int k = 0; k < colSize; k++) {
                    charTemp = matrix[j][k];
                    matrix[j][k] = matrix[j + 1][k];
                    matrix[j + 1][k] = charTemp;
                }
            }
        }
    }
}