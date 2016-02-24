CC = g++

drawtri : main.o mainframe.o dialogs.o
	$(CC) -o drawtri main.o mainframe.o dialogs.o `wx-config --libs --gl-libs`

main.o : main.cpp 
	$(CC) `wx-config --cxxflags` -c main.cpp -o main.o

dialogs.o : dialogs.cpp dialogs.h mainframe.h
	$(CC) `wx-config --cxxflags` -c dialogs.cpp -o dialogs.o

mainframe.o : mainframe.cpp
	$(CC) `wx-config --cxxflags` -c mainframe.cpp -o mainframe.o

clean : 
	rm -f *.o drawtri 
	
