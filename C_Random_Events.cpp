int findMinComplexity (int complexity[], int n, int days) 
{
    int ans = 0;
    sort(complexity, comlexity+n);     // sort the array
    
    // for days-1, do only 1 lecture of min complexity available
    for(int i=0; i<days-1; i++)
        ans += complexity[i];    // add that to ans

    // last day do rest of the lectures, so take max complexity of them
    ans += complexity[n-1];

}