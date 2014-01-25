CFLAGS=
INCLUDES=
LIBRARIES=
OBJS=src/main.o src/module.o


%.o: %.c
	gcc -fPIC $(CFLAGS) $(INCLUDES) -c -o $@ $<

module.so: $(OBJS)
	gcc -shared -Wl,-soname=module.so -o $@ src/module.o

main: $(OBJS) module.so
	gcc -rdynamic $(CFLAGS) -o $@ $(OBJS) $(LIBRARIES) -ldl

clean:
	-rm $(OBJS)
