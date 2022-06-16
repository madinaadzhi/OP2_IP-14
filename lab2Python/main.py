import lab2

if __name__ == '__main__':
    worker_file_name = "workers.txt"

    filemode = ""
    while not (filemode == 'a' or filemode == 'w'):
        filemode = input("Pick the file mode. Enter w to overwrite file or "
                         "a - to append to an existing: ")

    lab2.fill_file(worker_file_name, filemode)

    print("\nInitial file is:")
    lab2.print_file(worker_file_name)

    retired_filepath = "retired.txt"
    lab2.get_retire_workers(worker_file_name, retired_filepath)

    print("Workers who have retire in this year:")
    lab2.print_file(retired_filepath)

    lab2.remove_already_retired(retired_filepath)

    print("\nWorkers who have retire in this year without 70 y.o. men and 65 y.o. women:")
    lab2.print_file(retired_filepath)
