
ARCH = $(shell uname)

#PLUGIN = plugin

RELEASE_DIR=../bin
#RELEASE_PLUGIN_DIR=$(RELEASE_DIR)/$(PLUGIN)
OBJS = $(RELEASE_DIR)/objs

RENDERER = pluginTest
#RENDERER_OBJS     := $(addprefix objs/, $(RENDERER:=.o) )
RENDERER_BINARY = $(RELEASE_DIR)/$(RENDERER)

MAIN = main.c
HEADER_FILES = plugin.h
#CORE_HEADERS= $(addprefix core/, $(CORE_HEADERFILES)) 

#PLUGIN_FILES = camera light
#PLUGINS:= $(addprefix $(OBJS)/, $(PLUGIN_FILES:=.o))
#PLUGIN_DSOS:= $(addprefix $(RELEASE_PLUGIN_DIR)/, $(PLUGIN_FILES:=.so))

LIB_FILES = buf
LIBS = $(addprefix $(OBJS)/, $(LIB_FILES:=.o))
LIBS_DSO=$(addprefix $(OBJS)/, $(LIB_FILES:=.so))


CC = gcc
INCLUDE=-I.
LD=$(CC) $(OPT)
DEFS=-DNDEBUG
OPT=-O2 -msse2 -mfpmath=sse
WARN=-Wall
CWD=$(shell pwd)
CXXFLAGS=$(OPT) $(INCLUDE) $(WARN) $(DEFS)
CCFLAGS=$(CXXFLAGS)

ifeq ($(ARCH), Darwin)
  OS_VERSION = $(shell uname -r)
  SHARED_LDFLAGS = -flat_namespace -undefined suppress -bundle 
  LRT_LDFLAGS=$(OPT)
  INCLUDE += -I/sw/include
  #WARN += -Wno-long-double
endif

all: dir  $(RENDERER_BINARY)

dir:
	@echo '#######################'
	@echo 'Making Output Dirs'
	mkdir -p $(RELEASE_DIR)
	#mkdir -p $(RELEASE_PLUGIN_DIR)
	mkdir -p $(OBJS)

$(OBJS)/%.o: $(PLUGIN)/%.c 
	@echo '#######################'
	@echo "MAKING $@"
	$(CC) -c $(INCLUDE) -o $@ $<

$(RELEASE_PLUGIN_DIR)/%.so: $(OBJS)/%.o 
	$(LD) $(SHARED_LDFLAGS) $^ -o $@

$(OBJS)/%.o: %.c %.h 
	@echo '#######################'
	@echo "MAKING $@"
	$(CC) -c $(INCLUDE) -o $@ $<

$(OBJS)/%.so: $(OBJS)/%.o 
	$(LD) $(SHARED_LDFLAGS) $^ -o $@

$(RENDERER_BINARY): $(MAIN) $(HEADER_FILES) $(LIBS_DSO)
	@echo '#######################'
	@echo 'Making $< Binary'
	$(CC) $(INCLUDE) -I$(OBJS) -o $@ $<
	
