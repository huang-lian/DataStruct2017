Target = main
RM = -rm -rf

CPPFLAGS = -fexec-charset=utf-8 -Wall -O1 -g  -std=c++11
CPP = g++

$(Target): main.o expr.o
	$(CPP) -o $@ $^ $(CPPFLAGS)	
main.o: expr.h
expr.o: expr.h link_stack.h
.PHONY: clean 
clean:
	$(RM) $(Target) *.exe *.o *.gch *.out

run:
	make clean
	make
	./$(Target)
