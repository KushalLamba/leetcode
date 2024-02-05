/*                        nth fibbonacci number leetcode 50*/
// class Solution {
// public:
// int fibbohelper(int n,int *arr)
// {
//     if(n==1 || n==0)
//     {
//         return n;
//     }
//     if(arr[n]!=-1)
//     {
//         return arr[n];
//     }
//     arr[n]=fibbohelper(n-1,arr)+fibbohelper(n-2,arr);
//     return arr[n];
// }
//     int fib(int n) {
//         int *arr=new int[n+1];
//         for(int i=0;i<n+1;i++)
//         {
//             arr[i]=-1;
//         }
//         return fibbohelper(n,arr);
//     }
// };