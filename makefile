CC = g++ -std=c++11
DEBUG = -ggdb
FLAGS = -march=native -pipe -W -Wall -pedantic
LFLAGS = # Replace with project flags
VPATH = ./src # Attach additional directories with "<dir>:<dir>"

SOURCES = ./src/main.cpp

OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS_DEBUG = $(SOURCES:.cpp=$(DEBUG).o)

EXECUTABLE = runWithPrimus

.DEFAULT_GOAL:= debug

release: $(OBJECTS)
	@echo "\nLinking target $@"
	@$(CC) -O2 $(FLAGS) $(LFLAGS) $^ -o $(EXECUTABLE)
	@echo "\nLinking finished"

%.o: %.cpp
	@echo "\nCompiling $<"
	@$(CC) -O2 $(FLAGS) -c $< -o $@

debug: $(OBJECTS_DEBUG)
	@echo "\nLinking target $@"
	$(CC) $(DEBUG) $(FLAGS) $(LFLAGS) $^ -o $(EXECUTABLE)-debug
	@echo "\nLinking finished"

%$(DEBUG).o: %.cpp
	@echo "\nCompiling $<"
	$(CC) $(DEBUG) $(FLAGS) -c $< -o $@

.PHONY: clean

clean:
ifneq ("$(wildcard $(EXECUTABLE)-debug)", "")
	@echo "\nRemoving $(OBJECTS_DEBUG)"
	@rm $(OBJECTS_DEBUG)
	@echo "\nRemoving $(EXECUTABLE)-debug"
	@rm $(EXECUTABLE)-debug
else ifneq ("$(wildcard $(EXECUTABLE))", "")
	@echo "\nRemoving $(OBJECTS)"
	@rm $(OBJECTS)
	@echo "\nRemoving $(EXECUTABLE)"
	@rm $(EXECUTABLE)
endif
