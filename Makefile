CC=g++
binlocation=bin/ejdf
includeDirs=src/*.cc src/scenes/*.cc

all:
	mkdir -p bin/
clean:
	rm -f $(binlocation)
mac:
	make all clean	
	$(CC) $(includeDirs) -o $(binlocation) -std=c++1y -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework Cocoa -llua
linux:
	make all clean
	$(CC) $(includeDirs) -o $(binlocation) -std=c++1y -lSDL
win:
	make clean
	mkdir bin/
	$(CC) $(includeDirs) -o $(binlocation) -std=c++1y -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -lmingw32 -lSDL2main -lSDL2
