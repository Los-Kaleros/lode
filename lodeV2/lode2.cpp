#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

const int rows = 6;
const int cols = 6;
int MaxShips = 5;

int matrix[rows][cols];

void Clear()
{    
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void Show()
{
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void SetShips()
{
    int s = 0;
    while(s < MaxShips)
    {
        int x = rand() % rows;
        int y = rand() % cols;
        if(matrix[x][y] != 1)
        {
            s++;
            matrix[x][y] = 1;
        }
    }
}

int NumberOfShips()
{
    int c=0;
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            if(matrix[i][j] == 1)
            {
                c++;
            }
        }
    }
    
    return c;
}

bool Attack(int x, int y)
{
    if(matrix[x][y] == 1)
    {
        matrix[x][y] = 2;
        return true;
    }
    if(matrix[x][y] == 0)
	{
    	matrix[x][y] = 3;
		return false;	
	}
	else
	{
		return false;
	}
    
}


int main()
{
    srand(time(NULL));
    
    Clear();
    cout << "Vitam ta v mojej simple battleship hre!" << endl;
    cout << "Pocitac nahodne rozmiestnil 5 lodiek na 6 x 6 hracu plochu \n";
    cout << endl;
	Show();
    cout << endl;
    cout << "Na ploche sa zobrazuju 0 na pozicii kde lode niesu 1 kde lode su 2 kde su potopene lode a 3 je miesto kde si strielal avsak nic netrafil" << endl;
    cout << "-------------------------------------------------------- Nahodne pokladam lodky --------------------------------------------------------" << endl;
	cout << endl;
	SetShips();
    
	int pos1,pos2;
    char prompt;

    while(1)
    {	
    	int pos1, pos2;
        cout << endl;
		cout << "Prosim zadaj svoje suradnice pre zasah (najprv riadok potom stlpec, kladne cisla 0-5 napr. 0 0 je prve policko): ";
		cin >> pos1 >> pos2;
        while(1) 
        {
	        if((pos1 < 0) && (pos2 < 10))
	        {
	        	cout << "Zadal si zle suradnice!" << endl;
	        	cout << "Zadaj ich znovu: ";
	        	cin >> pos1 >> pos2;
			}
			if((pos1 >= 6) && (pos2 >= 6))
	        {
	        	cout << "Zadal si zle suradnice!" << endl;
	        	cout << "Zadaj ich znovu: ";
	        	cin >> pos1 >> pos2; 	
			}
			
			else
			{
				break;
			}
		}
		if(Attack(pos1,pos2))
        {
            cout << "Potopil si lod!" << endl;
        }
		else
		{
            cout << "Na tomto mieste sa nenachadza lod skus to znova" << endl;
        }
        
		cout << "Pocet zostavajucich lodi: " << NumberOfShips() << endl;
        if (NumberOfShips() == 0){
            Show();
			cout << "Vyhral si!\n";
            cout << "Spustit znova (y/n)?";
            string answer;
			cin >> answer;
            if(answer == "y")
            {
            	Clear;
				main();
			}
			else
			{
				break;	
			}
            
        }
        cout << "Chces sa vzdat (y/n)? ";
		cin >> prompt;
		cout << endl;
        if(prompt == 'y')
        {
            break;
        }

    }
    
    cout << "Prehral si!" << endl;
    Show();
    
    return 0;
}
