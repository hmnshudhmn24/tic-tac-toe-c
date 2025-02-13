CC = gcc
CFLAGS = -Wall -Wextra

all: tictactoe

tictactoe: src/main.o src/game_logic.o
	$(CC) $(CFLAGS) -o tictactoe src/main.o src/game_logic.o

src/main.o: src/main.c include/game_logic.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/game_logic.o: src/game_logic.c include/game_logic.h
	$(CC) $(CFLAGS) -c src/game_logic.c -o src/game_logic.o

clean:
	rm -f tictactoe src/*.o
