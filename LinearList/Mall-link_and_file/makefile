#常用参数设置
CPP      = g++ 
RM       = rm -f
CPPFLAGS =  -g -s -Wall
# 提取文件名
BIN_TARGET = main
$(BIN_TARGET): main.o product.o  ian_include.o mall_work.o
	$(CPP) $^ -o $(BIN_TARGET) 

main.o : main.cpp mall_work.h ian_include.h
	$(CPP) -c main.cpp -o $@ $(CPPFLAGS)
mall_work.o: mall_work.cpp mall_work.h  product.h
	$(CPP) -c mall_work.cpp -o $@ $(CPPFLAGS)
product.o: product.cpp product.h
	$(CPP) -c product.cpp  -o $@ $(CPPFLAGS)
ian_include.o: ian_include.cpp ian_include.h
	$(CPP) -c ian_include.cpp -o $@ $(CPPFLAGS)
.PHONY: clean 
clean: 
	${RM} $(BIN_TARGET) *.o *.gch
