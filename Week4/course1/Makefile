#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Dependency Directory
DEPDIR := .
#Dependency Flags     (  http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/#combine  )
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.dep

#Output File Name (.out - .map - .asm)
TARGET = final


ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	SIZE = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump
	CPPFLAGs = -DMSP432 -DCOURSE1 -DVERBOSE
	CPU = -mcpu=cortex-m4
	ARCH = -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
	SPECS = --specs=nosys.specs
	#Compiler Flags
	CFLAGS = -Wall -g -O0 -std=c99 
	
	LINKER_FILE = ./msp432p401r.lds
	LDFLAGS = -Wl,-T$(LINKER_FILE) -Wl,-M=$(TARGET).map
	#LDFLAGS = -Xlinker $(LINKER_FILE) -Xlinker -M=$(TARGET).map
	
	DumpFLAGS = -d
	
endif

ifeq ($(PLATFORM),HOST)
	CC = gcc
	SIZE = size
	OBJDUMP = objdump
	CPPFLAGs = -DHOST -DCOURSE1 -DVERBOSE
	CPU =
	ARCH = 
	SPECS =
	#Compiler Flags
	CFLAGS = -Wall -g -O0 -std=c99
	
	LINKER_FILE = ./msp432p401r.lds
	LDFLAGS = -Wl,-M=$(TARGET).map
	#LDFLAGS = -Xlinker -M=$(TARGET).map
	
	DumpFLAGS = -d
	
endif


# Relative Path of .c files:
Src_Path = ./src/

# Compiling the C files, by defining an implicit rule " using the pattern match operator (%)" : ------> The implicit rule can be applied on any build target ( main.o , memory.o - ...)
%.o : $(Src_Path)%.c
	@$(CC) $(INCLUDES) $(CPPFLAGs) $(CPU) $(ARCH) $(SPECS) $(CFLAGS) $(DEPFLAGS) -c -o $@ $^

# Preprocessing the C files, by defining an implicit rule " using the pattern match operator (%)" :	
%.i : %.c
	@$(CC) $(INCLUDES) $(CPPFLAGs) $(CPU) $(ARCH) $(SPECS) $(CFLAGS) -E  -o $@ $^
	

# Assembling the C files, by defining an implicit rule " using the pattern match operator (%)" :	
%.asm : %.c
	@$(CC) $(INCLUDES) $(CPPFLAGs) $(CPU) $(ARCH) $(SPECS) $(CFLAGS) -S  -o $@ $^
	
	
	
# Diassemble the project executable file "$(TARGET).out" , and save the output into a file named "$(TARGET).asm"
$(TARGET).asm : Check-Exe-Existence
	@$(OBJDUMP) $(DumpFLAGS) $(TARGET).out > $(TARGET).asm

Check-Exe-Existence :
	@test -s c1m2.out && echo "" || echo "Please call the Build Rule (make Build PLATFORM=platform-name) to generate the target executable file (c1m2.out)"

# Define Phony Targets:
.PHONY: compile-all Clean Build

# 1)Compile all C file (generate *.o files) without linking:
compile-all : $(OBJS)

# 2)Remove all generated files " Preprocessed files (*.i) - Assembly files (*.asm) - Object files (*.o) - executable file (.out) - map file (.map) ":
Clean :
	@rm -f *.i
	@rm -f *.asm
	@rm -f *.o
	@rm -f *.out
	@rm -f *.map
	@rm -f *.dep
	
Build : $(OBJS)
	@$(CC) $(ARCH) $(SPECS) $(LDFLAGS) -o $(TARGET).out $^
	@$(SIZE) -Atd $(TARGET).out
	
	

	
	

	


	



