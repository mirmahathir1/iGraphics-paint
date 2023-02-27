void confirm_natural_int(int* a)
{
    if(*a<0)
    {
        printf("\nNegative value will be turned into positive.\n");
        *a=-(*a);
    }
    fflush(stdin);
}

//#include<stdlib.h>
float** create_matrix(float **mat,int row,int column)
{
    mat=(float**)malloc(row*sizeof(float*));
    int i;
    for(i=0;i<row;i++)
        mat[i]=(float*)malloc(column*sizeof(float));
    return mat;
}

void multiply_matrix(float**mat1,float**mat2,float**mat3,int mat1_row,int mat1_column,int mat2_row,int mat2_column)
{
    int mat3_row=mat1_row;
    int mat3_column=mat2_column;
    int k,row,column;
    for(row=0;row<mat3_row;row++)
        for(column=0;column<mat3_column;column++)
    {
        mat3[row][column]=0;
        for(k=0;k<mat1_row;k++)
            mat3[row][column]=mat3[row][column]+mat1[row][k]*mat2[k][column];
    }
}

void print_matrix(float**mat,int mat_row,int mat_column)
{
    int row,column;
    for(row=0;row<mat_row;row++)
    {
        for(column=0;column<mat_column;column++)
        printf("%f\t",mat[row][column]);
        printf("\n");
    }
}

//#include<string.h>
void int_to_string(int a,char* string_2_pointer)
{
    int q,i;char c;char string[100];char *p;char *r=string_2_pointer;
    for(i=0;;i++)
    {
        q=a%10;
        a=a/10;
        c=(char)(q+48);
        p=string;
        *(p+i)=c;
        if(a==0)
        {
            *(p+i+1)='\0';
            break;
        }
    }
    p=p+strlen(string)-1;
    for(i=0;i<=strlen(string)-1;i++)
    {
        *(r+i)=*(p-i);
    }
    *(r+strlen(string))='\0';
    return;
}

//#include<windows.h>
clear()
{
    system("cls");
}



//#include<windows.h>
int moment(char i)
{
/*
    typedef struct _SYSTEMTIME
    {
		WORD wYear;
		WORD wMonth;
		WORD wDayOfWeek;
		WORD wDay;
		WORD wHour;
		WORD wMinute;
		WORD wSecond;
		WORD wMilliseconds;
	} SYSTEMTIME;
*/
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	switch(i)
	{
	case 'y':
        return str_t.wYear;
    case 'm':
        return str_t.wMonth;
    case 'w':
        return (str_t.wDayOfWeek+2);//In default, the 1st day is Monday
    case 'd':
        return str_t.wDay;
    case 'h':
        return (str_t.wHour);
    case 'M':
        return str_t.wMinute;
    case 's':
        return str_t.wMilliseconds;
    default:
        return -1;
	}
}

//#include<windows.h>
void gotoxy(int x,int y)
{
    COORD coord={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//#include<string.h>
void string_right_shift(char *string,char *string_2,int bit)
{
    int c,i;
    for(c=0;c<=(bit-1)-strlen(string);c++)
    {
        string_2[c]='0';
    }
    i=0;
    for(c=(bit-1)-strlen(string)+1;c<=9;c++)
    {
        string_2[c]=string[i];
        i++;
    }
    string_2[bit]='\0';
}

//#include<stdlib.h>
void savebmp(const char *filename,int w,int h,int dpi,double***rgb)
{
    typedef struct RGBType{
    double r;
    double g;
    double b;
    }RGBType;

    int n=w*h;
    RGBType *pixels=(RGBType*)malloc(n*sizeof(RGBType));
    int x,y,thisone;
    for(x=0;x<w;x++)
    {
        for(y=0;y<h;y++)
        {
            thisone=y*w + x;

            pixels[thisone].r=rgb[x][y][0];
            pixels[thisone].g=rgb[x][y][1];
            pixels[thisone].b=rgb[x][y][2];
        }
    }

  FILE *f;
  int k=w*h;
  int s=4*k;
  int filesize=54+s;

  double factor=39.375;
  int m=(int)factor;

  int ppm=dpi*m;
  unsigned char bmpfileheader[14]={'B','M',0,0,0,0,0,0,0,0,54,0,0,0};
    unsigned char bmpinfoheader[40]={40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};

    bmpfileheader[ 2]=(unsigned char)(filesize);
    bmpfileheader[ 3]=(unsigned char)(filesize>>8);
    bmpfileheader[ 4]=(unsigned char)(filesize>>16);
    bmpfileheader[ 5]=(unsigned char)(filesize>>24);

    bmpinfoheader[ 4]=(unsigned char)(w);
    bmpinfoheader[ 5]=(unsigned char)(w>>8);
    bmpinfoheader[ 6]=(unsigned char)(w>>16);
    bmpinfoheader[ 7]=(unsigned char)(w>>24);

    bmpinfoheader[ 8]=(unsigned char)(h);
    bmpinfoheader[ 9]=(unsigned char)(h>>8);
    bmpinfoheader[10]=(unsigned char)(h>>16);
    bmpinfoheader[11]=(unsigned char)(h>>24);

    bmpinfoheader[21]=(unsigned char)(s);
    bmpinfoheader[22]=(unsigned char)(s>>8);
    bmpinfoheader[23]=(unsigned char)(s>>16);
    bmpinfoheader[24]=(unsigned char)(s>>24);

    bmpinfoheader[25]=(unsigned char)(ppm);
    bmpinfoheader[26]=(unsigned char)(ppm>>8);
    bmpinfoheader[27]=(unsigned char)(ppm>>16);
    bmpinfoheader[28]=(unsigned char)(ppm>>24);

    bmpinfoheader[29]=(unsigned char)(ppm);
    bmpinfoheader[30]=(unsigned char)(ppm>>8);
    bmpinfoheader[31]=(unsigned char)(ppm>>16);
    bmpinfoheader[32]=(unsigned char)(ppm>>24);

    f=fopen(filename,"wb");

    fwrite(bmpfileheader,1,14,f);
    fwrite(bmpinfoheader,1,40,f);
    int i;
    for(i=0;i<k;i++)
    {
        RGBType rgb=pixels[i];

        double red=(pixels[i].r);
        double green=(pixels[i].g);
        double blue=(pixels[i].b);

        unsigned char color[3]={(int)blue,(int)green,(int)red};

        fwrite(color,1,3,f);
    }
    fclose(f);
}

//#include<stdlib.h>
double*** create_3D_array(double ***rgb,int width,int height,int depth)
{
    int i,j;
rgb = (double ***)malloc(width*sizeof(double**));
    for (i = 0; i< width; i++) {
         rgb[i] = (double **) malloc(height*sizeof(double *));
          for (j = 0; j < height; j++) {
              rgb[i][j] = (double *)malloc(depth*sizeof(double));
          }

        }
        return rgb;

}


