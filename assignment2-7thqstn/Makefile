all: pipe pipe1 pipe2

pipe: pipe.c pipes.h
	gcc -o pipe.out pipe.c -lrt
	
pipe1: pipe1.c pipes.h
	gcc -o pipe1.out pipe1.c -lrt
	
pipe2: pipe2.c pipes.h
	gcc -o pipe2.out pipe2.c -lrt

runPipe1:
	./Pipe1.out

runPipe2:
	./Pipe2.out

runPipe:
	./Pipe.out

clean:
	rm -rf *.out *.o
