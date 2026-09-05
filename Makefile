CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/interface.c src/temporizador.c src/tema1.c src/tema2.c
OUT = build/quiz.exe

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	$(OUT)

clean:
	del /Q $(subst /,\,$(OUT))
