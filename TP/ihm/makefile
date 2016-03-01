CC = g++

drawtri : main.o mainframe.o dialogs.o openGLCanvas.o
	$(CC) -o drawtri main.o mainframe.o dialogs.o openGLCanvas.o `wx-config --libs --gl-libs` -lglut -lGL

main.o : main.cpp 
	$(CC) `wx-config --cxxflags` -c main.cpp -o main.o

dialogs.o : dialogs.cpp dialogs.h mainframe.h
	$(CC) `wx-config --cxxflags` -c dialogs.cpp -o dialogs.o

mainframe.o : mainframe.cpp mainframe.h
	$(CC) `wx-config --cxxflags` -c mainframe.cpp -o mainframe.o
	
triangle.o : triangle.cpp triangle.h
	$(CC) `wx-config --cxxflags` -c triangle.cpp -o triangle.o
	
openGLCanvas.o : openGLCanvas.cpp openGLCanvas.h
	$(CC) -lglut `wx-config --cxxflags` -c openGLCanvas.cpp -o openGLCanvas.o -lglut -lGL
clean : 
	rm -f *.o drawtri 
	
