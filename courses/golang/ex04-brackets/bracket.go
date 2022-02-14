package brackets

func Bracket(inp string) (bool, error) {
	st := Stack{stack: make([]rune, 0)}
	for _, v := range inp {
		if v == '[' || v == '(' || v == '{' {
			st.Push(v)
		}
		if v == ']' || v == ')' || v == '}' {
			if len(st.stack) == 0 {
				return false, nil
			}
			if st.Peek() == openingBracket(v) {
				st.Pop()
			} else {
				return false, nil
			}
		}
	}

	if len(st.stack) == 0 {
		return true, nil
	} else {
		return false, nil
	}
}

type Stack struct {
	stack []rune
}

func (st *Stack) Push(r rune) {
	st.stack = append(st.stack, r)
}

func (st *Stack) Pop() rune {
	prevToLast := len(st.stack) - 1
	ret := st.stack[prevToLast]
	st.stack = st.stack[:prevToLast]
	return ret
}

func (st *Stack) Peek() rune {
	prevToLast := len(st.stack) - 1
	return st.stack[prevToLast]
}

func openingBracket(r rune) rune {
	switch r {
	case '}':
		return '{'
	case ')':
		return '('
	case ']':
		return '['
	default:
		return 0
	}
}
