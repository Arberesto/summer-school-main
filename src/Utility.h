#ifndef ROUGE_DEMO_UTILITY_H
#define ROUGE_DEMO_UTILITY_H

int *convertStringToVariables(const char *stringTemp, int size, int variablesSize);
int convertCharToInt(char *symbols, int size);
char *convertIntToChar(int value, int constSize);
int Pow(int value, int multiplier);
bool isInList(int checkedChar);
// void sort(char** matrix, char* parameters, int rowSize,int colSize);
void sortByParameter(char** matrix, int* parameters, int rowSize, int colSize);
#endif  // ROUGE_DEMO_UTILITY_H
