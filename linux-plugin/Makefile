all: toolgen.so

.phony: clean

clean:
	$(RM) *.o *.so

toolgen.so: toolgen.c
	$(CC) -fPIC -I JavaSDK/include -I JavaSDK/include/linux -shared -o $@ $<
