CC=g++
binlocation=bin/ejdf

all:
	mkdir -p bin/
clean:
	rm -f $(binlocation)
mac:
	make all clean
	$(CC) src/*.cc src/scenes/*.cc -o $(binlocation) -std=c++1y -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework Cocoa -llua
linux:
	make all clean
	$(CC) src/*.cc src/scenes/*.cc -o $(binlocation) -std=c++1y -lSDL
win:
	make all clean
	$(CC) src/*.cc src/scenes/*.cc -o $(binlocation) -std=c++1y -lSDL
