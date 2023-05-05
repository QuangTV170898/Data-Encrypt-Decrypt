.PHONY: build clean run
CC = gcc
PROJECT_DIR = /home/trung/Workspace/C-Program/Data-Encrypt-Decrypt
OBJECT_DIR = $(PROJECT_DIR)/build/aes
TARGET = aes
VPATH += $(PROJECT_DIR)/sample/aes
VPATH += $(PROJECT_DIR)/aes_encrypt
CFLAGS = -I$(PROJECT_DIR)/aes_encrypt -g
DEPS  += $(PROJECT_DIR)/aes_encrypt/*.h
SOURCE_FILES = $(notdir $(foreach VPATH, $(VPATH), $(wildcard $(VPATH)/*.c)))
OBJECT_FILES = $(patsubst %.c,$(PROJECT_DIR)/build/aes/%.o, $(SOURCE_FILES))
build: $(OBJECT_DIR)/$(TARGET)
$(OBJECT_DIR)/$(TARGET): $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) -o $@ 
$(OBJECT_DIR)/%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)
run:
	$(OBJECT_DIR)/$(TARGET)
clean:
	rm -rf $(OBJECT_DIR)/*.o $(OBJECT_DIR)/$(TARGET)
