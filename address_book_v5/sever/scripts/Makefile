CC := gcc
CFLAGS := -Wall -O3 -lsqlite3
Libs = -lpthread
Target := server   #check_putin
Source := $(wildcard src/*.c) #src/check_putin.c
Objs := $(patsubst %.c,%.o,$(Source)) #src/check_putin.o
Modules += display_judge insert_judge log_judge search_judge delete_judge login_judge tcp_server
AllObjs := $(addsuffix /src/*.o,$(Modules))
#check_putin/src/*.o pack_message/src/*.o main/src/*.o
