string removeKdigits(string num, int k)
{
    if (num.empty())
    {
        return "";
    }
    if (num.size() == 1 && k > 0)
    {
        return "0";
    }
    string s;
    s.push_back(num[0]);
    int i = 1;
    while (i < num.size() && k != 0)
    {
        if (s[s.size() - 1] == num[i])
        {
            s.push_back(num[i]);
            k++;
        }
        if (s[s.size() - 1] > num[i])
        {
            s.pop_back();
            s.push_back(num[i]);
        }
        k--;
        i++;
    }
    while (i < s.size())
    {
        s.push_back(num[i]);
    }
    return s;
}