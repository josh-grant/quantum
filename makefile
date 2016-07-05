default:
    @echo “USAGE: make <build>”

qubit:
	gcc -std=c11 -Wall -Wextra -Werror -g -pedantic ./src/qubittest.c -o ./bin/qubittest


clean:
	rm -rf ./bin/*