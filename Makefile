bin/makemake: bin/app.o  bin/login.o  bin/rainbow.o  bin/db.o  bin/filehandling.o  bin/Homescreen.o
	g++ --std=c++17 bin/app.o bin/login.o bin/rainbow.o bin/db.o bin/filehandling.o bin/Homescreen.o -o bin/app

bin/app.o: source/app.cpp
	g++ --std=c++17 -c source/app.cpp -o bin/app.o

bin/login.o: includes/login/login.cpp includes/login/login.h
	g++ --std=c++17 -c includes/login/login.cpp -o bin/login.o

bin/rainbow.o: includes/rainbow/rainbow.cpp includes/rainbow/rainbow.h
	g++ --std=c++17 -c includes/rainbow/rainbow.cpp -o bin/rainbow.o

bin/db.o: includes/db/db.cpp includes/db/db.h
	g++ --std=c++17 -c includes/db/db.cpp -o bin/db.o

bin/filehandling.o: includes/filehandling/filehandling.cpp includes/filehandling/filehandling.h
	g++ --std=c++17 -c includes/filehandling/filehandling.cpp -o bin/filehandling.o

bin/Homescreen.o: includes/Homescreen/Homescreen.cpp includes/Homescreen/Homescreen.h
	g++ --std=c++17 -c includes/Homescreen/Homescreen.cpp -o bin/Homescreen.o

clean:
	rm -rf bin/*.o
