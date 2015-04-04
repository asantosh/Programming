TARGET 	:= rem_comments
OUTFILE	:= output
INFILE	:= test

CFLAGS := -Wall -g

all:
	@echo "## Build in Progress"
	gcc $(CFLAGS) $(TARGET).c -o $(TARGET)
	@echo "## Build Completed"

run: $(TARGET)
	./$(TARGET) $(INFILE) $(OUTFILE)
	@echo "## --------------------------"
	@echo "## completed: Output File = $(OUTFILE)"

clean:
	@rm $(TARGET) $(OUTPUT)
