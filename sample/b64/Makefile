.PHONY: build clean run
CC = gcc
EXAMPLE_DIR = $(shell pwd)
PROJECT_DIR = $(EXAMPLE_DIR)/../..
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
build_static_lib:
	gcc -c $(PROJECT_DIR)/base64/b64.c -o $(PROJECT_DIR)/build/b64/b64.o $(CFLAGS)
	ar rcs $(PROJECT_DIR)/lib/static/libb64.a $(PROJECT_DIR)/build/b64/b64.o
build_static:
	gcc $(PROJECT_DIR)/sample/b64/base64_example.c -L$(PROJECT_DIR)/lib/static -lb64 -o $(PROJECT_DIR)/build/b64/b64 $(CFLAGS)
build_shared_lib:
	gcc -c $(PROJECT_DIR)/base64/b64.c -fPIC -o $(PROJECT_DIR)/build/b64/b64.o $(CFLAGS)
	gcc -shared $(PROJECT_DIR)/build/b64/b64.o -o $(PROJECT_DIR)/lib/shared/libb64.so 
build_shared:
	gcc $(PROJECT_DIR)/sample/b64/base64_example.c -L$(PROJECT_DIR)/lib/shared -lb64 -o $(PROJECT_DIR)/build/b64/b64 $(CFLAGS)