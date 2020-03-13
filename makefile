salida: main.cpp vector.hpp complejo.hpp racional.hpp
	g++ -o salida $^

clean:
	rm -f *.o salida core
