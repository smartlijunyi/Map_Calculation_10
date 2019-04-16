#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "structure.h"
#include "inform.h"
#include "readfile.h"
#include "buildgraph.h"
#include "shortpath.h"

int main(int argc,char *argv[]){
	LGraph Graph;
	Table T;
	ids s;
	newn n;
	read_file();
	oldnew(n);
	load(s);
	Graph = BuildGraph(n);
	DrawMap(n,s,Graph);
	int choice = 0;
	ShowMenu();
	while(1){
		printf("Please select(From 1 to 3): ");
		scanf("%i",&choice);
		if(choice == 1){
			ViewGraph(Graph);
			Info();
		}
		else if(choice == 2){
			int start,end;
			int s0,e0;
			printf("\nPlease input the start point: ");
			scanf("%i",&start);
			s0 = findid(n,start);
			if(s0 >= 0 && s0 <= 2118){
				InitTable(s0,Graph,T);
				Dijkstra_1(Graph,T);
				printf("Please input the end point: ");
				scanf("%i",&end);
				e0 = findid(n,end);
				if(e0 >= 0 && e0 <= 2118){
					FILE *fp1;
					fp1 = fopen("short.out","w");
					PrintOut_1(n,e0,T,fp1);
					printf("\n\nThe total length is %lf.\n\n",T[e0].Dist);
					fclose(fp1);
				}
				else
					printf("End Point can not be arrived directly!!!\n");
			}
			else
				printf("Start Point have no road!!!\n");
		}
		else if(choice == 3){
			DestroyGraph(Graph);
			Exit();
			break;
		}
		else 
			printf("Please input again!\n");
	}
	return 0;
}
