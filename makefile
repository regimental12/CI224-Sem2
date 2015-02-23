#directory for .EXE to be put.
BUILD_DIR=build

#Linked library variable. Will change linked libraries depending on Linux or Windows 
LINKS=-lSDL2
EXE=MineClone

ifeq ($(OS),Windows_NT)
	LINKS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lglew32 -lopengl32
	EXE=MineClone.exe
else
	UNAME_S := $(shell uname -s)
	
	ifeq ($(UNAME_S),Linux)
		LINKS=-lSDL2 -lSDL2_image -lGLEW -lGL -lGLU
		EXE=MineClone
	endif
endif

all:
	@echo 'Building MineClone'
	
	#Test if build directory exists. Then create if not there.
	test -d $(BUILD_DIR) || mkdir $(BUILD_DIR)
	
	g++ src/*.cpp $(LINKS) -std="c++11" -o build/MineClone
	@echo 'Finished building'
	@echo './build/MineClone to run'
	
#deletes outputted .exe	
clean:
	rm build/$(EXE)
	