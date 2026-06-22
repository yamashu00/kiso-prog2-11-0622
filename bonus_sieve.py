def sieve_of_erastosthenes(def_range):

    num_set = []
    for i in range(def_range):
        num_set.insert(-1,True)

    target_prime = 2
    last_target_prime = None
    del_target_num = 4
    con = False

    while con == False:
        if del_target_num > len(num_set):
            print("Done")
            break
        for i in range(def_range):
            num_set[del_target_num-1] = False
            del_target_num += target_prime
            if del_target_num > len(num_set):
                break

        target_num = target_prime + 1
        
        for i in range(def_range):
            if num_set[target_num-1] == True:
                last_target_prime = target_prime
                target_prime = target_num
                break
            target_num += 1
            
        del_target_num = target_prime * 2

    count = 1
    prime_set = []
    for i in num_set:
        if i == True:
            prime_set.append(count)
        count += 1

    return prime_set

print(sieve_of_erastosthenes())