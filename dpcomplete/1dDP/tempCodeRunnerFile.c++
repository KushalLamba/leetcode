bool helper(string s1,string s2,unordered_map<string,bool>& map)
{
  if(s1==s2) return true;
  if(s1.size()!=s2.size()) return false;
  int n=s1.size();
  string key=s1+"_"+s2;
  if(map.find(key)!=map.end()) return map[key];
  bool result=false;
  for(int i=1;i<n;i++)
  {
    bool swapped=helper(s1.substr(i,n-i),s2.substr(0,i),map);
    if(swapped)
    {
        result=true;
        break;
    }
    bool notswap=helper(s1.substr(0,i),s2.substr(0,i),map);
    if(notswap)
    {
        result=true;
        break;
    }
  }
  return map[key]=result;
}
bool isScrimble(string s1,string s2)
{
    unordered_map<string,bool> map;
    return helper(s1,s2,map);
}