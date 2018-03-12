#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// compile like:  gcc -Wall -O2 -DNROWS=10000 matrix1.c -o matrix1


#define NCOLS 100

void get_walltime(double *wct) {
  struct timeval tp;
  gettimeofday(&tp,NULL);
  *wct = (double)(tp.tv_sec+tp.tv_usec/1000000.0);
}


int main() {
double *table;
double ts,te;//time end, time start


  table = (double *)malloc(NROWS*NCOLS*sizeof(double)); 
  if (table==NULL) {
    printf("alloc error!\n");
    exit(1);
  }

  // warmup

  
for(int j=0; j<NCOLS; j++){
  for(int i=0 ; i<NROWS;i++){
     table[j*NROWS +i]=j*NROWS +i;
    }
  }
  // ...your code here...

  // get starting time (double, seconds) 
  get_walltime(&ts);
  
  // workload

 for(int j=0; j<NCOLS; j++){
  for(int i=0 ; i<NROWS;i++){
     table[j*NROWS +i]+=2;
    }
  }
    

  // get ending time
  get_walltime(&te);


 for(int j=0; j<NCOLS; j++){
  for(int i=0 ; i<NROWS;i++){
     table[j*NROWS +i]!=j*NROWS+i+2){ 
			printf ( "ERROR\n" );
	      return 1;
				}
    }
  }
  // check results
  double time= te-ts;
  // ...your code here...

  // print time elapsed and/or Maccesses/sec
  printf("Time :%d",time ,"\n")
  // ...your code here...  
  
  free(table);

  return 0;
}

