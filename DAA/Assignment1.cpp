#include <bits/stdc++.h>
using namespace std;


class fib{
    public:
    int n;
    fib(int n)
    {
        this->n=n;

    }

    void iterative()
    {
        int t1=0;
        int t2=1;
        int nexterm=0;

        for(int i=1;i<=n;i++)
        {
            if(i==1)
            {
                cout<<t1<<" ";
                continue;
            }
            if(i==2)
            {
                cout<<t2<<" ";
                continue;
            }

            nexterm=t1+t2;
            t1=t2;
            t2=nexterm;
            cout<<nexterm<<" ";
        }
        cout<<endl;

    }
    
    int recursive(int i)
    {
        if( i==0 || i==1)
        {
           return i;
    
        }
        return recursive(i-1)+recursive(i-2);
        
    }


};

int main()
{
    int n;
    cin>>n;
    fib f(n);
    cout<<"iterative: ";
    f.iterative();
    cout<<"recursive: ";
    for(int i=0;i<n;i++)
    {
        cout<< f.recursive(i)<<" ";

    }

    return 0;
}

/*
    Iterative Approach :
        Time Complexity :- O(N)
        Space Complexity :- O(1)
    Recursive Approach :
        Time Complexity :- O(2^N) --> Exponential Since on function makes recursive call to two more functions
        Space Complexity :- O(N) --> Max depth of recursion tree is N
*/

/*
    Input --> 
    Enter N:
    5
    Using Iteration fibonacci series:
    0 1 1 2 3
    Using Recursion fibonacci series:
    0 1 1 2 3

*/
