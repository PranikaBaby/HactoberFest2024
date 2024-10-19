def quick_sort(arr):
    """Sorts an array using the Quick Sort algorithm."""
    if len(arr) <= 1:  # Base case: arrays with 0 or 1 element are already sorted
        return arr
    else:
        pivot = arr[len(arr) // 2]  # Choose the pivot
        left = [x for x in arr if x < pivot]  # Elements less than pivot
        middle = [x for x in arr if x == pivot]  # Elements equal to pivot
        right = [x for x in arr if x > pivot]  # Elements greater than pivot
        return quick_sort(left) + middle + quick_sort(right)  # Combine results

if __name__ == "__main__":
    # Example usage
    array = [9, 7, 5, 11, 12, 2, 14, 3, 10, 6]
    print("Original array:", array)
    sorted_array = quick_sort(array)
    print("Sorted array:", sorted_array)
