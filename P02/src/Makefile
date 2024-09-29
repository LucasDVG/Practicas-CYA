# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática 
# Computabilidad y Algoritmia
#
# @author: Lucas de Vera Gil
# @gmail: alu0101550145@ull.edu.es
# @date: 25/09/2024

CXX = g++ 
CXXFLAGS = -std=c++23 -Wall -pedantic

all: p02_strings

p02_strings: main.cc strings.cc
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean

clean :
	@rm -rf *.o *gch *.out
	rm p02_strings
	rm -rf *~basura
	rm -rf a.out