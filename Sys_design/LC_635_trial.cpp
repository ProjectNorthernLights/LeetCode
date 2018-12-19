class LogSystem {
public:
  //have a map to contain mappings <id, timestamps>
  unordered_map<int, string> map;
  
  //Have another map where you can store which part of the string to slice
  unordered_map<string, pair<int, int>> lengths;
  
    LogSystem() 
    {
      lengths.emplace("Year", make_pair(0,4));
      lengths.emplace("Month", make_pair(5,2));
      lengths.emplace("Day", make_pair(8,2));
      lengths.emplace("Hour", make_pair(11,2));
      lengths.emplace("Minute", make_pair(14,2));
      lengths.emplace("Second", make_pair(17,2));
    }
    
    void put(int id, string timestamp) {
        map.emplace(id, timestamp);
    }
    
    vector<int> retrieve(string s, string e, string gra) 
    {
      vector<int> result;
      
      unordered_map<string, pair<int, int>> ::iterator itr;
      itr = lengths.find(gra);
      
      if(itr != lengths.end())
      {
        
        int start = itr->second.first;
        int length = itr->second.second;
        
        string sSlice = s.substr(start, length);
        string eSlice = e.substr(start, length);
        
        //iterate over the map looking for the granularity
        unordered_map<int, string> :: iterator mapItr;
        
        for(mapItr = map.begin() ; mapItr != map.end(); mapItr ++)
        {
          string timestamp = mapItr->second;
          string toLookFor = timestamp.substr(start, length);
          
          //Get the numeric rep of the string
          stringstream str(toLookFor);
          int integerVal ;
          str >> integerVal;
         
          stringstream sstr(sSlice);
          int integerValsSlice ;
          sstr >> integerValsSlice;
          
          stringstream estr(eSlice);
          int integerValeSlice ;
          estr >> integerValeSlice;
          
          if( integerValsSlice <= integerVal &&
              integerValeSlice >= integerVal)
          {
            result.push_back(mapItr->first);
          }
        }
      }
      
      return result;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
