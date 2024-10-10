def bin_search(arr, tar):
    left = 0
    right = len(arr) - 1
    i = int((left + right) / 2)

    while bool((left <= i) & (right >= i)):
        print(f"Проверка элемента в массиве по индексу {i}")


        if arr[i] == tar:
            print(f"{arr[i]} == {tar}")
            return i
        elif arr[i] < tar:
            print(f"{arr[i]} < {tar}")
            i+=1
        else:
            print(f"{arr[i]} > {tar}")
            i-=1
    return -1


if __name__ == "__main__":
    arr=[45, 34, 78, 52, 12, 88, 199, 1, 3]
    arr.sort()
    print("Отсортированный массив:", arr)

    tar=199
    result = bin_search(arr, tar)

    print(f"Элемент найден: индекс в массиве {result}, элемент {arr[result]}")
