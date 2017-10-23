#常用参数设置
CPP      = g++ 
RM       = rm -f
CPPFLAGS =  -I  -g -Wall -std=c++11

# 提取文件名
BIN_TARGET = main
$(BIN_TARGET): main.o product.o mall.o ian_include.o
	$(CPP) $^ -o $(BIN_TARGET) 

main.o : main.cpp mall.h ian_include.h
	$(CPP) -c main.cpp -o $@ $(CPPFLAGS)
mall.o: mall.cpp product.h ian_include.h mall.h
	$(CPP) -c mall.cpp -o $@ $(CPPFLAGS)
product.o: product.cpp product.h
	$(CPP) -c product.cpp  -o $@ $(CPPFLAGS)
ian_include.o: ian_include.cpp ian_include.h
	$(CPP) -c ian_include.cpp
.PHONY: clean 
clean: 
	${RM} $(BIN_TARGET) *.o *.gch
