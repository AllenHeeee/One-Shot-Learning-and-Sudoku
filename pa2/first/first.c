#include<stdio.h>
#include<stdlib.h>

int main (int argc,char** argv){
    FILE * fp;
    fp=fopen(argv[1],"r");//training data
    int co;
    fscanf(fp,"%d", &co);
    co++;
    int row;
    fscanf(fp,"%d", &row);
    double x[row][co];
    double y[row][1];
    //crate x and y
    for(int i=0;i<row;i++){
        for(int j=0;j<co+1;j++){
            if(j==0){
                x[i][j]=1;
                continue;
            }
            double num=0;
            fscanf(fp,"%lf", &num);
            char c;
            fscanf(fp,"%c", &c);
            if(j<co)
                x[i][j]=num;
            else{
                y[i][0]=num;
            }
        }
    }
    
    //print
//    printf("X:\n");
//    for(int i=0;i<row;i++){
//        for(int j=0;j<co;j++){
//            printf("%lf\t",x[i][j]);
//        }
//        printf("\n");
////    }
//    printf("\n");
//    for(int i=0;i<row;i++){
//            printf("%lf\t",y[i][0]);
//
//        printf("\n");
//    }
    
    //get transpose
     //printf("\n");
    double xt[co][row];
    for(int i=0;i<co;i++){
        for(int j=0;j<row;j++){
            xt[i][j]=x[j][i];
          // printf("%lf\t",xt[i][j]);
        }
         //printf("\n");
      
    }
    
    //mul
    //printf("Mul of xt and x\n");
    double mul[co][co];
    for(int i=0;i<co;i++){
        for(int j=0;j<co;j++){
            mul[i][j]=0;
            for(int k=0;k<row;k++){
                mul[i][j]+=xt[i][k]*x[k][j];
               // printf("xt:%lf\t",xt[i][k]);
                //rintf("x:%lf\t",x[k][j]);
                //printf("%lf\t",mul[i][j]);
            }
           // printf("*\n");
        }
    }
    ///print
//    printf("\n");
//    for(int i=0;i<co;i++){
//        for(int j=0;j<co;j++){
//            printf("%lf\t",mul[i][j]);
//        }
//        printf("\n");
//    }
    
    //get inverse
    double inv[co][co*2];
    for(int i=0;i<co;i++){
        for(int j=0;j<co;j++){
            inv[i][j]=mul[i][j];
        }
    }
//    //print
//     printf("\n");
//    for(int i=0;i<co;i++){
//        for(int j=0;j<co*2;j++){
//            printf("%lf\t",inv[i][j]);
//        }
//        printf("\n");
//    }
    
    
    double n[co][co];
    for(int i=0;i<co;i++){//get a 0 and 1 matrix
        for(int j=0;j<co;j++){
            if(i==j)
                n[i][j]=1.0;
            else
                n[i][j]=0.0;
        }
    }
    for(int i=0;i<co;i++){
        int a=0;
        for(int j=co;j<co*2;j++){
            inv[i][j]=n[i][a];
            a++;
            
        }
    }
    //print
//     printf("\n");
//    for(int i=0;i<co;i++){
//        for(int j=0;j<co*2;j++){
//            printf("%lf\t",inv[i][j]);
//        }
//         printf("\n");
//    }
//     printf("\n");
    for(int i=0;i<co;i++){
        for(int j=0;j<co;j++){
            if(i==j){
                for(int k=0;k<co;k++){
                    if(k!=i){
                        double num=inv[k][j];
                        double factor;
                         factor=num/inv[i][j];//////
                        factor*=-1;
                        for(int z=0;z<co*2;z++){
                            inv[k][z]=inv[i][z]*factor+inv[k][z];
                             //printf("%lf\t",inv[k][z]);
                        }
                       // printf("\n");
                    }
                }
            }
        }
    }
//    printf("\n");
//    for(int i=0;i<co;i++){
//        for(int j=0;j<co*2;j++){
//            printf("%lf\t",inv[i][j]);
//        }
//        printf("\n");
//    }
    for(int i=0;i<co;i++){
        double nu=1;
        for(int j=0;j<co*2;j++){
            
            if(j==i){
                nu=inv[i][j];
            }
            inv[i][j]=inv[i][j]/nu;
        }
    }
//    printf("\n");
//    for(int i=0;i<co;i++){
//        for(int j=0;j<co*2;j++){
//            printf("%lf\t",inv[i][j]);
//        }
//        printf("\n");
//    }
    int a=0,b=co;
    for(int i=0;i<co;i++){
        for(int j=0;j<co;j++){
            n[i][j]=inv[a][b];
            b++;
        }
        b=co;
        a++;
    }
//    printf("\n");
//    for(int i=0;i<co;i++){
//        for(int j=0;j<co;j++){
//            printf("%lf\t",n[i][j]);
//        }
//        printf("\n");
//    }
    
    //mul inv and xt
    double invxt[co][row];
    for(int i=0;i<co;i++){
        for(int j=0;j<row;j++){
            invxt[i][j]=0;
            for(int k=0;k<co;k++){//***
                invxt[i][j]+=n[i][k]*xt[k][j];
            }
        }
    }
//    printf("\n");
//    printf("invxt:\n");
//    for(int i=0;i<co;i++){
//        for(int j=0;j<row;j++){
//            printf("%lf\t",invxt[i][j]);
//        }
//        printf("\n");
//    }
    //mul*y
    double w[co][1];
    for(int i=0;i<co;i++){
        for(int j=0;j<1;j++){
            w[i][j]=0;
            for(int k=0;k<row;k++){///*
                w[i][j]+=invxt[i][k]*y[k][j];
            }
        }
    }
//    printf("\n");
//    for(int i=0;i<co;i++){
//        for(int j=0;j<1;j++){
//            printf("%lf\t",w[i][j]);
//        }
//        printf("\n");
//    }
//     printf("\n");
    fp=fopen(argv[2],"r");//test data
    int R;
    fscanf(fp,"%d", &R);
    double X[R][co];
    for(int i=0;i<R;i++){
        for(int j=0;j<co;j++){
            if(j==0){
                 X[i][j]=1;
                continue;
            }
            double num=0;
            fscanf(fp,"%lf", &num);
            char c;
            fscanf(fp,"%c", &c);
            X[i][j]=num;
            //printf("%lf\t",X[i][j]);
        }
         //printf("\n");
    }
    
    double result[R][1];
    
    for(int i=0;i<R;i++){
        for(int j=0;j<1;j++){
            result[i][j]=0;
            for(int k=0;k<co;k++){
                result[i][j]+=X[i][k]*w[k][j];
            }
        }
    }
    //printf("\n");
    for(int i=0;i<R;i++){
        for(int j=0;j<1;j++){
            printf("%0.0lf\n",result[i][j]);
        }
        //printf("\n");
    }
    fclose(fp);
    return 0;
}
