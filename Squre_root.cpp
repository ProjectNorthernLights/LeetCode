
0
▼
int sqrt(int x) {
    if (x == 0)
        return x;
    int left = 1, right = x;

    while (true) {
        int mid = (left + right) / 2;
        if (mid &gt; x / mid)
            right = mid - 1;
        else if (mid + 1 &gt; x / (mid + 1)) //mid &lt; x / mid
            return mid;
        else //mid &lt; x / mid
            left = mid + 1;
    }
}
