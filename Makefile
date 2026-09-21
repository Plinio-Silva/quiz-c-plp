CC = gcc
CFLAGS = -Wall -I. -Iinclude
SRC = src/main.c src/interface.c src/temporizador.c src/perguntas.c
CONIO_SRC = conio.c
OUT = build/quiz.exe

all: $(OUT)

$(OUT): $(SRC) $(CONIO_SRC) | build
	$(CC) $(CFLAGS) $(SRC) $(CONIO_SRC) -o $(OUT)

build:
	mkdir -p build

run: all
	$(OUT)

clean:
	rm -f $(OUT)
