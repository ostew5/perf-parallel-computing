/*
public class Activity_1_12
{
    static void Main(String[] args)
    {
        var rand = new Random();
        const int N = 100;

        int[,] A = new int[N, N];
        int[,] B = new int[N, N];
        int[,] C = new int[N, N];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                A[i, j] = rand.Next(1, 10);
                B[i, j] = rand.Next(1, 10);
                C[i, j] = 0;
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    C[i, j] += A[i, k] * B[k, j];
                }
            }
        }

        Console.WriteLine("done!");
    }
}
*/

public class Activity_1_12
{
    static void Main(String[] args)
    {
        var rand = new Random();
        var watch = new System.Diagnostics.Stopwatch();
        const int N = 100;

        int[,] A = new int[N, N];
        int[,] B = new int[N, N];
        int[,] C = new int[N, N];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                A[i, j] = rand.Next(1, 10);
                B[i, j] = rand.Next(1, 10);
                C[i, j] = 0;
            }
        }

        for (int x = 0; x != 10; x++)
        {
            watch.Start();

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    for (int k = 0; k < N; k++)
                    {
                        C[i, j] += A[i, k] * B[k, j];
                    }
                }
            }

            watch.Stop();

            Console.WriteLine($"Time taken: {watch.Elapsed.TotalMilliseconds} ms");

            watch.Reset();
        }
    }
}