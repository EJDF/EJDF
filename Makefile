CC=g++
binlocation=bin/ejdf
includeDirs=src/*.cc src/scenes/*.cc

# the ARGS variable is defined at runtime using ARGS="" syntax.
# ARGS are used for stuff liked defining compiler macros.

all:
	mkdir -p bin/
clean:
	rm -f $(binlocation)
mac:
	make all clean
	$(CC) ${ARGS} $(includeDirs) -o $(binlocation) -std=c++1y -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework Cocoa -llua
linux:
	make all clean
	$(CC) $(includeDirs) -o $(binlocation) -std=c++1y -lSDL
win:
	make clean
	mkdir bin/
	$(CC) $(includeDirs) -o $(binlocation) -std=c++1y -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -lmingw32 -lSDL2main -lSDL2
