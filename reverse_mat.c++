#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cmath>//pow�Լ��� ����ϱ� ���� ��������߰�

using namespace std;
//===============================================================================================================
//Ŭ���� ������ ����

//����� ������ ����ִ� Ŭ����
class matrix {
	//
	double** matrix_n1;
	double** matrix_n2;
	const int matrix_size;

public:

	//�ܺο��� ��������� �����ϱ� ���� �Լ���
	double** get_my_mat_n1()
	{
		return matrix_n1;
	}

	double** get_my_mat_n2()
	{
		return matrix_n2;
	}

	int get_my_num()
	{
		return matrix_size;
	}

	//matrix�� ũ�⸦ �������� ���� function����

	void matrix_size_get()
	{
		int ivalue;
		cout << "N_By_N����� size input : ";
		cin >> ivalue;
		matrix_size == ivalue;
	}

	//��� �����Ҵ�
	
	void new_matrix()
	{
		//matrix_n1�� �����Ҵ�
		matrix_n1 = new double* [matrix_size];
		for (int i = 0; i < matrix_size; i++)
		{
			matrix_n1[i] = new double[matrix_size];
		}

		//matrix_n2�� �����Ҵ�
		matrix_n2 = new double* [matrix_size];
		for (int i = 0; i < matrix_size; i++)
		{
			matrix_n2[i] = new double[matrix_size];
		}
	}

	//�����Ҵ� �޸� �����Լ�
	
	void delete_matrix()
	{
		//matrix_n2�� �����Ҵ� ����
		for (int i = 0; i < matrix_size; i++)
			delete[] matrix_n2[i];

		delete[] matrix_n2;

		//matrix_n1�� �����Ҵ� ����
		for (int i = 0; i < matrix_size; i++)
			delete[] matrix_n2[i];

		delete[] matrix_n2;
	}

	//��� ��ȯ�Լ�
	
	void** matrix_return(double **mymatrix, int n)
	{
		cout << "[��� ���]" << endl;
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				cout << mymatrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	//��� �� �ʱ�ȭ �Լ�
	
	void matrix_n1_Init()
	{
		//��������� �� ����
		for (int i = 0; i < matrix_size; i++)
		{
			for (int j = 0; j < matrix_size; j++)
			{
				cout << "������Ŀ��[" << i << "][" << j << "] : ";
				//printf("������Ŀ��[%d][%d] : ");
				cin >> matrix_n1[i][j];
				//scanf("%d", &matrix_1[i][j]);
			}
			cout << endl;
		}
		for (int i = 0; i < matrix_size; i++)
		{
			for (int j = 0; j < matrix_size; j++)
			{
				if (i == j)
					matrix_n2[i][j] = 1;
				else
					matrix_n2[i][j] = 0;
			}
		}
	}

	//�� �Լ��� ���ؼ� matrix�� ��� �������� �����Ұ��̴�.
	void matrix_information()
	{
		
	}
};

//===============================================================================================================

//����� ���� Ŭ����
class reverse_matrix {
	//����� �����´�.
	matrix mymatrix;
	double** matrix_1 = mymatrix.get_my_mat_n1();
	double** matrix_2 = mymatrix.get_my_mat_n2();
	int n = mymatrix.get_my_num();
	//���μ� �������� ����� ���ũ��(�ٲ��� �ϹǷ� ũ�⸦ �����ؿ´�.)
	int u_matrix_num = n;

public:
	//���콺 �����Լ�
	double ** matrix_rev_return()
	{
		//determinant = 0�̸�, 0��ȯ, 1�̸� 1��ȯ
		if (determinant == 0)
		{
			cout << "��Ľ��� ���� 0. ����� ������ ������ �� ����." << endl;
			return 0;
		}

		//���콺 ���� �ҰŹ��� �̿��Ҷ�, ������ matrix_1, matrix_2��� ���� ����Ǿ�� �Ѵ�.
			//for���� ���� ����

			//�� ��� �Ŀ� ���� ����ǹǷ�, 1���� ��ҵ��� ���� ������ش�.  
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				//i==j��쿡 ������ ���� ��������� �Ѵ�.
				//�밢����� 1�� �ǵ��� �ٲ���� �Ѵ�.
				if (i == j)
				{
					//matrix_1[i][j]
					//i==j�� ��쿡�� ���� ���� �� �����ش�.
					//�� ��� �Ǻ����� 1�� ������ش�.
					if (i == 0)//�� if���� �Ǻ��� ���� 0�ΰ�� �������� ���� �ʵ����ϴ� ����̴�. 
					{
						//i==0�� ��쿡�� �ֺ������ �ش��࿡ ���ؼ� �Ǻ��� 0�� �ƴѼ��� ���������Ѵ�.
							//������Ŀ��� ���� ���� �����ؾ���.
						if (i > 0)
						{
							//�ٷ� �Ʒ� ����� �Ǻ��࿡ �����ִ� ��������
							for (int jx = 0; jx < n; jx++)
							{
								matrix_1[i][jx] += matrix_1[i + 1][jx];
								matrix_2[i][jx] += matrix_2[i + 1][jx];
							}

							for (int jk = 0; jk < n; jk++)
							{

								matrix_1[i][jk] = matrix_1[i][jk] / matrix_1[i][j];
								matrix_2[i][jk] = matrix_2[i][jk] / matrix_1[i][j];
							}
						}
						else if (i = (n - 1))
						{
							//i==n-1�� ��� �ٷ� ���� ����� �Ǻ��࿡ �����ִ� ��������

							for (int jx = 0; jx < n; jx++)
							{
								matrix_1[i][jx] += matrix_1[i - 1][jx];
								matrix_2[i][jx] += matrix_2[i - 1][jx];
							}

							for (int jk = 0; jk < n; jk++)
							{

								matrix_1[i][jk] = matrix_1[i][jk] / matrix_1[i][j];
								matrix_2[i][jk] = matrix_2[i][jk] / matrix_1[i][j];
							}
						}

					}
					else//i�� 0�� �ƴѰ��! -> �׳� �����ص��ȴ�
					{
						for (int jk = 0; jk < n; jk++)
						{
							//i==j�� ��쿡�� ���� ���� �� �����ش�.
							//�� ��� �Ǻ����� 1�� ������ش�.
							matrix_1[i][jk] = matrix_1[i][jk] / matrix_1[i][j];
							matrix_2[i][jk] = matrix_2[i][jk] / matrix_1[i][j];
						}
					}

					//i==j�Ʒ��� ��ҵ��� 0���� ������ִ� ����
					//���� : i = j�� ���ڸ� ����� �ȵȴ�.
					if (i > 0)
					{
						for (int ik = i + 1; ik < n; ik++)
						{
							for (int jk = 0; jk < n; jk++)
							{
								matrix_1[ik][jk] -= matrix_1[ik][jk] * matrix_1[i][jk];
								matrix_2[ik][jk] -= matrix_2[ik][jk] * matrix_2[i][jk];
							}
						}
					}
					//i==j���� ��ҵ��� 0���� ������ִ� ����
					if (i < n)
					{
						for (int ik = n - 1; ik > (-1); ik--)
						{
							for (int jk = 0; jk < n; jk++)
							{
								matrix_1[ik][jk] -= matrix_1[ik][jk] * matrix_1[i][jk];
								matrix_2[ik][jk] -= matrix_2[ik][jk] * matrix_2[i][jk];
							}
						}
					}
				}
			}
		}
		//���� ������ ���� matrix_1���� �������, matrix_2���� ������� ����Ǿ��� ���̴�.
		cout<<"test return : [�������->������� output]\n"<<endl;
		mymatrix.matrix_return(matrix_1, n);
		cout << endl;

