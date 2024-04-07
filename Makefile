OPT = -Wall

a5: main.o Escape.o Hero.o Participant.o MoveBehaviour.o Ninja.o Snorc.o random.o
	g++ $(OPT) -o a5 main.o Escape.o Hero.o Participant.o MoveBehaviour.o Ninja.o Snorc.o random.o

main.o: main.cc Escape.h
	g++ $(OPT) -c main.cc 

Escape.o: Escape.cc Escape.h List.h Participant.h Hero.h Snorc.h Ninja.h defs.h
	g++ $(OPT) -c Escape.cc 

Hero.o: Hero.cc Hero.h Participant.h defs.h
	g++ $(OPT) -c Hero.cc 

MoveBehaviour.o: MoveBehaviour.cc MoveBehaviour.h defs.h Escape.h
	g++ $(OPT) -c MoveBehaviour.cc 

Ninja.o: Ninja.cc Ninja.h Participant.h defs.h
	g++ $(OPT) -c Ninja.cc 

Participant.o: Participant.cc Participant.h MoveBehaviour.h defs.h
	g++ $(OPT) -c Participant.cc 

Snorc.o: Snorc.cc Snorc.h Participant.h defs.h
	g++ $(OPT) -c Snorc.cc 

random.o: random.cc
	g++ $(OPT) -c random.cc 

clean:
	rm -f *.o a5