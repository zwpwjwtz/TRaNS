# Project: TRaNS
# Makefile created by Red Panda C++ 2.25

CPP      = g++
CC       = gcc
OBJ      = main.o parser/VariableParser.o module/Regulator.o module/Network.o parser/MainArgumentParser.o parser/ParameterParser.o parser/TopologyParser.o parser/NetworkParser.o
LINKOBJ  = main.o parser/VariableParser.o module/Regulator.o module/Network.o parser/MainArgumentParser.o parser/ParameterParser.o parser/TopologyParser.o parser/NetworkParser.o
CLEANOBJ  =  main.o parser/VariableParser.o module/Regulator.o module/Network.o parser/MainArgumentParser.o parser/ParameterParser.o parser/TopologyParser.o parser/NetworkParser.o TRaNS
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

main.o: main.cpp module/Regulator.h parser/VariableParser.h parser/NetworkParser.h module/Network.h parser/MainArgumentParser.h
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS) 

parser/VariableParser.o: parser/VariableParser.cpp parser/VariableParser.h
	$(CPP) -c parser/VariableParser.cpp -o parser/VariableParser.o $(CXXFLAGS) 

module/Regulator.o: module/Regulator.cpp module/Regulator.h
	$(CPP) -c module/Regulator.cpp -o module/Regulator.o $(CXXFLAGS) 

module/Network.o: module/Network.cpp module/constant.h module/Regulator.h module/Network.h
	$(CPP) -c module/Network.cpp -o module/Network.o $(CXXFLAGS) 

parser/MainArgumentParser.o: parser/MainArgumentParser.cpp parser/MainArgumentParser.h
	$(CPP) -c parser/MainArgumentParser.cpp -o parser/MainArgumentParser.o $(CXXFLAGS) 

parser/ParameterParser.o: parser/ParameterParser.cpp parser/ParameterParser.h
	$(CPP) -c parser/ParameterParser.cpp -o parser/ParameterParser.o $(CXXFLAGS) 

parser/TopologyParser.o: parser/TopologyParser.cpp module/constant.h parser/TopologyParser.h
	$(CPP) -c parser/TopologyParser.cpp -o parser/TopologyParser.o $(CXXFLAGS) 

parser/NetworkParser.o: parser/NetworkParser.cpp module/constant.h module/Regulator.h parser/NetworkParser.h module/Network.h parser/TopologyParser.h parser/ParameterParser.h
	$(CPP) -c parser/NetworkParser.cpp -o parser/NetworkParser.o $(CXXFLAGS) 
