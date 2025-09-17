CXX = g++
CXXFLAGS = -std=c++20 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TARGET = pokemon

SRC = main.cpp \
      $(wildcard entities/core/*.cpp) \
      $(wildcard gui/*.cpp) \
      $(wildcard gui/*/*.cpp) \
      $(wildcard gui/*/*/*.cpp)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

install: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

run:
	clear
	$(MAKE) clean
	$(MAKE) install