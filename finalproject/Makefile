
CMP = g++
CLASS = snowman
CLASS2 = gift
CLASS3 = tree
CLASS4 = coin
CLASS5 = background
MAIN = final
EXEC = go
FLAGS = -std=c++11 -lX11

$(EXEC): $(CLASS).o $(CLASS2).o $(CLASS3).o $(CLASS4).o $(CLASS5).o $(MAIN).o
	$(CMP) $(FLAGS) $(MAIN).o gfxnew.o $(CLASS).o $(CLASS2).o $(CLASS3).o $(CLASS4).o $(CLASS5).o -o $(EXEC) 
	# gfxnew.o is used for Windows machines. For Macs, it should be replaced with gfxnew_mac.o

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) $(FLAGS) -c $(CLASS).cpp -o $(CLASS).o

$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h
	$(CMP) $(FLAGS) -c $(CLASS2).cpp -o $(CLASS2).o

$(CLASS3).o: $(CLASS3).cpp $(CLASS3).h
	$(CMP) $(FLAGS) -c $(CLASS3).cpp -o $(CLASS3).o

$(CLASS4).o: $(CLASS4).cpp $(CLASS4).h
	$(CMP) $(FLAGS) -c $(CLASS4).cpp -o $(CLASS4).o

$(CLASS5).o: $(CLASS5).cpp $(CLASS5).h
	$(CMP) $(FLAGS) -c $(CLASS5).cpp -o $(CLASS5).o

$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CMP) $(FLAGS) -c $(MAIN).cpp -o $(MAIN).o

clean:
	rm $(CLASS).o $(CLASS2).o $(CLASS3).o $(CLASS4).o $(CLASS5).o $(MAIN).o
	rm $(EXEC)

