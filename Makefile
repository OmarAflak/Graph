CC = g++
ODIR = obj
PROG = graph
CXXFLAG = -std=c++11

$(PROG) : $(ODIR) $(ODIR)/Graph.o $(ODIR)/Utils.o $(ODIR)/Node.o $(ODIR)/Edge.o $(ODIR)/main.o 
	$(CC) -o $@ $(ODIR)/Graph.o $(ODIR)/Utils.o $(ODIR)/Node.o $(ODIR)/Edge.o $(ODIR)/main.o $(CXXFLAG)

$(ODIR)/Graph.o : ./src/Graph.cpp ./include/Graph.h ./include/Edge.h ./include/Utils.h 
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/Utils.o : ./src/Utils.cpp ./include/Utils.h 
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/Node.o : ./src/Node.cpp ./include/Node.h 
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/Edge.o : ./src/Edge.cpp ./include/Edge.h ./include/Node.h 
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/main.o : ./src/main.cpp ./include/Graph.h 
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR) :
	if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

.PHONY : clean
clean :
	if [ -d $(ODIR) ]; then rm $(ODIR) -r; fi
	if [ -f $(PROG) ]; then rm $(PROG); fi

