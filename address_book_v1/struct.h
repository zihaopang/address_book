#define MAX_SIZE 100

struct infor
{
    int id;
    char name[MAX_SIZE];
    char tele[MAX_SIZE];
    char address[MAX_SIZE];

    struct infor *prior;
    struct infor *next;
};

typedef struct infor Infor;
typedef Infor * Link;
