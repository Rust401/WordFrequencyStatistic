#Uncommit the next line to build the intermidiate file
#all: test.cpp i s att o ll

TARGET=WordMap.cpp main.cpp parser.cpp
LEVEL=-O3
COMPILER= clang++
OUTPUTPATH= ./bin/test

all: $(TARGET)
	$(COMPILER) -std=c++11 -g -o $(OUTPUTPATH) $(TARGET) $(LEVEL)
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