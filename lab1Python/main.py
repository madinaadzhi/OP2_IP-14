import lab1


if __name__ == '__main__':
    input_file = 'data.txt'
    lab1.fill_file(input_file)

    print("\nFile content: ")
    lab1.print_the_file_content(input_file)

    output_file = 'largest_words.txt'
    lab1.process_file(input_file, output_file)

    print("\nLargest words from each line of text:")
    lab1.print_the_file_content(output_file)
