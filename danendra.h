#ifndef danendra_h
#define danendra_h

#include <math.h>
#include <stdio.h>

double trigonometri(double x, char trig){   
    x = (x * M_PI) / 180;
	switch(trig){
        case 's' :
	    	return sin(x);
        case 'c' :  
			return cos(x);
        case 't' :
        	return tan(x);
        default :
       	 printf("pilihan tidak valid !");
    }
}

#endif
