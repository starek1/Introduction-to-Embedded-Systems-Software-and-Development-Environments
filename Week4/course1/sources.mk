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

# Add your Source files to this variable
ifeq ($(PLATFORM),MSP432)
	SOURCES := main.c \
               memory.c \
		       startup_msp432p401r_gcc.c \
		       system_msp432p401r.c \
		       interrupts_msp432p401r_gcc.c \
			   course1.c \
			   data.c \
			   stats.c
endif

ifeq ($(PLATFORM),HOST)
	SOURCES := main.c \
               memory.c \
		       course1.c \
			   data.c \
			   stats.c	   
endif


# For every .c file, associate .o file with the same name:	  
OBJS := $(SOURCES:.c=.o)


# Includes Paths:
COMMON_RELATIVE_INCLUDE_PATH = ./include/common
MSP432_RELATIVE_INCLUDE_PATH = ./include/msp432
CMSIS_RELATIVE_INCLUDE_PATH = ./include/CMSIS

# Add your include paths to this variable
INCLUDES = -I$(COMMON_RELATIVE_INCLUDE_PATH) \
		   -I$(MSP432_RELATIVE_INCLUDE_PATH) \
           -I$(CMSIS_RELATIVE_INCLUDE_PATH)

