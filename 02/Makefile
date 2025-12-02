CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm

TARGETS = a b

all: $(TARGETS)

%: %.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.SUFFIXES: # disable implicit rules

.PHONY: clean
clean:
	rm $(TARGETS)
