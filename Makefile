# this is a simple example for a Person to get disease and recover for five days
example: example.o Person.o Population.o
	g++ example.o Person.o Population.o -o output

# run this to get your own pandemix :)
# it's either contact = 0 & social distance = n
# or contact = n & no social distance aka social distance = 0
ebola: ebola.o Person.o Population.o
	g++ ebola.o Person.o Population.o -o output

# run this to start a simulation for 20 ppl with 1 social distance.
covid19: covid19.o Person.o Population.o
	g++ covid19.o Person.o Population.o -o output

# run this to start my Flu simulation
flu: flu.o Person.o Population.o
	g++ flu.o Person.o Population.o -o output

ebola.o: ebola.cpp
	g++ -c ebola.cpp

example.o: example.cpp
	g++ -c example.cpp

covid19.o: covid19.cpp
	g++ -c covid19.cpp

flu.o: flu.cpp
	g++ -c flu.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

Population.o: Population.cpp Population.h
	g++ -c Population.cpp

clean:
	rm *.o output