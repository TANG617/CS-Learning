# Makefile 示例

# 编译器
CC = g++

# 编译选项
CFLAGS = -Wall -std=c++11

# 源文件
SOURCES = main.cpp Node.cpp NodeList.cpp

# 目标文件
TARGET = NodeList.out

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
