// Mode
void practiceMode(char* ID, int isLogin, int baseballLength);
void multiMode(int baseballLength, char* ID1, char* ID2);
void AiMode(char* ID, int isLogin, int baseballLength, int aiDifficulty);

// Page
void signUpMode(void);
void loginMode(void);
int secondLoginMode(char* secondID, char* currentID);
void rankMode(char* ID, int isLogin, struct rank rank);
void mainMenuMode(char* ID, int isLogin);
void setGameOptionMode(int gameMode, char* ID, int isLogin);
void recordMode(char* ID, int isLogin, int gameMode, int baseballLength, int aiDifficulty);
void helpMode(void);