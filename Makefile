CPP=$(notdir $(shell (which FCCpx 2>/dev/null || which g++-5 || which g++) | tail -n 1) )
OPT=-O3 -Wall -DNDEBUG -fopenmp
INCLUDE=-I$(BOOST_PATH)

ifeq ($(CPP),FCCpx)
	OPT=-Kfast -Xg -fopenmp
endif

wsn.out: Makefile main.cpp node.cpp node.hpp random.cpp random.hpp wsn_nd_ld_aging.cpp wsn_nd_ld_aging.hpp
	$(CPP) $(OPT) $(INCLUDE) main.cpp wsn_nd_ld_aging.cpp random.cpp node.cpp -o wsn.out

clean:
	rm -f *.o wsn.out
