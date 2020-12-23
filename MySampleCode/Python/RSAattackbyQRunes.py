from pyqpanda import *

def gcd(m,n):
    if not n:
        return m
    else:
        return gcd(n, m%n)

def modReverse(c, m):
    if (c == 0):
        raise RecursionError('c is zero!')

    if (c == 1):
        return 1

    m1 = m
    quotient = []
    quo = m // c
    remainder = m % c

    quotient.append(quo)

    while (remainder != 1):
        m = c
        c = remainder
        quo = m // c
        remainder = m % c
        quotient.append(quo)

    if (len(quotient) == 1):
        return m - quo

    if (len(quotient) == 2):
        return 1 + quotient[0] * quotient[1]

    rev1 = 1
    rev2 = quotient[-1]
    reverse_list = quotient[0:-1]
    reverse_list.reverse()
    for i in reverse_list:
        rev1 = rev1 + rev2 * i
        temp = rev1
        rev1 = rev2
        rev2 = temp

    if ((len(quotient) % 2) == 0):
        return rev2

    return m1 - rev2

def plotBar(xdata, ydata):
    fig, ax = plt.subplots()
    fig.set_size_inches(6,6)
    fig.set_dpi(100)

    rects =  ax.bar(xdata, ydata, color='b')

    for rect in rects:
        height = rect.get_height()
        plt.text(rect.get_x() + rect.get_width() / 2, height, str(height), ha="center", va="bottom")

    plt.rcParams['font.sans-serif']=['Arial']
    plt.title("Origin Q", loc='right', alpha = 0.5)
    plt.ylabel('Times')
    plt.xlabel('States')

    plt.show()


def reorganizeData(measure_qubits, quick_meausre_result):
    xdata = []
    ydata = []

    for i in quick_meausre_result:
        xdata.append(i)
        ydata.append(quick_meausre_result[i])

    return xdata, ydata


def shorAlg(base, M):
    if ((base < 2) or (base > M - 1)):
        raise('Invalid base!')

    if (gcd(base, M) != 1):
        raise('Invalid base! base and M must be mutually prime')

    binary_len = 0
    while M >> binary_len != 0 :
        binary_len = binary_len + 1

    machine = init_quantum_machine(QMachineType.CPU_SINGLE_THREAD)

    qa = machine.qAlloc_many(binary_len*2)
    qb = machine.qAlloc_many(binary_len)

    qs1 = machine.qAlloc_many(binary_len)
    qs2 = machine.qAlloc_many(binary_len)
    qs3 = machine.qAlloc_many(2)

    prog = QProg()

    prog.insert(X(qb[0]))
    prog.insert(single_gate_apply_to_all(H, qa))
    prog.insert(constModExp(qa, qb, base, M, qs1, qs2, qs3))
    prog.insert(qft(qa).dagger())

    directly_run(prog)
    result = quick_measure(qa, 100)

    print(result)

    xdata, ydata = reorganizeData(qa, result)
    plotBar(xdata, ydata)

    return result

if __name__=="__main__":
    base = 7
    N = 15
    shorAlg(base, N)