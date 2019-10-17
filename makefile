#Uncommit the next line to build the intermidiate file
#all: test.cpp i s att o ll

TARGET=parser.cpp WordMap.cpp utils.cpp main.cpp
LEVEL=-O3
COMPILER= clang++ -std=c++11
OUTPUTPATH= ./bin/test
BOOST=-lboost_system -lboost_filesystem

all: $(TARGET)
	$(COMPILER) -g $(BOOST) -o $(OUTPUTPATH) $(TARGET) $(LEVEL)
	time $(OUTPUTPATH)

i:$(TARGET)
	 $(COMPILER) -E $(TARGET) -o test.i $(LEVEL)

ll:$(TARGET)
	 $(COMPILER) -S -emit-llvm $(TARGET) $(LEVEL)

s:$(TARGET)
	 $(COMPILER) -S -mllvm --x86-asm-syntax=intel $(TARGET) $(LEVEL)

att:$(TARGET)
	 $(COMPILER) -S $(TARGET) -o test_att.s $(LEVEL)

o:$(TARGET)
	 $(COMPILER) -c $(TARGET) -o test.o $(LEVEL)

clean:
	rm -f peda* .gdb* *.i *.ll *.s *.o

refresh:
	rm -f ./WordLibrary/default.wl
	touch ./WordLibrary/default.wl