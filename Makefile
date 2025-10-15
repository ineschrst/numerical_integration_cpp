all: numerical 

numerical: src/main.cpp src/integration.cpp
	g++ src/main.cpp src/integration.cpp -o numerical 

clean: 
	rm -f numerical 

run: numerical 
	./numerical