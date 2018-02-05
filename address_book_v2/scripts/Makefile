CC := gcc
CFLAGS := -Wall -O3
Libs = -lpthread
Target := address_book   #check_putin
Source := $(wildcard src/*.c) #src/check_putin.c
Objs := $(patsubst %.c,%.o,$(Source)) #src/check_putin.o
Modules += creat_link display_link input_infor insert_tail_node welcome input_order main reset search_infor del_infor 
AllObjs := $(addsuffix /src/*.o,$(Modules))
#check_putin/src/*.o pack_message/src/*.o main/src/*.o
