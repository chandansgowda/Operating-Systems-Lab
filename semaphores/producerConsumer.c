#include <stdio.h>
#include <stdlib.h>

int mutex=1,full=0,empty=3,x=0;

int wait(int s){
	return --s;
}

int signal(int s){
	return ++s;
}

void producer(){
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("Producer produces the item %d\n",x);
	mutex=signal(mutex);
}

void consumer(){
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("Consumer consumed the item %d\n",x);
	x--;
	mutex=signal(mutex);
}

void main(){
	int c;
	while(1){
		printf("\n1.Producer\n2.Consumer\n3.Exit\nEnter Choice>> ");
		scanf("%d",&c);
		switch(c){
			case 1: {
				if (mutex==1&&empty!=0) producer();
				else printf("Buffer is Full\n");
				break;
			}
			case 2: {
				if (mutex==1&&full!=0) consumer();
				else printf("Buffer is Empty\n");
				break;
			}
			case 3: exit(1);
		}
	}
}
