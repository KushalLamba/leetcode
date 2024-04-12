int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int sumg = 0;
    int sumc = 0;

    for (int i = 0; i < cost.size(); i++)
    {
        sumg += gas[i];
        sumc += cost[i];
    }
    if (sumc > sumg)
    {
        return -1;
    }
    int n = gas.size()-1;
    int sol = 0;
    int prev = 0;
    int i = 0;
    while (i != n)
    {
        if (i >= gas.size())
        {
            i = 0;
        }
        else if (gas[i] + prev < cost[i])
        {
            sol = i + 1;
            n = i;
            prev = 0;
        }
        else
        {
            prev = gas[i] - cost[i];
        }
        i++;
    }
    return sol;
}