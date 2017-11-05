main.out : test-queue_stack.cpp queue_stack.h
	g++ test-queue_stack.cpp -o $@
.PHONY:clean run test
clean:
	rm -f *.o

run :
	make clean
	make
	./main.out
test:
	make clean
	make
	./main.out < test-data.txt
