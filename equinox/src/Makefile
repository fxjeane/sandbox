ARCH = $(shell uname )

RELEASE_DIR			= ../bin
RELEASE_OBJS		= $(RELEASE_DIR)/objs
UTEST_RELEASE_DIR	= $(RELEASE_DIR)/utests
PLUGIN_DIR			= plugin
PLUGIN_RELEASE_DIR = $(RELEASE_DIR)/$(PLUGIN_DIR)

CC 			= gcc
CPP			= g++
CFLAGS 		= -O2 -finline-functions
CFLAGS 		+= -ansi -Wall -Winline
AR 			= ar
LIBS 		= -lm -lIlmImf -lHalf
INCLUDE		=-I. -I/usr/local/include/OpenEXR
SHARED_LDFLAGS = -flat_namespace -undefined suppress -bundle

# For debugging, uncomment the next one
#
# CFLAGS += -O0 -DDEBUG -g3 -gdwarf-2

###############
# Pretty print
###############
V		      = @
Q		      = $(V:1=)
QUIET_CC      = $(Q:@=@echo    '     CC       '$@;)
QUIET_AR      = $(Q:@=@echo    '     AR       '$@;)
QUIET_GEN     = $(Q:@=@echo    '     GEN      '$@;)
QUIET_LINK    = $(Q:@=@echo    '     LINK     '$@;)


EXECUTABLE 			= equinox
EXECUTABLE_BINARY	= $(RELEASE_DIR)/$(EXECUTABLE)

UTESTS				= EtParamUTest EtNodeUTest
UTESTS_FILES		= $(UTESTS:=.c)
UTESTS_EXECS		= $(addprefix $(UTEST_RELEASE_DIR)/, $(UTESTS))

MAIN 				= main.c
HEADER_FILES 		= EtTypes.h

LIB_FILES			= buf EtParam EtNode EtPluginManager EtGeometry EtBucket exr
LIB_HEADERS			= $(LIB_FILES:=.h)
LIB_OBJS			= $(addprefix $(RELEASE_OBJS)/, $(LIB_FILES:=.o))
LIB_FILE			= $(RELEASE_OBJS)/equinox.a

PLUGIN_FILES		= EtCamera
PLUGIN_HEADERS		= $(PLUGIN_FILES:=.h)
PLUGIN_OBJS			= $(addprefix $(PLUGIN_RELEASE_DIR)/,$(PLUGIN_FILES:=.so))

all: dir utests  run_utests $(PLUGIN_OBJS) $(EXECUTABLE_BINARY)

dir:
	@mkdir -p $(RELEASE_DIR)
	@mkdir -p $(RELEASE_OBJS)
	@mkdir -p $(UTEST_RELEASE_DIR)
	@mkdir -p $(PLUGIN_RELEASE_DIR)

utests: dir $(UTESTS_EXECS)
	@echo "UNIT TESTS Done!!"

run_utests:
	./run_utests

$(UTEST_RELEASE_DIR)/%: $(UTESTS_FILES) $(LIB_FILE)
	@echo 'Making utest $<'
	#$(QUIET_LINK) $(CC) $(LDFLAGS)  -o $@ $< $(LIB_FILE)

$(RELEASE_OBJS)/%.o: %.c $(LIB_HEADERS) $(HEADER_FILES) 
	@echo "// MAKING $@"
	$(CC) -c  -o $@ $<

$(RELEASE_OBJS)/%.o: %.cpp $(LIB_HEADERS) $(HEADER_FILES) 
	@echo "// MAKING $@"
	$(CPP)  -c $(INCLUDE) -DCPLUSPLUS -o $@ $<

$(PLUGIN_RELEASE_DIR)/%.so: $(PLUGIN_DIR)/%.c $(LIB_FILE) 
	@echo "// MAKING PLUGIN $@"
	$(QUIET_LINK) $(CC) $(INCLUDE)  $(SHARED_LDFLAGS) -o $@ $< $(LIB_FILE)

$(LIB_FILE): $(LIB_OBJS)
	$(QUIET_AR)$(AR) rcs $@ $(LIB_OBJS)

$(EXECUTABLE_BINARY): $(MAIN) $(LIB_FILE) $(HEADER_FILES) 
	@echo 'Making --- $(EXECUTABLE)'
	$(QUIET_LINK) $(CPP) $(LDFLAGS) $(LIBS) $(INCLUDE)  -DCPLUSPLUS -o $@ $< $(LIB_FILE)
	../bin/equinox
	open test.exr
clean:
	rm -vfr $(RELEASE_DIR)	
