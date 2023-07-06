NOT INSTALLED RN
encrypt.o: encrypt.h encrypt.c
	gcc -c encrypt.c

hider.o: message_hider.c
	gcc -c message_hider.c

hider_make: hider.o encrypt.o
	gcc hider.o encrypt.o -o hider_make

