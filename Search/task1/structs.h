typedef struct fmt
{
	char c;
	int *coord;
	struct fmt *parent;
} position;

typedef position *state;

typedef struct linked
{
	state *cur_state;
	struct linked *next;
} path;

typedef struct fmt2
{
	char **arr;
	int row;
	int col;
	int K;
} parsed;

typedef position *(*action)();
typedef position **frontier_;
