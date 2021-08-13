// optimised qapproach to calculate nth term
#include<bits/stdc++.h>
#define ll long long int 
#define vec vector<ll> 
#define f(a,b) for(ll i = a ; i < b ; i++ )
#define fj(a,b) for(ll j = a ; j < b ; j++ )
#define fk(a,b) for(ll k = a ; k < b ; k++ )
#define fasthoja ios_base::sync_with_stdio(false); cin.tie(NULL);
#define N 51
#define md 1000000007
using namespace std;

// Declaring our transformation matrix as global array 
ll A[2][2] = { {0 , 1}, 
	           {1 , 1}};
// this is identity matrix and is used for matrix multiplicationi
ll I[2][2];
// this is our Fn matrix
ll f[1][2] = {1 , 1};


// This function will multiply 2 square matrices
void Mul(ll A[][2] , ll B[][2] , ll dim ){
    
    ll res[dim][dim];
    
    f(0,dim){
        fj(0,dim){
            res[i][j] = 0;
            
            fk(0,dim){
                //Doing multiplication along with modular
                res[i][j] += (  ( A[i][k] % md ) * ( B[k][j] % md ) ) % md ;
            }
        }
    } //end of outer for loop
    
    f(0,dim) fj(0,dim) A[i][j] = res[i][j] % md ;
}

/* This function is used to multiply our
Fn to transformation Matrix and return Nth term */
ll Mul2(ll A[][2] , ll B[][2] ){
    
    ll res[1][2];
    
    f(0,1){
        fj(0,2){
            res[i][j] = 0;
            
            fk(0,2){
                //Doing multiplication along with modular
                res[i][j] += (  ( A[i][k] % md ) * ( B[k][j] % md ) ) % md ;
            }
        }
    } //end of outer for loop
   
   return res[0][0];
}

//This function will calculate power of Matrix
void power(ll A[2][2] , ll dim , ll n){
    
    //identity matrix initialization
    f(0,dim){
        fj(0,dim){
            if( i == j ) I[i][j] = 1;
            else         I[i][j] = 0;
        }
    }
    
    
    //optimised qapproach using binary exponentiation
    while( n > 0 ){
        
        if( n % 2 == 0 ){
            //even
            Mul(A,A,dim);
             n /= 2;
        }
        else{
            Mul(I,A,dim);
            n--;
        }
    }
    f(0,dim) fj(0,dim)  A[i][j] = I[i][j];
}

int main(void){
    fasthoja;
      ll n; cin >> n;
      ll k = 2;
      //This is function call to calculate power of matrix A to n-1
      power(A,k,n-1);
      cout << n << "th term is : " << Mul2(f,A) << "\n";
    return 0;
}

/*
Input: n = 10
Output: 10th term is 55
*/
    
