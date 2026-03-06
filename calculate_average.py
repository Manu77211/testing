
def calculate_average(numbers):
    for num in numbers:
        total += num          # BUG: 'total' never initialized
    return total / len(numbers)

scores = [85, 92, 78, 95, 88]
avg = calculate_average(scores)
print(f"Average score: {avg}")
