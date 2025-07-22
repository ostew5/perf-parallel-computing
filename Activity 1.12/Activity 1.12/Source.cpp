/*
//Task 2: Hello World using C and Visual Studio

#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	return 0;
}
/*

/*
//Task 3: Matrix Multiply (the Hello World of Parallel Computing)

#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(int argc, char* argv[])
{
	int A[N][N], B[N][N], C[N][N];

	srand(42);

	for (int i = 0; i != N; i++)
		for (int j = 0; j != N; j++)
		{
			A[i][j] = rand();
			B[i][j] = rand();
		}

	for (int i = 0; i != N; i++)
		for (int j = 0; j != N; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < N; k++)
				C[i][j] += A[i][k] * B[k][j];
		}

	printf("done!\n");

	return 0;
}
*/

/*
//Task 4: Saving and Comparing Results to ensure correctness is maintained

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 100

int main(int argc, char* argv[])
{
	int D[N][N];
	FILE* input;
	errno_t OK = fopen_s(&input, "log.bin", "rb"); // open "log.bin" for writing in binary mode
	assert(OK == 0);
	
	fread(D, sizeof(int), N * N, input);
	
	fclose(input);

	int A[N][N], B[N][N], C[N][N];

	srand(42);

	for (int i = 0; i != N; i++)
		for (int j = 0; j != N; j++)
		{
			A[i][j] = rand();
			B[i][j] = rand();
		}

	for (int i = 0; i != N; i++)
		for (int j = 0; j != N; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < N; k++)
				C[i][j] += A[i][k] * B[k][j];
		}

	for (int i = 0; i != N; i++)
		for (int j = 0; j != N; j++)
			assert(C[i][j] == D[i][j]); // compare the computed result with the saved result

	//FILE* output;
	//errno_t OK = fopen_s(&output, "log.bin", "wb"); // open "log.bin" for writing in binary mode
	//assert(OK == 0);
	//
	//fwrite(C, sizeof(int), N * N, output); // write the result matrix C to the file
	//fclose(output);
	
	return 0;
}
*/

/*
//Task 5: Timing your code

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <chrono>

#define N 100

int main(int argc, char* argv[])
{
	int A[N][N], B[N][N], C[N][N];

	srand(42);

	for (int i = 0; i != N; i++)
		for (int j = 0; j != N; j++)
		{
			A[i][j] = rand();
			B[i][j] = rand();
		}

	for (int x = 0; x < 10; x++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();

		for (int i = 0; i != N; i++)
			for (int j = 0; j != N; j++)
			{
				C[i][j] = 0;
				for (int k = 0; k < N; k++)
					C[i][j] += A[i][k] * B[k][j];
			}

		auto end_time = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> elapsed = end_time - start_time;

		printf("Time taken: %f seconds\n", elapsed.count());
	}

	return 0;
}
*/

//Task 6: Improving Performance

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <chrono>

#define N 100

int A[N][N], B[N][N], C[N][N];

int main(int argc, char* argv[])
{
	srand(42);

	for (int i = 0; i != N; i++)
		for (int j = 0; j != N; j++)
		{
			A[i][j] = rand();
			B[i][j] = rand();
		}

	for (int x = 0; x < 10; x++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();

		for (int i = 0; i != N; i++)
			for (int j = 0; j != N; j++)
			{
				double total = 0.0;
				
				for (int k = 0; k < N; k++)
					total += A[i][k] * B[k][j];

				C[i][j] = total;
			}

		auto end_time = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> elapsed = end_time - start_time;

		printf("Time taken: %f ms\n", elapsed.count() * 1000);
	}

	return 0;
}

/*
//Task 7: Exploring 2D array structures in C

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <chrono>

#define N 4

int A[N][N], B[N][N], C[N][N];

int main(int argc, char* argv[])
{
	for (int i = 0; i != N; i++)
		for (int j = 0; j != N; j++)
			printf("&A[%d][%d] = %p\n", i, j, (void*)&A[i][j]);

	srand(42);

	for (int i = 0; i != N; i++)
		for (int j = 0; j != N; j++)
		{
			A[i][j] = rand();
			B[i][j] = rand();
		}

	for (int x = 0; x < 10; x++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();

		for (int i = 0; i != N; i++)
			for (int j = 0; j != N; j++)
			{
				double total = 0.0;

				for (int k = 0; k < N; k++)
					total += A[i][k] * B[k][j];

				C[i][j] = total;
			}

		auto end_time = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> elapsed = end_time - start_time;

		printf("Time taken: %f seconds\n", elapsed.count());
	}

	return 0;
}
*/