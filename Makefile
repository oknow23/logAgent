OBJS = logAgent.o
SLIB = liblogAG.a

ifeq ($(CC),'')
	CC = gcc
endif

ifeq ($(AR),'')
	AR = ar
endif

All: clean
	$(CC) -c logAgent.c -o $(OBJS)
	$(AR) rcs $(SLIB) $(OBJS)
	cp $(SLIB) example

clean:
	rm -f $(OBJS) $(SLIB)
