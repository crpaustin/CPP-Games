del *.exe
del *.o
g++ -Wall -c board.cpp
g++ -Wall -c player.cpp
g++ -Wall -c artint.cpp
g++ -Wall -c game.cpp
g++ -Wall -c tictactoeai.cpp
g++ -o tictactoeai board.o player.o artint.o game.o tictactoeai.o
del *.o
cls
tictactoeai
