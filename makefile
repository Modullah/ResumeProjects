all:
	g++ -std=c++11 main.cpp Menu.cpp validInput.cpp Gameplay.cpp Vampire.cpp Character.cpp Lineup.cpp Barbarian.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp -o main
run:
	./main
clean:
	rm main
