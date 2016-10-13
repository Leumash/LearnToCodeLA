HEADERS=board.h player.h
OBJECTS=board.o game.o player.o

%.o: $.c $(HEADERS)
	g++ -c -o $@ $<

game.exe: $(OBJECTS)
	g++ -std=c++11 -o $@ $^

clean:
	rm -f *.o *.exe
