samples: queue_sample.o queue.o
	gcc -o queue_sample queue_sample.o queue.o

queue.o: queue.c
	gcc -c queue.c -ansi -pedantic -Wall

queue_sample.o: queue_sample.c
	gcc -c queue_sample.c

clean:
	@rm -rf *.o queue_sample
