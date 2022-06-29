#include<iostream>
#include<limits.h>
using namespace std;
void matrix (int p[], int n)
{
    int mat[n][n];
    int i, j, k, L, q;
    for (i=0; i<n; i++){
        for(int j=0;j<n;j++)
        mat[i][j] = 0;   
    }
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            mat[i][j] = INT_MAX;  
            for (k=i; k<=j-1; k++)
            {
                q = mat[i][k] + mat[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < mat[i][j])
                {
                    mat[i][j] = q;    
                }
            }
        }
    }
    cout<<"Minimum number of multiplications is : "<<mat[1][n-1];  
}
int main()
{
    int n,i;
    cout<<"enter number of matrices\n";
	cin>>n;
	int arr[n+1];
	cout<<"enter order of matrices in form of array\n";
	for(int i=0;i<=n;i++)
	cin>>arr[i];  
    matrix (arr, n+1);
    return 0;
}

