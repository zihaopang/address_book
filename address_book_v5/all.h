#include <stdlib.h> 
#include <unistd.h>
#include <stdio.h> 
#include <errno.h> 
#include <string.h>
#include <sys/socket.h>
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sqlite3.h>
#include <string.h>

#define MAX_SIZE 100
#define portnumber 3333
#define PASSWD_ERROR -1
#define PASSWD_RIGHT 1
#define LOG 20
#define LOGIN 21
#define LOG_SUCCESS 2
#define LOG_FAIL 18
#define LOGIN_SUCCESS 4
#define LOGIN_FAIL 5
#define INSERT 6
#define LIST 7
#define DELETE 8
#define SEARCH 9
#define INSERT_SUCCESS 10
#define INSERT_FAIL 11
#define DELETE_SUCCESS 12
#define DELETE_FAIL 13
#define LIST_SUCCESS 14
#define LIST_FAIL 15
#define INFOR_ACTION 17
#define ERROR 19
#define INFOR_PATH "/home/address_book/sever/infor.db"
#define PASS_INFOR person.user_name,person.user_passwd
#define PASSWD_PATH "/home/address_book/sever/passwd.db"
#define BASIC_INFOR person.id,person.name,person.tel,person.addr

int display();
int insert();
int passwd_judge();
void reset();
int search();
void welcome();
int delete_infor();
int input_order();
int passwd_table();
int main(int argc, char *argv[]); 
int login_judge(sqlite3 *passwd_db,int new_fd);
int log_judge(sqlite3 *passwd_db,int new_fd);
int insert_judge(sqlite3 *save_db,int new_fd); 
int display_judge(sqlite3 *save_db,int new_fd);
int delete_judge(sqlite3 *save_db,int new_fd);
int search_judge(sqlite3 *save_db,int new_fd);

struct infor
{
    int id;
    int flag;
    int list_row;
    int list_flag;
    int delete_num;
    int delete_row;
    int search_row;
    int list_column;
    int delete_flag;
    int search_flag;
    int delete_count;
    int delete_column;
    char name[MAX_SIZE];
    char tel[MAX_SIZE];
    char addr[MAX_SIZE];
    char user_name[MAX_SIZE];
    char user_passwd[MAX_SIZE];
};

