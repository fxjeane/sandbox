
ARCH = $(shell uname )

RELEASE_DIR	=../bin
RELEASE_OBJS= $(RELEASE_DIR)/objs

CC 			= gcc
CFLAGS 		= -O2 -finline-functions
CFLAGS 		+= -ansi -Wall -Winline
AR 			= ar
LIBS 		= -lm -lGL -lGLU -lglut
INCLUDE		=I$(RELEASE_OBJS)

ifeq ($(ARCH),Cygwin)
	LIBS = -lm -lopengl32 -lglu32 -lglut32
	LDFLAGS += -static-libgcc
endif

# For debugging, uncomment the next one
#
# CFLAGS += -O0 -DDEBUG -g3 -gdwarf-2

###############
# Pretty print
###############
V	      = @
Q	      = $(V:1=)
QUIET_CC      = $(Q:@=@echo    '     CC       '$@;)
QUIET_AR      = $(Q:@=@echo    '     AR       '$@;)
QUIET_GEN     = $(Q:@=@echo    '     GEN      '$@;)
QUIET_LINK    = $(Q:@=@echo    '     LINK     '$@;)


EXECUTABLE = equinox
EXECUTABLE_BINARY = $(RELEASE_DIR)/$(EXECUTABLE)

MAIN = main.c
HEADER_FILES = EtTypes.h

LIB_FILES	= buf EtParam EtNode
LIB_HEADERS	= $(LIB_FILES:=.h)
LIB_OBJS	= $(addprefix $(RELEASE_OBJS)/, $(LIB_FILES:=.o))
LIB_FILE	= $(RELEASE_OBJS)/equinox.a


all: dir  $(EXECUTABLE_BINARY)

dir:
	@mkdir -p $(RELEASE_DIR)
	@mkdir -p $(RELEASE_OBJS)


$(RELEASE_OBJS)/%.o: %.c $(LIB_HEADERS) $(HEADER_FILES) 
	@echo "// MAKING $@"
	$(CC) -c  -o $@ $<

$(LIB_FILE): $(LIB_OBJS)
	$(QUIET_AR)$(AR) rcs $@ $(LIB_OBJS)

$(EXECUTABLE_BINARY): $(MAIN) $(LIB_FILE) $(HEADER_FILES) 
	@echo 'Making $(EXECUTABLE)'
	$(QUIET_LINK) $(CC) $(LDFLAGS)  -o $@ $< $(LIB_FILE)

clean:
	rm -vfr $(RELEASE_DIR)	
