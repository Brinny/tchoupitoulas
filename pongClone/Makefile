CXX = g++
LDLIBS = -lglut -lGL -lGLEW -lIL -lILU

pong: pong.o Utilities.o Vertex.o Ball.o Paddle.o
	$(CXX) -o pong pong.o Utilities.o Vertex.o Ball.o Paddle.o $(LDLIBS) 

pong.o: pong.cpp pong.h Utilities.h Ball.h Paddle.h Vertex.h
	$(CXX) $(LDLIBS) -c pong.cpp

Vertex.o: Vertex.h
	$(CXX) $(LDLIBS) -c Vertex.cpp

Ball.o: Ball.h Vertex.h
	$(CXX) $(LDLIBS) -c Ball.cpp

Paddle.o: Paddle.h Vertex.h
	$(CXX) $(LDLIBS) -c Paddle.cpp

Utilities.o: Utilities.h
	$(CXX) $(LDLIBS) -c Utilities.cpp
