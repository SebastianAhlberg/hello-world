#include "libresistance.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc,char **argv){
	int count,conn;

	if (argc>2){
		count=atoi(argv[1]);
		conn=*argv[2];
	}
	else 
		return -1;
	
	float *res=malloc(sizeof(int)*count);

	for (int j=0;j<count;j++){
		res[j]=(j+1)*10;
	}

	printf("%f\n",calc_resistance(count,conn,res));
	 
	free(res);	
	return 0;
}
