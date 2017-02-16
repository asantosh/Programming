LIB_NAME = libgsh.so
APP_1 = app_a
APP_2 = app_b

LDFLAGS = -lgsh -L$(PWD)/

all: $(LIB_NAME) $(APP_1) $(APP_2)

$(LIB_NAME): libgsh.c
	$(CC) -c $< -fPIC
	$(CC) -shared -Wl,-soname,$@ -o $@  *.o


$(APP_1): app_a.c
	$(CC) $< $(LDFLAGS) -o $@

$(APP_2): app_b.c 
	$(CC) $< $(LDFLAGS) -o $@


clean:
	-rm $(LIB_NAME) $(APP_1) $(APP_2) *.o > /dev/null 2>&1
