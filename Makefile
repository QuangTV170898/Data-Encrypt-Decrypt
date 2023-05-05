.PHONY: build clean
CC = gcc
OBJECT_DIR = ./build
TARGET = aes
VPATH += .
VPATH += ./aes_encrypt
CFLAGS = -I./aes_encrypt -g
DEPS  += ./aes_encrypt/*.h
SOURCE_FILES = $(notdir $(foreach VPATH, $(VPATH), $(wildcard $(VPATH)/*.c)))
OBJECT_FILES = $(patsubst %.c,build/%.o, $(SOURCE_FILES))
build: $(OBJECT_DIR)/$(TARGET)
$(OBJECT_DIR)/$(TARGET): $(OBJECT_FILES) $(DEPS)
	@$(CC) $(OBJECT_FILES) -o $@ 
$(OBJECT_DIR)/%.o: %.c $(DEPS)
	@$(CC) -c $< -o $@ $(CFLAGS)
run:
	@$(OBJECT_DIR)/$(TARGET)
clean:
	@rm -rf $(OBJECT_DIR)/*.o $(OBJECT_DIR)/$(TARGET)
