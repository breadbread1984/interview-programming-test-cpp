CXXFLAGS=-I.
LIBS=
OBJS=$(patsubst %.cpp,%.o,$(wildcard *.cpp))
EXECS=$(patsubst %.cpp,%,$(wildcard *.cpp))

all: $(EXECS)

cut_rope: cut_rope.o
	$(CXX) $^ $(LIBS) -o ${@}

clean:
	$(RM) $(OBJS) $(EXECS)
