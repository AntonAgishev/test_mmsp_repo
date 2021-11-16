#include <iostream>
#include <string>
#include "ReadTXT.h"
#include "HelpFunction.h"
#include "FindX.h"
#include <iomanip>
using namespace std;

const int SIZE = 10;
string PATH = "Labrab5_2020.txt";
string VARIANT = "������� 1";

int main() {

	setlocale(0, "rus");

	double** matrix;

	matrix = ReadTXT(PATH, VARIANT, SIZE);
	cout << endl << "�������:" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	vector<double> L;
	L = Find_X(matrix, SIZE);
	cout << endl << "����������� ��������:" << endl;
	for (int i = 0; i < L.size(); i++) {
		cout << "[" << i + 1 << "]" << L[i] << endl;
	}

	vector<vector<double>> VV;
	VV = Find_Vector(matrix, L, SIZE);

	cout << fixed << setprecision(4);
	cout << endl << "����������� �������:" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << "Z" << i << " :";
		for (int j = 0; j < SIZE; j++) {
			cout << VV[i][j] << " ";
		}
		cout << endl;
	}


		


	cout << endl << "�������� �1:" << endl;
	for (int index = 0; index < SIZE; index++) {
		vector <double> vec_1;
		for (int i = 0; i < SIZE; i++) {
			double z = 0;
			for (int j = 0; j < SIZE; j++) {
				z += matrix[i][j] * VV[index][j];
			}
			vec_1.push_back(z);
		}

		vector<double> vec_2;
		for (int i = 0; i < SIZE; i++) {
			double z = VV[index][i] * L[index];
			vec_2.push_back(z);
		}

		cout << fixed << setprecision(4);
		cout << endl << "A*X[" << index << "]-L[" << index << "]*X: " << endl;
		for (int i = 0; i < SIZE; i++) {
			cout << vec_1[i] - vec_2[i] << " ";
		} cout << endl;
	}
	// ������ ��������
	double sum(0);
	cout << endl << "�������� �2:" << endl;
	for (int index = 0; index < SIZE; ++index) 
	{
		cout << fixed << setprecision(4);
			for (int i = 0; i < SIZE; ++i)
			{
				for (int j = 0; j < SIZE; ++j)
				{
					sum += VV[index][j] * VV[i][j];
				}
				cout << sum << " ";
				sum = 0;
			}
			cout << endl;
	}
	
	//������� ������, ���������� ��� �������
	for (int i = 0; i < SIZE; i++) {
		delete matrix[i];
	} delete[] matrix;
	
	return 0;
}