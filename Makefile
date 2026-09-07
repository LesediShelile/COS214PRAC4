CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SOURCES = $(wildcard *.cpp)
OBJECTS =$(SOURCES:.cpp=.o)
		
TARGET = taskforge
$(TARGET):$(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<


clean: 
	rm -f *.o taskforge.exe
