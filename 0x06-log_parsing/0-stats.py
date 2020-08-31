#!/usr/bin/python3
'''
Script for log parsing
'''
import sys


def main():
    '''
    Main program for reading lines from stdin
    '''
    a = []
    dictio = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
              "405": 0, "500": 0, "file_size": 0}
    i = 0
    try:
        for lines in sys.stdin:
            a = lines.split(" ")
            if checking_code(a[7]) == 1:
                dictio[a[7]] += 1
                value = a[8].replace("\n", "")
                dictio["file_size"] += int(value)
                i += 1
            if i % 10 == 0:
                printing_stats(dictio)
    except KeyboardInterrupt:
        printing_stats(dictio)
    except (BrokenPipeError, IOError):
            pass
    sys.exit(1)


def checking_code(str):
    '''
    Checks if a line matches code criteria
    '''
    codes = ["200", "301", "400", "401" "403", "404", "405", "500"]
    if str in codes:
        return (1)
    else:
        return(0)


def printing_stats(dictio):
    '''
    Function that prints the dictio
    '''
    if dictio["file_size"] > 0:
        print("File size: {}".format(dictio["file_size"]))
    if dictio["200"] > 0:
        print("200: {}".format(dictio["200"]))
    if dictio["301"] > 0:
        print("301: {}".format(dictio["301"]))
    if dictio["400"] > 0:
        print("400: {}".format(dictio["400"]))
    if dictio["401"] > 0:
        print("401: {}".format(dictio["401"]))
    if dictio["403"] > 0:
        print("403: {}".format(dictio["403"]))
    if dictio["404"] > 0:
        print("404: {}".format(dictio["404"]))
    if dictio["405"] > 0:
        print("405: {}".format(dictio["405"]))
    if dictio["500"] > 0:
        print("500: {}".format(dictio["500"]))
    return (0)

if __name__ == "__main__":
    main()
