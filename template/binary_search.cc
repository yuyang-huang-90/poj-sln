
int main()
{
    int l, r;
    int A[200];
    while (l < r - 1)
    {
        int m = l + (r - l) / 2;
        // check condition 1 
        if (A[m] > A[l])
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    // check condition 2
    return 0;
}