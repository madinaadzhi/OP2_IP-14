import datetime as dt


def get_age(birth_date: str) -> int:
    birth_date_object = dt.datetime.strptime(birth_date, "%d.%m.%Y")  # DD.MM.YYYY

    current_date = dt.datetime.now()
    years = (current_date - birth_date_object).days // 365

    return years
