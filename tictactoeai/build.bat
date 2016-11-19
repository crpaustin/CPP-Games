del *.exe
del *.o
g++ -Wall -c board.cpp
g++ -Wall -c tictactoeai.cpp
g++ -Wall -c player.cpp
g++ -Wall -c artint.cpp
g++ -o tictactoeai board.o tictactoeai.o player.o artint.o
tictactoeai
