// Basic Function
void getBaseballNumber(int* result, int length);
void getCurrentNumber(int* result, int length, int option);
void printResult(int strike, int ball, int out, int length);
void storeData(struct rememberedData* storedData, int* currentNumber, int baseballLength, struct resultData currentData, int tryCount);
void printRememberedData(struct rememberedData* storedData, int baseballLength, int tryCount, int player);
int getBaseballLength(void);
int baseballNumberFilter(int* baseballNumber, int baseballLength);
int compareResultData(struct resultData A, struct resultData B);
int getRandomNumber(int min, int max);

int checkNumberInArray(int number, int* arr, int arrLength);
void copyIntArray(int* copiedArray, int copiedArraySize, int* resultArray, int resultArraySize);

int toggleTurn(int turn);
int toInt(char character);
char toChar(int integer);

struct resultData checkData(int* currentNumber, int* baseballNumber, int length);

// AI Function
void getNextNumber_prototypeAI(int* result, int possibilityArr[][10], int possibilityCount, int tryCount, int baseballLength);
int getPossibilityArr_prototypeAI(int possibilityArr[][10], int possibilityCount, struct rememberedData previousData, int baseballLength);
int makeAllPossibilityArr(int possibilityArr[][10], int baseballLength);

// Auth Function
void inputID(char* ID);
void inputPW(char* PW);
void updateAuthDB(FILE* AuthDB, char* ID, char* PW);
int authenticateUser(FILE* AuthDB, char* ID, char* PW);
int checkUsedID(FILE* AuthDB, char* ID);

// Design Function
void initialDesign(void);
void setCurser(short x, short y);
void setColor(unsigned short color, unsigned short background);
void cursorView(char show);
void removeOneLine(int line);
void removeArea(int rowStart, int rowEnd, int columnStart, int columnEnd);
int arrowControl(void);
int selectColumnMenu(int x, int y, int count);

void printLargeNumber(char character, int displayNumber);
int LNX(int displayNumber);
void printMainLogo(int x, int y);

void printMainMenu(void);
void printLogin(void);
void printMode(void);
void printHelp(void);
void printBaseballLength(void);
void printFreeBaseballSetting(void);
void printPracticeModeForm(void);
void printSignUpModeForm(void);
void printLoginModeForm(void);