CC = g++

CFLAGS = -Wall -g -std=c++11

EXEC = subd catrom spiral

P = Point.cpp

TXTS = subd.txt catrom.txt subdSpiral.txt catromSpiral.txt

C = ConnectedLineSegments.txt

S = spiral.txt

all: subd catrom spiral

subd:
	$(CC) -o $@ $P subd.cpp $(CFLAGS)

catrom:
	$(CC) -o $@ $P catrom.cpp $(CFLAGS)

spiral:
	$(CC) -o $@ $P Spiral.cpp $(CFLAGS)

runSubd:
	./subd  > subd.txt $C

runCatrom:
	./catrom > catrom.txt $C

runSubdSpiral:
	./subd  > subdSpiral.txt $S

runCatromSpiral:
		./catrom > catromSpiral.txt $S

genSpiral:
	./spiral > spiral.txt

run: runSubd runCatrom

runSpiral: genSpiral runSubdSpiral runCatromSpiral

clean:
	rm -f $(EXEC)
	#rm -f $(TXTS) $S
