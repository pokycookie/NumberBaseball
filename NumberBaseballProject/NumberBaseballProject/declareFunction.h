// Basic Function
void getBaseballNumber(int* result, int length);
int getCurrentNumber(int* currentNumber, int length, int option);
void printResult(int strike, int ball, int out, int length);
void storeData(struct rememberedData* storedData, int* currentNumber, int baseballLength, struct resultData currentData, int tryCount);
void printRememberedData(struct rememberedData* storedData, int baseballLength, int tryCount, int player);
int getBaseballLength(void);
int baseballNumberFilter(int* baseballNumber, int baseballLength);
int compareResultData(struct resultData A, struct resultData B);
int compareRankDBAndRank(struct rankDB rankDB, struct rank rank, char* ID);
int getRandomNumber(int min, int max);

int checkNumberInArray(int number, int* arr, int arrLength);
void copyIntArray(int* copiedArray, int copiedArraySize, int* resultArray, int resultArraySize);

int toggleTurn(int turn);
int toInt(char character);
char toChar(int integer);
int power(int x, int y);

struct time convertTimeUnit(int sec);

struct resultData checkData(int* currentNumber, int* baseballNumber, int length);

// AI Function
void getNextNumber(int* result, int possibilityArr[][10], int possibilityCount, int tryCount, int baseballLength);
int getPossibilityArr(int possibilityArr[][10], int possibilityCount, struct rememberedData previousData, int baseballLength, int aiDifficulty, int limit);
int makeAllPossibilityArr(int possibilityArr[][10], int baseballLength);

// Auth Function
void inputID(char* ID);
void inputPW(char* PW);
void updateAuthDB(FILE* AuthDB, char* ID, char* PW);
int authenticateUser(FILE* AuthDB, char* ID, char* PW);
int checkUsedID(FILE* AuthDB, char* ID);

// Rank Function
struct fileName getFileName(struct rank rank);
void setRankDB(FILE* RankDB, struct rank rank);
void updateRankDB(FILE* RankDB, char* ID, struct rank rank);
void printRankBoard(FILE* RankDB, char* ID, struct rank rank, int isLogin);
void updateMulitRankDB(FILE* RankDB, char* ID1, char* ID2, char* winner, struct rank rank);
void printMyRanking(FILE* RankDB, char* ID, struct rank rank);

void findRankDBByID(FILE* RankDB, char* ID, struct rank rank);
struct rankDB findRankDB(FILE* RankDB, char* ID, struct rank rank);

// Design Function
void initialDesign(void);
void setCurser(short x, short y);
void setColor(unsigned short color, unsigned short background);
void cursorView(char show);
void removeOneLine(int line);
void removeArea(int rowStart, int rowEnd, int columnStart, int columnEnd);
int arrowControl(void);
int selectColumnMenu(int x, int y, int count);
int makeGameMenu();

void printLargeNumber(char character, int displayNumber);
int LNX(int displayNumber);

void printGameOption(int gameMode);
int selectGameOption(void);
int selectAiDifficulty(int isGameOption);
int GOX(int displayNumber);

void printGameMode(void);
int selectGameMode(void);
int GMX(int displayNumber);

void printRecordMode(void);

void printGameResult(struct rank rank, char* player1, int* baseballNumber1, char* player2, int* baseballNumber2, char* winner, int isLogin);

void printMainLogo(int x, int y);
void printLogin(void);
void printMode(void);
void printPracticeModeForm(int mode, int aiDifficulty, int baseballLength);
void printSignUpModeForm(void);
void printLoginModeForm(void);
void printOkButton(int x, int y);
int checkNumberInArray(int number, int* arr, int arrLength);
void printRankBoardForm(int mode, int length, int aiDifficulty);
void printUserName(int mode, char* ID1, char* ID2, int isLogin);
void printUserInputArea(int mode, int isMyTurn);
int getInputX(int baseballLength);
void printArrow(int direction);