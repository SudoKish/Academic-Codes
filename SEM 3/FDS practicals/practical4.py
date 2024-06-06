def longest_word(s):
    # Split the string into words
    words = s.split()
    # Find the word with the maximum length
    longest = max(words, key=len)
    return longest

def char_frequency(s, char):
    # Count how many times the character 'char' appears in the string 's'
    return s.count(char)

def is_palindrome(s):
    # Remove spaces and convert to lowercase for accurate palindrome check
    s_cleaned = s.replace(" ", "").lower()
    # Check if the cleaned string is equal to its reverse
    return s_cleaned == s_cleaned[::-1]

def first_substring_index(s, substring):
    # Find the index of the first appearance of the substring
    return s.find(substring)

def word_count(s):
    # Split the string into words
    words = s.split()
    # Create a dictionary to store the frequency of each word
    frequency = {}
    for word in words:
        # Convert the word to lowercase to make the word count case-insensitive
        word = word.lower()
        if word in frequency:
            # If the word is already in the dictionary, increment its count
            frequency[word] += 1
        else:
            # If the word is not in the dictionary, add it with count 1
            frequency[word] = 1
    return frequency

# Test the functions with a sample string
sample_string = "This is a sample string with sample words and this string is just a sample."

# a) Display word with the longest length
print("Word with the longest length:", longest_word(sample_string))

# b) Determine the frequency of occurrence of a particular character in the string
char = 's'
print(f"Frequency of '{char}' in the string:", char_frequency(sample_string, char))

# c) Check whether the given string is a palindrome or not
palindrome_string = "A man a plan a canal Panama"
print(f"Is the string '{palindrome_string}' a palindrome?:", is_palindrome(palindrome_string))

# d) Display the index of the first appearance of the substring
substring = "sample"
print(f"Index of the first appearance of '{substring}':", first_substring_index(sample_string, substring))

# e) Count the occurrences of each word in a given string
print("Word count in the string:", word_count(sample_string))
