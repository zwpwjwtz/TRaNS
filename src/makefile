# Project: TRaNS
# Makefile created by Red Panda C++ 2.25

CPP      = g++
CC       = gcc
OBJ      = module/Network.o parser/NetworkParser.o main.o parser/TopologyParser.o parser/MainArgumentParser.o parser/VariableParser.o parser/ParameterParser.o module/Regulator.o
LINKOBJ  = module/Network.o parser/NetworkParser.o main.o parser/TopologyParser.o parser/MainArgumentParser.o parser/VariableParser.o parser/ParameterParser.o module/Regulator.o
CLEANOBJ  =  module/Network.o parser/NetworkParser.o main.o parser/TopologyParser.o parser/MainArgumentParser.o parser/VariableParser.o parser/ParameterParser.o module/Regulator.o TRaNS
LIBS     = 
INCS     =  
CXXINCS  =  
BIN      = TRaNS
CXXFLAGS = $(CXXINCS)  -g3 -pipe -Wall -D__DEBUG__
CFLAGS   = $(INCS)  -g3 -pipe -Wall -D__DEBUG__
RM       = rm -rf

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	-$(RM) $(CLEANOBJ) > /dev/null 2>&1

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

module/Network.o: module/Network.cpp module/Network.h module/Regulator.h
	$(CPP) -c module/Network.cpp -o module/Network.o $(CXXFLAGS) 

parser/NetworkParser.o: parser/NetworkParser.cpp parser/ParameterParser.h parser/NetworkParser.h module/Network.h module/Regulator.h parser/TopologyParser.h
	$(CPP) -c parser/NetworkParser.cpp -o parser/NetworkParser.o $(CXXFLAGS) 

main.o: main.cpp parser/NetworkParser.h parser/VariableParser.h parser/MainArgumentParser.h module/Network.h module/Regulator.h
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS) 

parser/TopologyParser.o: parser/TopologyParser.cpp parser/TopologyParser.h
	$(CPP) -c parser/TopologyParser.cpp -o parser/TopologyParser.o $(CXXFLAGS) 

parser/MainArgumentParser.o: parser/MainArgumentParser.cpp parser/MainArgumentParser.h
	$(CPP) -c parser/MainArgumentParser.cpp -o parser/MainArgumentParser.o $(CXXFLAGS) 

parser/VariableParser.o: parser/VariableParser.cpp parser/VariableParser.h
	$(CPP) -c parser/VariableParser.cpp -o parser/VariableParser.o $(CXXFLAGS) 

parser/ParameterParser.o: parser/ParameterParser.cpp parser/ParameterParser.h
	$(CPP) -c parser/ParameterParser.cpp -o parser/ParameterParser.o $(CXXFLAGS) 

module/Regulator.o: module/Regulator.cpp module/Regulator.h
	$(CPP) -c module/Regulator.cpp -o module/Regulator.o $(CXXFLAGS) 
