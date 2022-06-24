NAME = helloworld

OBJECTS = $(NAME).o 

#CC = /opt/rh/devtoolset-8/root/usr/bin/g++ -DMIPCH_IGNORE_CXX_SEEK -O3 -msse2 -DNDEBUG -std=c++2a
CC = g++ -std=c++2a 

MAKEFLAGS += J4

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(IDIR) $(D) $(LIBS) $(CWP_FLAGS) $(MAKEFLAGS) -o $@

%.o: %.cpp
	$(CC) $(IDIR) $(D) $(CPPFLAGS) -c $<

clean:
	rm -rf $(NAME) *.o *~ out in *.d

