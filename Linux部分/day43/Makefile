CC :=gcc
srcs :=$(wildcard *.c)
targets :=$(patsubst %.c,%,$(srcs))
all:$(targets)

%:%.c
	$(CC) -o $@ $< -lpthread -g
rebuild:clean all
clean:
	rm -rf $(targets)
