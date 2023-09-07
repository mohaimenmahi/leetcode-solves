class Solution:
    def splitString(self, s: str) -> bool:
        def dfs(idx, prev):
            if idx == len(s):
                return True

            for i in range(idx, len(s)):
                val = int(s[idx:i+1])
                if val + 1 == prev and dfs(i+1, val):
                    return True
            return False

        for i in range(len(s)-1):
            val = int(s[:i+1])
            if dfs(i+1, val):
                return True
            
        return False
        