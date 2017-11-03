Target = main
RM = -rm -rf

CPPFLAGS = -fexec-charset=gbk -finput-charset=utf-8 -Wall -O0 -g -s -std=c++11
CPP = g++
$(Target): main.o poly.o
	$(CPP) -o $@ $^ $(CPPFLAGS)
main.o: poly.h
poly.o: poly.h
.PHONY: clean
clean:
	$(RM) *.o $(Target)
