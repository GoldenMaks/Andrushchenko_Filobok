CFLAGS = -Wall


all: final

final: main.o gauss.o mat_io.o backsubst.o
	gcc $(CFLAGS) -o $@ $^


main.o: main.c gauss.h mat_io.h backsubst.h
	gcc $(CFLAGS) -c -o $@ $<


gauss.o: gauss.c gauss.h
	gcc $(CFLAGS) -c -o $@ $<


mat_io.o: mat_io.c mat_io.h
	gcc $(CFLAGS) -c -o $@ $<


backsubst.o: backsubst.c backsubst.h
	gcc $(CFLAGS) -c -o $@ $<


clean: 
	rm -f main.o gauss.o mat_io.o backsubst.o final
