import java.util.*;

public class LongestCommonSubsequence_top_down
{
	static TreeMap<String, Character> resultStr = new TreeMap<>();
	public static int LCSLength(String s1, String s2, int n, int m, Map<String, Integer> map)
	{
		if(n == 0 || m == 0)
		{
			return 0;
		}
		
		String key = n + "|" + m;
		if (! map.containsKey(key))
		{
			if (s1.charAt(n-1) == s2.charAt(m-1))
			{
				map.put(key, LCSLength(s1, s2, n-1, m-1, map) + 1);
			}
			else
			{
				map.put(key, Integer.max(LCSLength(s1, s2, n-1, m, map), LCSLength(s1, s2, n, m-1, map)));
			}
			
		}
		return map.get(key);
	}
	public static void main(String[] args)
	{
		Map<String, Integer> map = new HashMap<>();
		String s1 = "ABCBDAB", s2 = "BDCABA";
		System.out.println("result:" + LCSLength(s1, s2,  s1.length(), s2.length(), map));
		
		Map<String, Integer> map1 = new HashMap<>();
		String s11 = "AAAAAAAAAAAAAAAA", s22 = "BBBBBBBBBBBBBBBA";
		System.out.println("result2:" + LCSLength(s11, s22,  s11.length(), s22.length(), map1));
	}
}