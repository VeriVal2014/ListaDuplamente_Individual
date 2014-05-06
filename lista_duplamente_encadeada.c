#include <stdlib.h>
#include <stdio.h>
#include "lista_duplamente_encadeada.h"

List list = {.firstNode=NULL, .lastNode=NULL};

void unalocc (Node* nodeFree){
	free(nodeFree);
}

int insertEmpty(int num){

	Node *nodeInsert= malloc(sizeof(Node));
	if(!nodeInsert){
		return -2;
	}
	
	else{
		nodeInsert->element=num;
		
		nodeInsert->next=NULL;
		nodeInsert->previous=NULL;
		
		list.firstNode=nodeInsert;
		list.lastNode=nodeInsert;
		
		return 0;
	}

}

int insertFront(int num){

	if(list.firstNode==NULL){
		int result=insertEmpty(num);
		return result;
	}
	else{
		Node *nodeInsert= malloc(sizeof(Node));
		if(!nodeInsert){
			return -2;
		}
		else{
			nodeInsert->element=num;
			nodeInsert->next=list.firstNode;
			nodeInsert->previous=NULL;
			
			list.firstNode->previous=nodeInsert;
			
			list.firstNode=nodeInsert;
			return 0;
		}
	}	
}

int insertEnd(int num){
	if(list.firstNode==NULL){
		int result=insertEmpty(num);
		return result;
	}
	else{
		Node *nodeInsert= malloc(sizeof(Node));
		if(!nodeInsert){
			return -2;
		}
		else{
			nodeInsert->element=num;
			nodeInsert->next=NULL;
			nodeInsert->previous=list.lastNode;
			list.lastNode->next=nodeInsert;
	
			list.lastNode=nodeInsert;
	
			return 0;
		}
	}

}

int deleteNum (int num){
	Node *nodeNow=list.firstNode;
	Node *nodeOld=NULL;
	if(nodeNow==NULL){
		return -1;
	}
	else{
		do{
			if(nodeNow->element==num){
				if (nodeNow==list.firstNode){

					list.firstNode=nodeNow->next;
					if(nodeNow!=list.lastNode){
						list.firstNode->previous=NULL;
					}
				}
				else{
					if(nodeNow->next==NULL){
						nodeOld->next=NULL;
						list.lastNode=nodeOld;
					}
					else{
						nodeOld->next=nodeNow->next;	
						nodeNow->next->previous =nodeOld;
					}
				}
				unalocc(nodeNow);

			}
			else{
			nodeOld= nodeNow;
			}

			nodeNow=nodeNow->next;
		}while(nodeNow!= NULL);
	return 0;
	}
}
int show(){
	Node *nodeShow=list.firstNode;
	if(nodeShow==NULL){
		return -1;
	}
	else{	
		do{

			printf("%d ", nodeShow->element);
		
			nodeShow=nodeShow->next;
		}while(nodeShow!=NULL);
		
		return 0;
	}
}

extern int reverseShow(){

	Node *nodeShow=list.lastNode;
	if(nodeShow==NULL){
		return -1;
	}
	else{	
		do{

			printf("%d ", nodeShow->element);
		
			nodeShow=nodeShow->previous;
		}while(nodeShow!=NULL);
		
		return 0;
	}

}

int end(){
	Node *nodeDelete=list.firstNode;
	Node *nodeNextDelete=NULL;
	if (nodeDelete==NULL){
		return 0;
	}
	else{
		do{
			nodeNextDelete=nodeDelete->next;
			unalocc(nodeDelete);
			nodeDelete=nodeNextDelete;
		}while(nodeDelete!= NULL);
		return 0;
	}
}



