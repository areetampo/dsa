class Solution:
     def hasSpecialSubstring(self, inppp_strrrr: str, subbyyyyyyyy: int) -> bool:
        total_length = len(inppp_strrrr)
        for indexxuuu in range(total_length - subbyyyyyyyy + 1):
            current_char = inppp_strrrr[indexxuuu]
            if inppp_strrrr[indexxuuu:indexxuuu+subbyyyyyyyy] != current_char * subbyyyyyyyy:
                continue
            if indexxuuu > 0 and inppp_strrrr[indexxuuu-1] == current_char:
                continue
            if indexxuuu + subbyyyyyyyy < total_length and inppp_strrrr[indexxuuu+subbyyyyyyyy] == current_char:
                continue
            return True
        return False
        