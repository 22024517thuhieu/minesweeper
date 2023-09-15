#include <iostream>
#include <ctime>
#include <cstdlib> 

using namespace std;

int m, n, k;
int count; //count player's turns
int x, y; //player's choice
int computerField[100][100];
char fieldShown [100][100];
int availableGrid[100][100];
int x0[3] = {-1, 0, 1};
int y0[3] = {-1, 0, 1};
void minePosition ();
void updateField();
void enterChoice();
bool checkChoice(int x, int y);
void mineField();
void result (int x, int y);
void printMineField();
void printResult();

int main () {
	cin >> m >> n >> k;
	minePosition();
	mineField();
	do {
		enterChoice();
		system("cls");
		result(x, y);
	} while (checkChoice(x, y) == true && count<(m*n-k));
	if (checkChoice(x, y)) cout << "YOU WIN!" << endl;
	else cout << "GAME OVER!" << endl;
	printResult();
	return 0;
}

void mineField(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			fieldShown[i][j] = '*';
		}
	}
	printMineField();
}

void printMineField() {
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			cout << fieldShown[i][j] << " ";
		}
		cout << endl;
	}
}

void enterChoice(){
	cout << "\n" << "Please enter your choice: " << "\n";
	do{
		cin >> x >> y;
	} while (availableGrid[x][y] != 0 || x<1 || y>m || y<1 || y>n);
	
	availableGrid[x][y] = 1;
}

void minePosition(){
	int mineQuantity = 0;
	while(mineQuantity < k){
		srand(time(0));
		int x1 = rand()%m + 1;
		int y1 = rand()%n + 1;
		if(computerField[x1][y1] != -1){
			computerField[x1][y1] = -1;
			mineQuantity++;
		}
	}
	updateField();
}

bool checkChoice(int x, int y){
	if(computerField[x][y] == -1){
		return false;
	}
	return true;
}

void updateField(){
	int count;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			count = 0;
			if(computerField[i][j] != -1){
				for(int t=0; t<3; t++){
					for(int k=0; k<3; k++){
						if(computerField[i+x0[t]][j+y0[k]] == -1){
							count++;
						}
					}
				}
				computerField[i][j] = count;
			}
		}
	}
}

void result(int x, int y){
	if(computerField[x][y] == -1){
		fieldShown[x][y] = '!';
	}
	else {
		fieldShown[x][y] = char(computerField[x][y]+48);
		count++;
	}
	printMineField();
}

void printResult(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(computerField[i][j] == -1){
				fieldShown[i][j] = '!';
			}
			else{
				fieldShown[i][j] = char(computerField[i][j]+48);
			}
		}
	}
	printMineField();
	/ksmx
}

