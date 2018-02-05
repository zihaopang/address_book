#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_SIZE 100


struct infor
{
    char id[MAX_SIZE];
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
void insert_tail_node(Link *head,Link *newnode);
void save_infor(Link *head,FILE *stream);
void write_in_line();
void passwd_table();
void passwd_judge(FILE *fp);
int read_line(int fd,char *buf,int max_len);
