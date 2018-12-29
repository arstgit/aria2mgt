CC=gcc
CFLAGS=-I.
PREFIX=/usr/local

all: main.o
	$(CC) -o main main.o

.PHONY: clean
clean:
	rm main main.o

.PHONY: install
install: main
	mkdir -p ${PREFIX}/bin
	cp $< ${PREFIX}/bin/aria2mgt


.PHONY: uninstall
uninstall:
	rm -f $< ${PREFIX}/bin/aria2mgt
