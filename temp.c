#define SIZE 15
#define CHARSIZE 2
#define MAX 1000

#define PLAY1CURREENT 3 // no zero
#define PLAY2CURREENT 4
#define PLAY1 1
#define PLAY2 2


struct singleInfo{
    int linkNum;
    int oppNum;
};

struct singleScore{
    struct singleInfo info[4];
    int score;
};

struct singleScore myBoardScore[15][15];