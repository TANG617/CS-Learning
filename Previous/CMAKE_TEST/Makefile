# 声明编译器和编译选项
CC = g++
CFLAGS = -Wall -Wextra -std=c++11

# 声明目标文件和源文件
OBJS = main.o lib.o
SRCS = main.cpp lib.cpp

# 声明依赖关系和生成规则
all: myprogram

myprogram: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.cpp lib.h
	$(CC) $(CFLAGS) -c main.cpp

lib.o: lib.cpp lib.h
	$(CC) $(CFLAGS) -c lib.cpp


# 声明清理规则
clean:
	rm -f *.o myprogram
