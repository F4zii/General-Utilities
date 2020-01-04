#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define M 50

// computes the imtegral image from the original image
void compute_integral_image(int image[][M], int n, int m, int integral_image[][M]);

// the sum of the rectangle , like the formula
int sum_rect(int integral_image[][M], int rect[4]);

/* calculating the sliding average of
sliding window in the original image */
void sliding_average(int integral_image[][M], int n, int m, int h, int w, int average[][M]);

// gets the image dimensions from the user
void get_image_dimensions(int *n, int *m);

// gets the image from the user
void get_image(int n, int m, int image[][M]);

// gets the sliding window dimensions from the user
void get_sliding_window_dimensions(int *n, int *m, int *h, int *w);

// calculates integral and average
void calculate_integral_and_average(int image[][M],int integral_image[][M],int average[][M],int n,int m,int h,int w);

// prints integral and average images
void print_integral_and_average(int integral_image[][M],int average[][M],int n,int m);

//prints the matrix in size of n*m
void print_matrix(int img[][M],int n,int m);


int main()
{
     int image[M][M], integral_image[M][M], average[M][M];
     int n,m,h,w;
     get_image_dimensions(&n, &m);
     get_image(n,m,image);
     get_sliding_window_dimensions(&n,&m,&h,&w);
     calculate_integral_and_average(image,integral_image,average,n,m,h,w);
     //print results
     print_integral_and_average(integral_image,average,n,m);

     return 0;
}


void compute_integral_image(int image[][M], int n, int m, int integral_image[][M])
{
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<m;j++)
          {
               if(i==0&&j==0)
               {
                    integral_image[i][j]=image[0][0];
               }
               else if(i==0)
               {
                    integral_image[i][j]=image[i][j]+integral_image[i][j-1];
               }
               else if(j==0)
               {
                    integral_image[i][j]=image[i][j]+integral_image[i-1][j];
               }
               //calculate some values that will be used in the calculate below
               else
               {
               		//the cell in location i,j (i!=0&&j!=0) is the_cell_in_image + the_cells_in_locations_[i-1][j],[i][j-1]_in_integral - the_cell_in_location_[i-1][j-1]_in_integral
                    integral_image[i][j]=
                    /*the cell in image*/
				integral_image[i-1][j]
				/*the cells in locations [i][j-1],[i-1][j] in integral*/
				+integral_image[i][j-1]+image[i][j]
				/*the cell in location [i-1][j-1] in integral*/
				-integral_image[i-1][j-1];
               }
          }
     }
}

int sum_rect(int integral_image[][M], int rect[4])
{
     //rect[0]=top
     //rect[1]=left
     //rect[2]=bottom
     //rect[3]=right
     return integral_image[rect[2]][rect[3]]-integral_image[rect[0]-1][rect[3]]-integral_image[rect[2]][rect[1]-1]+integral_image[rect[0]-1][rect[1]-1];
}

void sliding_average(
 int integral_image[][M], int n, int m, int h, int w, int average[][M]
)
{
     int rect[4]={0};
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<m;j++)
          {
               //calc the top,left,bottom,right
               rect[0]=i-(h/2);
               rect[1]=j-(w/2);
               rect[2]=i+(h/2);
               rect[3]=j+(w/2);
               if(i==0)
                    rect[0]=0;
               if(j==0)
                    rect[1]=0;
               if(i+h/2>=n)
                    rect[2]=n-1;
               if(j+w/2>=m)
                    rect[3]=m-1;
               //set the average
               average[i][j]=round(sum_rect(integral_image,rect)/((double)h*w));
          }
     }
}

//get dimensions from user
void get_image_dimensions(int *n, int *m)
{

     printf("Enter image dimensions:\n");
     while(scanf("%d%d",n,m)!=EOF&&(*n>50||*m>50||*n<0||*m<0))
     {
          printf("Invalid input.\nEnter image dimensions:\n");
          scanf("%d%d",n,m);
     }
}

void get_image(int n, int m, int image[][M])
{
    //get image from user
     printf("Enter image:\n");
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<m;j++)
          {
               scanf("%d",&(image[i][j]));
          }
     }
}


void get_sliding_window_dimensions(int *n, int *m, int *h, int *w)
{
     printf("Enter sliding window dimensions:\n");
     do {
          if (scanf("%d%d",h,w)==2) break;
     }while(scanf("%d%d",h,w)!=EOF&&(*n<*h||*m<*w||*h<0||*w<0));
}



//prints the matrix
void print_matrix(int img[][M],int n,int m)
{
     for(int i=0;i<n;i++)
     {
     	printf("%d",img[i][0]);
          for(int j=1;j<m;j++)
               printf(" %d",img[i][j]);
		putchar('\n');
     }
}

void calculate_integral_and_average(int image[][M],int integral_image[][M],int average[][M],int n,int m,int h,int w)
{
     compute_integral_image(image,n,m,integral_image);
     sliding_average(integral_image,n,m,h,w,average);
}

void print_integral_and_average(int integral_image[][M],int average[][M],int n,int m)
{
     printf("Integral image is:\n");
     print_matrix(integral_image,n,m);
     printf("Smoothed image is:\n");
     print_matrix(average,n,m);
}
