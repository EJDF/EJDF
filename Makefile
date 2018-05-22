CC=g++
outdir=bin/ejdf

all:
	mkdir bin/
clean:
	rm $(outdir)


mac:
	$(CC) src/*.cc src/scenes/*.cc -o $(outdir) -std=c++1y -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -framework Cocoa -llua
linux:
	$(CC) src/*.cc src/scenes/*.cc -o $(outdir) -std=c++1y -lSDL
win:
	$(CC) src/*.cc src/scenes/*.cc -o $(outdir) -std=c++1y -lSDL
