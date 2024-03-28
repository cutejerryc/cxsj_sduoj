import string
import random

def generate_uppercase_string_with_all_letters():
    # 生成包含全部大写字母的列表
    uppercase_letters = list(string.ascii_uppercase)
    
    # 随机确定字符串长度在 [100, 10000] 区间内
    length = random.randint(30, 100)
    
    # 如果长度小于26，直接返回全部大写字母的组合
    if length <= 26:
        return ''.join(uppercase_letters[:length])
    else:
        # 如果长度大于26，则随机打乱大写字母列表，并重复拼接直到达到指定长度
        random.shuffle(uppercase_letters)
        while len(uppercase_letters) < length:
            uppercase_letters.extend(uppercase_letters)
        random.shuffle(uppercase_letters)
        
        # 确保至少每个字母都包含一次
        remaining_length = length - 26
        additional_letters = list(string.ascii_uppercase)
        random.shuffle(additional_letters)
        result_string = ''.join(uppercase_letters[:length - remaining_length])
        result_string += ''.join(additional_letters[:remaining_length])
        
        return result_string

# 调用函数生成字符串
result_string = generate_uppercase_string_with_all_letters()
print(result_string)
