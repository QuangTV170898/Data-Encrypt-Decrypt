.PHONY: build clean run
CC = gcc
EXAMPLE_DIR = $(shell pwd)
PROJECT_DIR = $(EXAMPLE_DIR)/../..
OBJECT_DIR = $(PROJECT_DIR)/build/aes
TARGET = aes
VPATH += $(PROJECT_DIR)/sample/aes
VPATH += $(PROJECT_DIR)/aes
CFLAGS = -I$(PROJECT_DIR)/aes -g
DEPS  += $(PROJECT_DIR)/aes/*.h
SOURCE_FILES := $(notdir $(foreach VPATH, $(VPATH), $(wildcard $(VPATH)/*.c)))
OBJECT_FILES := $(patsubst %.c,$(PROJECT_DIR)/build/aes/%.o, $(SOURCE_FILES))
build: $(OBJECT_DIR)/$(TARGET)
$(OBJECT_DIR)/$(TARGET): $(OBJECT_FILES)
	$(CC) $(OBJECT_FILES) -o $@ 
$(OBJECT_DIR)/%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)
run:
	$(OBJECT_DIR)/$(TARGET)
clean:
	rm -rf $(OBJECT_DIR)/*.o $(OBJECT_DIR)/$(TARGET)
print-%:
	@echo $($(subst print-,,$@))
build_static_lib:
	gcc -c $(PROJECT_DIR)/aes/aes.c -o $(PROJECT_DIR)/build/aes/aes.o $(CFLAGS)
	ar rcs $(PROJECT_DIR)/lib/static/libaes.a $(PROJECT_DIR)/build/aes/aes.o
build_static:
	gcc $(PROJECT_DIR)/sample/aes/aes_example.c -L$(PROJECT_DIR)/lib/static -laes -o $(PROJECT_DIR)/build/aes/aes $(CFLAGS)
build_shared_lib:
	gcc -c $(PROJECT_DIR)/aes/aes.c -fPIC -o $(PROJECT_DIR)/build/aes/aes.o $(CFLAGS)
	gcc -shared $(PROJECT_DIR)/build/aes/aes.o -o $(PROJECT_DIR)/lib/shared/libaes.so 
build_shared:
	gcc $(PROJECT_DIR)/sample/aes/aes_example.c -L$(PROJECT_DIR)/lib/shared -laes -o $(PROJECT_DIR)/build/aes/aes $(CFLAGS)