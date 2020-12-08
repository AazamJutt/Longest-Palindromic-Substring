string findPalindrome(string s)
{
    int n = s.size();
    string palindrome = "";
    int** tab = new int*[n];
    string res;
    string temp;
    //Allocating and Initializing Matrix with 0
    for (int i = 0; i < n; i++)
        tab[i] = new int[n] {0};
    bool* indexes = new bool[n] {false};
    //filling diagonals
    for (int i = 0; i < n; i++)
        tab[i][i] = 1;
    int i = 0, j = 1, count = 1;

    while (count < n-1)
    {
        if (j == n)
        {
            count++;
            i = 0;
            j = count;
        }
        if (s[i] == s[j])
        {
            tab[i][j] = tab[i + 1][j - 1] + 2;
            if (!indexes[i] && !indexes[j])//if indexes are not selected
            {
                if (count == 2)//odd length
                {
                    indexes[i] = true;
                    indexes[i + 1] = true;
                    indexes[j] = true;
                }
                else
                {
                    indexes[i] = true;
                    indexes[j] = true;
                }
            }
        }
        else
            tab[i][j] = max(tab[i][j - 1], tab[i + 1][j]);
        i++;
        j++;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<indexes[i]<<' ';
        if (indexes[i])
            res += s[i];
    }
    cout << '\n';
    return res;    
}