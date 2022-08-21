# Makefile
CC = gcc
CFLAGS = -g -Wall
LDFLAGS =  
CFILE = sqlselect.c
OBJECTS = sqlselect.o
TARGET = sqlselect
INCLUDE = -I/usr/include/mysql
LIBS = -L/usr/lib/aarch64-linux-gnu -lmysqlclient -lz -lzstd -lssl -lcrypto -lresolv -lm

$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) $(INCLUDE) $(LIBS) -g -o $(TARGET)
	

$(OBJECTS) : $(CFILE)
	$(CC) $(INCLUDE) -g -c $(CFILE)

clean:
	rm -f *.o
	rm -f $(TARGET)
#	rm -f *.json
