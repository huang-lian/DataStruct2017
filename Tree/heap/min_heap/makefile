TARGET = main.out
OBJS = main.o
INC =../include
vpath %.h ../include/
vpath %.o ../obj/
vpath %,cpp ../src/:

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
.PHONY: clean run test
clean:
	@set -e; $(RM) $(TARGET) $(OBJS) *.d
run :
	@set -e; make; \
	./$(TARGET);\
	make clean
test :
	@set -e; make; \
	./$(TARGET) < test.txt;\
	make clean
