# 指令编译器和选项  
CC=gcc  
CFLAGS=-Wall 
LIBS=-lm
  
# 目标文件  
TARGET=Main
SRCS = $(wildcard *.c)    #当前文件夹下面的所有.c文件

# 依赖目标  
OBJS =$(SRCS:.c=.o)            #

$(TARGET):$(OBJS)  
# @echo TARGET:$(OBJS)  
# @echo OBJECTS:$^  
	$(CC) -o $@ $^ $(LIBS)    #$@指目标文件，这里是hellomake,$^指所有依赖文件，这里指hellofunc.o,hellomake.o

clean:  
	rm -rf $(TARGET) $(OBJS)  

%.o:%.c  
	$(CC) $(CFLAGS) -o $@ -c $<   #$<指第一个依赖文件此处以此为Main.c





# all:Main
# Main:Main.c
# 	gcc -g $^ -o $@ 
# SeqListTest:SeqListTest.o
# 	gcc -g $^ -o $@ 
# SeqListTest.o:
# 	gcc -g -c $< -o $@
# SeqList:SeqList.o
# 	gcc -g $^ -o $@
# SeqList.o:SeqList.h
# 	gcc -g -c $< -o $@	  
# clear:
# 	rm -f Main
