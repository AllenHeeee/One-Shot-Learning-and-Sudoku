#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (int argc,char** argv){
    FILE * fp;
    fp=fopen(argv[1],"r");
    if(fp==NULL){
        printf("no-solution\n");
        return 0;
    }
    int co=0;
    int matrix[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            char buff[255];
            fscanf(fp,"%s", buff);
            if(strcmp(buff,"-") == 0){
                matrix[i][j]=0;
                co++;
            }else{
                int num=atoi(buff);
                matrix[i][j]=num;
            }
            
        }
    }
    int loc[81][2];
    int index=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]==0){
                loc[index][0]=i;
                loc[index][1]=j;
                index++;
            }
        }
    }
    //check
    int no=1;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]!=0){
                no=0;
            }
        }
    }//check null item
    if(no==1){
        printf("no-solution\n");
        return 0;
    }
    no=0;//check repetive inputs
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]!=0){
                for(int k=0;k<9;k++){//check in one row
                    if(k==j){
                        continue;
                    }
                    if(matrix[i][k]==matrix[i][j]){
                        printf("no-solution\n");
                        return 0;
                    }
                }
                for(int k=0;k<9;k++){//check in one column
                    if(k==i)continue;
                    if(matrix[k][j]==matrix[i][j]){
                        printf("no-solution\n");
                        return 0;
                    }
                }
                //
                if(i<3&&j<3){
                    //zone 1
                    for(int x=0;x<3;x++){
                        for(int y=0;y<3;y++){
                            if(x==i&&y==j)continue;
                            if(matrix[x][y]==matrix[i][j]){
                                printf("no-solution\n");
                                return 0;
                            }
                        }
                    }
                }
                else if(i<3&&j<6){
                    //zone 2
                    for(int x=0;x<3;x++){
                        for(int y=3;y<6;y++){
                            if(x==i&&y==j)continue;
                            if(matrix[x][y]==matrix[i][j]){
                                printf("no-solution\n");
                                return 0;
                            }
                        }
                    }
                }else if(i<3&&j<9){
                    //zone 3
                    for(int x=0;x<3;x++){
                        for(int y=6;y<9;y++){
                            if(x==i&&y==j)continue;
                            if(matrix[x][y]==matrix[i][j]){
                                printf("no-solution\n");
                                return 0;
                            }
                        }
                    }
                }else if(i<6&&j<3){
                    //zone 4
                    for(int x=3;x<6;x++){
                        for(int y=0;y<3;y++){
                            if(x==i&&y==j)continue;
                            if(matrix[x][y]==matrix[i][j]){
                                printf("no-solution\n");
                                return 0;
                            }
                        }
                    }
                }else if(i<6&&j<6){
                    //zone 5
                    for(int x=3;x<6;x++){
                        for(int y=3;y<6;y++){
                            if(x==i&&y==j)continue;
                            if(matrix[x][y]==matrix[i][j]){
                                printf("no-solution\n");
                                return 0;
                            }
                        }
                    }
                }else if(i<6&&j<9){
                    //zone 6
                    for(int x=3;x<6;x++){
                        for(int y=6;y<9;y++){
                            if(x==i&&y==j)continue;
                            if(matrix[x][y]==matrix[i][j]){
                                printf("no-solution\n");
                                return 0;
                            }
                        }
                    }
                }else if(i<9&&j<3){
                    //zone 7
                    for(int x=6;x<9;x++){
                        for(int y=0;y<3;y++){
                            if(x==i&&y==j)continue;
                            if(matrix[x][y]==matrix[i][j]){
                                printf("no-solution\n");
                                return 0;
                            }
                        }
                    }
                }else if(i<9&&j<6){
                    //zone 8
                    for(int x=6;x<9;x++){
                        for(int y=3;y<6;y++){
                            if(x==i&&y==j)continue;
                            if(matrix[x][y]==matrix[i][j]){
                                printf("no-solution\n");
                                return 0;
                            }
                        }
                    }
                }else{
                    //zone 9
                    for(int x=6;x<9;x++){
                        for(int y=6;y<9;y++){
                            if(x==i&&y==j)continue;
                            if(matrix[x][y]==matrix[i][j]){
                                printf("no-solution\n");
                                return 0;
                            }
                        }
                    }
                }
                //
            }
        }
    }//check done
//    for(int i=0;i<9;i++){
//        for(int j=0;j<9;j++){
//            printf("%d\t",matrix[i][j]);
//        }
//        printf("\n");
//    }
    //int poss[9]={1,2,3,4,5,6,7,8,9};
    index=-1;
