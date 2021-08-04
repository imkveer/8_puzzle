#include <stdio.h>
#include <stdlib.h>

int manhattan(int A[][3], int B[][3]);
int alter(int A[][3], int B[][3],int steps);
int diffup(int A[][3], int B[][3]);
int diffdown(int A[][3], int B[][3]);
int diffleft(int A[][3], int B[][3]);
int diffright(int A[][3], int B[][3]);
int minimum(int a, int b, int c, int d);
void display(int A[][3]);
int main(int argc, char *argv[])
{
	  int A[3][3] = {{4,3,0}, {6,7,2}, {8,1,5}};

	    int B[3][3] =  {{0,1,2}, {3,4,5}, {6,7,8}};
         int i, j,d;
	       int steps =0 ;
	       printf("   Target: \n");
	       display(B);
	       printf("   Original: \n");
	       display(A);
			printf("\ninitial manhattan distance =  %d 	\n",manhattan(B,A));
			while(1)
			{
			    			d = manhattan(A, B);
									       if(d==0)     {  printf("\n\n\n puzzle solved in steps : %d\n\n", steps);    return 0; 	}


									       steps++;

									       printf("\nStep: %d \n", steps);

									       alter(A, B,steps);

									       display(A);



			}

			return 0;
}

void display(int A[][3])
{
	      int i,j;
	            for(i=0;i<3;i++)
			             {
					               for(j=0;j<3;j++)
							                printf(" %d ", A[i][j]);
						                printf("\n");
								         }
		     }

int manhattan(int A[][3], int B[][3])
{

	int counter =0 ,i,j,k,l,m,n,p,s=0;

	for(i=0;i<3; i++)

		for( j=0;j<3;j++)

 			if(A[i][j] != B[i][j])

 			{     p=A[i][j];

     				if((p!=0)&&(B!=0))    {   for(k=0;k<3;k++)
				       for(l=0;l<3;l++)

					       if(B[k][l]==p){
					       if(k>i)
						       m=k-i;
					       else
						       m=i-k;
					       if(l>j)
						       n=l-j;
					       else
						       n=j-l;
					       s=n+m;
					       }
		       }

				       counter=counter+s;
		       }

		      return counter;
}

int alter(int A[][3], int B[][3],int steps)
{

	     int dup, ddown, dleft, dright;
	          int temp, i , j, flag=0, serial=0,q=steps-1;
		       char ran[4],kch[9],change;

		              dup = diffup(A, B);
			      ddown = diffdown(A, B);
			      dleft = diffleft(A, B);
			     dright = diffright(A, B);

			  int min = minimum(dup, ddown, dleft, dright);
               if(steps==2)
					change ='l';
				else if (steps==3)
					change='d';

			      else if (steps==9)
				      change='r';
				else
				{	if (min == dright)
		       			           ran[serial++] = 'r';
				     if (min == dleft)
   			 		            ran[serial++] = 'l';
	 			     if (min == dup)
	    					     ran[serial++] = 'u';
		 		     if (min == ddown)
		                                    ran[serial++] = 'd';


						    int sel = rand()%serial;

						     change = ran[sel];

				}

						    if(change == 'r')

						    {for(i=0;i<3;i++)

							    for (j=0;j<2;j++)

								    if(A[i][j]==0)
                                        {      A[i][j] = A[i][j+1];      A[i][j+1] = 0;
                                    printf("\n minimum manhattan distance =  %d 	\n",manhattan(B,A));
								    printf(" right\n"); return 0;  }
																					          }



						    else if(change == 'l')

						    {for(i=0;i<3;i++)

							    for (j=1;j<3;j++)

								    if(A[i][j]==0)       {      A[i][j] = A[i][j-1];      A[i][j-1] = 0;
								    printf("\n minimum  manhattan distance =  %d 	\n",manhattan(B,A));
								      printf(" left\n");return 0; }

						    }



						    else if(change == 'u')

						    {for(i=1;i<3;i++)

							    for (j=0;j<3;j++)

								    if(A[i][j]==0)
                                        {      A[i][j] = A[i-1][j];      A[i-1][j] = 0;
                                        printf("\n minimum manhattan distance =  %d 	\n",manhattan(B,A));
                                    printf(" up\n");  return 0;}

						    }



						    else if(change == 'd')

						    {for(i=0;i<2;i++)

							    for (j=0;j<3;j++)

								    if(A[i][j]==0)
                                        {      A[i][j] = A[i+1][j];      A[i+1][j] = 0;
								    printf("\n minimum  manhattan distance =  %d 	\n",manhattan(B,A));
								      printf(" down\n"); return 0; }

						    }



						    return 0;

}


int diffup(int A[][3], int B[][3])
{
	     int temp[3][3], i, j;

	          for(i=0;i<3;i++)
			         for (j=0;j<3;j++)
					         temp[i][j] = A[i][j];

		       for(i=1;i<3;i++)
			              for (j=0;j<3;j++)

					      if(A[i][j]==0)

					      {

						      temp[i-1][j] = 0;

						      temp[i][j] = A[i-1][j];

					      }
		           return manhattan(temp, B);
}

int diffdown(int A[][3], int B[][3])
{
	     int temp[3][3], i, j;



	     for(i=0;i<3;i++)

		     for (j=0;j<3;j++)

			     temp[i][j] = A[i][j];



	     for(i=0;i<2;i++)

		     for (j=0;j<3;j++)

			     if(A[i][j]==0)

			     {

				     temp[i+1][j] = 0;

				     temp[i][j] = A[i+1][j];

			     }
		           return manhattan(temp, B);
}

int diffleft(int A[][3], int B[][3])
{
	     int temp[3][3], i, j;
	     for(i=0;i<3;i++)
        for (j=0;j<3;j++)

			     temp[i][j] = A[i][j];

	     for(i=0;i<3;i++)

		     for (j=1;j<3;j++)

			     if(A[i][j]==0)

			     {

				     temp[i][j-1] = 0;

				     temp[i][j] = A[i][j-1];
													                             }
		           return manhattan(temp, B);
}

int diffright(int A[][3], int B[][3])
{
	     int temp[3][3], i, j;
	     for(i=0;i<3;i++)

		     for (j=0;j<3;j++)
			     temp[i][j] = A[i][j];

	     for(i=0;i<3;i++)
		     for (j=0;j<2;j++)
			     if(A[i][j]==0)

			     {
				     temp[i][j+1] = 0;
				     temp[i][j] = A[i][j+1];

			     }
	     return manhattan(temp, B);

}


int minimum (int a, int b, int c , int d)
{
   	int min = a;
	if(b<min)
		min= b;
	if(c<min)
		min = c;
	if(d<min)
		min = d;



	return min;
}
