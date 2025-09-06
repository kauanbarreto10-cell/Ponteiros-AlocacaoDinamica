all: main.out

main.out: main.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

main.o: main.c
	$(CC) $(CFLAGS) -c $<

.PHONY: test
test: main.out
	bash ./testes/test1.sh

.PHONY: clean
clean:
	rm -f main.out *.o