# Makefile
CC = gcc
CFLAGS = -g -Wall
LDFLAGS =  
OBJECTS = sqllink.o
TARGET = sqllink
INCLUDE = -I/usr/include/mysql
LIBS = -L/usr/lib/aarch64-linux-gnu -lmysqlclient -lz -lzstd -lssl -lcrypto -lresolv -lm
BIN = /root/study/bin

$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) $(INCLUDE) $(LIBS) -g -o $(TARGET)
	

$(OBJECTS) : sqllink.c
	$(CC) $(INCLUDE) -g -c sqllink.c

install:
	cp $(TARGET) $(BIN)

clean:
	rm -f *.o
	rm -f $(TARGET)
#	rm -f *.json
