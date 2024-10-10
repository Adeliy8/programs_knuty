def enigma(message):
    en_message = ""
    for char in message:
        if char.isalpha():
            base = ord('A') if char.isupper() else ord('a')
            encrypted_char = chr((ord(char) - base + 3) % 26 + base)  # Шифрование
            en_message += encrypted_char
        else:
            en_message += char
    return en_message

def de_enigma(encrypted_message):
    de_message = ""
    for char in encrypted_message:
        if char.isalpha():
            base = ord('A') if char.isupper() else ord('a')
            decrypted_char = chr((ord(char) - base - 3) % 26 + base)  # Дешифрование
            de_message += decrypted_char
        else:
            de_message += char
    return de_message


message = "HELLO world 123456789!"
en_message = enigma(message)
print("Зашифрованный текст: ", en_message)

# Дешифрование
de_en_message = de_enigma(en_message)
print("Расшифрованный текст: ", de_en_message)