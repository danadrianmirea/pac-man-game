# Variables
CXX = clang++
CXXFLAGS = -std=c++11 -I ./includes
LDFLAGS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
LIBS = lib/libraylib.a
EXEC = pac-man

SRC =	src/main.cpp \
		src/run_game.cpp \
		src/Map/Map.cpp \
		src/Key/Key.cpp \
		src/PacMan/PacMan.cpp \
		src/PacMan/Cpu.cpp

all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@

clean:
	rm -f $(EXEC)

re: clean all

run: re
	./$(EXEC)

.PHONY: all clean run