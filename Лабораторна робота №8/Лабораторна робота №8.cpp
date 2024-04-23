#include <iostream>
#include <Windows.h>

using namespace std;

void create_a_mass(double** mass, int rows_mass, int colum_mass);
void Enter_size_mass(int& size_n, int& size_m);
void Output_mass(double** mass, int rows, int colum);
void Enter_mass(double** mass, int rows, int colum);
void Checking_element_of_mass(double** mass, int rows, int colum);
void first_task(double** A, int rows_A, int colum_A, double max_num_B);
void second_task(double** A, int rows_A, int colum_A);
void third_task(double** B, int rows_B, int colum_B, int index_of_row_max_num_B);
void finding_max_element_B(double** B, int rows_B, int colum_B, int& index_of_row_max_num_B, double& max_num_B);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout << "\t\tЛабораторна робота №8\n\n";
	
	//Введення розмірності матриць
	int rows_A, colum_A, rows_B, colum_B;
	cout << "Введення розмірності матриці А\n";
	Enter_size_mass(rows_A, colum_A);
	cout << "Введення розмірності матриці В\n";
	Enter_size_mass(rows_B, colum_B);

	//Вмділення динамічної пам'ятідля наших масивів
	double** A = new double* [rows_A];
	double** B = new double* [rows_B];
	//Створення масиву А
	create_a_mass(A, rows_A, colum_A);
	//Створення масиву В
	create_a_mass(B, rows_B, colum_B);

	//Введення елементів наших матриць
	cout << "Введення матриці А" << endl;
	Enter_mass(A, rows_A, colum_A);
	cout << "Введення матриці B" << endl;
	Enter_mass(B, rows_B, colum_B);

	//Ввиведення наших матриць
	cout << "Матриця А\n\n";
	Output_mass(A, rows_A, colum_A);
	cout << "\nМатриця В\n\n";
	Output_mass(B, rows_B, colum_B);
	
	//Знаходження найбільший елемент та його індекс
	double max_num_B = B[0][0];
	int index_of_row_max_num_B = 0;
	finding_max_element_B(B, rows_B, colum_B, index_of_row_max_num_B, max_num_B);

	//1 Завдання
	cout << "\t\tЗавдання №1\n\n";
	first_task(A, rows_A, colum_A, max_num_B);

	cout << "Матриця А із збільшеними елементами на максимальний елемент матриці В\n\n";
	Output_mass(A, rows_A, colum_A);
	//2 Завдання
	cout << "\t\tЗавдання №2\n\n";

	second_task( A, rows_A, colum_A);

	cout << "Матриця А із заміненими боковими стовпцями\n\n";
	Output_mass(A, rows_A, colum_A);

	//3 Завдання
	cout << "\t\tЗавдання №3\n\n";
	
	third_task(B, rows_B, colum_B, index_of_row_max_num_B);
		
	cout << "Матриця B із відсортованим рядком де знаходиться найбільший елемент\n\n";
	Output_mass(B, rows_B, colum_B);

	// Видалення динамічної пам'яті виділеної для наших матриць
	for (int i = 0;i < rows_A;i++) {
		delete[] A[i];
	}
	for (int i = 0;i < rows_B;i++) {
		delete[] B[i];
	}
	delete[] A;
	delete[] B;

	return 0;
	system("pause");
}


/////////////////////////////////////////////////////////////////////////
void first_task(double** A, int rows_A, int colum_A, double max_num_B) {
	for (int i = 0;i < rows_A;i++) {
		for (int j = 0;j < colum_A;j++) {
			A[i][j] += max_num_B;
		}
	}
}
///////////////////////////////////////////////////////
void second_task(double** A, int rows_A, int colum_A) {
	for (int i = 0;i < rows_A;i++) {
		for (int j = 0;j < 1;j++) {
			swap(A[i][j], A[i][colum_A - j - 1]);
		}

	}
}
//////////////////////////////////////////////////////////////////////////////////
void third_task(double** B, int rows_B, int colum_B, int index_of_row_max_num_B) {
	for (int i = 0;i < colum_B;i++) {
		for (int j = 0;j < colum_B;j++) {
			if (B[index_of_row_max_num_B][i] < B[index_of_row_max_num_B][j]) {
				swap(B[index_of_row_max_num_B][i], B[index_of_row_max_num_B][j]);
			}
		}
	}
}
/////////////////////////////////////////////////
void Enter_size_mass(int& size_n, int& size_m) {
	cout << "Введіть розмір матриць для n(стовпців, де n >= 6): ";
	cin >> size_n;
	
	invalid_input_for_n:
	while (!cin) {
		if (!cin) {
			cin.clear();
			cin.ignore(32767, '\n');
		}
		cout << "Ви ввели слово або букву\n";
		cout << "Введіть розмір матриць для n(стовпців, де n >= 6): ";
		cin >> size_n;
	}
	while (size_n < 6) {
		if (!cin) {
			cin.ignore(32767, '\n');
			goto invalid_input_for_n;
		}
		cout << "Ви ввели розмір менший за 6\n";
		cout << "Введіть розмір матриць для n(стовпців, де n >= 6): ";
		cin >> size_n;
	}



	cout << "Введіть розмір матриць для m(рядків, де m >= 6): ";
	cin >> size_m;
    invalid_input_for_m:
	while (!cin) {
		if (!cin) {
			cin.clear();
			cin.ignore(32767, '\n');
		}
		cout << "Ви ввели слово або букву\n";
		cout << "Введіть розмір матриць для m(рідків, де m >= 6): ";
		cin >> size_m;
	}
	while (size_m < 6) {
		if (!cin) {
			cin.ignore(32767, '\n');
			goto invalid_input_for_m;
		}
		cout << "Ви ввели розмір менший за 6\n";
		cout << "Введіть розмір матриць для m(рядків, де m >= 6): ";
		cin >> size_m;
	}

	cout << endl;
}
//////////////////////////////////////////////////////
void Output_mass(double** mass, int rows, int colum) {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < colum;j++) {
			cout << mass[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
//////////////////////////////////////////////////////
void Enter_mass(double** mass, int rows, int colum) {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < colum;j++) {
			cout << "Введіть [" << i + 1 << ";" << j + 1 << "] елемент матриці: ";
			cin >> mass[i][j];
		    Checking_element_of_mass(mass, rows, colum);
		}
	}
	cout << endl;
}
////////////////////////////////////////////////////////////////////
void Checking_element_of_mass(double** mass, int rows, int colum) {

	
	while (!cin) {
		if (!cin) {
			cin.clear();
			cin.ignore(32767, '\n');
		}
		for (int i = 0;i < rows;i++) {
			for (int j = 0;j < colum;j++) {
	         if(mass[i][j] == !cin) {
	    	      cout << "Ви ввелм не число, а букву чи слово" << endl;
		          cout << "Введіть [" << i + 1 << ";" << j + 1 << "] елемент матриці: ";
			      cin >> mass[i][j];
	       	}
		    }
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void finding_max_element_B(double** B, int rows_B, int colum_B, int& index_of_row_max_num_B, double& max_num_B) {
	for (int i = 0;i < rows_B;i++) {
		for (int j = 0;j < colum_B;j++) {
			if (max_num_B < B[i][j]) {
				max_num_B = B[i][j];
				index_of_row_max_num_B = i;

			}
		}
	}
}
///////////////////////////////////////////////////////////////////
void create_a_mass(double** mass, int rows_mass, int colum_mass) {
	for (int i = 0;i < rows_mass;i++) {
		mass[i] = new double[colum_mass];
	}
}