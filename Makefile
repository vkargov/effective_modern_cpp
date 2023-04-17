CFLAGS += -std=c++2b -O0 -g3

%: %.cpp
	clang++-12 $^ -o $@ $(CFLAGS)
