package main

import (
	"fmt"
	"unicode"
)

func caesarCipher(i rune, shift int) rune {
	if unicode.IsLetter(i) {
		base := 'A'
		if unicode.IsLower(i) {
			base = 'a'
		}
		return (i-base+rune(shift))%26 + base
	}
	return i
}

func encrypt(text string, shift int) string {
	result := ""
	for _, i := range text {
		result += string(caesarCipher(i, shift))
	}
	return result
}

func main() {
	text := "Hello, World 123456789!"
	encryptedText := encrypt(text, 3)
	fmt.Println(encryptedText)
}
