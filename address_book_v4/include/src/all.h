#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sqlite3.h>

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

void input_order();
void display_link(Link *head);
void search_infor(Link *head);
void creat_link(Link *head);
void welcome();
void reset();
int del_infor(Link *head);
void input_infor();
void save_infor(Link *head);
void passwd_judge(sqlite3 *db_passwd);
void passwd_table();
void write_in_line(Link *head);
void insert_tail_node(Link *head,Link *newnode);
