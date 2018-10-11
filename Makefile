OBJ=test.o libresistance.o
LIB=libresistance.so


all : $(OBJ)
	cc -c -fPIC libresistance.c 
	cc -shared -fPIC -o libresistance.so libresistance.o
	mkdir -p lib
	mv libresistance.so lib/
	cc -o res_test test.c -L./lib -lresistance -Wl,-rpath,./lib/	

lib : libresistance.o
	cc -c -fPIC libresistance.c
	cc -shared -fPIC -o libresistance.so libresistance.o

install: 
	sudo mv lib/libresistance.so /usr/lib
	cc -o /usr/bin/res_test test.o -lresistance

test.o: libresistance.h
libresistance.o : libresistance.h

libresistance.so : libresistance.o
 

