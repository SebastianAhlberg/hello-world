#include <string.h>
float parallel(int count, float *array){
	float eRes=0;
	for (int i=0;i<count;i++){
		if (array[i]==0)
			return 0;
		eRes+=1/array[i];
	}
	return (eRes==0 ? 0:1/eRes); 
}

float serial(int count, float *array){
	float eRes=0;
	for (int i=0;i<count;i++){
		eRes+=array[i];
	} 
	return eRes;
}	

float calc_resistance(int count, char conn,float *array){
	if (strcmp(&conn,"P")==0){
		return parallel(count,array);
	}
	else if (strcmp(&conn,"S")==0){
		return serial(count,array);
	}
	else{
		return -1;
	}
}
