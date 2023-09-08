
def main():

    owing = 50

    while True:

        while True:
            payment = int(input("Insert coin: "))
            if (payment == 25) or (payment == 10) or (payment == 5):
                break
            else:
                print(f"Amount due: {owing}")
       
        owing = amountowing(payment, owing)

        if owing > 0:
            print(f"Amount due: {owing}")

        elif owing == 0:
            print(f"Change owed: {owing}")
            break

        else:
            owing = str(owing)
            owing = owing.lstrip("-")
            print(f"Change owed: {owing}")
            break

def amountowing(payment, owing):
    owing = (owing - payment)
    return owing

main()



