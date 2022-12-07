CXX= /usr/bin/g++
CXXFLAGS= -Wall -std=c++17
OUT= main

a:
	$(CXX) $(CXXFLAGS) -o $(OUT) $(Q)/a.cpp

b:
	$(CXX) $(CXXFLAGS) -o $(OUT) $(Q)/b.cpp

run:
	./$(OUT) < $(Q)/input.txt	

clean:
	rm $(OUT)
