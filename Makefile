all: main
.PHONY: main
main: main.cpp string.cpp
	g++ -fno-rtti -Wall -Wextra -o $@ $^

clean:
	rm -rf *.o main