//    for(int i=0;i<co;i++){
//        for(int j=1;j<=9;j++){
//            poss[i][j-1]=j;
//        }
//    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]==0){
                int poss[9]={1,2,3,4,5,6,7,8,9};
                index++;
                int count=9;
                for(int k=0;k<9;k++){// in one row
                    if(matrix[i][k]!=0){
                        poss[matrix[i][k]-1]=-1;
                        count--;
                    }
                }
                for(int k=0;k<9;k++){
                    if(matrix[k][j]!=0){
                        if(poss[matrix[k][j]-1]!=-1){
                            poss[matrix[k][j]-1]=-1;
                            count--;
                        }
                    }
                }
                if(i<3&&j<3){
                    //zone 1
                    for(int x=0;x<3;x++){
                        for(int y=0;y<3;y++){
                            int n= matrix[x][y];
                            if(n!=0){
                                n--;
                                if(poss[n]!=-1){
                                    poss[n]=-1;count--;
                                }
                            }
                        }
                    }
                }
                else if(i<3&&j<6){
                    //zone 2
                    for(int x=0;x<3;x++){
                        for(int y=3;y<6;y++){
                            int n= matrix[x][y];
                            if(n!=0){
                                n--;
                                if(poss[n]!=-1){
                                    poss[n]=-1;count--;
                                }
                            }
                        }
                    }
                }
                else if(i<3&&j<9){
                    //zone 3
                    for(int x=0;x<3;x++){
                        for(int y=6;y<9;y++){
                            int n= matrix[x][y];
                            if(n!=0){
                                n--;
                                if(poss[n]!=-1){
                                    poss[n]=-1;count--;
                                }
                            }
                        }
                    }
                }
                else if(i<6&&j<3){
                    //zone 4
                    for(int x=3;x<6;x++){
                        for(int y=0;y<3;y++){
                            int n= matrix[x][y];
                            if(n!=0){
                                n--;
                                if(poss[n]!=-1){
                                    poss[n]=-1;count--;
                                }
                            }
                        }
                    }
                }else if(i<6&&j<6){
                    //zone 5
                    for(int x=3;x<6;x++){
                        for(int y=3;y<6;y++){
                            int n= matrix[x][y];
                            if(n!=0){
                                n--;
                                if(poss[n]!=-1){
                                    poss[n]=-1;count--;
                                }
                            }
                        }
                    }
                }else if(i<6&&j<9){
                    //zone 6
                    for(int x=3;x<6;x++){
                        for(int y=6;y<9;y++){
                            int n= matrix[x][y];
                            if(n!=0){
                                n--;
                                if(poss[n]!=-1){
                                    poss[n]=-1;count--;
                                }
                            }
                        }
                    }
                }else if(i<9&&j<3){
                    //zone 7
                    for(int x=6;x<9;x++){
                        for(int y=0;y<3;y++){
                            int n= matrix[x][y];
                            if(n!=0){
                                n--;
                                if(poss[n]!=-1){
                                    poss[n]=-1;
                                    count--;
                                }
                            }
                        }
                    }
                }else if(i<9&&j<6){
                    //zone 8
                    for(int x=6;x<9;x++){
                        for(int y=3;y<6;y++){
                            int n= matrix[x][y];
                            if(n!=0){
                                n--;
                                if(poss[n]!=-1){
                                    poss[n]=-1;
                                    count--;
                                }
                            }
                        }
                    }
                }else{
                    //zone 9
                    for(int x=6;x<9;x++){
                        for(int y=6;y<9;y++){
                            int n= matrix[x][y];
                            if(n!=0){
                                n--;
                                if(poss[n]!=-1){
                                    poss[n]=-1;
                                    count--;
                                }
                            }
                        }
                    }
                }
                if(count==0){
                    /////// jump up
                    matrix[i][j]=matrix[loc[index-1][0]][loc[index-1][1]];
                    if(matrix[i][j]==0){
                        index--;
                         matrix[i][j]=matrix[loc[index-1][0]][loc[index-1][1]];
                    }
                    i=loc[index-1][0];
                    j=loc[index-1][1]-1;
                    if(j<0){
                        j=8;
                        i--;
                        if(i<0){
                            printf("no-solution\n");
                            return 0;
                        }
                    }
                    matrix[loc[index-1][0]][loc[index-1][1]]=0;
                    index--;
                    
                    continue;
//                    printf("no-solution\n");
//                    return 0;//**
                }
                if(count==1){
                    for(int x=0;x<9;x++){
                        if(poss[x]!=-1){
                            matrix[i][j]=poss[x];
                            break;
                        }
                    }
                }
                if(count>1){
                    for(int x=8;x>=0;x--){
                        if(poss[x]!=-1){
                            matrix[i][j]=poss[x];
                            break;
                        }
                    }
//                    if(poss[i][j]==0){
//
//                    }
                }
            }
            
            
        }
    }
//    int newposs[co][10];
//    for(int i=0;i<co;i++){
//        for(int j=0;j<9;j++){
//            newposs[i][j]=-1;
//        }
//    }
//    int c=0;
//    for(int i=0;i<co;i++){
//        c=0;
//        for(int j=1;j<9;j++){
//            if(poss[j]!=0){
//                newposs[i][c+1]=poss[j];
//                c++;
//            }
//        }
//        newposs[i][0]=c;
//        newposs[i][c+1]=c;
//    }
//
    
    
    
    //check avl
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

    
    
    
    

    
    
    return 0;
}