		cout << "test return : [�������->����� output]\n" << endl;
		mymatrix.matrix_return(matrix_2, n);
		cout << endl;

		return matrix_2;
	}
	//����, rev_matrix �Լ��� ��ȯ���� 0�̸�, main�Լ��� �� ��, 0, det!=0�̸� ������� ��ȯ�ȴ�.

	//���μ�����_determination
	//2functions

	//prints the determinant
	printf("the determinant is %lf\n", determinant(n, Matrix));

	//M�� ���ο��� ��� ���� ������ n-1���پ�� ���¿����� ���ο� ����� �����Լ�

	//determinant ��� �Լ�
	double determinant(int n, double **m)
	{

		double det = 0;
		//the functions continues to call its self until n=2
		if (n == 1)
		{
			return m[0][0];
		}
		if (n == 2)
		{
			det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
		}
		else
		{
			double** M =  new double*[n - 1];//�ᱹ �� M�� Vla�� ����� �� ����, �����Ҵ��ؾ��Ѵ�. 
			for (int e = 0; e < n; e++)
			{
				M[e] = new double[n - 1];
			}
			for (int i = 0; i < n; i++)
			{
				subMatrix(n, M, m, 0, i);//submatrix�� �����´�.
				det += m[0][i] * pow(-1, i) * determinant(n - 1, M);//���
			}
		}
		//1���� �����Ҵ� ����
		delete[] M;

		//2���� �����Ҵ� ����
		for (int i = 0; i < n-1; i++)
			delete[] M[i];

		delete[] M;

		//3���� �����Ҵ� ����


		return det;
	}
	//���μ� ������ ���� ��� ���� ������ n-1���پ�� ���¿����� ���ο� ����� �����Լ�
	void subMatrix(int n, double M[n - 1][n - 1], double m[n][n], int I, int J)
	{
		int i, a = 0, b = 0;
		int j;
		for (i = 0; i < n; i++)
		{
			if (i != I)
			{
				for (j = 0; j < n; j++)
				{
					if (J != j)
					{
						M[a][b] = m[i][j];

						b++;

					}
				}

				a++;
				b = 0;
			}
		}

	}


};

//===============================================================================================================
//main �Լ�

int main(void)
{
	


}

//===============================================================================================================
//���μ����� ���¼ҽ��ڵ� �����ϱ�==========================================

int
main()
{
	int n, k = 0;


	printf("how many rows does the matrix have");
	scanf("%d", &n);
	double Matrix[n][n];
	printf("enter the numbers in order with an enter after each one");
	//Taking user input for 2D array
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%lf", &Matrix[i][j]);
		}
	}

	//prints the determinant
	printf("the determinant is %lf\n", determinant(n, Matrix));

	return 0;
}