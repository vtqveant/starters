OBJS=src/main.o

%.o: %.c
	gcc -fPIC -c -o $@ $<

main: $(OBJS) 
	gcc -o $@ $(OBJS) 

clean:
	-rm $(OBJS)
