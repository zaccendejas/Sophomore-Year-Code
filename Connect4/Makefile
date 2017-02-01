
CMP = g++
CLASS = C4Col
CLASS2 = C4Board
MAIN = main
EXEC = go
FLAGS = -std=c++11

$(EXEC): $(CLASS).o $(CLASS2).o $(MAIN).o
	$(CMP) $(FLAGS) $(MAIN).o  $(CLASS).o $(CLASS2).o -o $(EXEC)

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) $(FLAGS) -c $(CLASS).cpp -o $(CLASS).o

$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h
	$(CMP) $(FLAGS) -c $(CLASS2).cpp -o $(CLASS2).o

clean:
	rm $(CLASS).o $(CLASS2).o $(MAIN).o
	rm $(EXEC)

