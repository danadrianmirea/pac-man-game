CXX = clang++
CXXFLAGS = -std=c++11 -I ./includes
EXEC = pac-man

SRC =	src/main.cpp \
		src/game.cpp \
		src/utils.cpp \
		src/pixels.cpp \
		src/Map/Map.cpp \
		src/Key/Key.cpp \
		src/PacMan/PacMan.cpp \
		src/PacMan/Cpu.cpp

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LDFLAGS = -lm -lpthread -ldl -lrt -lX11
else ifeq ($(UNAME_S),Darwin)
	LDFLAGS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
endif

LIBS = lib/libraylib.a

all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(EXEC)

re: clean all

run: all
	./$(EXEC)

.PHONY: all clean run
