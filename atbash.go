package main

import (
	"fmt"
)

func atbashCipher(text string) string {
	result := ""

	for _, ch := range text {
		if ch >= 'A' && ch <= 'Z' {
			result += string('Z' - (ch - 'A'))
		} else if ch >= 'a' && ch <= 'z' {
			result += string('z' - (ch - 'a'))
		} else {
			result += string(ch)
		}
	}

	return result
}

func main() {
	var inputText string

	fmt.Print("Text: ")
	fmt.Scanln(&inputText)

	outputText := atbashCipher(inputText)

	fmt.Println("Result:", outputText)
}
