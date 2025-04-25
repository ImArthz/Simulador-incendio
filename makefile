CC = g++
CFLAGS = -Wall -std=c++11 -Isrc
SRCDIR = src
BINDIR = bin
SOURCES = $(wildcard $(SRCDIR)/*/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SOURCES))
EXECUTABLE = simulador

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BINDIR) $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)