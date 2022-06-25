NAME = 02_FindIfGenericLambda
#NAME = 01_LambdaBasic 02_FindIfGenericLambda  03_GenericCapture  04_multiplyBy2Lambda  05_count_if  06_count_if_ref  07_generate
#IDIR = -I/usr/include/eigen3/Eigen/

OBJECTS = $(NAME).o 

CC = /opt/rh/devtoolset-7/root/usr/bin/g++ -DMIPCH_IGNORE_CXX_SEEK -O3 -msse2 -DNDEBUG -std=c++14

MAKEFLAGS += J4

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(IDIR) $(D) $(LIBS) $(CWP_FLAGS) $(MAKEFLAGS) -o $@

%.o: %.cpp
	$(CC) $(IDIR) $(D) $(CPPFLAGS) -c $<

clean:
	rm -rf $(NAME) *.o *~ out out2 in *.d

