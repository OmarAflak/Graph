CC = g++
ODIR = obj
PROG = main
CXXFLAG = -std=c++11

$(PROG) : $(ODIR) $(ODIR)/Utils.o $(ODIR)/Node.o $(ODIR)/Graph.o $(ODIR)/main.o $(ODIR)/Vertex.o 
	$(CC) -o $@ $(ODIR)/Utils.o $(ODIR)/Node.o $(ODIR)/Graph.o $(ODIR)/main.o $(ODIR)/Vertex.o $(CXXFLAG)

$(ODIR)/Utils.o : ./src/Utils.cpp ./include/Utils.h 
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/Node.o : ./src/Node.cpp ./include/Node.h 
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/Graph.o : ./src/Graph.cpp ./include/Graph.h ./include/Vertex.h ./include/Utils.h 
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/main.o : ./src/main.cpp ./include/Graph.h 
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/Vertex.o : ./src/Vertex.cpp ./include/Vertex.h ./include/Node.h 
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR) :
	if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

.PHONY : clean
clean :
	if [ -d $(ODIR) ]; then rm $(ODIR) -r; fi
	if [ -f $(PROG) ]; then rm $(PROG); fi

