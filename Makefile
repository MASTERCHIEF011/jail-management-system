bin/makemake: bin/app.o  bin/login.o  bin/rainbow.o 
	g++ --std=c++17 bin/app.o bin/login.o bin/rainbow.o  -o bin/app

bin/app.o: source/app.cpp
	g++ --std=c++17 -c source/app.cpp -o bin/app.o

bin/login.o: includes/login/login.cpp includes/login/login.h
	g++ --std=c++17 -c includes/login/login.cpp -o bin/login.o

bin/rainbow.o: includes/rainbow/rainbow.cpp includes/rainbow/rainbow.h
	g++ --std=c++17 -c includes/rainbow/rainbow.cpp -o bin/rainbow.o

clean:
	rm -rf bin/*.o
