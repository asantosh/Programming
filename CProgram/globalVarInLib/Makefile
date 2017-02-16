LIB_NAME = libgsh.so
APP_1 = app_a
APP_2 = app_b

CFLAGS+= -lgsh -L.

all: $(LIB_NAME) $(APP_1) $(APP_2)

$(LIB_NAME): libgsh.c
	$(CC) -c $< -fPIC -o $@

$(APP_1): app_a.c
$(APP_2): app_b.c 


clean:
	-rm $(LIB_NAME) $(APP_1) $(APP_2) > /dev/null 2>&1
