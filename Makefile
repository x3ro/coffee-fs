SOURCE_DIR=src
OBJECT_DIR=build

CC=clang
CFLAGS=-Iinclude -Iexample/include -Wall -pedantic -Werror

_OBJ = cfs-coffee.o in-memory-backend.o main.o
OBJ = $(patsubst %, $(OBJECT_DIR)/%, $(_OBJ))



$(OBJECT_DIR)/%.o: example/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJECT_DIR)/%.o: src/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

build/coffee: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f build/*
