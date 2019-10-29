def find_substring__(string, substring):
    len_s = len(string)
    len_sub = len(substring)
    table_offset = {chr(i): len_sub for i in range(256)}
    for i in range(len_sub - 1):
        table_offset[sub[i]] = len_sub - i - 1
    k = len_sub - 1
    while k < len_s:
        j = 0
        while (j < len_sub and s[k - j] == sub[len_sub - j - 1]):
            j += 1
        if j != len_sub:
            k += table_offset[s[k]]
        else:
            return k - len_sub + 1
    return -1