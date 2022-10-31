class Solution {
    public String largepal(String num) {
        int[] count = new int[10];
        int center = -1;
        BuildString first = new BuildString();
        BuildString second;
        for (char c : num.toCharArray()) {
            count[c - '0']++;
        }
        int c = 0;
        for (int i = 9; i >= 0; i--) {
            c = 0;
            if (count[i] % 2 == 1 && center == -1) {
                center = i;
            }
            if (first.length() == 0 && i == 0) {
                continue;
            }
            while (c < count[i] / 2) {
                first.append(String.valueOf(i));
                c++;
            }
        }
        second = new BuildString(first.toString());
        if (center != -1) {
            first.append(center);
        }
        first.append(second.reverse().toString());
        return first.length() == 0 ? "0" : first.toString();
    }
}