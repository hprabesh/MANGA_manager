CXXFLAGS = --std=c++17
GTXFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: manga

debug: CXXFLAGS += -g
debug: manga

manga: main.o mainwin.o multientrydialog.o entrydialog.o store.o order.o item.o customer.o product.o plant.o tool.o mulch.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o multientrydialog.o entrydialog.o store.o order.o item.o customer.o product.o plant.o tool.o mulch.o $(GTXFLAGS) -o manga
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTXFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTXFLAGS) -o mainwin.o
entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTXFLAGS) -o entrydialog.o
multientrydialog.o: multientrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c multientrydialog.cpp $(GTXFLAGS) -o multientrydialog.o
customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp -o customer.o
cli.o: cli.cpp *.h
	$(CXX) $(CXXFLAGS) -c cli.cpp -o cli.o
store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp -o store.o
order.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c order.cpp -o order.o
item.o: item.cpp item.h
	$(CXX) $(CXXFLAGS) -c item.cpp -o item.o
product.o: product.cpp *.h
	$(CXX) $(CXXFLAGS) -c product.cpp -o product.o
plant.o: plant.cpp *.h
	$(CXX) $(CXXFLAGS) -c plant.cpp -o plant.o
tool.o: tool.cpp *.h
	$(CXX) $(CXXFLAGS) -c tool.cpp -o tool.o
mulch.o: mulch.cpp *.h
	$(CXX) $(CXXFLAGS) -c mulch.cpp -o mulch.o

clean:
	rm -f *.o *.gch ~* a.out manga

