build:
	gcc -O3 -rdynamic -std=c99 -I. -L. -Wl,-rpath=.  -llib  dle.c -lm  -o dle -ldl

lib:
	gcc -Wall -lm -fPIC -c lib.c
	gcc -shared -Wl,-soname,liblib.so.1 -o liblib.so.1.0 lib.o 
	mv liblib.so.1.0 liblib.so