// Mode
int practiceMode(char* ID); // Return 0: Game End, 1: Back
int multiMode(void); // Return 0: Game End, 1: Back
int AiMode(char* ID); // Return 0: Game End, 1: Back

// Page
void signUpMode(void);
void loginMode(void);
void rankMode(char* ID, struct rank rank);
int mainMenuMode(char* ID, int isLogin);