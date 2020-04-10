bin/makemake: bin/app.o  bin/login.o  bin/rainbow.o bin/database.o bin/filehandling.o bin/homescreen.o
	g++ --std=c++17 bin/app.o bin/login.o bin/rainbow.o bin/database.o bin/filehandling.o bin/homescreen.o -o bin/app

bin/app.o: source/app.cpp
	g++ --std=c++17 -c source/app.cpp -o bin/app.o

bin/login.o: includes/login/login.cpp includes/login/login.h
	g++ --std=c++17 -c includes/login/login.cpp -o bin/login.o

bin/rainbow.o: includes/rainbow/rainbow.cpp includes/rainbow/rainbow.h
	g++ --std=c++17 -c includes/rainbow/rainbow.cpp -o bin/rainbow.o

bin/database.o: includes/database/database.cpp includes/database/database.h
	g++ --std=c++17 -c includes/database/database.cpp -o bin/database.o

bin/filehandling.o: includes/filehandling/filehandling.cpp includes/filehandling/filehandling.h
	g++ --std=c++17 -c includes/filehandling/filehandling.cpp -o bin/filehandling.o

bin/homescreen.o : includes/Homescreen/Homescreen.cpp includes/Homescreen/Homescreen.h
	g++ --std=c++17 -c includes/Homescreen/Homescreen.cpp -o bin/homescreen.o

clean:
	rm -rf bin/*.o
