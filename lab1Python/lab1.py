def find_largest_word(line: str) -> str:
    max_word = ""
    word_list = line.split()
    for word in word_list:
        if len(word) > len(max_word):
            max_word = word
    return max_word


def count_words(filename: str) -> str:
    counter = 0
    with open(filename, 'r') as file:
        for line in file:
            word_list = line.split()
            counter += len(word_list)
    return str(counter)


def fill_file(filename: str, mode_write='w') -> None:
    print("Enter the text, or don't enter anything to stop:")
    lines = []
    line = input("Enter the line: ")
    while line:
        lines.append(line)
        line = input("Enter the line: ")
    text = '\n'.join(lines)

    with open(filename, mode_write) as file:
        file.write(text)


def print_the_file_content(filename: str) -> None:
    with open(filename, 'r') as file:
        print(file.read())


def process_file(filename_from: str, filename_to: str, mode_write='w') -> None:
    with open(filename_from, 'r') as file_from:
        with open(filename_to, mode_write) as file_to:
            for line in file_from:
                file_to.write(find_largest_word(line) + "\n")
            file_to.write("\nCount words in the text: " + count_words(filename_from))
