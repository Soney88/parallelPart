#include <stdio.h>
//#include <omp.h>

#include "Init.h"
#include "Destruct.h"
#include "Compute.h"
#include "Params.h"
#include "Prints.h"

int main(int argc, char** argv) {

//    printf("Using %i Threads\n", omp_get_num_procs());
    printf("Initialising...\n");

    long double t_start, t_end, dt;
    long double beamspeed, circumference;
    long double *times;
    long double h;
    int len, k;
    particle p;


    init(&t_start, &t_end, &dt,
        &beamspeed, &circumference,
        &len,
        &times,
        &p,
	&h
    );



    truncateFile();
    truncate_signals();
    printf("Computing...\n");
    compute(t_start, t_end, dt,
        p.x,p.y,p.z,
        p.px,p.py,p.pz,
        p.m,p.q, len,
        &k, &times,
        beamspeed, circumference,
	&h);


    printf("Printing...\n");
    printf("%i Umrundungen\n", k);
    print_signal(&times,len,k);


    destruct(p, &times);



    return EXIT_SUCCESS;
}
