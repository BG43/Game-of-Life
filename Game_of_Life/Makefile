LDFLAGS = -lpthread -lX11

Game_of_Life.o: Game_of_Life.cpp Board.h guiboard.h

guiboard.o: guiboard.cpp guiboard.h

Game_of_Life: Game_of_Life.o guiboard.o
	$(CXX) Game_of_Life.o guiboard.o -o Game_of_Life $(LDFLAGS)

clean:
	rm *.o Game_of_Life
