TARGET = main.out
OBJS = main.o expr.o ian.o
INC =./include
VPATH = src:include

CPP = g++
CPPFLAGS = -fexec-charset=utf-8 -Wall -O1 -g  -std=c++11 -I $(INC)
$(TARGET): $(OBJS)
	$(CPP) $^ -o $@ $(CPPFLAGS)
	$(RM) $(OBJS) *.d
%.d : %.cpp
	@set -e; $(RM) $@; \
	  $(CPP) -MM $< $(CPPFLAGS) > $@.$$$$; \
	  sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	  $(RM) $@.$$$$
-include $(OBJS:.o=.d)
.PHONY: clean run
clean:
	@set -e; $(RM) $(TARGET) $(OBJS) *.d
run :
	@set -e; make; \
	  $(RM) $(OBJS) *.d
	./$(TARGET)
