package stack

func New() *Stack {
	return &Stack{
		stack: make([]int, 0),
	}
}

type Stack struct {
	stack []int
}

func (st *Stack) Push(val int) {
	st.stack = append(st.stack, val)
}

func (st *Stack) Pop() int {
	ret := st.stack[len(st.stack)-1]
	st.stack = st.stack[:len(st.stack)-1]
	return ret
}
