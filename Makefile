final: mainServer.cpp subServer.cpp client.cpp
	g++ mainServer.cpp -o mainServer.out
	g++ subServer.cpp -o subServer.out
	g++ client.cpp -o client.out
	g++ prg.cpp -o prg.exe.out

mainServer:
	./mainServer.out

subServer:
	./subServer.out

client:
	./client,out

prg:
	./prg.out

mainServer: mainServer.cpp
	g++ mainServer.cpp -o mainServer.out

subServer: subServer.cpp
	g++ subServer.cpp -o subServer.out

client: client.cpp
	g++ client.cpp -o client.out

client: prg.cpp
	g++ prg.cpp -o prg.out

clean:
	rm mainServer.out
	rm subServer.out
	rm client.out
	rm prg.out
