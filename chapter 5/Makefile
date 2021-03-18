CC = clang
CFLAGS = -Wall -Wextra
TARGETS := $(foreach i,$(shell seq 8),hw$i.out)

all: $(TARGETS)

%.out: %.c
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	rm -f ./*.out