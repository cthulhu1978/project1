#
p0:     p0.c p0.h
	cc -c p0.c
	cc -o p0 p0.o

clean:
	rm -f p0
	rm -f *.o
