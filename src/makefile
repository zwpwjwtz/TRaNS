# Project: TRaNS
# Makefile created by Red Panda C++ 2.26

CPP      = g++
CC       = gcc
OBJ      = parser/MainArgumentParser.o module/RegulatorFactory.o module/NoiseGenerator.o module/Network.o parser/NetworkParser.o parser/TopologyParser.o main.o parser/VariableParser.o parser/ParameterParser.o module/Regulator.o
LINKOBJ  = parser/MainArgumentParser.o module/RegulatorFactory.o module/NoiseGenerator.o module/Network.o parser/NetworkParser.o parser/TopologyParser.o main.o parser/VariableParser.o parser/ParameterParser.o module/Regulator.o
CLEANOBJ  =  parser/MainArgumentParser.o module/RegulatorFactory.o module/NoiseGenerator.o module/Network.o parser/NetworkParser.o parser/TopologyParser.o main.o parser/VariableParser.o parser/ParameterParser.o module/Regulator.o TRaNS
LIBS     = 
INCS     =  -I"/home/user/.conda/envs/pytorch/include/python3.10" 
CXXINCS  =  -I"/home/user/.conda/envs/pytorch/include/python3.10" 
BIN      = TRaNS
CXXFLAGS = $(CXXINCS)  -g3 -std=c++11 -pipe -Wall -D__DEBUG__
CFLAGS   = $(INCS)  -g3 -pipe -Wall -D__DEBUG__
RM       = rm -rf

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	-$(RM) $(CLEANOBJ) > /dev/null 2>&1

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

parser/MainArgumentParser.o: parser/MainArgumentParser.cpp parser/MainArgumentParser.h
	$(CPP) -c parser/MainArgumentParser.cpp -o parser/MainArgumentParser.o $(CXXFLAGS) 

module/RegulatorFactory.o: module/RegulatorFactory.cpp module/RegulatorFactory.h module/name.h
	$(CPP) -c module/RegulatorFactory.cpp -o module/RegulatorFactory.o $(CXXFLAGS) 

module/NoiseGenerator.o: module/NoiseGenerator.cpp module/NoiseGenerator.h
	$(CPP) -c module/NoiseGenerator.cpp -o module/NoiseGenerator.o $(CXXFLAGS) 

module/Network.o: module/Network.cpp module/Regulator.h module/NoiseGenerator.h module/Network.h module/constant.h
	$(CPP) -c module/Network.cpp -o module/Network.o $(CXXFLAGS) 

parser/NetworkParser.o: parser/NetworkParser.cpp parser/ParameterParser.h module/Regulator.h parser/NetworkParser.h module/NoiseGenerator.h module/Network.h module/constant.h parser/TopologyParser.h
	$(CPP) -c parser/NetworkParser.cpp -o parser/NetworkParser.o $(CXXFLAGS) 

parser/TopologyParser.o: parser/TopologyParser.cpp module/constant.h parser/TopologyParser.h
	$(CPP) -c parser/TopologyParser.cpp -o parser/TopologyParser.o $(CXXFLAGS) 

main.o: main.cpp module/Regulator.h parser/NetworkParser.h parser/MainArgumentParser.h parser/VariableParser.h module/NoiseGenerator.h module/Network.h
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS) 

parser/VariableParser.o: parser/VariableParser.cpp parser/VariableParser.h
	$(CPP) -c parser/VariableParser.cpp -o parser/VariableParser.o $(CXXFLAGS) 

parser/ParameterParser.o: parser/ParameterParser.cpp parser/ParameterParser.h
	$(CPP) -c parser/ParameterParser.cpp -o parser/ParameterParser.o $(CXXFLAGS) 

module/Regulator.o: module/Regulator.cpp module/Regulator.h module/NoiseGenerator.h module/name.h
	$(CPP) -c module/Regulator.cpp -o module/Regulator.o $(CXXFLAGS) 
