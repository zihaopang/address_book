CC := gcc
CFLAGS := -Wall -O3
Libs = -lpthread
Target := client   #check_putin
Source := $(wildcard src/*.c) #src/check_putin.c
Objs := $(patsubst %.c,%.o,$(Source)) #src/check_putin.o
Modules += tcp_client delete display input_order insert passwd reset search welcome 
AllObjs := $(addsuffix /src/*.o,$(Modules))
#check_putin/src/*.o pack_message/src/*.o main/src/*.o
