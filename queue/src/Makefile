all: queue.o queue_sample.o
	gcc -o queue_sample queue_sample.o queue.o

queue.o: queue.c
	gcc -c queue.c

queue_sample.o: queue_sample.c
	gcc -c queue_sample.c

clean:
	@rm -rf *.o queue_sample
