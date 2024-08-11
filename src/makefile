# Project: TRaNS
# Makefile created by Red Panda C++ 2.26

CPP      = g++
CC       = gcc
OBJ      = parser/VariableParser.o binding/Python/PythonNetworkWrapper.o module/Regulator.o main.o parser/MainArgumentParser.o parser/TopologyParser.o parser/ParameterParser.o binding/Python/PythonVectorParser.o module/RegulatorFactory.o module/NoiseGenerator.o parser/NetworkParser.o binding/Python/TRaNS.o module/Network.o
LINKOBJ  = parser/VariableParser.o module/Regulator.o main.o parser/MainArgumentParser.o parser/TopologyParser.o parser/ParameterParser.o module/RegulatorFactory.o module/NoiseGenerator.o parser/NetworkParser.o module/Network.o
CLEANOBJ  =  parser/VariableParser.o binding/Python/PythonNetworkWrapper.o module/Regulator.o main.o parser/MainArgumentParser.o parser/TopologyParser.o parser/ParameterParser.o binding/Python/PythonVectorParser.o module/RegulatorFactory.o module/NoiseGenerator.o parser/NetworkParser.o binding/Python/TRaNS.o module/Network.o TRaNS
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

parser/VariableParser.o: parser/VariableParser.cpp parser/VariableParser.h
	$(CPP) -c parser/VariableParser.cpp -o parser/VariableParser.o $(CXXFLAGS) 

binding/Python/PythonNetworkWrapper.o: binding/Python/PythonNetworkWrapper.cpp module/NoiseGenerator.h module/Network.h binding/Python/PythonVectorParser.h module/RegulatorFactory.h binding/Python/PythonNetworkWrapper.h module/Regulator.h
	$(CPP) -c binding/Python/PythonNetworkWrapper.cpp -o binding/Python/PythonNetworkWrapper.o $(CXXFLAGS) 

module/Regulator.o: module/Regulator.cpp module/name.h module/NoiseGenerator.h module/Regulator.h
	$(CPP) -c module/Regulator.cpp -o module/Regulator.o $(CXXFLAGS) 

main.o: main.cpp module/NoiseGenerator.h parser/NetworkParser.h module/Network.h parser/VariableParser.h module/Regulator.h parser/MainArgumentParser.h
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS) 

parser/MainArgumentParser.o: parser/MainArgumentParser.cpp parser/MainArgumentParser.h
	$(CPP) -c parser/MainArgumentParser.cpp -o parser/MainArgumentParser.o $(CXXFLAGS) 

parser/TopologyParser.o: parser/TopologyParser.cpp module/constant.h parser/TopologyParser.h
	$(CPP) -c parser/TopologyParser.cpp -o parser/TopologyParser.o $(CXXFLAGS) 

parser/ParameterParser.o: parser/ParameterParser.cpp parser/ParameterParser.h
	$(CPP) -c parser/ParameterParser.cpp -o parser/ParameterParser.o $(CXXFLAGS) 

binding/Python/PythonVectorParser.o: binding/Python/PythonVectorParser.cpp binding/Python/PythonVectorParser.h
	$(CPP) -c binding/Python/PythonVectorParser.cpp -o binding/Python/PythonVectorParser.o $(CXXFLAGS) 

module/RegulatorFactory.o: module/RegulatorFactory.cpp module/name.h module/NoiseGenerator.h module/RegulatorFactory.h module/Regulator.h
	$(CPP) -c module/RegulatorFactory.cpp -o module/RegulatorFactory.o $(CXXFLAGS) 

module/NoiseGenerator.o: module/NoiseGenerator.cpp module/NoiseGenerator.h
	$(CPP) -c module/NoiseGenerator.cpp -o module/NoiseGenerator.o $(CXXFLAGS) 

parser/NetworkParser.o: parser/NetworkParser.cpp parser/ParameterParser.h module/NoiseGenerator.h parser/NetworkParser.h module/Network.h module/constant.h module/Regulator.h parser/TopologyParser.h
	$(CPP) -c parser/NetworkParser.cpp -o parser/NetworkParser.o $(CXXFLAGS) 

binding/Python/TRaNS.o: binding/Python/TRaNS.cpp binding/Python/PythonNetworkWrapper.h
	$(CPP) -c binding/Python/TRaNS.cpp -o binding/Python/TRaNS.o $(CXXFLAGS) 

module/Network.o: module/Network.cpp module/NoiseGenerator.h module/Network.h module/constant.h module/Regulator.h
	$(CPP) -c module/Network.cpp -o module/Network.o $(CXXFLAGS) 
