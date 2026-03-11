EXEC = tp9

$(EXEC): main.o
	g++ -o $@ $^

main.o: main.cpp
	g++ -c $< --std=c++20

clean:
	rm -f *.o $(EXEC)