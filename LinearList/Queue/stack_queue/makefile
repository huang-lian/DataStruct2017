main.out : test-stack_queue.cpp stack_queue.h 
	g++ -o main.out test-stack_queue.cpp
.PHONY:run clean test
run :
	make
	./main.out
clean:
	rm -f *.out *.gch
test:
	make
	./main.out < test-data.txt

