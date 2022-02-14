package downcase

func Downcase(str string) (string, error) {
	s := []rune(str)
	for i, let := range str {
		switch {
		case let >= 'A' && let <= 'Z':
			s[i] = let - 'A' + 'a'
		}
	}
	return string(s), nil
}
