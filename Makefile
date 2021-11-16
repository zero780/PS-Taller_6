taller6: obj/taller6.o
	gcc -Wall obj/taller6.o -lm -o bin/promedio

obj/taller6.o: src/taller6.c
	gcc -Wall -I include/ -c $^ -lm -o $@

.PHONY: clean

clean:
	rm bin/* obj/*
