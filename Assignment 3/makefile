# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall -Iinclude

# Targets
all: musicalLL

musicalLL: mainA3.o createPlayList.o addNewSong.o playPlayList.o playSongGivenId.o playSongGivenName.o countNotesInASong.o deleteASongGivenId.o deletePlayList.o
	$(CC) $(CFLAGS) -o bin/musicalLL $^

# Object file rules
mainA3.o: mainA3.c include/givenA3.h
	$(CC) $(CFLAGS) -c mainA3.c -o mainA3.o

createPlayList.o: src/createPlayList.c include/givenA3.h
	$(CC) $(CFLAGS) -c src/createPlayList.c -o createPlayList.o

addNewSong.o: src/addNewSong.c include/givenA3.h
	$(CC) $(CFLAGS) -c src/addNewSong.c -o addNewSong.o

playPlayList.o: src/playPlayList.c include/givenA3.h
	$(CC) $(CFLAGS) -c src/playPlayList.c -o playPlayList.o

playSongGivenId.o: src/playSongGivenId.c include/givenA3.h
	$(CC) $(CFLAGS) -c src/playSongGivenId.c -o playSongGivenId.o

playSongGivenName.o: src/playSongGivenName.c include/givenA3.h
	$(CC) $(CFLAGS) -c src/playSongGivenName.c -o playSongGivenName.o

countNotesInASong.o: src/countNotesInASong.c include/givenA3.h
	$(CC) $(CFLAGS) -c src/countNotesInASong.c -o countNotesInASong.o

deleteASongGivenId.o: src/deleteASongGivenId.c include/givenA3.h
	$(CC) $(CFLAGS) -c src/deleteASongGivenId.c -o deleteASongGivenId.o

deletePlayList.o: src/deletePlayList.c include/givenA3.h
	$(CC) $(CFLAGS) -c src/deletePlayList.c -o deletePlayList.o

# Clean command (deletes .o files in root and src folders)
clean:
	del /Q *.o 2>NUL
	del /Q src\*.o 2>NUL
	del /Q bin\musicalLL 2>NUL