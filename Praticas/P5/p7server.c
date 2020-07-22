#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "p7.h"


double sum (double i1, double i2){
    return i1 + i2;
}
double sub (double i1, double i2){
    return i1 - i2;
}
double mult (double i1, double i2){
    return i1 * i2;
}
double quo (double i1, double i2){
    return i1 / i2;
}

struct Calculador fillCalculador(double i1, double i2){
    struct Calculador calc;
    calc.sum = sum(i1,i2);
    calc.sub = sub(i1,i2);
    calc.mult = mult(i1,i2);
    calc.quo = quo(i1,i2);

    return calc;
}

int main(int argc, char **argv) {
	int fd;
	double args[2];
	mkfifo("/tmp/fifo_req", 0660);
	fd = open("/tmp/fifo_req", O_RDONLY);

	int fd2;
	struct Calculador calc;
	mkfifo("/tmp/fifo_ans", 0660);
	fd2 = open("/tmp/fifo_ans", O_WRONLY);


	while (read(fd,  args, 2 * sizeof(double)) > 0) {
		if ( args[0] == 0 && args[1] == 0) break;
		calc = fillCalculador(args[0], args[1]);
		write(fd2, &calc, sizeof(struct Calculador));
	}

	close(fd); close(fd2);
	unlink("/tmp/fifo_req"); unlink("/tmp/fifo_ans");

	return 0;
}
