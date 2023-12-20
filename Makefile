CFLAGS = -Wall


all: final

final: main.o gauss.o mat_io.o backsubst.o
        gcc $(CFLAGS) -c $@ $^


main.o: main.c gauss.h mat_io.h backsubst.h
        gcc $(CFLAGS) -c $@ $<


gauss.o: gauss.c gauss.h
        gcc $(CFLAGS) -c $@ $<


mat_io.o: mat_io.c mat_io.h
        gcc $(CFLAGS) -c $@ $<


backsubst.o: backsubst.c backsubst.h
        gcc $(CFLAGS) -c $@ $<


clean: 
        rm -f main.o gauss.o mat_io.o backsubst.o final
