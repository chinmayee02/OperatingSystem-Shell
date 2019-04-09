#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include<string.h>

int main(int argc, char *argv[])
{
int h = atoi(argv[1]);
int i;
int c = atoi(argv[2]);
pid_t pid1,pid2;


printf("%d : process starting\n", getpid());
printf("%d : has parent id is %d\n",getpid(),getppid());
printf("%d : Height of the tree is %d\n",getpid(),h);
printf("%d : Creating %d children at %d height\n",getpid(),c,(h-1));

if(h>1)
{
        for(i=0;i<c;i++)
        {
               pid1=fork();

                        if(pid1<0)
                        {
                                printf("Error");
                                exit(-1);
                        }
                        else if(pid1==0)
                        {
                                   printf("child process created with id  %d and parent id %d\n",getpid(),getppid());

                                char child[2];
                                char height[2];
                                sprintf(child,"%d",c);
                                sprintf(height,"%d",h-1);
                                strcpy(argv[2],child);
                                strcpy(argv[1],height);
                                if(execv(argv[0],argv)==-1)
                                {
                                        fprintf(stderr,"error");
                                }
                                exit(0);
						  }

        }
                while(c>0)
                {
                        wait(0);
                        printf("Parent %d is waiting for child %d\n",getpid(),getppid());
                        c--;
                }
                 printf("Parent terminating %d\n",getpid());


}


return 0;

}
