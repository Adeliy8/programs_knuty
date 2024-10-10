def atbash(text):
    result = ""
    for ch in text:
        if 'A' <= ch <= 'Z':
            result += chr(ord('Z') - (ord(ch)-ord('A')))
        elif 'a' <= ch <= 'z':
            result += chr(ord('z') - (ord(ch)-ord('a')))
        elif '0' <= ch <= '9':
            result += ch
        else:
            result+=ch

    return result

text = "Hello, мир! 1234567890"
output_text = atbash(text)
print("Зашифрованный текст: ", output_text)

decrypted_text = atbash(output_text) #дешифрование - обратное преобразование
print("Расшифрованный текст: ", decrypted_text)