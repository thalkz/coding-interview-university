# Arrays in Python are Vectors by default

def array_tests():
    array = []
    for i in range(20):
        array.append(i)

    print("Vector with 20 elements")
    print(array)

    array.insert(0, 200)
    array.insert(5, 100)

    print("Prepend 200 and add 100 at 5th position")
    print(array)
    print("5th Item : " + str(array[5]))

    for i in range(15):
        array.pop()

    print("Pop 15 items")
    print(array)

    array.remove(100)
    print("Remove value 100")
    print(array)

    array.sort();
    array.reverse();
    print("Sort and reverse array")
    print(array)

def main():
    array_tests()

if __name__ == "__main__":
    main()
