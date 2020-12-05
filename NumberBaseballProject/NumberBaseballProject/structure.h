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