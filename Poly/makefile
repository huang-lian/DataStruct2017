Target = main
RM = -rm -rf

$(Target): main.o poly.o
	g++ -o $@ $^
main.o: poly.h
poly.o: poly.h
.PHONY: clean
clean:
	$(RM) *.o $(Target)
