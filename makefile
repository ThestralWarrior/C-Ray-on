CC = gcc
CFLAGS = -Iheader -fopenmp
SOURCES = src/main.c src/compute.c src/rendering.c src/output.c src/sphere.c
OBJECTS = $(SOURCES:src/%.c=obj/%.o)
TARGET = crayon

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) -fopenmp

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir -p obj

clean:
	rm -rf $(TARGET) obj