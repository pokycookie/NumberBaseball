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