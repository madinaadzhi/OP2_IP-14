import pickle
from get_age import get_age
import datetime as dt
import os


class Person:
    def __init__(self, fullname, birth_date, gender, post):
        self.fullname = fullname
        self.birth_date = birth_date
        self.gender = gender
        self.rank = post


def fill_file(filepath: str, filemode: str) -> None:
    workers = []

    with open(filepath, f'{filemode}b') as file:
        count = int(input('Enter count of workers: '))
        if count <= 0:
            print('No data given!')
        else:
            for i in range(count):
                fullname = input('\nEnter the fullname of worker: ')
                birth_date = input('Enter the date of birth in DD.MM.YYYY format: ')
                gender = input('Enter gender of worker (m - male, f - female): ')
                post = input("Enter the worker's company post: ")

                p = Person(fullname, birth_date, gender, post)
                workers.append(p)

            pickle.dump(workers, file)


def print_file(filepath: str) -> None:
    def print_data(person, age):
        print(
            f"Fullname of worker: {person.fullname}",
            f"Birth date: {person.birth_date} (age: {age})",
            f"Gender: {person.gender}",
            f"Work post: {person.post}\n",
            sep="\n"
        )

    with open(filepath, 'rb') as file:
        file.seek(0)

        for workers in read_from_pickle(filepath):
            try:
                for worker in workers:
                    print_data(worker, get_age(worker.birth_date))
            except:
                print_data(workers, get_age(workers.birth_date))


def get_retire_workers(from_path: str, to_path: str) -> None:
    def save_retired(person):
        current_year = dt.date.today().year
        year_delta = current_year - int(person.birth_date[-4:])

        if (person.gender.lower() == 'm' and year_delta == 70) or \
                (person.gender.lower() == 'f' and year_delta == 65):
            pickle.dump(person, to_file)

    with open(from_path, 'rb') as from_file:
        from_file.seek(0)

        with open(to_path, 'wb') as to_file:
            for workers in read_from_pickle(from_path):
                try:
                    for worker in workers:
                        save_retired(worker)
                except:
                    save_retired(workers)


def read_from_pickle(filepath: str):
    with open(filepath, 'rb') as file:
        try:
            while True:
                yield pickle.load(file)
        except EOFError:
            pass


def remove_already_retired(filepath: str) -> None:
    def del_retired(person):
        personal_age = get_age(person.birth_date)
        already_retired = (person.gender.lower() == 'm' and personal_age >= 70) or \
                          (person.gender.lower() == 'f' and personal_age >= 65)

        if not already_retired:
            pickle.dump(person, temp)

    with open(filepath, 'rb') as file:

        temp_path = 'temp_file.txt'
        with open(temp_path, 'wb') as temp:
            for workers in read_from_pickle(filepath):
                try:
                    for worker in workers:
                        del_retired(worker)
                except:
                    del_retired(workers)

    os.remove(filepath)
    os.rename(temp_path, filepath)
