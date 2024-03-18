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
	LIBS = lib/libraylib_linux.a
else ifeq ($(UNAME_S),Darwin)
	LDFLAGS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
	LIBS = lib/libraylib_macos.a
endif

all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LIBS) -o $(EXEC) $(LDFLAGS)

clean:
	rm -f $(EXEC)

re: clean all

run: all
	./$(EXEC)

.PHONY: all clean run
