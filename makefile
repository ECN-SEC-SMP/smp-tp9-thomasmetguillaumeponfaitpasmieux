EXEC = tp9

$(EXEC): main.o csv.o
	g++ -o $@ $^

main.o: main.cpp
	g++ -c $< --std=c++20

csv.o: csv.cpp csv.h
	g++ -c $< --std=c++20

clean:
	rm -f *.o $(EXEC)