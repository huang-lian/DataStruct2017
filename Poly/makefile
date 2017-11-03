Target = main
RM = -rm -rf

# 如果遇上编码问题,请取消下一行注释,将输出可执行文件编码设置为gbk
#CPPFLAGS = -fexec-charset=gbk -finput-charset=utf-8 -Wall -O0 -g -s -std=c++11
CPP = g++
$(Target): main.o poly.o
	$(CPP) -o $@ $^ $(CPPFLAGS)
main.o: poly.h
poly.o: poly.h
.PHONY: clean
clean:
	$(RM) *.o $(Target)
