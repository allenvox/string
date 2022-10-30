all: main
.PHONY: main
main: main.cpp string.cpp
	g++ -Wall -Wextra -o $@ $^

clean:
	rm -rf *.o main