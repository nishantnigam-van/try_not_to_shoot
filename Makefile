files := main.cpp texture.cpp enemy.cpp player.cpp background.cpp gamelogic.cpp bullets.cpp


default:
	cd src; g++ ${files} -lSDL3 -lSDL3_image -o mygame; ./mygame
