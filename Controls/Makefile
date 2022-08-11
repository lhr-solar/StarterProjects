# where the compiled code is going
TARGET = controls-simulator.out

# where the written code is coming from
SRC = $(wildcard *.c)

# add necessary OS files
SRC += \
$(wildcard uCOS-III-Simulator/uC-CPU/*.c) \
$(wildcard uCOS-III-Simulator/uC-CPU/Posix/GNU/*.c) \
$(wildcard uCOS-III-Simulator/uC-LIB/*.c) \
$(wildcard uCOS-III-Simulator/uCOS-III/Source/*.c) \
$(wildcard uCOS-III-Simulator/uCOS-III/Ports/POSIX/GNU/*.c)

# put any object files in here
BUILD_DIR = Objects
OBJ = $(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.c=.o)))	# Create object file list from files in SRC
vpath %.c $(sort $(dir $(SRC)))		# In case files aren't found

# Header files to include
INC_DIR = \
-I uCOS-III-Simulator/uC-CPU \
-I uCOS-III-Simulator/uC-CPU/Posix/GNU \
-I uCOS-III-Simulator/uC-LIB \
-I uCOS-III-Simulator/uCOS-III/Source \
-I uCOS-III-Simulator/uCOS-III/Ports/POSIX/GNU \

# Standard libraries used
LIB = -lm -lpthread

# Compiler options
FLAGS = -Wall -g -std=c11 $(INC_DIR)	
# -Wall all warnings
# -g debugging allowed
# -std=c11 specify c version
# -lm -lpthread link specific libraries that we require

# More compiler options
DEF = -D_XOPEN_SOURCE=600 -DSIMULATOR
# -D_XOPEN_SOURCE=600 use POSIX 6 standards

all: $(TARGET)

# clear all output files
clean:
	rm -fR Objects
	rm -f *.out

# run gcc on each of the provided files and link them to the output
$(TARGET): $(OBJ) $(BUILD_DIR)
	gcc -o $@ $(OBJ) $(FLAGS) $(LIB)
# -o $@ output to $@ ($@ refers to TARGET)
# $(OBJ) include these object files
# $(FLAGS) options for compilation
# $(LIB) link these libraries

# compile every file that hasn't been compiled yet and output each to a separate file
$(BUILD_DIR)/%.o: %.c $(BUILD_DIR)
	gcc -c -o $@ $< $(FLAGS) $(DEF)
# -c compile, don't link
# -o output to $@ ($@ refers to $(BUILD_DIR)/%.o)
# compile $< ($< refers to %.c, any file with .c extension) 

$(BUILD_DIR):	# make objects directory
	mkdir $@