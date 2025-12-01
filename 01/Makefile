CC = gcc
CFLAGS = -Wall

TARGETS = a b

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(TARGETS) 
