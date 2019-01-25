#include <stdio.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <climits>

using namespace std;

int thirdSmallest(unordered_set<int> candidates)
{
  if(candidates.size() < 3)
    return 0;
    
  int fSmallest = INT_MAX;
  int sSmallest = INT_MAX;
  int tSmallest = INT_MAX;
  
  for( auto iter = candidates.begin();
       iter != candidates.end();
       iter ++)
  {
    if( *iter < fSmallest)
    {
      tSmallest = sSmallest;
      sSmallest = fSmallest;
      fSmallest = *iter;
    }
    else if( *iter < sSmallest)
    {
      tSmallest = sSmallest;
      sSmallest = *iter;
    }
    else if( *iter < tSmallest)
    {
      tSmallest = *iter;
    }
  }
  
  return tSmallest;
}

int main()
{
  
  unordered_set<int> candidates ;
  
  /*candidates.insert(10);
  candidates.insert(8);
  candidates.insert(11);
  candidates.insert(9);
  candidates.insert(15);
  candidates.insert(7);
  candidates.insert(6);*/
  
  /*candidates.insert(10);
  candidates.insert(8);
  candidates.insert(11);
  candidates.insert(9);*/
  
  /*candidates.insert(-10);
  candidates.insert(8);
  candidates.insert(11);
  candidates.insert(9);*/

  candidates.insert(4);
  candidates.insert(5);
  candidates.insert(0);
  candidates.insert(0);

  
  cout << " thirdSmallest is " << thirdSmallest(candidates) << endl;
    return 0;
}
