CXX = g++ 
CXXFLAGS = -std=c++17 -Wall -pedantic -pedantic-errors
LDFLAGS = -lX11 -lcurl

SOURCES = main.cpp XTranslator/xtranslator.cpp

EXECUTABLE = xtranslator

build:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS)
