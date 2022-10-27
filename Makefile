TARGET = matrix-check-lib
CC = gcc

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))


$(TARGET): $(OBJ) 
	$(CC) $(OBJ) -o $(TARGET) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< -o $@ 

clean:
	rm $(TARGET) $(OBJ_DIR)*.o

run:
	./$(TARGET)




