all: donut order main.cpp
	g++ -pedantic-errors -g main.cpp donut order -o main
donut: donut.h donut.cpp
	g++ -pedantic-errors -g -c donut.cpp -o donut
order: order.h order.cpp
	g++ -pedantic-errors -g -c order.cpp -o order