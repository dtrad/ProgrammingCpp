NAME = test_Inv
IDIR=-I/usr/include/eigen3/Eigen/

OBJECTS = $(NAME).o Timer.o 
MAKEFLAGS += -j4
CC=/opt/rh/devtoolset-7/root/usr/bin/g++ -DMIPCH_IGNORE_CXX_SEEK -O3 -msse2 -DNDEBUG -g -std=c++14  -fopenmp

$(NAME): $(OBJECTS) 
	$(CC) $(OBJECTS) $(IDIR) $(D) $(LIBS) $(CWP_FLAGS)  -o $@ 
%.o : %.cpp 
	$(CC) $(IDIR) $(D) $(CPPFLAGS)  -c $<
clean:
	rm -rf $(NAME) *.o *~ out out2 in *.d

