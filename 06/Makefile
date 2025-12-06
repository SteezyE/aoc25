CC = gcc
CFLAGS = -Wall

TARGETS = a

all: $(TARGETS)

%: %.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.SUFFIXES: # remove implicit rules

.PHONY: clean
clean:
	rm $(TARGETS)
