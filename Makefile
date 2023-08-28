all: SolveEquation

test: SquareSolverWithTest.o Solving.o AnswerEqual.o test.o
	g++ -o myprog.exe SquareSolver2.o Solving.o AnswerEqual.o test.o

SolveEquation: SquareSolver2.o Solving.o AnswerEqual.o
	g++ -o myprog.exe SquareSolver2.o Solving.o AnswerEqual.o

SquareSolver2.o: SquareSolver2.cpp
	g++ -c SquareSolver2.cpp

SquareSolverWithTest.o: SquareSolver2.cpp
	g++ -DTEST -c  SquareSolver2.cpp


Solving.o: Solving.cpp
	g++ -c Solving.cpp

test.o: test.cpp
	g++ -c test.cpp

AnswerEqual.o: AnswerEqual.cpp
	g++ -c AnswerEqual.cpp

clean:
	rm *.o