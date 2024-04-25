# #
#
# Main Makefile for Duckling_RTOS project
#
# @author Geronimo Freese
#
# #

PROJECT_NAME = Duckling

# Compiler
CC_PREFIX = arm-none-eabi-
CC = gcc
CFLAGS = -Wall -std=c99 -mcpu=cortex-m4 -mthumb -nostdlib -nolibc
C_OBJ_FLAGS = $(CFLAGS)
C_DEBUG_FLAGS = -g

# Linker
LD_PREFIX = arm-none-eabi-
LD = gcc
LDFLAGS = -mcpu=cortex-m4 -mthumb

# Directories
SRC_DIR 		:=	src
INC_DIR 		:= 	include
OBJ_DIR 		:= 	obj
DEBUG_DIR 	:= 	debug
BUILD_DIR 	:= 	build
BIN_DIR 		:= 	bin


# Files
SRC := $(shell find $(SRC_DIR) -name "*.c")
INC := $(shell find $(INC_DIR) -name "*.h")
OBJ := $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
OBJ_DEBUG := $(addprefix $(DEBUG_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
vpath %.c $(SRC_DIR)


TARGET = $(BIN_DIR)/$(PROJECT_NAME).elf
TARGET_DEBUG = $(DEBUG_DIR)/$(PROJECT_NAME).elf


# clean files list
DISTCLEAN_LIST := $(OBJ) \
                  $(OBJ_DEBUG)
CLEAN_LIST := $(TARGET) \
			  			$(TARGET_DEBUG) \
			  			$(DISTCLEAN_LIST)

# default rule
default: makedir all

# non-phony targets
$(TARGET): $(OBJ)
	$(LD_PREFIX)$(LD) $(LDFLAGS) -I$(INC_DIR) $^ -o $@


#
#
#	THIS IS THE PROBLEM SPOT
#
#
$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c #$(filter %.c, $(SRC))
	$(CC_PREFIX)$(CC) $(C_OBJ_FLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DEBUG)/: $(SRC)
	$(CC_PREFIX)$(CC) $(C_OBJ_FLAGS) $(C_DEBUG_FLAGS) -o $@ $<

$(TARGET_DEBUG): $(OBJ_DEBUG)
	$(CC_PREFIX)$(CC) $(CFLAGS) $(C_DEBUG_FLAGS) $(OBJ_DEBUG) -o $@


# phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(BIN_DIR) $(OBJ_DIR) $(DEBUG_DIR)

.PHONY: all
all: $(TARGET)

.PHONY: debug
debug: $(TARGET_DEBUG)

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)

.PHONY: distclean
distclean:
	@echo CLEAN $(DISTCLEAN_LIST)
	@rm -f $(DISTCLEAN_LIST)


debug_make:
	@echo $(OBJ)
