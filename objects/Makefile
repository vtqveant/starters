# CFLAGS=-m32
CFLAGS=-m32

OBJS=src/cobjects.o 
INCLUDES=

%.o: %.c
	gcc -fPIC $(CFLAGS) $(INCLUDES) -c -o $@ $<

cobjects: $(OBJS) $(AUDIO_IN_LIB)
	gcc $(CFLAGS) -o $@ $(OBJS) $(LIBRARIES)

clean:
	-rm $(OBJS)
