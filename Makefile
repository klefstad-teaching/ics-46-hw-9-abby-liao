F = -std=c++20 -Wall -Wextra -Wpedantic -Wfatal-errors
P = dijkstras
Z = ICS46_hw9.zip

SRC = src/dijkstras.cpp src/dijkstras_main.cpp
HEADERS = src/dijkstras.h

all: $(P)

$(P): $(SRC) $(HEADERS)
	g++ $(F) $(SRC) -o $(P)

clean:
	/bin/rm -f $(P) $(Z)

zip: clean
	zip $(Z) Makefile src/dijkstras_main.cpp src/dijkstras.h src/dijkstras.cpp src/small.txt src/medium.txt src/large.txt src/largest.txt

run: $(P)
	./$(P)


