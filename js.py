def find_first_occurrence(file_path, target_string):
    with open(file_path, 'r') as file:
        for line_number, line in enumerate(file, start=1):
            if target_string in line:
                return line_number
    return -1

file_path = '/home/wangxv/Files/cxsj_sduoj/week7/out.txt'  # 替换成你的文件路径
target_string = input('your_target_string')  # 替换成你要查找的字符串

line_number = find_first_occurrence(file_path, target_string)
if line_number != -1:
    print(f"The first occurrence of '{target_string}' is found at line {line_number}.")
else:
    print(f"'{target_string}' is not found in the file.")
