samples: heap_sample.o heap.o
	gcc -o heap_sample heap_sample.o heap.o queue.o

heap.o: heap.c
	gcc -c heap.c -ansi -pedantic -Wall

heap_sample.o: heap_sample.c
	gcc -c heap_sample.c

clean:
	@rm -rf *.o heap_sample
