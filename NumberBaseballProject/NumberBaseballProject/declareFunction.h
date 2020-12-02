// Basic Function
void getBaseballNumber(int* result, int length);
void getCurrentNumber(int* result, int length);
void printResult(int strike, int ball, int out, int length);
void storeData(struct rememberedData* storedData, int* currentNumber, int baseballLength, struct resultData currentData, int tryCount);
void printRememberedData(struct rememberedData* storedData, int baseballLength, int tryCount);

int getBaseballLength(void);
int toInt(char character);

struct resultData checkData(int* currentNumber, int* baseballNumber, int length);

// Design Function
void initialDesign(void);
void setCurser(short x, short y);
void cursorView(char show);
void removeOneLine(int line);
int arrowControl(void);
int selectColumnMenu(int x, int y, int count);

void printMainMenu(void);
void printLogin(void);
void printMode(void);
void printHelp(void);
void printBaseballLength(void);
void printFreeBaseballLength(void);
void printPracticeModeForm(void);