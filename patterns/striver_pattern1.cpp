#include <iostream>
using namespace std;
void pattern1(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << "*";
        }
        cout << endl;

    }
}
void pattern2(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void pattern4(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
void pattern5(int n)
{
    for(int i=n;i>=1;i--)
    {
        for(int j=i;j>=1;j--)
        {
          cout << "*";
        }
        cout <<endl;
    }
}
void pattern6(int n)
{
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
          cout << j ;
        }
        cout <<endl;
    }
}
void pattern7(int n)
{
    for (int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i);j++)
        {
            cout << " ";
        }
        for(int k=1;k<=(2*i)-1;k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern8(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            cout << " ";
        }
        for(int k=1;k<=(2*n-(2*i-1));k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern9(int n)
{

{
    for (int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i);j++)
        {
            cout << " ";
        }
        for(int k=1;k<=(2*i)-1;k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
for(int l=1;l<=n;l++)
    {
        for( int m=1;m<=l-1;m++)
        {
            cout << " ";
        }
        for(int o=1;o<=(2*n-(2*l-1));o++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern10(int n)
{
    for(int i=1;i<=2*n-1;i++)
    {
        if(i<=n)
        {
            for(int j=1;j<=i;j++)
            {
                cout << "*";
            }
            cout << endl;
        }
        else
        {
            for(int j=1;j<=n-(i-n);j++)
            {
                cout << "*";
            }
            cout << endl;
        }
        
    }
}
void pattern11(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if((i%2==0 && j%2==0) || (i%2!=0 && j%2!=0))
            cout << "1";
            else
            cout << "0";
        }
        cout << endl;
    }
}
void pattern12(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout << j;
        }
        for(int k=1;k<=(2*n)-(2*i);k++)
        cout << " ";
        for(int l=i;l>=1;l--)
        cout << l;

        cout << endl;
    }
}
void pattern13(int n)
{
    int num=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
           cout <<num++ << " ";
        }
        cout <<endl;
    }
}
void pattern14(int n)
{
    for( int i=1;i<=n;i++)
    {
        for(char j='A' ; j< 'A'+i ;j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void pattern15(int n)
{
    for(int i=n;i>=1;i--)
    {
        for(char j='A';j<'A'+i ;j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void pattern16(int n)
{
    char alp = 'A';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout << alp;
        }
        alp=alp+1;
        cout << endl;
    }
}
void pattern17(int n)
{
    for(int i=1 ; i<=n ;i++ )
    {
        int j=0;
        for(j=1;j<= (n-i);j++)
        {
            cout << " " ;
        }
        char alp='A'-1;;
        for(int k = j ; k<=n ; k++)
        {
            alp++;
            cout << alp ;
        }
        while(alp!='A' && alp >'A')
        {
            alp--;
            cout << alp;
        }
        cout << endl;
    }
}
void pattern18(int n)
{
    char alp = 'A' + n ;
    for(int i = 1 ; i <= n ; i++)
    {
        for(char j = alp - i ; j < alp ; j++)
        {
            cout << j ;
        }
        cout << endl ;
    }
}
void pattern19(int n)
{
    for(int i = 1 ; i <= 2*n ; i++)
    {
        if( i <= n){
        for(int j = n - i + 1 ; j>=1 ; j-- )
        {
            cout << "*";
        }
        for( int k=1 ; k <= 2*i-2 ; k++ )
        {
            cout << " ";
        }
        for(int l = n - i + 1 ; l >=1 ; l-- )
        {
            cout << "*";
        }
        }
        else
        {
            for(int j = 1 ; j <= i-n ; j++ )
            {
                cout << "*";
            }
            for(int k = 1 ; k <= 2*(2*n-i) ; k++ )
            {
                cout << " ";
            }
            for(int l = 1 ; l <= i-n; l++ )
            {
                cout << "*";
            }
        }
        cout << endl ;
        
    }
}
void pattern20(int n)
{
    for(int i = 1 ; i<=2*n-1 ; i++)
    {
       if( i<=n )
       {
        for(int j=1;j<=i ; j++)
        {
            cout << "*";
        }
        for(int k=1 ; k<=2*(n-i) ; k++)
        {
            cout << " ";
        }
        for(int l=1 ; l<=i ; l++)
        {
            cout << "*";
        }
       }
       else
       {
        for(int j=1 ; j<= 2*n-i ; j++ )
        {
            cout << "*";
        }
        for(int k=1 ; k<=(2*i)-(2*n) ; k++ )
        {
            cout << " ";
        }
        for(int l=1 ; l<= 2*n-i ; l++ )
        {
            cout << "*";
        }
       }
       cout << endl;
    }
}
void pattern21(int n)
{
    for(int i =1; i<=n ;i++)
    {
        if(i==1 || i==n)
        {
            for(int j=1; j <=n ;j++)
            {
                cout << "*";
            }
        }
        else
        {
            cout << "*";
            for(int k=1 ; k<= (n-2) ; k++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    pattern20(n);
}