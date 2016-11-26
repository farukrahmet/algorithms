min_stack = []
stack = []


def push(member):
    if(not min_stack):
        min_stack.append(member)
    elif(member <= min_stack[-1]):
        min_stack.append(member)
    stack.append(member)


def pop():
    if(not stack):
        print("stack is empty")
    if(stack[-1] == min_stack[-1]):
        min_stack.pop()
    return stack.pop()


def get_min_stack():
    return min_stack[-1]


def test(fn):
    def wrap(*args, **kwargs):
        ret = fn(*args, **kwargs)
        if ret:
            print("pass %s" % (fn.__name__))
        else:
            print("fail %s" % (fn.__name__))
    return wrap


@test
def test_just_push():
    push(5)
    return get_min_stack() == 5


@test
def test_push_10_20_0_1_and_pop():
    push(10)
    push(20)
    push(0)
    push(1)
    # stack is [10,20,0,1]
    # min stack is should be [10,0]
    pop()
    return get_min_stack() == 0


@test
def test_push_10_20_0_1_and_2_times_pop():
    push(10)
    push(20)
    push(0)
    push(1)
    # stack is [10,20,0,1]
    # min stack is should be [10,0]
    pop()
    pop()
    return get_min_stack() == 10
