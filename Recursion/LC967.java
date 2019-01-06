class LC967 {

    public int[] numsSameConsecDiff(int N, int K) {
        Set<String> list = new TreeSet<>();
        int start = 1;
        if(N == 1) {
            start = 0;
        }
        for (int i = start; i <= 9; i++) {
            Set<String> values = numsSameConsecDiffHelper(N - 1, K, i);
            list.addAll(values);
        }
        
        return list.stream().map(t -> Integer.parseInt(t)).mapToInt(t -> t).toArray();
    }
    

    private Set<String> numsSameConsecDiffHelper(int N, int K, int prev) {
        Set<String> result = new TreeSet<>();
        if(N == 0) {
            result.add(Integer.toString(prev));
            return result;
        }
        
        String prevString = Integer.toString(prev);
        Set<String> rest = new TreeSet<>();
        
        if(prev + K < 10) {
            rest.addAll(numsSameConsecDiffHelper(N -1, K, prev + K));
        }
        if(prev - K >= 0) {
            rest.addAll(numsSameConsecDiffHelper(N -1, K, prev - K));
        }
        
        result.addAll(rest.stream().map(s -> prevString + s).collect(Collectors.toSet()));
                      
        return result;
        
    }
    
}