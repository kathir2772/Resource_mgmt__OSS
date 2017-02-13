#!/bin/bash

oss:fork_main.o Resource.o chaild_1.o chaild_2.o chaild_3.o chaild_4.o
	gcc fork_main.o Resource.o chaild_1.o chaild_2.o chaild_3.o chaild_4.o -o oss 

fork_main.o:fork_main.c
	gcc -c fork_main.c
Resource.o:Resource.c
	gcc -c Resource.c

chaild_1.o:chaild_1.c
	gcc -c chaild_1.c

chaild_2.o:chaild_2.c
	gcc -c chaild_2.c

chaild_3.o:chaild_3.c
	gcc -c chaild_3.c
chaild_4.o:chaild_4.c
	gcc -c chaild_4.c

clean:
	rm -r *.o	
