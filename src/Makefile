all: compiler

OBJS = syntactic.o main.o lexical.o

LLVMCONFIG = llvm-config
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++11

syntactic.cpp: syntactic.y
	bison -d -o $@ $^
	
syntactic.hpp: syntactic.cpp

lexical.cpp: lexical.l syntactic.hpp
	flex -o $@ $^

%.o: %.cpp
	clang++ -c $(CPPFLAGS) -o $@ $<

compiler: $(OBJS)
	clang++ -o $@ $(OBJS) 

clean:
	$(RM) -rf syntactic.cpp syntactic.hpp lexical.cpp $(OBJS) compiler log.txt

test: compiler test.c
	./compiler test.c
