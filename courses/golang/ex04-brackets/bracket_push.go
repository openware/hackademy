package brackets

func Bracket(s string) (bool, error) {
	bracket := map[rune]rune{
		'}': '{',
		')': '(',
		']': '[',
	}
	stack := make([]rune, 0)
	for _, b := range s {
		v, ok := bracket[b]
		if ok {
			length := len(stack)
			if length > 0 && stack[length-1] == v {
				stack = stack[:len(stack)-1]
			} else {
				return false, nil
			}
		} else {
			stack = append(stack, b)
		}
	}
	if len(stack) > 0 {
		return false, nil
	}
	return true, nil
}
