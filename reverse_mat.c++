#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cmath>//pow함수를 사용하기 위해 헤더파일추가

using namespace std;
//===============================================================================================================
//클래스 선언할 공간

//행렬의 정보를 담고있는 클래스
class matrix {
	//
	double** matrix_n1;
	double** matrix_n2;
	const int matrix_size;

public:

	//외부에서 멤버변수에 접근하기 위한 함수들
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

	//matrix의 크기를 가져오기 위한 function선언

	void matrix_size_get()
	{
		int ivalue;
		cout << "N_By_N행렬의 size input : ";
		cin >> ivalue;
		matrix_size == ivalue;
	}

	//행렬 동적할당
	
	void new_matrix()
	{
		//matrix_n1의 동적할당
		matrix_n1 = new double* [matrix_size];
		for (int i = 0; i < matrix_size; i++)
		{
			matrix_n1[i] = new double[matrix_size];
		}

		//matrix_n2의 동적할당
		matrix_n2 = new double* [matrix_size];
		for (int i = 0; i < matrix_size; i++)
		{
			matrix_n2[i] = new double[matrix_size];
		}
	}

	//동적할당 메모리 해제함수
	
	void delete_matrix()
	{
		//matrix_n2의 동적할당 해제
		for (int i = 0; i < matrix_size; i++)
			delete[] matrix_n2[i];

		delete[] matrix_n2;

		//matrix_n1의 동적할당 해제
		for (int i = 0; i < matrix_size; i++)
			delete[] matrix_n2[i];

		delete[] matrix_n2;
	}

	//행렬 반환함수
	
	void** matrix_return(double **mymatrix, int n)
	{
		cout << "[행렬 출력]" << endl;
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				cout << mymatrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	//행렬 값 초기화 함수
	
	void matrix_n1_Init()
	{
		//정방행렬의 값 지정
		for (int i = 0; i < matrix_size; i++)
		{
			for (int j = 0; j < matrix_size; j++)
			{
				cout << "정방행렬요소[" << i << "][" << j << "] : ";
				//printf("정방행렬요소[%d][%d] : ");
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

	//이 함수를 통해서 matrix의 모든 정보들을 구성할것이다.
	void matrix_information()
	{
		
	}
};

//===============================================================================================================

//역행렬 연산 클래스
class reverse_matrix {
	//행렬을 가져온다.
	matrix mymatrix;
	double** matrix_1 = mymatrix.get_my_mat_n1();
	double** matrix_2 = mymatrix.get_my_mat_n2();
	int n = mymatrix.get_my_num();
	//여인수 전개에서 사용할 행렬크기(바뀌어야 하므로 크기를 복사해온다.)
	int u_matrix_num = n;

public:
	//가우스 조던함수
	double ** matrix_rev_return()
	{
		//determinant = 0이면, 0반환, 1이면 1반환
		if (determinant == 0)
		{
			cout << "행렬식의 값이 0. 역행렬 연산을 진행할 수 없다." << endl;
			return 0;
		}

		//가우스 조던 소거법을 이용할때, 연산은 matrix_1, matrix_2모두 같이 진행되어야 한다.
			//for문을 통해 연산

			//행 계산 후에 열이 변경되므로, 1차원 요소들을 먼저 사용해준다.  
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				//i==j경우에 연산을 먼저 진행해줘야 한다.
				//대각행렬이 1이 되도록 바꿔줘야 한다.
				if (i == j)
				{
					//matrix_1[i][j]
					//i==j인 경우에서 같은 행을 다 나눠준다.
					//이 경우 피봇들을 1로 만들어준다.
					if (i == 0)//이 if문은 피봇의 값이 0인경우 계산오류가 나지 않도록하는 계산이다. 
					{
						//i==0인 경우에는 주변행들을 해당행에 더해서 피봇이 0이 아닌수로 만들어줘야한다.
							//단위행렬에도 같은 연산 적용해야함.
						if (i > 0)
						{
							//바로 아래 행들을 피봇행에 더해주는 연산진행
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
							//i==n-1인 경우 바로 위의 행들을 피봇행에 더해주는 연산진행

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
					else//i가 0이 아닌경우! -> 그냥 실행해도된다
					{
						for (int jk = 0; jk < n; jk++)
						{
							//i==j인 경우에서 같은 행을 다 나눠준다.
							//이 경우 피봇들을 1로 만들어준다.
							matrix_1[i][jk] = matrix_1[i][jk] / matrix_1[i][j];
							matrix_2[i][jk] = matrix_2[i][jk] / matrix_1[i][j];
						}
					}

					//i==j아래의 요소들을 0으로 만들어주는 과정
					//조건 : i = j가 격자를 벗어나면 안된다.
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
					//i==j위의 요소들을 0으로 만들어주는 과정
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
		//위의 과정을 통해 matrix_1에는 단위행렬, matrix_2에는 역행렬이 저장되었을 것이다.
		cout<<"test return : [정방행렬->단위행렬 output]\n"<<endl;
		mymatrix.matrix_return(matrix_1, n);
		cout << endl;

		cout << "test return : [단위행렬->역행렬 output]\n" << endl;
		mymatrix.matrix_return(matrix_2, n);
		cout << endl;

		return matrix_2;
	}
	//만약, rev_matrix 함수의 반환값이 0이면, main함수로 들어갈 때, 0, det!=0이면 역행렬이 반환된다.

	//여인수전개_determination
	//2functions

	//prints the determinant
	printf("the determinant is %lf\n", determinant(n, Matrix));

	//M은 내부에서 행과 열의 개수가 n-1씩줄어든 상태에서의 새로운 행렬의 구성함수

	//determinant 계산 함수
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
			double** M =  new double*[n - 1];//결국 이 M을 Vla로 사용할 수 없고, 동적할당해야한다. 
			for (int e = 0; e < n; e++)
			{
				M[e] = new double[n - 1];
			}
			for (int i = 0; i < n; i++)
			{
				subMatrix(n, M, m, 0, i);//submatrix를 가져온다.
				det += m[0][i] * pow(-1, i) * determinant(n - 1, M);//재귀
			}
		}
		//1차원 동적할당 해제
		delete[] M;

		//2차원 동적할당 해제
		for (int i = 0; i < n-1; i++)
			delete[] M[i];

		delete[] M;

		//3차원 동적할당 해제


		return det;
	}
	//여인수 전개를 위해 행과 열의 개수가 n-1씩줄어든 상태에서의 새로운 행렬의 구성함수
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
//main 함수

int main(void)
{
	


}

//===============================================================================================================
//여인수전개 오픈소스코드 변경하기==========================================

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