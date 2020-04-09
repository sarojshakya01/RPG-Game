if [ -f *.out ]; then
    rm *.out
fi
g++ character.cpp main.cpp mage.cpp barbarian.cpp game.cpp -Wall -Wextra -std=c++11 -o a.out
# g++ character.cpp main.cpp barbarian.cpp -Wall -Wextra -std=c++11 -o a.out

if [ -f a.out ]; then
    ./a.out < input.txt
fi