# Project: TRaNS
# Makefile created by Red Panda C++ 2.26

CPP      = g++
CC       = gcc
OBJ      = module/Network.o parser/NetworkParser.o module/RegulatorFactory.o binding/Python/PythonVectorParser.o parser/TopologyParser.o module/Regulator.o binding/Python/PythonNetworkWrapper.o binding/Python/TRaNS.o parser/VariableParser.o parser/MainArgumentParser.o parser/ParameterParser.o module/NoiseGenerator.o main.o
LINKOBJ  = module/Network.o parser/NetworkParser.o module/RegulatorFactory.o parser/TopologyParser.o module/Regulator.o parser/VariableParser.o parser/MainArgumentParser.o parser/ParameterParser.o module/NoiseGenerator.o main.o
CLEANOBJ  =  module/Network.o parser/NetworkParser.o module/RegulatorFactory.o binding/Python/PythonVectorParser.o parser/TopologyParser.o module/Regulator.o binding/Python/PythonNetworkWrapper.o binding/Python/TRaNS.o parser/VariableParser.o parser/MainArgumentParser.o parser/ParameterParser.o module/NoiseGenerator.o main.o TRaNS
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

module/Network.o: module/Network.cpp module/Network.h module/Regulator.h module/NoiseGenerator.h module/constant.h
	$(CPP) -c module/Network.cpp -o module/Network.o $(CXXFLAGS) 

parser/NetworkParser.o: parser/NetworkParser.cpp module/Network.h parser/TopologyParser.h parser/NetworkParser.h parser/ParameterParser.h module/Regulator.h module/NoiseGenerator.h module/constant.h
	$(CPP) -c parser/NetworkParser.cpp -o parser/NetworkParser.o $(CXXFLAGS) 

module/RegulatorFactory.o: module/RegulatorFactory.cpp module/RegulatorFactory.h module/name.h
	$(CPP) -c module/RegulatorFactory.cpp -o module/RegulatorFactory.o $(CXXFLAGS) 

binding/Python/PythonVectorParser.o: binding/Python/PythonVectorParser.cpp binding/Python/PythonVectorParser.h
	$(CPP) -c binding/Python/PythonVectorParser.cpp -o binding/Python/PythonVectorParser.o $(CXXFLAGS) 

parser/TopologyParser.o: parser/TopologyParser.cpp parser/TopologyParser.h module/constant.h
	$(CPP) -c parser/TopologyParser.cpp -o parser/TopologyParser.o $(CXXFLAGS) 

module/Regulator.o: module/Regulator.cpp module/name.h module/Regulator.h module/NoiseGenerator.h
	$(CPP) -c module/Regulator.cpp -o module/Regulator.o $(CXXFLAGS) 

binding/Python/PythonNetworkWrapper.o: binding/Python/PythonNetworkWrapper.cpp binding/Python/PythonVectorParser.h module/Network.h module/RegulatorFactory.h binding/Python/PythonNetworkWrapper.h module/Regulator.h module/NoiseGenerator.h
	$(CPP) -c binding/Python/PythonNetworkWrapper.cpp -o binding/Python/PythonNetworkWrapper.o $(CXXFLAGS) 

binding/Python/TRaNS.o: binding/Python/TRaNS.cpp binding/Python/PythonNetworkWrapper.h
	$(CPP) -c binding/Python/TRaNS.cpp -o binding/Python/TRaNS.o $(CXXFLAGS) 

parser/VariableParser.o: parser/VariableParser.cpp parser/VariableParser.h
	$(CPP) -c parser/VariableParser.cpp -o parser/VariableParser.o $(CXXFLAGS) 

parser/MainArgumentParser.o: parser/MainArgumentParser.cpp parser/MainArgumentParser.h
	$(CPP) -c parser/MainArgumentParser.cpp -o parser/MainArgumentParser.o $(CXXFLAGS) 

parser/ParameterParser.o: parser/ParameterParser.cpp parser/ParameterParser.h
	$(CPP) -c parser/ParameterParser.cpp -o parser/ParameterParser.o $(CXXFLAGS) 

module/NoiseGenerator.o: module/NoiseGenerator.cpp module/NoiseGenerator.h
	$(CPP) -c module/NoiseGenerator.cpp -o module/NoiseGenerator.o $(CXXFLAGS) 

main.o: main.cpp module/Network.h parser/VariableParser.h parser/NetworkParser.h module/Regulator.h module/NoiseGenerator.h parser/MainArgumentParser.h
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS) 
