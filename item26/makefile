CXX := g++
CFLAGS := -std=c++11
CPP = $(wildcard *.cpp)
BIN = $(CPP:.cpp=)

all: $(BIN)

%.o: %.cpp
	$(CXX) -o $@ $(CFLAGS) -c $<

$(BIN): $(CPP:.cpp=.o)
	$(CXX) -o $(<:.o=) $(CFLAGS) $<

clean:
	rm -rf *.o $(BIN)
