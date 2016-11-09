exe ?= out.bin
file ?= sync.c
CFLAGS = -Wall -std=gnu99
LDFLAGS = -pthread

all : $(exe)

run : $(exe)
	@echo -c "\nExecuting ./$(exe)\n"
	./$(exe)
	@echo -c "\nDone from Makefile\n"

debug : CFLAGS += -g -DDEBUG
debug : $(exe)


$(exe) : $(file)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

clean :
	rm -rf $(exe)

