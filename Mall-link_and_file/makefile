# 以下makefile是目前能够理解的全部 
# 2017年5月17日 14:34:38
# by huang_lian@foxmail.com
#
#文件目标设置
BIN = ./
SRC = ./
INC = ./
OBJ = ./
TARGET =main

#常用参数设置
CPP      = g++ 
RM       = rm -f
CPPFLAGS =  -I $(INC) -g -Wall -std=c++11

# 提取文件名
BIN_TARGET = $(BIN)/$(TARGET)
SOURCE = $(wildcard $(SRC)/*.cpp)
OBJECT = $(patsubst %.cpp,$(OBJ)/%.o,$(notdir $(SOURCE)))

# 生成目标文件
# $^ 表示去重的全体依赖项
$(BIN_TARGET): $(OBJECT)
	$(CPP) $^ -o $(BIN_TARGET) 

# 生成中间文件
# %文件通配符，依赖项的每一个%都与目标中的对应
# $<依赖目标中的第一个，此时与模式中的每一个%对应
$(OBJ)/%.o : $(SRC)/%.cpp
	$(CPP) -c $< -o $@ $(CPPFLAGS)

.PHONY: clean 
clean: 
	${RM} $(OBJECT) $(BIN_TARGET)
