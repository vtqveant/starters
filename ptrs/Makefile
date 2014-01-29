CFLAGS=
INCLUDES=
LIBRARIES=
OBJS=src/main.o


%.o: %.c
	gcc -fPIC $(CFLAGS) $(INCLUDES) -c -o $@ $<

main: $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS) $(LIBRARIES) 

clean:
	-rm $(OBJS)
