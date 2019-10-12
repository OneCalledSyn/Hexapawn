all: hexapawn

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

