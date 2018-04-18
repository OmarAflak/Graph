CC = g++
ODIR = obj
PROG = graph
CXXFLAG = -std=c++11

$(PROG) : $(ODIR) $(ODIR)/graph.o $(ODIR)/utils.o $(ODIR)/node.o $(ODIR)/edge.o $(ODIR)/main.o
	$(CC) -o $@ $(ODIR)/graph.o $(ODIR)/utils.o $(ODIR)/node.o $(ODIR)/edge.o $(ODIR)/main.o $(CXXFLAG)

$(ODIR)/graph.o : ./src/graph.cpp ./include/graph.h ./include/edge.h ./include/utils.h
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/utils.o : ./src/utils.cpp ./include/utils.h
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/node.o : ./src/node.cpp ./include/node.h
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/edge.o : ./src/edge.cpp ./include/edge.h ./include/node.h
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/main.o : ./src/main.cpp ./include/graph.h
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR) :
	if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

.PHONY : clean
clean :
	if [ -d $(ODIR) ]; then rm $(ODIR) -r; fi
	if [ -f $(PROG) ]; then rm $(PROG); fi
