#include<iostream>
#include<iomanip>
#include<Windows.h>

using namespace std;
void Change(int** a, const int row1, const int row2, const int colCount);

void print(int** mas, const int row, const int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
			cout << setw(4) << mas[i][k];
		cout << endl<<endl;
	}
}
void Creat(int **mas, const int row, const int col, const int Low, const int High)
{
	int b;
	cout << "		 A" << endl<<endl;
	for (int i = 0; i < row; i++)
		for (int k = 0; k < col; k++)
		{
			b = Low + rand() % (High - Low + 1);
			mas[i][k] = b;
			
		}
}

void Sort(int** a, const int rowCount, const int col)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((a[i1][0] > a[i1 + 1][0])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] < a[i1 + 1][1])
				||
				(a[i1][0] == a[i1 + 1][0] &&
					a[i1][1] == a[i1 + 1][1] &&
					a[i1][3] < a[i1 + 1][3]))
				Change(a, i1, i1 + 1, col);
				

}
void Change(int** a, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		
		tmp = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = tmp;
	}
}
int Sum(int** mas, const int row, const int col,int &s,int &q)
{
	for(int i=0;i<row;i++)
		for(int k=0;k<col;k++)
			if ((mas[i][k] % 6 == 0) && (i + k) != 5)
			{
				s += mas[i][k];
				q++;
				
			}
	return s;
}
int main()
{
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));

	int L = 11;
	int H = 74;

	int row = 2;
	int col = 2;

	int** mas =new int*[row];
	for (int i = 0; i < row; i++)
		mas[i] = new int[col];

	Creat(mas, row, col, L, H);
	print(mas, row, col);
	cout << endl << endl;
	Sort(mas, row, col);
	cout << "		 B" << endl << endl;
	print(mas, row, col);

	int s = 0;
	int k = 0;
	Sum(mas, row, col,s,k);
	cout << "Сума елеметів,які підходять умові: " << s << endl << endl;
	cout <<"Кількість елеметів,які підходять умові: "<< k << endl<<endl;
	
	for (int i = 0; i < row; i++)
		delete[] mas[i];
	delete[] mas;
	return 0;
}