#include "stdio.h"


void MoveDisk(int diskNum, int start, int end, int mid);

int main(){
	int disks;
	
	printf("enter number of disks: ");
	scanf("%d", &disks);
	MoveDisk(disks, 1, 3, 2);
}

void MoveDisk(int diskNum, int start, int end, int mid){
	if(diskNum > 1){
		MoveDisk(diskNum-1, start, mid, end);

		printf("Move disk %d from post %d to post %d\n", diskNum, start, end);

		MoveDisk(diskNum-1, mid, end, start);



	} else {
		printf("Move disk 1 from post %d to post %d.\n", start, end);
	}
	




}
