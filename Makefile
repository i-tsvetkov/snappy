CXX = g++
CXXFLAGS += -Wall -std=c++11
LIBS = -l snappy

all: snappy

snappy: snappy.cpp
	$(CXX) $(CXXFLAGS) snappy.cpp -o snappy $(LIBS)

clean:
	rm -f snappy

