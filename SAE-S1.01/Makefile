CXX := g++
RM  := rm -f

TARGET	:= main.elf
TEST	:= cat.pgm
OUTPUT	:= out.txt


all:	$(TARGET)
	clear
	./$< --input $(TEST) --output $(OUTPUT)
	./$< --input $(TEST) --output /dev/tty0

clean:	$(TARGET)
	$(RM) $^
  
%.elf:	*.cc
	$(CXX) -o $@ $^
