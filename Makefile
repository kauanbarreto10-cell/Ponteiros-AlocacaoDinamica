saida.out:
	gcc -c main.c 
	gcc -o main.out main.o -lm

clean:
	rm main.out *.o

test: saida.out
	bash ./testes/test1.sh