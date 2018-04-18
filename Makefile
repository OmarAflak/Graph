CC = g++
ODIR = obj
CXXFLAG = -std=c++11

all : $(ODIR) $(ODIR)/node.o $(ODIR)/edge.o $(ODIR)/graph.o $(ODIR)/utils.o

$(ODIR)/node.o : ./src/node.cpp ./include/node.h ./include/dataInterface.h ./include/utils.h
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/edge.o : ./src/edge.cpp ./include/edge.h ./include/node.h ./include/dataInterface.h ./include/utils.h
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/graph.o : ./src/graph.cpp ./include/graph.h ./include/graphEntry.h ./include/edge.h ./include/node.h ./include/dataInterface.h ./include/utils.h
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/utils.o : ./src/utils.cpp ./include/utils.h
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR) :
	if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

.PHONY : clean
clean :
	if [ -d $(ODIR) ]; then rm $(ODIR) -r; fi
