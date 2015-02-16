#Linked library variable. Will change linked libraries depending on Linux or Windows 
LINKS=-lSDL2

ifeq ($(OS),Windows_NT)
	LINKS=-lmingw32 -lSDL2main -lSDL2 -lglew32 -lopengl32
else
	UNAME_S := $(shell uname -s)
	
	ifeq ($(UNAME_S),Linux)
		LINKS=-lSDL2 -lGLEW -lGL
	endif
endif

all:
	@echo 'Building MineClone'
	g++ src/*.cpp $(LINKS) -std="c++11" -o build/MineClone
	@echo 'Finished building'
	@echo './build/MineClone to run'
	
#deletes outputted .exe	
clean:
	rm build/MineClone
	