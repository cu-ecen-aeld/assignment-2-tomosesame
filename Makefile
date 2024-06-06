CC := gcc
CFLAGS := -Wall -Wextra -Werror

ifeq ($(CROSS_COMPILE),)
CROSS_COMPILE :=
endif

writer: finder-app/writer.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -o writer finder-app/writer.c

clean:
	rm -f writer *.o

.PHONY: clean
