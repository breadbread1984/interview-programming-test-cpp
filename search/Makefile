CXXFLAGS=-I.
LIBS=
OBJS=$(patsubst %.cpp,%.o,$(wildcard *.cpp))
EXECS=$(patsubst %.cpp,%,$(wildcard *.cpp))

all: $(EXECS)

btree: btree.o
	$(CXX) $^ $(LIBS) -o ${@}

clean:
	$(RM) $(OBJS) $(EXECS)
