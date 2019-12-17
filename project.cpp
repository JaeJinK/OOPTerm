#include<iostream>
#include<cstdlib>
#include<time.h>
#include<conio.h>
using namespace std;

int ONE_BLOCK=1;
int TWO_BLOCK=2;
int THREE_BLOCK=3;
int ROW=5;
int COLUMN=12;
int r=1;//x좌표 이동 
int c=0;//y좌표 이동 
int bord[12][5]={0};
int block[3][3];
int blockColor;
int score=0;
int style;


void blockMakeAndPlace(){
	srand(time(NULL));
	style = rand() % 3;//랜덤 스타일
	
	if(style==0) {//tree
		srand(time(NULL));
		for(int i=0;i<THREE_BLOCK;i++){//make
			for(int j=0;j<THREE_BLOCK;j++){
				if(j==1){
					blockColor=(rand()%4)+1;
					block[i][j]=blockColor;
				}
				else{
					block[i][j]=0;
				}
			}
		}
		for(int i=0;i<THREE_BLOCK;i++){
			for(int j=0;j<THREE_BLOCK;j++){
				bord[i][j+1]=block[i][j];
			}
		}
		
	}
	else if(style==1){//ford
		srand(time(NULL));
		for(int i=0;i<THREE_BLOCK;i++){
			for(int j=0;j<THREE_BLOCK;j++){
				if(((i==1)&&(j==0||j==1))||(i==0&&j==1)){
					blockColor=(rand()%4)+1;
					block[i][j]=blockColor;
				}
				else{
					block[i][j]=0;
				}
			}
		}
		for(int i=0;i<THREE_BLOCK;i++){
			for(int j=0;j<THREE_BLOCK;j++){
				bord[i][j+1]=block[i][j];
			}
		}
	}
	else{//cross
		for(int i=0;i<THREE_BLOCK;i++){
			srand(time(NULL));
			for(int j=0;j<THREE_BLOCK;j++){
				if(!((i==0||i==2)&&(j==0||j==2))){
					blockColor=(rand()%4)+1;
					block[i][j]=blockColor;
				}
				else{
					block[i][j]=0;
				}
			}
		}
		for(int i=0;i<THREE_BLOCK;i++){
			for(int j=0;j<THREE_BLOCK;j++){
				bord[i][j+1]=block[i][j];
			}
		}
	}
}


void removeBBM(){ 
	if(style==0){
		for(int i=0;i<THREE_BLOCK;i++){
			bord[i+c][1+r]=0;
		}
	}
	if(style==1){
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				if(!(i==0&&j==0)){
					bord[i+c][j+r]=0;
				}
			}
		}
	}
	if(style==2){
		for(int i=0;i<THREE_BLOCK;i++){
			for(int j=0;j<THREE_BLOCK;j++){
				if(!((i==0||i==2)&&(j==0||j==2))){
					bord[i+c][j+r]=0;
				}
			}
		}
	}
}


void moveLeft(){
	if(style==0){//tree 블를을 right 
		 for(int i=0;i<THREE_BLOCK;i++){
		 	if(!(bord[i+c][2+r]==0)&&(2+r+1<ROW)){
		 		return;
			 }
		 }
		removeBBM();
		r-=1;
		for(int i=0;i<THREE_BLOCK;i++){
			bord[i+c][1+r]=block[i][1];
		}
	}
	else if(style==1){//ford 블록을 right 
		for(int i=0;i<2;i++){
		 	if(!(bord[i+c][2+r]==0)&&(2+r+1<ROW)){
		 		return;
			 }
		 }
		 removeBBM();
		 r-=1;
		 for(int i=0;i<2;i++){
		 	for(int j=0;j<2;j++){
		 		if(!(i==0&&j==0)){
		 			bord[i+c][j+r]=block[i][j];
				 }
		 		
			 }
		 }
		 
	}
	else if(style==2){
		if(!(bord[0+c][2+r]==0&&bord[1+c][3+r]==0&&bord[2+c][2+r]==0)){
			return;
		}
		removeBBM();
		r-=1;
		for(int i=0;i<THREE_BLOCK;i++){
			for(int j=0;j<THREE_BLOCK;j++){
				if(!((i==0||i==2)&&(j==0||j==2))){
					bord[i+c][j+r]=block[i][j];
				}
			}
		}
	}
}


