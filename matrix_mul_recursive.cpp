#include <iostream>
#include <vector>

using namespace std;
#define randsize 9

vector<vector<int>> add_vector(vector<vector<int>> A, vector<vector<int>> B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> square_matrix_multiply_recursive(vector<vector<int>> A, vector<vector<int>> B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    if (n == 1)
    {
        // cout<<"test1\n";
        C[0][0] = A[0][0] * B[0][0];
    }
    else
    {
        // cout<<"test2\n";
        int mid = n / 2;
        vector<vector<int>> A11(mid, vector<int>(mid));
        vector<vector<int>> A12(mid, vector<int>(mid));
        vector<vector<int>> A21(mid, vector<int>(mid));
        vector<vector<int>> A22(mid, vector<int>(mid));
        vector<vector<int>> B11(mid, vector<int>(mid));
        vector<vector<int>> B12(mid, vector<int>(mid));
        vector<vector<int>> B21(mid, vector<int>(mid));
        vector<vector<int>> B22(mid, vector<int>(mid));

        for (int i = 0; i < mid; i++)
        {
            for (int j = 0; j < mid; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + mid];
                A21[i][j] = A[i + mid][j];
                A22[i][j] = A[i + mid][j + mid];
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + mid];
                B21[i][j] = B[i + mid][j];
                B22[i][j] = B[i + mid][j + mid];
            }
        }
        // cout<<"test3\n";
        vector<vector<int>> C11 = add_vector(square_matrix_multiply_recursive(A11, B11), square_matrix_multiply_recursive(A12, B21));
        vector<vector<int>> C12 = add_vector(square_matrix_multiply_recursive(A11, B12), square_matrix_multiply_recursive(A12, B22));
        vector<vector<int>> C21 = add_vector(square_matrix_multiply_recursive(A21, B11), square_matrix_multiply_recursive(A22, B21));
        vector<vector<int>> C22 = add_vector(square_matrix_multiply_recursive(A21, B12), square_matrix_multiply_recursive(A22, B22));
        C.resize(n, vector<int>(n));
        for (int i = 0; i < mid; i++)
        {
            for (int j = 0; j < mid; j++)
            {
                C[i][j] = C11[i][j];
                C[i][j + mid] = C12[i][j];
                C[i + mid][j] = C21[i][j];
                C[i + mid][j + mid] = C22[i][j];
            }
        }
    }
    return C;
}

bool poweroftwo(int n)
{
    return ((n > 0) && (n & (n - 1)));
}

int main()
{
    int n = 16;
    if (poweroftwo(n))
    {
        exit(1);
    }
    vector<vector<int>> A, B;
    A.resize(n, vector<int>(n));
    B.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = (rand() % randsize) + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[i][j] = (rand() % randsize) + 1;
        }
    }
    cout << "The Matrices are: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout<<endl;
    // cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nThe multiplied matrix is: \n";
    vector<vector<int>> C = square_matrix_multiply_recursive(A, B);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}