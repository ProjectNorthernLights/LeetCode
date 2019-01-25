#include <stdio.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

int thirdSmallest(unordered_set<int> candidates)
{
  int cnt = 1;
  if(candidates.size() < 3)
    return 0;
    
  set<int, greater<int>> ordered_set;
  for(auto iter = candidates.begin();
      iter != candidates.end();
      iter ++)
  {
    ordered_set.insert(*iter);
  }
  
  for(auto iter = ordered_set.begin();
      iter != ordered_set.end();
      iter++, cnt++)
  {
    if(cnt == 3)
      return *iter;
  }
}

int main()
{
  
  unordered_set<int> candidates ;
  candidates.insert(4);
  candidates.insert(1);
  candidates.insert(3);
  candidates.insert(2);
  candidates.insert(5);
  
  cout << " thirdSmallest is " << thirdSmallest(candidates) << endl;
    return 0;
}
