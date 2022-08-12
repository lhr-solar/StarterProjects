# Your target file; the file you will execute in your terminal to run your code. The result of all of your code being linked together.
TARGET := starter.out

# Where all the object files (compiled c files) will go after compilation
BUILD_DIR := Objects

# Compiler
CC = gcc

# Sources: all of the files you want to compile. First, we get all files with a .c extension in the current directory. Then, we add all files with a .c extension in the uCOS-III-Simulator directory.
SRCS := $(wildcard *.c)
SRCS += $(shell find uCOS-III-Simulator -type f -name '*.c')

# Add the test file to the sources.
ifneq ($(TEST), none)
TEST_FILE := Test_$(TEST).c
SRCS += \
$(wildcard Tests/$(TEST_FILE))
endif

# Object files (replace all .c with .o in SRCS, notdir ignores previous file path so that everything can be in BUILD_DIR)
OBJS := $(addprefix $(BUILD_DIR)/,$(notdir $(SRCS:.c=.o)))
vpath %.c $(sort $(dir $(SRCS)))		# In case files aren't found

# Included files (all directories under the current directory)
INCS := $(addprefix -I,$(shell find . -type d))

# Standard libraries used
LIB := -lm -lpthread
# -lm -lpthread link specific libraries that we require

# Compiler options
FLAGS := -Wall -g -std=c11 $(INCS)
# -Wall all warnings
# -g debugging allowed
# -std=c11 specify c version
# $(INCS) include the headers

# More compiler options
DEF := -D_XOPEN_SOURCE=600 -DSIMULATOR
# -D_XOPEN_SOURCE=600 use POSIX 6 standards

# recipe for all
all: $(TARGET)

# remove objects
clean:
	rm -fR $(BUILD_DIR)
	rm -f *.out

# link everything into output
$(TARGET): $(OBJS) $(BUILD_DIR)
	$(CC) -o $@ $(OBJS) $(FLAGS) $(LIB)

# compile to each object file individually
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) -c -o $@ $< $(FLAGS) $(DEF)

# create objects directory if not already present
$(BUILD_DIR):
	-mkdir $@