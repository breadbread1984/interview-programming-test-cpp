CXXFLAGS=-I.
LIBS=
OBJS=$(patsubst %.cpp,%.o,$(wildcard *.cpp))
EXECS=$(patsubst %.cpp,%,$(wildcard *.cpp))

all: $(EXECS)

bubble: bubble.o
	$(CXX) $^ $(LIBS) -o ${@}

bucket: bucket.o
	$(CXX) $^ $(LIBS) -o ${@}

count: count.o
	$(CXX) $^ $(LIBS) -o ${@}

heap: heap.o
	$(CXX) $^ $(LIBS) -o ${@}

insert: insert.o
	$(CXX) $^ $(LIBS) -o ${@}

merge: merge.o
	$(CXX) $^ $(LIBS) -o ${@}

qsort: qsort.o
	$(CXX) $^ $(LIBS) -o ${@}

radix: radix.o
	$(CXX) $^ $(LIBS) -o ${@}

select: select.o
	$(CXX) $^ $(LIBS) -o ${@}

shell: shell.o
	$(CXX) $^ $(LIBS) -o ${@}

clean:
	$(RM) $(OBJS) $(EXECS)

