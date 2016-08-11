# boost library is necessary
# specify it by INCLUDE environment variables

OPT ?= -O3 -Wall -DNDEBUG -fopenmp
INCLUDE ?=

wsn.out: Makefile main.cpp node.cpp node.hpp random.cpp random.hpp wsn_nd_ld_aging.cpp wsn_nd_ld_aging.hpp
	$(CXX) $(OPT) $(INCLUDE) main.cpp wsn_nd_ld_aging.cpp random.cpp node.cpp -o wsn.out

clean:
	rm -f *.o wsn.out
