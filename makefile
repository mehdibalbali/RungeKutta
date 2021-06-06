CC=gcc
CFLAGS=-c -lm

OBJ_DIR=obj
HEAD_DIR=headers

EXEC=RKutta

SOURCES=main.c RK_t.c fonctions_utiles.c
OBJECTS=$(SOURCES:%.c =$(OBJ_DIR)%.o)

all: $(EXEC)

$(EXEC): $(OBJECTS) 
	$(CC) $^ -o $@ -lm


$(OBJ_DIR)/%.o: *.c
	$(CC) $(CFLAGS) $< -o $@


clean: 
	rm $(OBJECTS) $(EXEC)
