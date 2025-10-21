void bubbleSort(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                swap(v, i, j);
            }
        }
    }
}