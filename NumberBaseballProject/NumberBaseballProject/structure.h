#include <time.h>

struct resultData {
	int strike;
	int ball;
	int out;
};

struct rememberedData {
	int baseballNumber[10];
	struct resultData resultData;
};

struct auth {
	char ID[10];
	char PW[15];
};

struct player {
	int baseballNumber[10];
	int currentNumber[10];
	int tryCount;
	struct resultData checkedData;
	struct rememberedData rememberedData[30];
};

struct AI {
	int baseballNumber[10];
	int currentNumber[10];
	int tryCount;
	int possibilityArr[3628800][10]; // 10! = 3628800
	int possibilityCount;
	struct rememberedData previousData;
	struct rememberedData rememberedData[30];
};

struct time {
	int minute;
	int second;
};

struct fileName {
	char fileName[25];
};

// Rank Information
struct rank {
	int mode; // 1: Single, 2: Multi, 3: A.I
	int baseballLength;
	int aiDifficulty; // 0: NULL 1: Easy, 2: Normal, 3: Hard, 4: Extream

	int tryCount;
	struct time recordTime;
	struct tm realTime;
};

// Rank DB Contents
struct rankDB {
	char ID[10];
	int ranking;
	int tryCount;
	int recordMin;
	int recordSec;
	int realYear;
	int realMonth;
	int realDate;
	int realHour;
	int realMin;
	int realSec;
};