.PHONY: build clean run
CC = gcc
PROJECT_DIR = /home/trung/Workspace/C-Program/Data-Encrypt-Decrypt
TARGET = b64
OBJECT_DIR = $(PROJECT_DIR)/build/b64
VPATH += $(PROJECT_DIR)/sample/b64
VPATH += $(PROJECT_DIR)/base64
CFLAGS = -I$(PROJECT_DIR)/base64 -g
DEPS  += $(PROJECT_DIR)/base64/*.h
SOURCE_FILES = $(notdir $(foreach VPATH, $(VPATH), $(wildcard $(VPATH)/*.c)))
OBJECT_FILES = $(patsubst %.c,$(PROJECT_DIR)/build/b64/%.o, $(SOURCE_FILES))
build: $(OBJECT_DIR)/$(TARGET)
$(OBJECT_DIR)/$(TARGET): $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) -o $@ 
$(OBJECT_DIR)/%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)
run:
	$(OBJECT_DIR)/$(TARGET)
clean:
	rm -rf $(OBJECT_DIR)/*.o $(OBJECT_DIR)/$(TARGET)
