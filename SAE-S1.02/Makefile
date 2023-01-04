CXX		:= g++
CFLAGS	:= -Wall -std=c++17 -v -O3

TARGET	:= main.elf


all:	$(TARGET)

clean:	
	$(RM) *.elf *.csv

run:	$(TARGET)
	./$<


%.elf:	*.cpp
	$(CXX) $(CFLAGS) -o $@ $^