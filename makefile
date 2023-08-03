image : imagelib.h imagelib.c equaliza.c;\
         gcc imagelib.c equaliza.c -lm -o equaliza;\

limpa  : ;\
         rm -f *~ equaliza *-equaliza.pgm