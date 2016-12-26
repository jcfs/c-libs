all: heap.o heap_sample.o
	gcc -o heap_sample heap_sample.o heap.o

heap.o: heap.c
	gcc -c heap.c

heap_sample.o: heap_sample.c
	gcc -c heap_sample.c

clean:
	@rm -rf *.o heap_sample
