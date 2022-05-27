compile:
	gcc *.c -o trab1 -lm

run:
	./trab1 entrada.txt 2 saida.txt

clean:
	rm -rf *.o