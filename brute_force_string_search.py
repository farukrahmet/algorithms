def search(text, pattern):
    i = 0
    text_length = len(text)
    pattern_length = len(pattern)
    found = 0
    while i <= text_length - pattern_length and not found:
        j = 0
        while j < pattern_length and text[i+j] == pattern[j]:
            j += 1
        if j == pattern_length:
            found = 1
        else:
            i += 1
    if found:
        return i
    else:
        return -1
