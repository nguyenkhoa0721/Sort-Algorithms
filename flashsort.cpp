void flashSort(int arr[], int n)
{
    //classification
    int maxval = arr[0];
    int idx = 0, k;
    int minval = arr[0];
    int m = 0.43 * n;
    int *L = new int[m + 1];
    for (int i = 0; i <= m; i++)
    {
        L[i] = 0;
    }
    L[0] = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxval)
        {
            maxval = arr[i];
            idx = i;
        }
        if (minval > arr[i])
            minval = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        k = ((float)(m - 1) / (maxval - minval)) * (arr[i] - minval);
        L[k]++;
    }
    for (int i = 1; i < m; i++)
    {
        L[i] += L[i - 1];
    }
    swapp(arr[0], arr[idx]);

    // permutation
    int move = 0;
    int j = 0;
    k = m - 1;
    while (move < n)
    {
        while (j > L[k])
        {
            j++;
            k = ((float)(m - 1) / (maxval - minval)) * (arr[j] - minval);
        }
        int flash = arr[j];
        while (j <= L[k])
        {
            k=((float)(m - 1) / (maxval - minval)) * (flash - minval);
            swapp(arr[L[k]], flash);
            L[k]--;
            move++;
        }
    }

    //insertsort
    for (int k = 0; k < m - 1; k++)
    {
        for (int i = L[k + 1] - 1; i > L[k]; i--)
        {
            int hold;
            if (arr[i] > arr[i + 1])
            {
                hold = arr[i];
                j = i;
                while (hold > arr[j + 1])
                    arr[j++] = arr[j + 1];
                arr[j] = hold;
            }
        }
    }
    delete[] L;
}