package downcase

func Downcase(str string) (lowerStr string, err error) {

	for _, char := range str {
		if 65 <= char && char <= 90 {
			lowerStr += string(char + 32)
		} else {
			lowerStr += string(char)
		}
	}

	return lowerStr, nil
}
