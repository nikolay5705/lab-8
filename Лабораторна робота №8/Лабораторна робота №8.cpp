#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

void create_a_mass(double** mass, int rows_mass, int colum_mass);
void Enter_size_mass_for_stream(int& size_mass, int& index, ifstream& fin);
void Enter_size_mass(int& size_mass, int& index);
void Output_mass(double** mass, int rows, int colum);
void Enter_mass_for_stream(double** mass, int rows, int colum, ifstream& fin);
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
	
	char input[] = "input_2.txt";
	char output[] = "output_2.txt";

	ifstream fin(input);
	ofstream fout(output);

	bool flag = false, flag_for_empty_fille = true;
	int temp_for_empty_file, counter_for_empty_file = 0;
	int choose_option;
	cout << "Оберать звідки будете брати іеформацію, для програми" << endl;
	cout << "Де 1 - ви будете вводити інформацію з консолі" << endl;
	cout << "A  0 - ви будете вводити інформацію з файлу" << endl;
	cout << "Введіть цифру: ";
	cin >> choose_option;

	while (!cin) {
		if (!cin) {
			cin.clear();
			cin.ignore(32767, '\n');
		}

		cout << "Ви ввели слово або букву\n";
		cout << "Введіть цифру: ";
		cin >> choose_option;

	}
	if (choose_option == 1)flag = true;


	cout << "\t\tЛабораторна робота №8\n\n";


	if (flag == false) {
		if (!fin.is_open()) {
			cout << "Файл " << input << " не було відкрито за певинх умов" << endl;
		}
		else {
			cout << "Файл " << input << " було успішно відкрито" << endl;
		}
		if (!fout.is_open()) {
			cout << "Файл " << output << " не було відкрито за певинх умов" << endl;
		}
		else {
			cout << "Файл " << output << " було успішно відкрито" << endl;
		}
		if (fin.is_open()) {
			while (fin >> temp_for_empty_file) {
				++counter_for_empty_file;
			}
		}
		if (counter_for_empty_file == 0) {
			cout << "Ваш файл пустий тому програма не може обробляти ваші дані з файлу" << endl;
			cout << "Будь ласка введіть числа у файлі" << endl;
			flag_for_empty_fille = false;
		}		
		else if (counter_for_empty_file < 76) {
			cout << "У файлі недостатньо елементів тому програма не може обробляти ваші дані з файлу" << endl;
			cout << "Будь ласка введіть числа у файлі" << endl;
			flag_for_empty_fille = false;
		}
		fin.close();
		fout.close();

	}
	
	if (flag_for_empty_fille || choose_option == 1) {
		ifstream fin(input);
		ofstream fout(output);

		int rows_A, colum_A, rows_B, colum_B, index = 0;

		if (flag) {
			cout << "Введення розмірності матриці А\n";
			Enter_size_mass(rows_A, index);
			Enter_size_mass(colum_A, index);
			cout << "Введення розмірності матриці В\n";
			Enter_size_mass(rows_B, index);
			Enter_size_mass(colum_B, index);
		}
		else {
			cout << "Введення розмірності матриці А\n";
			Enter_size_mass_for_stream(rows_A, index, fin);
			Enter_size_mass_for_stream(colum_A, index, fin);
			cout << "Введення розмірності матриці В\n";
			Enter_size_mass_for_stream(rows_B, index, fin);
			Enter_size_mass_for_stream(colum_B, index, fin);
		}


		if ((counter_for_empty_file >= 4 + rows_A * colum_A + rows_B * colum_B) || (choose_option == 1)) {
			//Вмділення динамічної пам'ятідля наших масивів
			double** A = new double* [rows_A];
			double** B = new double* [rows_B];
			//Створення масиву А
			create_a_mass(A, rows_A, colum_A);
			//Створення масиву В
			create_a_mass(B, rows_B, colum_B);
			//Введення елементів наших матриць

			if (flag) {
				cout << "Введення матриці А" << endl;
				Enter_mass(A, rows_A, colum_A);
				cout << "Введення матриці B" << endl;
				Enter_mass(B, rows_B, colum_B);
			}
			else {
				cout << "Введення матриці А" << endl;
				Enter_mass_for_stream(A, rows_A, colum_A, fin);
				cout << "Введення матриці B" << endl;
				Enter_mass_for_stream(B, rows_B, colum_B, fin);
			}
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
			second_task(A, rows_A, colum_A);
			cout << "Матриця А із заміненими боковими стовпцями\n\n";
			Output_mass(A, rows_A, colum_A);
			//3 Завдання
			cout << "\t\tЗавдання №3\n\n";
			third_task(B, rows_B, colum_B, index_of_row_max_num_B);
			cout << "Матриця B із відсортованим рядком де знаходиться найбільший елемент\n\n";
			Output_mass(B, rows_B, colum_B);
			// Видалення динамічної пам'яті виділеної для наших матриць
			fin.close();
			fout.close();
			for (int i = 0;i < rows_A;i++) {
				delete[] A[i];
			}
			for (int i = 0;i < rows_B;i++) {
				delete[] B[i];
			}
			delete[] A;
			delete[] B;
		}
		else {
			cout << "У файлі недостатньо елементів тому програма не може обробляти ваші дані з файлу" << endl;
			cout << "Будь ласка введіть числа у файлі" << endl << endl;
		}
	}
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
void Enter_size_mass_for_stream(int& size_mass, int& index, ifstream& fin) {
	if(index == 0 || index == 2)cout << "Введіть розмір матриць для n(стовпців, де n >= 6): ";
	else cout << "Введіть розмір матриць для m(рядків, де m >= 6): ";
	fin >> size_mass;
	while (fin.fail()) {
		if (fin.fail()) {
			fin.clear();
			fin.ignore(32767, '\n');
		}
		cout << "Ви ввели слово або букву\n";
		cout << "Введіть розмір матриці: ";
		fin >> size_mass;
	}
	while (size_mass < 6) {
		if (fin.fail()) {
			fin.clear();
			fin.ignore(32767, '\n');
			while (fin.fail()) {
				if (fin.fail()) {
					fin.clear();
					fin.ignore(32767, '\n');
				}
				cout << "Ви ввели слово або букву\n";
				cout << "Введіть розмір матриці: ";
				fin >> size_mass;
			}
		}
		if (size_mass < 6) {
			cout << "Ви ввели розмір менший за 6\n";
			cout << "Введіть розмір матриці: ";
			fin >> size_mass;
		}
		
	}
	index++;
	cout << endl << endl;
}
/////////////////////////////////////////////////
void Enter_size_mass(int& size_mass, int& index) {
	if (index == 0 || index == 2)cout << "Введіть розмір матриць для n(стовпців, де n >= 6): ";
	else if(index == 1 || index == 3) cout << "Введіть розмір матриць для m(рядків, де m >= 6): ";
	cin >> size_mass;
	while (!cin) {
		if (!cin) {
			cin.clear();
			cin.ignore(32767, '\n');
		}
		
			cout << "Ви ввели слово або букву\n";
			cout << "Введіть розмір матриці: ";
			cin >> size_mass;
		
	}
	while (size_mass < 6) {
		while (!cin) {
			if (!cin) {
				cin.clear();
				cin.ignore(32767, '\n');
			}
				cout << "Ви ввели слово або букву\n";
				cout << "Введіть розмір матриці: ";
				cin >> size_mass;
			
		}
		if (size_mass < 6) {
			cout << "Ви ввели розмір менший за 6\n";
			cout << "Введіть розмір матриці: ";
			cin >> size_mass;
		}

	}
	index++;
	cout << endl << endl;
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
			while (!cin) {
				if (!cin) {
					cin.clear();
					cin.ignore(32767, '\n');
				}
				if(!cin){
					cout << "Ви ввелм не число, а букву чи слово" << endl;
					cout << "Введіть [" << i + 1 << ";" << j + 1 << "] елемент матриці цифрами ";
					cin >> mass[i][j];
				}
				
			}
		}
	}
	
	cout << endl;
}
//////////////////////////////////////////////////////
void Enter_mass_for_stream(double** mass, int rows, int colum, ifstream& fin) {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < colum;j++) {
			cout << "Введіть [" << i + 1 << ";" << j + 1 << "] елемент матриці: ";
			fin >> mass[i][j];
			while (fin.fail()) {
				if (fin.fail()) {
					fin.clear();
					fin.ignore(32767, '\n');
				}
				if (fin.fail()) {
					cout << "Ви ввелм не число, а букву чи слово" << endl;
					cout << "Введіть [" << i + 1 << ";" << j + 1 << "] елемент матриці цифрами ";
					fin >> mass[i][j];
				}

			}
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
	         if(mass[i][j] == cin.fail()) {
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