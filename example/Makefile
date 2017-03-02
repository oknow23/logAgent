OBJNAME = test
ifeq ($(CC),'')
	CC = gcc
endif

all: clean
	$(CC) $(OBJNAME).c -L . -llogAG -o $(OBJNAME).o
clean:
	rm -f $(OBJNAME).o
