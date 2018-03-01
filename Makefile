CC = g++
PROG = main
ODIR = obj
SRCS = src
HDRS = include
_OBJS = main.o Utils.o Node.o Vertex.o Graph.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(PROG) : $(ODIR) $(ODIR)/main.o
	$(CC) -o $@ $(OBJS)

$(ODIR)/Utils.o : $(SRCS)/Utils.cpp $(HDRS)/Utils.h
	$(CC) -c $< -o $@

$(ODIR)/Node.o : $(SRCS)/Node.cpp $(HDRS)/Node.h
	$(CC) -c $< -o $@

$(ODIR)/Vertex.o : $(SRCS)/Vertex.cpp $(HDRS)/Vertex.h $(ODIR)/Node.o
	$(CC) -c $< -o $@

$(ODIR)/Graph.o : $(SRCS)/Graph.cpp $(HDRS)/Graph.h $(ODIR)/Utils.o $(ODIR)/Vertex.o
	$(CC) -c $< -o $@

$(ODIR)/main.o : $(SRCS)/main.cpp $(ODIR)/Graph.o
	$(CC) -c $< -o $@

$(ODIR) :
	if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

.PHONY: clean
clean :
	if [ -d $(ODIR) ]; then rm $(ODIR) -r; fi
	if [ -f $(PROG) ]; then rm $(PROG); fi