void moveRight(){
	if(style==0){//tree 블를을 right 
		 for(int i=0;i<THREE_BLOCK;i++){
		 	if(!(bord[i+c][2+r]==0)&&(2+r+1<ROW)){
		 		return;
			 }
		 }
		removeBBM();
		r+=1;
		for(int i=0;i<THREE_BLOCK;i++){
			bord[i+c][1+r]=block[i][1];
		}
	}
	else if(style==1){//ford 블록을 right 
		for(int i=0;i<2;i++){
		 	if(!(bord[i+c][2+r]==0)&&(2+r+1<ROW)){
		 		return;
			 }
		 }
		 removeBBM();
		 r+=1;
		 for(int i=0;i<2;i++){
		 	for(int j=0;j<2;j++){
		 		if(!(i==0&&j==0)){
		 			bord[i+c][j+r]=block[i][j];
				 }
		 		
			 }
		 }
		 
	}
	else if(style==2){
		if(!(bord[0+c][2+r]==0&&bord[1+c][3+r]==0&&bord[2+c][2+r]==0)){
			return;
		}
		removeBBM();
		r+=1;
		for(int i=0;i<THREE_BLOCK;i++){
			for(int j=0;j<THREE_BLOCK;j++){
				if(!((i==0||i==2)&&(j==0||j==2))){
					bord[i+c][j+r]=block[i][j];
				}
			}
		}
	}
}


void moveDown(){
	if(style==0){//tree 블를을 right 
		if(!(bord[1+c][2+r]==0)){
			return;
		}
		removeBBM();
		c+=1;
		for(int i=0;i<THREE_BLOCK;i++){
			bord[i+c][1+r]=block[i][1];
		}
	}
	else if(style==1){//ford 블록을 right 
		for(int i=0;i<2;i++){
		 	if(!(bord[2+r][i+c]==0)){
		 		return;
			 }
		 }
		 removeBBM();
		 c+=1;
		 for(int i=0;i<2;i++){
		 	for(int j=0;j<2;j++){
		 		if(!(i==0&&j==0)){
		 			bord[i+c][j+r]=block[i][j];
				 }
		 		
			 }
		 }
		 
	}
	else if(style==2){
		if(!(bord[2+r][0+c]==0&&bord[3+r][1+c]==0&&bord[2+r][2+c]==0)){
			return;
		}
		removeBBM();
		c+=1;
		for(int i=0;i<THREE_BLOCK;i++){
			for(int j=0;j<THREE_BLOCK;j++){
				if(!((i==0||i==2)&&(j==0||j==2))){
					bord[i+c][j+r]=block[i][j];
				}
			}
		}
	}
}
void moveBlock(char move){//추후 c,r은 블록이 제거된 후 1로 해줌.
	if(move=='a'){
		moveLeft();
	} 
	if(move=='d'){
		moveRight();	 
	}
	if(move=='s'){
		moveDown();
	} 
}





void printBord(){
	for(int i=0;i<COLUMN;i++){
		for(int j=0;j<ROW;j++){
			cout<<" "<<bord[i][j]<<" ";
		}
		cout<<::endl;
	}
	cout<<"---------------------"<<::endl;
}

int main(void){
	while(true){
		printBord();
		blockMakeAndPlace();
		printBord();
		while(true){
			cout<<"입력: ";
			char ch=getch();
			cout<<::endl;
			if(ch=='x'){
				r=1;
				c=0;
				printBord();
				break;
			}
			moveBlock(ch);
			printBord();
		}
	}
	return 0;
}
