CC = g++

drawtri : main.o mainframe.o dialogs.o openGLCanvas.o
	$(CC) -o drawtri main.o mainframe.o dialogs.o `wx-config --libs --gl-libs`

main.o : main.cpp 
	$(CC) `wx-config --cxxflags --gl-libs` -c main.cpp -o main.o

dialogs.o : dialogs.cpp dialogs.h mainframe.h
	$(CC) `wx-config --cxxflags --gl-libs` -c dialogs.cpp -o dialogs.o

mainframe.o : mainframe.cpp mainframe.h
	$(CC) `wx-config --cxxflags --gl-libs` -c mainframe.cpp -o mainframe.o
	
openGLCanvas.o : openGLCanvas.cpp openGLCanvas.h
	$(CC) `wx-config --cxxflags --gl-libs` -c openGLCanvas.cpp -o openGLCanvas.o
clean : 
	rm -f *.o drawtri 
	
