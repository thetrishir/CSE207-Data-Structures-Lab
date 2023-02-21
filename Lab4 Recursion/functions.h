/**
    Implement the following functions using recursion.
    You get 10 points for each problem
*/


/**
    The following function should take an integer n as its
    argument and return the sum of all even integers upto n.

    You should use recursion to solve the problem. You can
    assume that n is an even integer
*/

int func(int n){
    if(n!=0){
        if(n%2==0){
            return n+func(n-1);
        }
        else
            return func(n-1);
    }
    else
    return n;
}

/**
    The following function should take a non-negative integer
    n as its argument and return the sum of the squares of all
    digits of n.

    You should use recursion to solve the problem.
*/

int sum_of_digits_squared(int n){
    if (n!=0){
        return(n%10)*(n%10+ sum_of_digits_squared(n/10);
    }
    else
    return 0;
}

/**
    The following max_of_array function should take an integer array
    ara[] consisting only of positive integers and the size of the
    array n  as its arguments, and return the value of the maximum
    element in the array. The elements of the array are in the indices
    0 to n-1.

    You should use recursion to solve the problem. To do so, you
    can implement the recursive function rec, and call rec from the
    max_of_array function using appropriate parameters.
*/

int rec(int ara[], int n, int pos){
    if(n<0)
    return pos;
    else{
        if(pos>=ara[n])
            return rec(ara,n-1,pos);
        if(pos<ara[n])
            return rec(ara,n-1,ara[n]);
    }

}

int max_of_array(int ara[], int n){
    return  rec(ara,n-2,ara[n-1]);
}


/**
    The following function should take a
    non-negative integer n as argument and
    return the value of the factorial of n.

    In case you do not remember,

    factorial(n)=1 X 2 X 3 X .... X n

    You can assume that the value of n will
    be such that n! will not overflow.

    You should use recursion to solve the
    problem.
*/

int factorial(int n){
    if(n!=0){
        return n*factorial(n-1);
    }
    else
    return 1;
}






