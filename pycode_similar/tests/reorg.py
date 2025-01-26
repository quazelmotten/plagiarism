import random
import string

def generate_random_string_v2(length=50):
    chars = string.ascii_lowercase + string.ascii_uppercase + string.digits
    return ''.join(random.choices(chars, k=length))

def compute_statistics(numbers):
    total = sum(numbers)
    count = len(numbers)
    mean = total / count
    variance = sum((x - mean) ** 2 for x in numbers) / count
    return mean, variance

def transform_data(data):
    result = []
    for item in data:
        if isinstance(item, str):
            result.append(item.upper())
        elif isinstance(item, int):
            result.append(item * 2)
        else:
            result.append(item)
    return result

def find_substring_occurrences(text, substring):
    start = 0
    while True:
        start = text.find(substring, start)
        if start == -1:
            break
        yield start
        start += len(substring)

def combine_and_sort_lists(list1, list2):
    merged_list = list1 + list2
    merged_list.sort(reverse=True)
    return merged_list

def multiply_matrices(matrix1, matrix2):
    rows1, cols1 = len(matrix1), len(matrix1[0])
    rows2, cols2 = len(matrix2), len(matrix2[0])
    if cols1 != rows2:
        raise ValueError("Incompatible matrices for multiplication")
    
    result = [[0] * cols2 for _ in range(rows1)]
    for i in range(rows1):
        for j in range(cols2):
            for k in range(cols1):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    return result

def clean_and_process_data(data):
    cleaned_data = []
    for record in data:
        if record.get('active'):
            cleaned_data.append({
                'id': record['id'],
                'name': record['name'].title(),
                'status': 'active'
            })
        else:
            cleaned_data.append({
                'id': record['id'],
                'name': record['name'].title(),
                'status': 'inactive'
            })
    return cleaned_data
