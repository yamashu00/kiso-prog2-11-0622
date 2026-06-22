def eucidean_algorithm(a,b):
    input_a = a
    input_b = b

    output_big = 0
    output_small = 0

    if input_a < input_b:
        output_big = input_b
        output_small = input_a

    elif input_b < input_a:
        output_big = input_a
        output_small = input_b

    div_target = output_big
    div_by = output_small

    comp = False
    modulo = None
    common_denominator = None

    while comp == False:
        modulo = div_target % div_by

        if modulo == 0:
            common_denominator = div_by
            comp = True
        
        div_target = div_by
        div_by = modulo

    if common_denominator == 1:
        return False
    else:
        return common_denominator

print(eucidean_algorithm())