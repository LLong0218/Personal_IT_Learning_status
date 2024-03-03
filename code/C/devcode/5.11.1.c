 #include <stdio.h>
 #define min_min 60
 int cal( int min ){
 	int hour,left_min=min;
 	printf("Begin transation\n");
 	if(left_min>=min_min){
 		hour=min/60;
 		left_min=min%60;
 		if(hour>1&&left_min>1){
 			printf("Convert %d hours and %d minutes\n",hour,left_min);
 		}
 		else
 			printf("Convert %d hour and %d minute\n",hour,left_min);
 	}
 	else{
 		if(left_min>1){
 			printf("Convert %d minutes\n",min);
 		}
 		else
 			printf("Convert %d minute\n",min);
 	}
 	printf("Exit program\n");
 	return 0;
 
 }
 int main(){
 	cal(1);
 }
 
 
